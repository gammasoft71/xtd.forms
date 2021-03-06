#pragma once
#include <stdexcept>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/create_params.h>
#include <wx/fontpicker.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_font_picker : public control_handler {
      public:
        wx_font_picker(const xtd::forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          this->control_handler::create<wxFontPickerCtrl>(reinterpret_cast<control_handler*>(create_params.parent())->main_control(), wxID_ANY, wxFont(), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()));
#if defined(__WIN32__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::button_face().r(), xtd::drawing::system_colors::button_face().g(), xtd::drawing::system_colors::button_face().b(), xtd::drawing::system_colors::button_face().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
#endif
        }
        
        void SetBackgroundColour(const wxColour &colour) override {
          control_handler::SetBackgroundColour(colour);
          static_cast<wxFontPickerCtrl*>(control())->GetPickerCtrl()->SetBackgroundColour(colour);
        }

        virtual void SetPosition(const wxPoint& pt) override {
          control_handler::SetPosition(pt);
        }

        wxSize GetClientSize() const override {
          return control()->GetSize();
        }
        
        void SetClientSize(int32_t width, int32_t height) override {
          SetSize(width, height);
        }
      };
    }
  }
}
