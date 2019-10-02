#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("User control example");

      user_control1.parent(*this);
      user_control1.cursor(cursors::hand());
      user_control1.back_color(color::light_blue);
      user_control1.location({50, 50});
      user_control1.double_click += [this](const control& sender, const event_args& e) {
        user_control1.back_color(user_control1.back_color() == color::light_blue ? color::light_pink : color::light_blue);
      };
    }
    
  private:
    user_control user_control1;
  };
}

int main() {
  application::run(examples::form1());
}