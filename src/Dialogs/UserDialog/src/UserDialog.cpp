#include <wx/wx.h>

class UserInputDialog : public wxDialog {
public:
  UserInputDialog(wxWindow *parent) : wxDialog(parent, wxID_ANY, "Input Dialog") {
    this->SetClientSize(200, 80);
    this->CenterOnParent();
  }
  
  wxString GetInputText() const {return this->text->GetValue();}
  virtual void SetInputText(const wxString& inputString) {this->text->SetValue(inputString);}

private:
  wxPanel* panel = new wxPanel(this, wxID_ANY);
  wxTextCtrl* text = new wxTextCtrl(this->panel, wxID_ANY, wxEmptyString, wxPoint(10, 10), wxSize(180, 25));
  wxButton* buttonOk = new wxButton(this->panel, wxID_OK, "OK", wxPoint(10, 50));
  wxButton* buttonCancel = new wxButton(this->panel, wxID_CANCEL, "Cancel", wxPoint(100, 50));
};

class Form1 : public wxFrame {
public:
  Form1() : wxFrame(nullptr, wxID_ANY, "User dialog example", wxDefaultPosition, wxSize(800, 450), wxDEFAULT_FRAME_STYLE) {
    this->Center();
    
    this->buttonDialog->Bind(wxEVT_BUTTON, [&](wxCommandEvent& e) {
      UserInputDialog dialog(this);
      dialog.SetInputText(this->inputText->GetLabel());
      if(dialog.ShowModal() == wxID_OK) this->inputText->SetLabel(dialog.GetInputText());
    });
  }
private:
  wxPanel* panel = new wxPanel(this, wxID_ANY);
  wxButton* buttonDialog = new wxButton(this->panel, wxID_ANY, "Dialog", wxPoint(10, 10));
  wxStaticText* inputText = new wxStaticText(this->panel, wxID_ANY, "User input text", wxPoint(10, 50));
};

class Application : public wxApp {
  bool OnInit() override {return (new Form1())->Show();}
};

wxIMPLEMENT_APP(Application);