# include <app/interface/widgets.hpp>

using namespace NotePile;

MainWidgets::MainWidgets(void) {

}

MainWidgets::

MainWidgets::MainWidgets(wxFrame *target) {
    Init(target);
}

void MainWidgets::Init(wxFrame *target) {
    //buttons
    button.Create(target, wxID_ANY, "Click Me", wxPoint(10,10), wxSize(150, 50));
    killButton.Create(target, wxID_ANY, "X", wxPoint(100, 200), wxSize(30,25));
    txt.Create(target, wxID_ANY, "", wxPoint(10,70), wxSize(300, 30));
    list.Create(target, wxID_ANY, wxPoint(10,110), wxSize(300, 30));
};