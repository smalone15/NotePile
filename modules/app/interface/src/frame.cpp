#include <wx/wx.h>
#include <iostream>
#include <app/interface/frame.hpp>

using namespace NotePile;

wxBEGIN_EVENT_TABLE(MasterFrame, wxFrame)
wxEND_EVENT_TABLE()

MasterFrame :: MasterFrame(const wxString &title)
{
    // Call stuff I need happening before the Create()
    SetBackgroundStyle(wxBG_STYLE_TRANSPARENT);
    SetTransparent(100);
    
    // Now call constructor
    Create(nullptr, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxFRAME_SHAPED | wxBORDER_NONE | wxTRANSPARENT_WINDOW);
    components.Init(this);

    int width, height;
    wxDisplaySize(&width, &height);
    width *= 0.5;
    double aspect = 16.0 / 9.0;

    SetSize(width, (int)(width / aspect));
    Center();

    // button commands
    components.button.Bind(
        wxEVT_COMMAND_BUTTON_CLICKED, 
        &MasterFrame::button_clicked, 
        this
    );
}

MasterFrame :: ~MasterFrame(void) {

}


void MasterFrame :: button_clicked(wxCommandEvent &evt) {
    std :: cout << "Clicked Primary Button" << std :: endl;
    components.list.Append(components.txt.GetValue());
    evt.Skip();
}