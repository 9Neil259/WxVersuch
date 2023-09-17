#pragma once

#ifndef SIMPLE_H_INCLUDED
#define SIMPLE_H_INCLUDED
#include "unit.hpp"
#include <wx/wx.h>
#include <wx/listctrl.h>

class Simple : public wxFrame
{
public:
    Simple(const wxString& title);
    wxStaticText *m_text;
    wxStaticBitmap *m_bitmap;
    void OnItemSelected(wxCommandEvent & event);
    void OnCheckBoxClicked(wxCommandEvent& event);
    bool showInfo;
    wxMenuBar *menuBar;
    wxMenu* fileMenu;
    wxMenu* helpMenu;
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
private:
    wxListCtrl* listCtrl; 
    Unit* selectedUnit;
    
     wxDECLARE_EVENT_TABLE();
     
     enum {
    ID_About = wxID_HIGHEST + 1
};
};
#endif // SIMPLE_H_INCLUDED
