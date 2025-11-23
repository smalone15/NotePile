#include <app/interface/frame.hpp>
#include <app/interface/launcher.hpp>

using namespace NotePile;

bool Launcher::OnInit() {
    m = new MasterFrame("NotePile");
    m->Show();
    return true;
}

