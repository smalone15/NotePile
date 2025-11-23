#include <wx/wx.h>
#include <app/interface/launcher.hpp>


#define REALEASE_BUILD
#ifdef RELEASE_BUILD
wxIMPLEMENT_APP(NotePile::Launcher)
#else
wxIMPLEMENT_APP_CONSOLE(NotePile::Launcher);
#endif