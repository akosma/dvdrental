//---------------------------------------------------------------------------
//
// Name:        dvdrentalApp.h
// Author:      ako
// Created:     11/14/2006 12:14:42 PM
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __MAINApp_h__
#define __MAINApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class DvdRental : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
