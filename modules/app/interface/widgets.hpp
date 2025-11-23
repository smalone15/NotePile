#include <wx/wx.h>

namespace NotePile {
    class MainWidgets {
        public:
            MainWidgets(void);
            MainWidgets(wxFrame *target);
            void Init(wxFrame *target);
            wxButton button;
            wxButton killButton;
            wxTextCtrl txt;
            wxListBox list;
    };
}