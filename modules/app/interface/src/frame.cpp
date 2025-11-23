#include <wx/wx.h>
#include <wx/display.h>
#include <iostream>
#include <app/interface/frame.hpp>

#ifdef _WIN32
#include <wx/msw/private.h>

void MakeWindowClickThrough(wxWindow* win)  //function makes window clickthroughable if called in constructor
{
    HWND hwnd = GetHwndOf(win);

    LONG ex = GetWindowLong(hwnd, GWL_EXSTYLE);
    ex |= WS_EX_LAYERED | WS_EX_TRANSPARENT;
    SetWindowLong(hwnd, GWL_EXSTYLE, ex);

    SetLayeredWindowAttributes(hwnd, 0, 180, LWA_ALPHA);

}
#endif

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
    // MakeWindowClickThrough(this); //Make window clickthrough-able, problem is, no components within the frame are clickable either...
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
    components.killButton.Bind(
        wxEVT_BUTTON,
        &MasterFrame::killButton_clicked,
        this
    );
}

MasterFrame :: ~MasterFrame(void) {

}

//Button Functions
void MasterFrame :: button_clicked(wxCommandEvent &evt) {
    std :: cout << "Clicked Primary Button" << std :: endl;
    components.list.Append(components.txt.GetValue());
    evt.Skip();
}

void MasterFrame:: killButton_clicked(wxCommandEvent &evt) {
    std :: cout << "Clicked Kill Frame Button" << std :: endl;
    Close();
    evt.Skip();
}