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
    class SecondaryWidgets
    {
        public:
            SecondaryWidgets(void);
            SecondaryWidgets(wxFrame *target);
            void OnInit(wxFrame *target);
            wxPanel childPanel;
    };
}