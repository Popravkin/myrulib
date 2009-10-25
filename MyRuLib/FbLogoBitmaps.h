#ifndef __XPMBITMAPS_H__
#define __XPMBITMAPS_H__

#include "res/nocheck.xpm"
#include "res/checked.xpm"
#include "res/checkout.xpm"

#ifndef __WXMSW__
#include "res/home.xpm"
#endif

#include <wx/wx.h>

class FbLogoBitmap: public wxBitmap
{
	public:
		FbLogoBitmap()
			#ifndef __WXMSW__
			:wxBitmap(home_xpm)
			#endif
		{
			#ifdef __WXMSW__
			wxIcon icon(wxT("aaaa"));
			CopyFromIcon(icon);
			#endif
		};

	private:
		void Unused()
		{
			wxUnusedVar(nocheck_xpm);
			wxUnusedVar(checked_xpm);
			wxUnusedVar(checkout_xpm);
			wxUnusedVar(home_xpm);
		};
};

#endif // __XPMBITMAPS_H__
