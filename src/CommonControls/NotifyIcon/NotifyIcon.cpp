#include "Gammasoft.xpm"
#include "wxNotifyIcon.h"

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "NotifyIcon example", wxDefaultPosition, wxSize(300, 300)) {
    notifyIcon1.SetIcon(wxIcon(GammasoftIcon));
    notifyIcon1.Bind(wxEVT_TASKBAR_LEFT_DCLICK, [&](wxTaskBarIconEvent& event) {
      Show(!IsShown());
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxStaticText* label1 = new wxStaticText(panel, wxID_ANY, "Double click on Gammasoft tray icon\nto show or hide this form.", wxPoint(10, 10));
  wxNotifyIcon notifyIcon1;
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
