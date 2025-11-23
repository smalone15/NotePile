#include <wx/wx.h>

namespace NotePile {
    class MainWidgets {
        public:
            MainWidgets(void);
            MainWidgets(wxFrame *target);
            void Init(wxFrame *target);
            wxButton button;
            wxTextCtrl txt;
            wxListBox list;
    };
}