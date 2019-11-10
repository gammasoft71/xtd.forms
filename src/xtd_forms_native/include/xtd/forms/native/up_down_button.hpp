#pragma once
#include "../create_params.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class up_down_button {
      public:
        up_down_button() = delete;
        static void maximum(intptr_t control, int32_t maximum);
        static void minimum(intptr_t control, int32_t minimum);
        static int32_t value(intptr_t control);
        static void value(intptr_t control, int32_t value);
      };
    }
  }
}