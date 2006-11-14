//---------------------------------------------------------------------------
//
// Name:        dvdrentalApp.cpp
// Author:      ako
// Created:     11/14/2006 12:14:42 PM
// Description: 
//
//---------------------------------------------------------------------------

#include "dvdrental.h"
#include "main.h"

IMPLEMENT_APP(DvdRental)

bool DvdRental::OnInit()
{
    Main* frame = new Main(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int DvdRental::OnExit()
{
	return 0;
}
