#include <wx/wx.h>
#include <wx/display.h>
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

    // Set Parent Window Size - stuck at a small size though...
    wxDisplay display(wxDisplay::GetFromWindow(this));
    wxRect screenRect = display.GetClientArea();

    //Resize full frame to ful screen (But still windowed, not true fullscreen)
    SetSize(screenRect.GetWidth(), screenRect.GetHeight());
    SetPosition(screenRect.GetPosition());

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