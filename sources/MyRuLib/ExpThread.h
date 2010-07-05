#ifndef __EXPTHREAD_H__
#define __EXPTHREAD_H__

#include <wx/wx.h>
#include <wx/thread.h>
#include <wx/arrimpl.cpp>
#include <wx/filename.h>
#include <wx/process.h>
#include <wx/timer.h>
#include "BaseThread.h"
#include "FbWindow.h"
#include "FbConst.h"
#include "FbBookEvent.h"

class ExportFileItem
{
	public:
		ExportFileItem(const wxFileName &n, const int i): filename(n), id(i) {};
	public:
		wxFileName filename;
		int id;
};

WX_DECLARE_OBJARRAY(ExportFileItem, ExportFileArray);

class FbExportDlg : public FbDialog
{
	private:
		class ExportLog: public wxLog
		{
			public:
				ExportLog(FbExportDlg * parent);
				virtual ~ExportLog();
			protected:
				void DoLog(wxLogLevel level, const wxChar *szString, time_t t);
				void DoLogString(const wxChar *szString, time_t t) {}
			private:
				FbExportDlg * m_parent;
				wxLog * m_old;
				DECLARE_NO_COPY_CLASS(ExportLog)
		};
		class JoinedThread: public wxThread
		{
			public:
				JoinedThread(FbExportDlg * parent)
					: wxThread(wxTHREAD_JOINABLE), m_parent(parent) {}
				void Execute();
			protected:
				virtual void OnExit();
				FbExportDlg * m_parent;
		};
		class ExportThread: public JoinedThread
		{
			public:
				ExportThread(FbExportDlg * parent, int format, const ExportFileItem &item);
			protected:
				virtual void * Entry();
			private:
				int m_format;
				int m_id;
				wxString m_filename;
		};
		class GzipThread: public JoinedThread
		{
			public:
				GzipThread(FbExportDlg * parent, const wxArrayString &args);
			protected:
				virtual void * Entry();
			private:
				wxArrayString m_filelist;
		};
		class ZipThread: public JoinedThread
		{
			public:
				ZipThread(FbExportDlg * parent, const wxArrayString &args);
			protected:
				virtual void * Entry();
			private:
				wxArrayString m_filelist;
		};
		class DelThread: public JoinedThread
		{
			public:
				DelThread(FbExportDlg * parent, const wxArrayString &args);
			protected:
				virtual void * Entry();
			private:
				wxArrayString m_filelist;
		};
		class ExportProcess: public wxProcess
		{
			public:
				ExportProcess(FbExportDlg * parent): m_parent(parent) { Redirect(); }
				virtual void OnTerminate(int pid, int status);
				virtual bool HasInput();
				#ifdef __WXMSW__
				bool m_dos;
				#endif // __WXMSW__
			protected:
				wxString ReadLine(wxInputStream * stream);
				FbExportDlg * m_parent;
		};
	public:
		FbExportDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER );
		~FbExportDlg();
		void Execute();
		void LogMessage(const wxString &msg);
		ExportFileArray m_filelist;
		int m_format;
	private:
		void Start();
		void Finish();
		wxString GetScript(int format);
		wxString GetCommand(const wxString &script, const wxFileName &filename);
		void ExportFile(size_t index, const ExportFileItem &item);
		void ExecScript(size_t index, const wxFileName &filename);
		wxArrayString m_scripts;
		size_t m_index;
		size_t m_script;
		ExportProcess m_process;
		ExportLog m_log;
		bool m_closed;
		int m_errors;
		JoinedThread * m_thread;
	private:
		wxStaticText m_info;
		wxListBox m_text;
		wxGauge m_gauge;
		wxButton m_button;
		wxTimer m_timer;
	private:
		void OnTimer(wxTimerEvent& event);
		void OnIdle(wxIdleEvent& event);
		void OnProcessTerm(wxProcessEvent& event);
		void OnCancelBtn(wxCommandEvent& event);
		void OnCloseBtn(wxCommandEvent& event);
		void OnScriptRun(wxCommandEvent& event);
		void OnScriptLog(wxCommandEvent& event);
		void OnScriptError(wxCommandEvent& event);
		void OnScriptExit(wxCommandEvent& event);
		void OnCloseDlg(wxCloseEvent& event);
		DECLARE_EVENT_TABLE()
		DECLARE_CLASS(FbExportDlg);
};

#endif // __EXPTHREAD_H__