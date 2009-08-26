///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 29 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include <wx/artprov.h>
#include "FbManager.h"
#include "FbParams.h"
#include "SettingsDlg.h"
#include "ZipReader.h"
#include "BookListCtrl.h"
#include "MyRuLibApp.h"
#include "db/Types.h"

///////////////////////////////////////////////////////////////////////////

BEGIN_EVENT_TABLE( SettingsDlg, wxDialog )
	EVT_BUTTON( ID_LIBRARY_DIR_BTN, SettingsDlg::OnSelectFolderClick )
	EVT_BUTTON( ID_DOWNLOAD_DIR_BTN, SettingsDlg::OnSelectFolderClick )
	EVT_BUTTON( ID_EXTERNAL_BTN, SettingsDlg::OnSelectFolderClick )
	EVT_TREE_ITEM_ACTIVATED(ID_TYPELIST, SettingsDlg::OnTypelistActivated)
END_EVENT_TABLE()

SettingsDlg::SettingsDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    wxNotebook* m_notebook;
    wxPanel* m_panel1;
    wxStaticText* m_staticText1;
    wxTextCtrl* m_textCtrl1;
    wxStaticText* m_staticText5;
    wxTextCtrl* m_textCtrl5;
    wxBitmapButton* m_bpButton5;
    wxStaticText* m_staticText2;
    wxTextCtrl* m_textCtrl2;
    wxBitmapButton* m_bpButton2;
    wxStaticText* m_staticText31;
    wxTextCtrl* m_textCtrl3;
    wxBitmapButton* m_bpButton3;
    wxStaticText* m_staticText4;
    wxTextCtrl* m_textCtrl4;
    wxBitmapButton* m_bpButton4;
    wxCheckBox* m_checkBox1;
    wxPanel* m_panel2;
    wxStaticText* m_staticText6;
    wxTextCtrl* m_textCtrl6;
    wxBitmapButton* m_bpButton6;
    wxCheckBox* m_checkBox2;
    wxCheckBox* m_checkBox3;
    wxRadioBox* m_radioBox1;
    wxRadioBox* m_radioBox2;
    wxPanel* m_panel3;
    wxCheckBox* m_checkBox21;
    wxStaticText* m_staticText7;
    wxTextCtrl* m_textCtrl7;
    wxStaticText* m_staticText8;
    wxTextCtrl* m_textCtrl8;
    wxStaticText* m_staticText9;
    wxTextCtrl* m_textCtrl9;
    wxStaticText* m_staticText10;
    wxTextCtrl* m_textCtrl10;
	wxPanel* m_panel4;
	wxToolBar* m_tools;
    wxStdDialogButtonSizer* m_sdbSizerBtn;
    wxButton* m_sdbSizerBtnOK;
    wxButton* m_sdbSizerBtnCancel;

	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxFlexGridSizer* fgSizerMain;
	fgSizerMain = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizerMain->SetFlexibleDirection( wxBOTH );
	fgSizerMain->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_notebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel1 = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizerTop11;
	fgSizerTop11 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizerTop11->SetFlexibleDirection( wxBOTH );
	fgSizerTop11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText1 = new wxStaticText( m_panel1, wxID_ANY, _("Описание библиотеки:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizerTop11->Add( m_staticText1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrl1 = new wxTextCtrl( m_panel1, ID_LIBRARY_TITLE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl1->SetMinSize( wxSize( 200,-1 ) );

	fgSizerTop11->Add( m_textCtrl1, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );

	m_staticText2 = new wxStaticText( m_panel1, wxID_ANY, _("Папка с файлами zip\nбиблиотеки lib.rus.ec:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizerTop11->Add( m_staticText2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	m_textCtrl2 = new wxTextCtrl( m_panel1, ID_LIBRARY_DIR_TXT, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl2->SetMinSize( wxSize( 300,-1 ) );

	bSizer4->Add( m_textCtrl2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_bpButton2 = new wxBitmapButton( m_panel1, ID_LIBRARY_DIR_BTN, wxArtProvider::GetBitmap(wxART_FOLDER_OPEN), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer4->Add( m_bpButton2, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );

	fgSizerTop11->Add( bSizer4, 1, wxEXPAND, 5 );

	m_staticText31 = new wxStaticText( m_panel1, wxID_ANY, _("Файлы скаченные\nчерез интернет:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	fgSizerTop11->Add( m_staticText31, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	m_textCtrl3 = new wxTextCtrl( m_panel1, ID_DOWNLOAD_DIR_TXT, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl3->SetMinSize( wxSize( 300,-1 ) );

	bSizer5->Add( m_textCtrl3, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_bpButton3 = new wxBitmapButton( m_panel1, ID_DOWNLOAD_DIR_BTN, wxArtProvider::GetBitmap(wxART_FOLDER_OPEN), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer5->Add( m_bpButton3, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );

	fgSizerTop11->Add( bSizer5, 1, wxEXPAND, 5 );

	bSizer1->Add( fgSizerTop11, 1, wxEXPAND|wxTOP, 5 );

	m_checkBox21 = new wxCheckBox( m_panel1, ID_USE_PROXY, _("Использовать прокси-сервер"), wxDefaultPosition, wxDefaultSize, 0 );

	bSizer1->Add( m_checkBox21, 0, wxALL|wxEXPAND, 5 );

	wxFlexGridSizer* fgSizer16;
	fgSizer16 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer16->SetFlexibleDirection( wxBOTH );
	fgSizer16->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText7 = new wxStaticText( m_panel1, wxID_ANY, _("    Адрес прокси-сервера:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	fgSizer16->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	m_textCtrl7 = new wxTextCtrl( m_panel1, ID_PROXY_ADDR, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl7->SetMinSize( wxSize( 100,-1 ) );

	bSizer13->Add( m_textCtrl7, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );

	m_staticText8 = new wxStaticText( m_panel1, wxID_ANY, _("Порт:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer13->Add( m_staticText8, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrl8 = new wxTextCtrl( m_panel1, ID_PROXY_PORT, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl8->SetMinSize( wxSize( 60,-1 ) );

	bSizer13->Add( m_textCtrl8, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );

	fgSizer16->Add( bSizer13, 0, wxEXPAND, 5 );

	m_staticText9 = new wxStaticText( m_panel1, wxID_ANY, _("    Имя пользователя:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	fgSizer16->Add( m_staticText9, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	m_textCtrl9 = new wxTextCtrl( m_panel1, ID_PROXY_NAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl9->SetMinSize( wxSize( 110,-1 ) );

	bSizer14->Add( m_textCtrl9, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );

	m_staticText10 = new wxStaticText( m_panel1, wxID_ANY, _("Пароль:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer14->Add( m_staticText10, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrl10 = new wxTextCtrl( m_panel1, ID_PROXY_PASS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	m_textCtrl10->SetMinSize( wxSize( 110,-1 ) );

	bSizer14->Add( m_textCtrl10, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );

	fgSizer16->Add( bSizer14, 0, wxEXPAND, 5 );

	bSizer1->Add( fgSizer16, 0, wxEXPAND, 5 );

	m_panel1->SetSizer( bSizer1 );
	m_panel1->Layout();
	bSizer1->Fit( m_panel1 );
	m_notebook->AddPage( m_panel1, _("Папки и файлы"), true );

	m_panel4 = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );

	m_tools = new wxToolBar( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORZ_TEXT|wxTB_NODIVIDER);
	m_tools->AddTool( wxID_ANY, _("Изменить"), wxArtProvider::GetBitmap(wxART_EXECUTABLE_FILE), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString );
	m_tools->AddTool( wxID_ANY, _("Удалить"), wxArtProvider::GetBitmap(wxART_DELETE), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString );
	m_tools->Realize();

	bSizer10->Add( m_tools, 0, wxTOP|wxRIGHT|wxLEFT|wxEXPAND, 5 );

//	BookListCtrl * typelist = new BookListCtrl( m_panel4, ID_TYPELIST, wxTR_HIDE_ROOT | wxTR_FULL_ROW_HIGHLIGHT | wxTR_COLUMN_LINES | wxTR_MULTIPLE );
	BookListCtrl * typelist = new BookListCtrl( m_panel4, ID_TYPELIST, wxTR_NO_LINES | wxTR_HIDE_ROOT | wxTR_FULL_ROW_HIGHLIGHT | wxTR_COLUMN_LINES );
    typelist->AddColumn (_T("Тип"), 50, wxALIGN_LEFT);
    typelist->AddColumn (_T("Программа"), 300, wxALIGN_LEFT);
    typelist->SetColumnEditable (0, false);
    typelist->SetColumnEditable (1, false);
    typelist->colSizes.Add(1);
    typelist->colSizes.Add(9);
	m_typelist = typelist;

	bSizer10->Add( m_typelist, 1, wxBOTTOM|wxRIGHT|wxLEFT|wxEXPAND, 5 );

	m_panel4->SetSizer( bSizer10 );
	m_panel4->Layout();
	bSizer10->Fit( m_panel4 );
	m_notebook->AddPage( m_panel4, _("Типы файлов"), false );

	m_panel2 = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText6 = new wxStaticText( m_panel2, wxID_ANY, _("Папка внешнего\nустройства:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer8->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );

	m_textCtrl6 = new wxTextCtrl( m_panel2, ID_EXTERNAL_TXT, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl6->SetMinSize( wxSize( 300,-1 ) );

	bSizer8->Add( m_textCtrl6, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_bpButton6 = new wxBitmapButton( m_panel2, ID_EXTERNAL_BTN, wxArtProvider::GetBitmap(wxART_FOLDER_OPEN), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer8->Add( m_bpButton6, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );

	bSizer12->Add( bSizer8, 0, wxEXPAND, 5 );

	wxFlexGridSizer* fgSizer23;
	fgSizer23 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer23->SetFlexibleDirection( wxBOTH );
	fgSizer23->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_checkBox2 = new wxCheckBox( m_panel2, ID_TRANSLIT_FOLDER, _("Транслитерация имени папки"), wxDefaultPosition, wxDefaultSize, 0 );

	fgSizer23->Add( m_checkBox2, 0, wxALL, 5 );

	m_checkBox3 = new wxCheckBox( m_panel2, ID_TRANSLIT_FILE, _("Транслитерация имен файлов"), wxDefaultPosition, wxDefaultSize, 0 );

	fgSizer23->Add( m_checkBox3, 0, wxALL, 5 );

	wxString m_radioBox1Choices[] = { _("Автор / Книга"), _("Автор / Серия / Книга") };
	int m_radioBox1NChoices = sizeof( m_radioBox1Choices ) / sizeof( wxString );
	m_radioBox1 = new wxRadioBox( m_panel2, ID_FOLDER_FORMAT, _("Организация папок и файлов"), wxDefaultPosition, wxDefaultSize, m_radioBox1NChoices, m_radioBox1Choices, 1, wxRA_SPECIFY_COLS );
	m_radioBox1->SetSelection( 0 );
	fgSizer23->Add( m_radioBox1, 0, wxALL, 5 );

	wxString m_radioBox2Choices[] = { _("filename.fb2"), _("filename.fb2.zip") };
	int m_radioBox2NChoices = sizeof( m_radioBox2Choices ) / sizeof( wxString );
	m_radioBox2 = new wxRadioBox( m_panel2, ID_FILE_FORMAT, _("Формат выгрузки"), wxDefaultPosition, wxDefaultSize, m_radioBox2NChoices, m_radioBox2Choices, 1, wxRA_SPECIFY_COLS );
	m_radioBox2->SetSelection( 0 );
	fgSizer23->Add( m_radioBox2, 0, wxALL, 5 );

	bSizer12->Add( fgSizer23, 0, wxEXPAND, 5 );

	m_panel2->SetSizer( bSizer12 );
	m_panel2->Layout();
	bSizer12->Fit( m_panel2 );
	m_notebook->AddPage( m_panel2, _("Внешнее устройство"), false );

	fgSizerMain->Add( m_notebook, 1, wxEXPAND | wxALL, 5 );

	m_sdbSizerBtn = new wxStdDialogButtonSizer();
	m_sdbSizerBtnOK = new wxButton( this, wxID_OK );
	m_sdbSizerBtn->AddButton( m_sdbSizerBtnOK );
	m_sdbSizerBtnCancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizerBtn->AddButton( m_sdbSizerBtnCancel );
	m_sdbSizerBtn->Realize();
	fgSizerMain->Add( m_sdbSizerBtn, 1, wxEXPAND|wxALL, 5 );

	this->SetSizer( fgSizerMain );
	this->Layout();
	fgSizerMain->Fit( this );
}

SettingsDlg::~SettingsDlg()
{
}

void SettingsDlg::OnSelectFolderClick( wxCommandEvent& event )
{
    wxTextCtrl * textCtrl = (wxTextCtrl*)FindWindowById( event.GetId() - 1);

    if (!textCtrl) return;

    wxDirDialog dlg(
        this,
        _("Выберите директорию"),
        textCtrl->GetValue(),
        wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST | wxDD_NEW_DIR_BUTTON
    );

	if (dlg.ShowModal() == wxID_OK)  textCtrl->SetValue(dlg.GetPath());
}

void SettingsDlg::Assign(bool write)
{
    enum Type {
        tText,
        tCheck,
        tRadio,
    };
    struct Struct{
        int param;
        ID control;
        Type type;
    };

    const Struct ids[] = {
        {DB_LIBRARY_TITLE, SettingsDlg::ID_LIBRARY_TITLE, tText},
        {FB_LIBRARY_DIR, SettingsDlg::ID_LIBRARY_DIR_TXT, tText},
        {FB_DOWNLOAD_DIR, SettingsDlg::ID_DOWNLOAD_DIR_TXT, tText},
        {FB_EXTERNAL_DIR, SettingsDlg::ID_EXTERNAL_TXT, tText},
        {FB_TRANSLIT_FOLDER, SettingsDlg::ID_TRANSLIT_FOLDER, tCheck},
        {FB_TRANSLIT_FILE, SettingsDlg::ID_TRANSLIT_FILE, tCheck},
        {FB_FOLDER_FORMAT, SettingsDlg::ID_FOLDER_FORMAT, tRadio},
        {FB_FILE_FORMAT, SettingsDlg::ID_FILE_FORMAT, tRadio},
        {FB_USE_PROXY, SettingsDlg::ID_USE_PROXY, tCheck},
        {FB_PROXY_ADDR, SettingsDlg::ID_PROXY_ADDR, tText},
        {FB_PROXY_PORT, SettingsDlg::ID_PROXY_PORT, tText},
        {FB_PROXY_NAME, SettingsDlg::ID_PROXY_NAME, tText},
        {FB_PROXY_PASS, SettingsDlg::ID_PROXY_PASS, tText},
    };

    const size_t idsCount = sizeof(ids) / sizeof(Struct);

    FbParams params;

    for (size_t i=0; i<idsCount; i++) {
        switch (ids[i].type) {
            case tText:
                if (wxTextCtrl * control = (wxTextCtrl*)FindWindowById(ids[i].control))
                    if (write)
                        params.SetText(ids[i].param, control->GetValue());
                    else
                        control->SetValue(params.GetText(ids[i].param));
				break;
            case tCheck:
                if (wxCheckBox * control = (wxCheckBox*)FindWindowById(ids[i].control))
                    if (write)
                        params.SetValue(ids[i].param, control->GetValue());
                    else
                        control->SetValue((bool)params.GetValue(ids[i].param));
				break;
            case tRadio:
                if (wxRadioBox * control = (wxRadioBox*)FindWindowById(ids[i].control))
                    if (write)
                        params.SetValue(ids[i].param, control->GetSelection());
                    else
                        control->SetSelection(params.GetValue(ids[i].param));
				break;
        }

    }

	if (write) ZipReader::Init();
};

void SettingsDlg::Execute(wxWindow* parent)
{
    SettingsDlg dlg(parent, wxID_ANY, _("Настройка параметров программы"), wxDefaultPosition, wxDefaultSize);

    dlg.Assign(false);
	dlg.FillTypelist();

    if (dlg.ShowModal() == wxID_OK) {
   	    AutoTransaction trans;
    	dlg.Assign(true);
    	dlg.SaveTypelist();
    }
};

void SettingsDlg::FillTypelist()
{
	wxCriticalSectionLocker enter(wxGetApp().m_DbSection);

	wxString sql = wxT("\
		SELECT \
			books.file_type, types.command, \
			CASE WHEN books.file_type='fb2' THEN 1 ELSE 2 END AS number\
		FROM ( \
			 SELECT DISTINCT LOWER(file_type) AS file_type FROM BOOKS GROUP BY file_type \
			 UNION SELECT DISTINCT file_type FROM types \
			 UNION SELECT 'fb2' \
			 UNION SELECT 'pdf' \
			 UNION SELECT 'djvu' \
			 UNION SELECT 'txt' \
		) AS books \
		  LEFT JOIN types ON books.file_type = types.file_type \
		ORDER BY number, books.file_type \
     ");

	PreparedStatement* pStatement = wxGetApp().GetDatabase()->PrepareStatement(sql);
	DatabaseResultSet* result = pStatement->ExecuteQuery();

	m_typelist->Freeze();

    m_typelist->DeleteRoot();
    wxTreeItemId root = m_typelist->AddRoot (_T("Root"));

	while ( result && result->Next() ) {
		wxString file_type = result->GetResultString(wxT("file_type"));
		wxString command = result->GetResultString(wxT("command"));
		if (file_type == wxT("exe")) continue;

		wxTreeItemId item = m_typelist->AppendItem(root, file_type);
		m_typelist->SetItemText (item, 1, command);

		if (FbManager::GetSystemCommand(file_type, command))
			m_typelist->SetItemText (item, 1, command);
	}

    m_typelist->ExpandAll(root);

	m_typelist->Thaw();
}

void SettingsDlg::OnTypelistActivated( wxTreeEvent & event )
{
	wxTreeItemId item = event.GetItem();
	if (item.IsOk()) SelectApplication(item);
	event.Skip();
}

void SettingsDlg::SelectApplication(const wxTreeItemId &item)
{
#ifdef __WIN32__
    wxString wildCard = _("Исполняемые файлы (*.exe)|*.exe");
#else
    wxString wildCard = wxFileSelectorDefaultWildcardStr;
#endif

	wxString title = _("Выберите приложение для просмотра %s файлов…");

    wxFileDialog dlg (
		this,
		title,
		wxEmptyString,
		m_typelist->GetItemText (item, 1),
		wildCard,
		wxFD_OPEN | wxFD_FILE_MUST_EXIST,
		wxDefaultPosition
    );

	if (dlg.ShowModal() == wxID_OK) {
		m_typelist->SetItemText(item, 1, dlg.GetPath());
	}
}

void SettingsDlg::SaveTypelist()
{
	wxCriticalSectionLocker enter(wxGetApp().m_DbSection);
	Types types(wxGetApp().GetDatabase());
	TypesRowSet * rows = types.All();

	wxTreeItemIdValue cookie;
	wxTreeItemId root = m_typelist->GetRootItem();
	wxTreeItemId child = m_typelist->GetFirstChild(root, cookie);
	while (child.IsOk()) {
		wxString file_type = m_typelist->GetItemText(child, 0);
		wxString command = m_typelist->GetItemText(child, 1);
        child = m_typelist->GetNextChild(root, cookie);
		bool found = false;
		for (size_t i = 0; i<rows->Count(); i++) {
			TypesRow * row = rows->Item(i);
			if (row->file_type == file_type) {
				found = true;
				if (command.IsEmpty()) {
					row->Delete();
				} else {
					wxString sys_command;
					if (FbManager::GetSystemCommand(file_type, sys_command) && command == sys_command) {
						row->Delete();
					} else {
						row->command = command;
						row->Save();
					}
				}
				break;
			}
		}
		if (found) continue;

		wxString sys_command;
		if (FbManager::GetSystemCommand(file_type, sys_command) && command == sys_command) continue;

		TypesRow * row = types.New();
		row->file_type = file_type;
		row->command = command;
		row->Save();
	}
}
