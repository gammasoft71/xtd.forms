#include <stdexcept>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/text_box.hpp>
#include "control_handler.hpp"
#include <wx/textctrl.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  class wx_text_box : public control_handler {
  public:
    wx_text_box(wxWindow *parent, wxWindowID id, const wxString& value, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize) {
      this->control_handler::create<wxTextCtrl>(parent, id, value, pos, size);
    }
  };
}

intptr_t text_box::create(intptr_t parent, const drawing::size& size) {
  if (parent == 0) throw invalid_argument("parent can't be null");
  return (intptr_t) new wx_text_box(reinterpret_cast<control_handler*>(parent)->control(), wxID_ANY, wxEmptyString, wxDefaultPosition, {size.width(), size.height()});
}

color text_box::default_back_color() {
  static color default_color;
  if (default_color == color::empty) {
    native::application::initialize_application();
    wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "");
    wxTextCtrl* text_box = new wxTextCtrl(frame, wxID_ANY, "");
    wxColour colour = text_box->GetBackgroundColour();
#if defined (__APPLE__)
    default_color = color::from_handle(reinterpret_cast<intptr_t>(colour.OSXGetNSColor()));
#else
    default_color = color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
#endif
    delete text_box;
    delete frame;
  }
  return default_color;
}

color text_box::default_fore_color() {
  static color default_color;
  if (default_color == color::empty) {
    native::application::initialize_application();
    wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "");
    wxTextCtrl* text_box = new wxTextCtrl(frame, wxID_ANY, "");
    wxColour colour = text_box->GetForegroundColour();
#if defined (__APPLE__)
    default_color = color::from_handle(reinterpret_cast<intptr_t>(colour.OSXGetNSColor()));
#else
    default_color = color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
#endif
    delete text_box;
    delete frame;
  }
  return default_color;
}

string text_box::text(intptr_t control) {
  if (control == 0) return {};
  return static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetValue().ToStdString();
}

void text_box::text(intptr_t control, const string& text) {
  if (control == 0) return;
  static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(text);
  //send_message(control, control, WM_SETTEXT, 0, reinterpret_cast<intptr_t>(reinterpret_cast<control_handler*>(control)->control()->GetLabel().ToStdString().c_str()));
}
