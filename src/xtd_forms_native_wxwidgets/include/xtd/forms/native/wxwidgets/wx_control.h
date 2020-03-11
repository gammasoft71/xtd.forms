#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.h>
#include <wx/panel.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_control : public control_handler {
      public:
        wx_control(const forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          this->create<wxPanel>(((control_handler*)create_params.parent())->container(), wxID_ANY, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), style_to_wx_style(create_params.style(), create_params.ex_style()));
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          return 0;
        }
      };
    }
  }
}