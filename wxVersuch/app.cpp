#include "app.hpp"
#include "simple.h"
#include <wx/wx.h>

bool App::OnInit() {
    wxImage::AddHandler(new wxPNGHandler);
    Simple *simple= new Simple(wxT("Dwarfish Fighter Stats"));
    simple->Center();
    simple->Show(true);
  return true;
}

wxIMPLEMENT_APP(App);
