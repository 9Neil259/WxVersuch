#include "simple.h"
#include "unit.hpp"
#include <wx/listctrl.h>

Simple::Simple(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(1250, 750))
{
    
    menuBar = new wxMenuBar;
    fileMenu = new wxMenu;
    fileMenu->Append(wxID_EXIT, "Exit");
    menuBar->Append(fileMenu, "File");
    helpMenu = new wxMenu;
    helpMenu->Append(ID_About, "About");
    menuBar->Append(helpMenu, "Help");
    SetMenuBar(menuBar);
    Bind(wxEVT_MENU, &Simple::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &Simple::OnAbout, this, ID_About);
    
    
    showInfo = false;

    DwarvishFighter dwarf("Dwarf");
    ElvishArcher elf("Elf");
    DrakeBurner drake("Drake");

    wxCheckBox* checkbox = new wxCheckBox(this, wxID_ANY, "Show Stats", wxPoint(100, 400));
    checkbox->Bind(wxEVT_CHECKBOX, &Simple::OnCheckBoxClicked, this);
    checkbox->SetValue(true);

    // Erstellen Sie m_text mit einer Position und Größe
    m_text = new wxStaticText(this, wxID_ANY, wxT(""), wxPoint(10, 10), wxSize(200, 100));
    wxImage img("images/dwarvishfighter.png", wxBITMAP_TYPE_PNG);
    m_bitmap = new wxStaticBitmap(this, -1, wxBitmap(img), wxPoint(180, 350));
    
    wxListView* listView = new wxListView(this, wxID_ANY, wxPoint(400, 10), wxDefaultSize, wxLC_REPORT);
    listView->AppendColumn("");
    listView->InsertItem(0, dwarf.name());
    listView->InsertItem(1, elf.name());
    listView->InsertItem(2, drake.name());
    listView->Bind(wxEVT_LIST_ITEM_SELECTED, &Simple::OnItemSelected, this);
    
    listCtrl = new wxListCtrl(this, wxID_ANY, wxPoint(400, 300), wxDefaultSize, wxLC_REPORT);
    listCtrl->InsertColumn(0, wxT("Name"));
    listCtrl->InsertColumn(1, wxT("Strikes"));
    listCtrl->InsertColumn(2, wxT("Range"));
    listCtrl->InsertColumn(3, wxT("Type"));
    

}   

void Simple::OnItemSelected(wxCommandEvent& event) {
        std::string selectedName = "Drake";
        std::string imagePath = "images/dwarvishfighter.png";
        if (selectedName == "Dwarf") {
            selectedUnit = new DwarvishFighter("Dwarf");
            imagePath = "images/dwarvishfighter.png";
        } else if (selectedName == "Elf") {
            selectedUnit = new ElvishArcher("Elf");
            imagePath = "images/elvisharcher.png";
        } else if (selectedName == "Drake") {
            selectedUnit = new DrakeBurner("Drake");
            imagePath = "images/drakeburner.png";
        }
              
        listCtrl->InsertItem(0, selectedUnit->melee_weapon().name());
        listCtrl->SetItem(0, 1, wxString::Format("%d", selectedUnit->melee_weapon().strikes()));
        listCtrl->SetItem(0, 2, selectedUnit->melee_weapon().is_ranged() ? wxT("ranged") : wxT("melee"));
        listCtrl->SetItem(0, 3, wxT("blade"));
        std::string stats = "Name: " + selectedUnit->name() + "\nHP: " + std::to_string(selectedUnit->max_health()) + "\nMoves: " + std::to_string(selectedUnit->moves())+"\nWeapons";
        m_text->SetLabel(stats);
        
        // Laden Sie das Bild der ausgewählten Einheit
        
        m_bitmap->SetBitmap(wxBitmap(imagePath, wxBITMAP_TYPE_PNG));
        m_bitmap->Show();

        showInfo = true;
}
void Simple::OnCheckBoxClicked(wxCommandEvent& event) {
    wxCheckBox* checkbox = dynamic_cast<wxCheckBox*>(event.GetEventObject());
    bool isChecked = checkbox->GetValue();
    if (!isChecked) {
        m_text->SetLabel("");
        listCtrl->Hide();
    }
    else {
            listCtrl->Show();
        }
    }
void Simple::OnExit(wxCommandEvent& event) {
    Close(true);
}

// Event-Handler für "About" Menüpunkt
void Simple::OnAbout(wxCommandEvent& event) {
    wxMessageBox("This is a viewer for creatures in a mythical game", "About Unit GUI", wxOK | wxICON_INFORMATION, this);
}

wxBEGIN_EVENT_TABLE(Simple, wxFrame)
    EVT_MENU(wxID_EXIT, Simple::OnExit)
    EVT_MENU(ID_About, Simple::OnAbout)
wxEND_EVENT_TABLE();
