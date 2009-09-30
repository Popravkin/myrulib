/***************************************************************
 * Name:      FbManager.h
 * Purpose:   Defines Application Frame
 * Author:    Kandrashin Denis (mail@kandr.ru)
 * Created:   2009-05-22
 * Copyright: Kandrashin Denis (www.lintest.ru)
 * License:
 **************************************************************/

#ifndef FBMANAGER_H
#define FBMANAGER_H

#include <wx/wx.h>
#include <wx/listbox.h>
#include <wx/wxsqlite3.h>
#include "wx/treelistctrl.h"

class AuthorsRowSet;

class BookTreeItemData: public wxTreeItemData
{
public:
	BookTreeItemData(BookTreeItemData * data):
		m_id(data->GetId()),
		title(data->title),
		file_name(data->file_name),
		file_type(data->file_type),
		file_size(data->file_size),
		sequence(data->sequence),
		number(data->number)
	{ };
	BookTreeItemData(wxSQLite3ResultSet & result);
	BookTreeItemData(int id): m_id(id) {};
	int GetId() { return m_id; };
private:
	int m_id;
public:
	wxString title;
	wxString file_name;
	wxString file_type;
	int file_size;
	wxString sequence;
	int number;
};

class FbManager
{
	public:
		static wxString GetAnnotation(int id);
		static void FillBooks(wxTreeListCtrl * treelist, int id_author, bool fb2only);
		static void FillAuthorsChar(wxListBox *listbox, const wxChar & findLetter);
		static void FillAuthorsText(wxListBox *listbox, const wxString & findText);
		static void OpenBook(int id, wxString &file_type);
		static wxString GetSystemCommand(const wxString & file_type);
		static wxString GetOpenCommand(const wxString & file_type);
};

class BookInfo
{
public:
    static void MakeLower(wxString & data);
    static void MakeUpper(wxString & data);
};

#endif //FBMANAGER_H
