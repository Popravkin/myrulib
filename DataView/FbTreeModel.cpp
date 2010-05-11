#include "FbTreeModel.h"

// -----------------------------------------------------------------------------
// class FbTreeDataArray
// -----------------------------------------------------------------------------

WX_DEFINE_OBJARRAY(FbTreeDataArray);

// -----------------------------------------------------------------------------
// class FbTreeDataNode
// -----------------------------------------------------------------------------

bool FbTreeDataNode::SetValue(FbTreeModel &model, const wxVariant &variant, unsigned int col)
{
    if (col == 0) {
        FbTitleData data;
        data << variant;
        Check(model, data.IsChecked());
    }
    return true;
}

// -----------------------------------------------------------------------------
// class FbParentDataNode
// -----------------------------------------------------------------------------

void FbParentDataNode::Check(FbTreeModel &model, bool checked)
{
    m_checked = FbTitleData::State(checked);
    for (size_t i=0; i<m_children.Count(); i++) m_children[i]->Check(model, checked);

    FbParentDataNode * owner = GetOwner();
    if (owner) owner->CheckChildren(model);
}

void FbParentDataNode::CheckChildren(FbTreeModel &model)
{
    for (size_t i=0; i<m_children.Count(); i++) {
        if (i == 0) {
            m_checked = m_children[i]->m_checked;
        } else if (m_checked != m_children[i]->m_checked) {
            m_checked = FbTitleData::ST_GRAY;
            break;
        }
    }
    model.ValueChanged(wxDataViewItem(this), 0);
    FbParentDataNode * owner = GetOwner();
    if (owner) owner->CheckChildren(model);
}

// -----------------------------------------------------------------------------
// class FbLetterDataNode
// -----------------------------------------------------------------------------

unsigned int FbLetterDataNode::GetChildren( const FbTreeModel &model, wxDataViewItemArray &children )
{
	if (m_children.Count()) {
		for (size_t i=0; i<m_children.Count(); i++) children.Add( wxDataViewItem(m_children[i]) );
		return m_children.Count();
	} else {
		for (size_t i=0; i<m_count; i++) {
			FbTreeDataNode * item = new FbAuthorDataNode(this, m_checked);
			m_children.Add( item );
			children.Add( wxDataViewItem(item) );
		}
		return m_count;
	}
}

void FbLetterDataNode::TestChildren(const FbTreeModel &model, NodeType type)
{
	if (m_count) {
		wxString sql = wxT("SELECT AuthId FROM Auth WHERE Letter=? ORDER BY SearchName");
		wxSQLite3Statement stmt = model.GetDatabase()->PrepareStatement(sql);
		stmt.Bind(1, (wxString)m_letter);
		wxSQLite3ResultSet result = stmt.ExecuteQuery();
		size_t i = 0;
		while (result.NextRow()) {
			if (i>=m_children.Count()) break;
			FbAuthorDataNode * author = (FbAuthorDataNode*)(m_children[i]);
			author->SetId(result.GetInt(0));
			i++;
		}
		m_count = 0;
	}
}

void FbLetterDataNode::GetValue(const FbTreeModel &model, wxVariant &variant, unsigned int col)
{
	if ( col==0 ) variant << FbTitleData(GetName(model), m_checked, 0);
}

// -----------------------------------------------------------------------------
// class FbAuthorDataNode
// -----------------------------------------------------------------------------

wxString FbAuthorDataNode::GetName(const FbTreeModel &model)
{
    wxString text;
    if (model.FindItemText(this, text)) return text;

    if (m_id) {
        wxString sql = wxT("SELECT FullName FROM Auth WHERE AuthId=?");
        wxSQLite3Statement stmt = model.GetDatabase()->PrepareStatement(sql);
        stmt.Bind(1, m_id);
        wxSQLite3ResultSet result = stmt.ExecuteQuery();
        if (result.NextRow()) return model.PushItemText(this, result.GetString(0));
    }
    return wxT("(noname)");
}

bool FbAuthorDataNode::SeqExists(const FbTreeModel &model)
{
    wxString sql = wxT("SELECT SeqnId FROM BkSeqn WHERE AuthId=? AND SeqnId<>0 LIMIT 1");
    wxSQLite3Statement stmt = model.GetDatabase()->PrepareStatement(sql);
    stmt.Bind(1, m_id);
    wxSQLite3ResultSet result = stmt.ExecuteQuery();
    return result.NextRow();
}

unsigned int FbAuthorDataNode::GetChildren( const FbTreeModel &model, wxDataViewItemArray &children )
{
	m_owner->TestChildren(model, GetType());

	if (m_children.Count()) {
		for (size_t i=0; i<m_children.Count(); i++) children.Add( wxDataViewItem(m_children[i]) );
		return m_children.Count();
	};

	if (SeqExists(model)) {
        wxString sql = wxT("SELECT COUNT(DISTINCT SeqnId) FROM BkSeqn WHERE AuthId=?");
        wxSQLite3Statement stmt = model.GetDatabase()->PrepareStatement(sql);
        stmt.Bind(1, m_id);
        wxSQLite3ResultSet result = stmt.ExecuteQuery();
        m_count = result.NextRow() ? result.GetInt(0) : 0;
		for (size_t i=0; i<m_count; i++) {
			FbTreeDataNode * item = new FbSequenceDataNode(this, m_checked);
			m_children.Add( item );
		    children.Add( wxDataViewItem(item) );
		}
	} else {
        wxString sql = wxT("SELECT COUNT(BookId) FROM BkSeqn WHERE AuthId=?");
        wxSQLite3Statement stmt = model.GetDatabase()->PrepareStatement(sql);
        stmt.Bind(1, m_id);
        wxSQLite3ResultSet result = stmt.ExecuteQuery();
        m_count = result.NextRow() ? result.GetInt(0) : 0;
		for (size_t i=0; i<m_count; i++) {
			FbTreeDataNode * item = new FbBookDataNode(this, m_checked);
			m_children.Add( item );
		    children.Add( wxDataViewItem(item) );
		}
    }
	return m_count;
}

void FbAuthorDataNode::GetValue(const FbTreeModel &model, wxVariant &variant, unsigned int col)
{
	m_owner->TestChildren(model, GetType());
	if ( col==0 ) variant << FbTitleData(GetName(model), m_checked, 1);
}

void FbAuthorDataNode::TestChildren(const FbTreeModel &model, NodeType type)
{
	m_owner->TestChildren(model, GetType());

	if (m_count) {
	    switch (type) {
            case NT_SEQUENCE: {
                wxString sql = wxT("SELECT BkSeqn.SeqnId, COUNT(BookId) FROM BkSeqn LEFT JOIN Seqn ON Seqn.SeqnId=BkSeqn.SeqnId WHERE AuthId=? GROUP BY BkSeqn.SeqnId ORDER BY Seqn.SeqnName");
                wxSQLite3Statement stmt = model.GetDatabase()->PrepareStatement(sql);
                stmt.Bind(1, m_id);
                wxSQLite3ResultSet result = stmt.ExecuteQuery();
                size_t i = 0;
                while (result.NextRow()) {
                    if (i>=m_children.Count()) break;
                    FbSequenceDataNode * item = (FbSequenceDataNode*)(m_children[i]);
                    item->SetId(result.GetInt(0), result.GetInt(1));
                    i++;
                }
                m_count = 0;
            } break;
            case NT_BOOK: {
                wxString sql = wxT("SELECT BkSeqn.BookId FROM BkSeqn LEFT JOIN Book ON Book.BookId=BkSeqn.BookId WHERE AuthId=? ORDER BY Title");
                wxSQLite3Statement stmt = model.GetDatabase()->PrepareStatement(sql);
                stmt.Bind(1, m_id);
                wxSQLite3ResultSet result = stmt.ExecuteQuery();
                size_t i = 0;
                while (result.NextRow()) {
                    if (i>=m_children.Count()) break;
                    FbBookDataNode * item = (FbBookDataNode*)(m_children[i]);
                    item->SetId(result.GetInt(0));
                    i++;
                }
                m_count = 0;
            } break;
	    }
	}
}

// -----------------------------------------------------------------------------
// class FbSequenceDataNode
// -----------------------------------------------------------------------------

wxString FbSequenceDataNode::GetName(const FbTreeModel &model)
{
    wxString text;
    if (model.FindItemText(this, text)) return text;

    if (m_id) {
        wxString sql = wxT("SELECT SeqnName FROM Seqn WHERE SeqnId=?");
        wxSQLite3Statement stmt = model.GetDatabase()->PrepareStatement(sql);
        stmt.Bind(1, m_id);
        wxSQLite3ResultSet result = stmt.ExecuteQuery();
        if (result.NextRow()) return model.PushItemText(this, result.GetString(0));
    }
    return wxT("(Misc.)");
}

void FbSequenceDataNode::GetValue(const FbTreeModel &model, wxVariant &variant, unsigned int col)
{
	m_owner->TestChildren(model, GetType());
	if ( col==0 ) variant << FbTitleData(GetName(model), m_checked, 2);
}

unsigned int FbSequenceDataNode::GetChildren( const FbTreeModel &model, wxDataViewItemArray &children )
{
	m_owner->TestChildren(model, GetType());

	if (m_children.Count()) {
		for (size_t i=0; i<m_children.Count(); i++) children.Add( wxDataViewItem(m_children[i]) );
		return m_children.Count();
	} else {
		for (size_t i=0; i<m_count; i++) {
			FbTreeDataNode * item = new FbBookDataNode(this, m_checked);
			m_children.Add( item );
			children.Add( wxDataViewItem(item) );
		}
		return m_count;
	}
}

void FbSequenceDataNode::TestChildren(const FbTreeModel &model, NodeType type)
{
	if (m_count) {
		wxString sql = wxT("SELECT BkSeqn.BookId FROM BkSeqn INDEXED BY BkSeqn_AuthId LEFT JOIN Book ON Book.BookId=BkSeqn.BookId WHERE BkSeqn.AuthId=? AND SeqnId=? ORDER BY Number, Title");
		wxSQLite3Statement stmt = model.GetDatabase()->PrepareStatement(sql);
		stmt.Bind(1, m_owner->GetId());
		stmt.Bind(2, m_id);
		wxSQLite3ResultSet result = stmt.ExecuteQuery();
		size_t i = 0;
		while (result.NextRow()) {
			if (i>=m_children.Count()) break;
			FbBookDataNode * item = (FbBookDataNode*)(m_children[i]);
			item->SetId(result.GetInt(0));
			i++;
		}
		m_count = 0;
	}
}

// -----------------------------------------------------------------------------
// class FbBookDataNode
// -----------------------------------------------------------------------------

wxString FbBookDataNode::GetName(const FbTreeModel &model)
{
    if (m_id) {
        wxString sql = wxT("SELECT Title FROM Book WHERE BookId=?");
        wxSQLite3Statement stmt = model.GetDatabase()->PrepareStatement(sql);
        stmt.Bind(1, m_id);
        wxSQLite3ResultSet result = stmt.ExecuteQuery();
        if (result.NextRow()) return result.GetString(0);
    }
    return wxT("(not found)");
}

void FbBookDataNode::GetValue(const FbTreeModel &model, wxVariant &variant, unsigned int col)
{
	m_owner->TestChildren(model, GetType());

    switch ( col ) {
		case fbCOL_TITLE: {
		    int level = m_owner->GetType() == NT_AUTHOR ? 2 : 3;
			variant << FbTitleData(GetName(model), m_checked, level);
		} break;
		case fbCOL_ROWID: {
			variant = wxString::Format("%d", m_id);
		} break;
	}
}

void FbBookDataNode::Check(FbTreeModel &model, bool checked)
{
    m_checked = FbTitleData::State(checked);
    m_owner->CheckChildren(model);
}

// -----------------------------------------------------------------------------
// class FbParentTreeDataArray
// -----------------------------------------------------------------------------

WX_DEFINE_OBJARRAY(FbParentTreeDataArray);

// -----------------------------------------------------------------------------
// class FbTreeModelData
// -----------------------------------------------------------------------------

FbTreeModelData::FbTreeModelData(wxSQLite3ResultSet &result)
{
	m_rowid = result.GetInt(0);
	m_bookid = result.GetInt(1);
	m_title = result.GetAsString(2);
	m_filesize = result.GetInt(3);
}

FbTreeModelData::FbTreeModelData(const FbTreeModelData &data) :
	m_rowid(data.m_rowid),
	m_bookid(data.m_bookid),
	m_title(data.m_title),
	m_authors(data.m_authors),
	m_filesize(data.m_filesize)
{
}

wxString FbTreeModelData::Format(const int number)
{
	int hi = number / 1000;
	int lo = number % 1000;
	if (hi)
		return Format(hi) + wxT(" ") + wxString::Format(wxT("%03d"), lo);
	else
		return wxString::Format(wxT("%d"), lo);
}

wxString FbTreeModelData::GetValue(unsigned int col)
{
	switch (col) {
		case fbCOL_ROWID:
			return wxString::Format("%d", m_rowid);
		case fbCOL_BOOKID:
			return wxString::Format("%d", m_bookid);
		case fbCOL_TITLE:
			return m_title;
		case fbCOL_SIZE:
			return Format(m_filesize);
		default:
			return wxEmptyString;
	}
}

// -----------------------------------------------------------------------------
// class FbTreeModel
// -----------------------------------------------------------------------------

FbTreeModel::FbTreeModel(const wxString &filename)
{
    m_parents = new FbParentTreeDataArray;

	m_database = new wxSQLite3Database;
	m_database->Open(filename);
}

FbTreeModel::~FbTreeModel()
{
    wxDELETE(m_database);
    wxDELETE(m_parents);
}

bool FbTreeModel::FindItemText(void * id, wxString &text) const
{
    for (size_t i=0; i<m_parents->Count(); i++) {
        FbParentTreeDataItem data = m_parents->Item(i);
        if (data.GetID() == id) {
            m_parents->RemoveAt(i);
            m_parents->Insert(data, 0);
            text = data.GetText();
            return true;
        }
    }
    return false;
}

const wxString & FbTreeModel::PushItemText(void * id, const wxString &text) const
{
    while (m_parents->Count() > BOOK_CASHE_SIZE) m_parents->RemoveAt(BOOK_CASHE_SIZE);
    FbParentTreeDataItem data(id, text);
    m_parents->Insert(data, 0);
    return text;
}

unsigned int FbTreeModel::GetChildren(const wxDataViewItem &item, wxDataViewItemArray &children) const
{
	if (item.IsOk()) {
		return Node(item)->GetChildren(*this, children);
	} else {
		for (size_t i=0; i<m_children.Count(); i++) children.Add( wxDataViewItem(m_children[i]) );
		return m_children.Count();
	}
}

void FbTreeModel::GetValue(wxVariant &variant, const wxDataViewItem &item, unsigned int col) const
{
    FbTreeDataNode * node = Node(item);
	if (node) node->GetValue(*this, variant, col);
}

bool FbTreeModel::SetValue(const wxVariant &variant, const wxDataViewItem &item, unsigned int col)
{
    FbTreeDataNode * node = Node(item);
	return node ? node->SetValue(*this, variant, col) : true;
}

bool FbTreeModel::GetAttr(const wxDataViewItem &item, unsigned int col, wxDataViewItemAttr &attr) const
{
    if (item.IsOk() && IsContainer(item))  {
        attr.SetBold(true);
        return true;
    } else return false;
}

wxDataViewItem FbTreeModel::GetParent( const wxDataViewItem &item ) const
{
    FbTreeDataNode * node = Node(item);
	return node ? node->GetParent() : wxDataViewItem(NULL);
}

bool FbTreeModel::IsContainer( const wxDataViewItem &item ) const
{
    FbTreeDataNode * node = Node(item);
	return node ? node->IsContainer() : true;
}

// -----------------------------------------------------------------------------
// class FbTreeModel
// -----------------------------------------------------------------------------

FbFullTreeModel::FbFullTreeModel(const wxString &filename)
    : FbTreeModel(filename)
{
	wxString sql = wxT("SELECT Letter, count(AuthId) FROM Auth GROUP BY Letter ORDER BY 1");
	wxSQLite3ResultSet result = m_database->ExecuteQuery(sql);
	while (result.NextRow()) {
		wxString text = result.GetString(0);
		wxChar letter = text.IsEmpty() ? wxT(' ') : text[0];
		unsigned int count = result.GetInt(1);
		FbLetterDataNode * item = new FbLetterDataNode(letter, count);
		m_children.Add(item);
	}
}