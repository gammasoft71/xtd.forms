#pragma once
#include <functional>
#include <map>
#include <memory>
#include <string>
#include <xtd/drawing/color.hpp>
#include <xtd/drawing/point.hpp>
#include <xtd/drawing/size.hpp>

#include "key_event_handler.hpp"
#include "key_press_event_handler.hpp"
#include "mouse_event_handler.hpp"
#include "message.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class control {
    private:
      enum class state {
        empty = 0,
        double_click_fired = 0b1,
        mouse_entered = 0x10,
      };
      
    public:
      static const control null;
      
      control() = default;
      
      /// @cond
      control(const control&) = delete;
      /// @endcond
      
      virtual ~control();

      virtual drawing::color back_color() const {return this->back_color_;}
      virtual void back_color(const drawing::color& color);

      virtual drawing::size client_size() const {return this->client_size_;}
      virtual void client_size(const drawing::size& size);

      virtual drawing::size default_size() const {return{0, 0};}
      
      virtual bool enabled() const {return this->enabled_;}
      virtual void enabled(bool enabled);

      virtual drawing::color fore_color() const {return this->fore_color_;}
      virtual void fore_color(const drawing::color& color);
      
      virtual intptr_t handle() const;
      
      virtual int height() const {return this->size_.height();}
      virtual void height(int height) {this->size({this->size_.width(), height});}
      
      virtual drawing::point location() const {return this->location_;}
      virtual void location(const drawing::point& location);

      virtual const std::string& name() const {return this->name_;}
      virtual void name(const std::string& name) {this->name_ = name;}
      
      virtual control& parent() const {return *this->parent_;}
      virtual void parent(const control& parent);

      virtual drawing::size size() const {return this->size_;}
      virtual void size(const drawing::size& size);
      
      virtual const std::string& text() const {return this->text_;}
      virtual void text(const std::string& text);
      
      virtual bool visible() const {return this->visible_;}
      virtual void visible(bool visible);

      virtual int width() const {return this->size_.width();}
      virtual void width(int width) {this->size({width, this->size_.height()});}
      
      virtual int x() const {return this->location_.x();}
      virtual void x(int x) {this->size({x, this->location_.y()});}
      
      virtual int y() const {return this->location_.y();}
      virtual void y(int y) {this->size({this->location_.x(), y});}

      template<typename control_t>
      static std::unique_ptr<control_t> create(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}) {
        std::unique_ptr<control_t> item = std::make_unique<control_t>();
        item->location(location);
        item->size(size);
        return item;
      }

      template<typename control_t>
      static std::unique_ptr<control_t> create(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}) {
        std::unique_ptr<control_t> item = std::make_unique<control_t>();
        item->parent(parent);
        item->location(location);
        item->size(size);
        return item;
      }

      template<typename control_t>
      static std::unique_ptr<control_t> create(const std::string& text, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}) {
        std::unique_ptr<control_t> item = std::make_unique<control_t>();
        item->text(text);
        item->location(location);
        item->size(size);
        return item;
      }

      template<typename control_t>
      static std::unique_ptr<control_t> create(const control& parent, const std::string& text, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}) {
        std::unique_ptr<control_t> item = std::make_unique<control_t>();
        item->parent(parent);
        item->text(text);
        item->location(location);
        item->size(size);
        return item;
      }

      void create_control();
      
      virtual void hide() {this->visible(false);}

      virtual void create_handle();
      
      virtual void destroy_handle();
      
      static control& from_child_handle(intptr_t handle);

      static control& from_handle(intptr_t handle);
      
      bool is_null() const;
      
      virtual void on_back_color_changed(const event_args& e);

      virtual void on_click(const event_args& e);

      virtual void on_client_size_changed(const event_args& e);

      virtual void on_create_control();
      
      virtual void on_double_click(const event_args& e);
      
      virtual void on_enabled_changed(const event_args& e);

      virtual void on_fore_color_changed(const event_args& e);
      
      virtual void on_got_focus(const event_args& e);
      
      virtual void on_handle_created(const event_args& e);
      
      virtual void on_handle_destroyed(const event_args& e);

      virtual void on_key_down(key_event_args& e);
      
      virtual void on_key_press(key_press_event_args& e);
      
      virtual void on_key_up(key_event_args& e);
      
      virtual void on_location_changed(const event_args& e);
      
      virtual void on_lost_focus(const event_args& e);
      
      virtual void on_mouse_click(const mouse_event_args& e);
      
      virtual void on_mouse_double_click(const mouse_event_args& e);

      virtual void on_mouse_down(const mouse_event_args& e);

      virtual void on_mouse_enter(const event_args& e);
      
      virtual void on_mouse_horizontal_wheel(const mouse_event_args& e);
      
      virtual void on_mouse_leave(const event_args& e);
      
      virtual void on_mouse_move(const mouse_event_args& e);

      virtual void on_mouse_up(const mouse_event_args& e);

      virtual void on_mouse_wheel(const mouse_event_args& e);
      
      virtual void on_parent_changed(const event_args& e);
 
      virtual void on_size_changed(const event_args& e);

      virtual void on_text_changed(const event_args& e);
      
      virtual void on_visible_changed(const event_args& e);
      
      intptr_t send_message(intptr_t hwnd, int msg, intptr_t wparam, intptr_t lparam);
      
      virtual void show() {this->visible(true);}
      
      virtual void wnd_proc(message& message);
      
      event<control, event_handler<control>> back_color_changed;
      
      event<control, event_handler<control>> click;
      
      event<control, event_handler<control>> client_size_changed;
      
      event<control, event_handler<control>> double_click;

      event<control, event_handler<control>> got_focus;
      
      event<control, event_handler<control>> handle_created;
      
      event<control, event_handler<control>> handle_destroyed;
      
      event<control, event_handler<control>> enabled_changed;

      event<control, event_handler<control>> fore_color_changed;
      
      event<control, key_event_handler<control>> key_down;
      
      event<control, key_press_event_handler<control>> key_press;
      
      event<control, key_event_handler<control>> key_up;
      
      event<control, event_handler<control>> location_changed;
      
      event<control, event_handler<control>> lost_focus;
      
      event<control, mouse_event_handler<control>> mouse_click;
      
      event<control, mouse_event_handler<control>> mouse_double_click;
      
      event<control, mouse_event_handler<control>> mouse_down;
      
      event<control, event_handler<control>> mouse_enter;
      
      event<control, mouse_event_handler<control>> mouse_horizontal_wheel;
      
      event<control, event_handler<control>> mouse_leave;
      
      event<control, mouse_event_handler<control>> mouse_move;
      
      event<control, mouse_event_handler<control>> mouse_up;
      
      event<control, mouse_event_handler<control>> mouse_wheel;
      
      event<control, event_handler<control>> parent_changed;
      
      event<control, event_handler<control>> size_changed;
      
      event<control, event_handler<control>> text_changed;
      
      event<control, event_handler<control>> visible_changed;

      intptr_t __get_handle__() const {return this->handle_;}
      
    protected:
      virtual void def_wnd_proc(message& message);
      
      void get_properties();
      void set_properties();
      drawing::color back_color_;
      drawing::size client_size_ {-1, -1};
      bool enabled_ = true;
      drawing::color fore_color_;
      intptr_t handle_ = 0;
      static std::map<intptr_t, control*> handles_;
      std::string name_;
      drawing::point location_ {0, 0};
      control* parent_ = const_cast<control*>(&control::null);
      drawing::size size_ {-1, -1};
      std::string text_;
      bool visible_ = true;
      control::state state_ = state::empty;
      
    private:
      bool get_state(control::state flag) const {return ((int)this->state_ & (int)flag) == (int)flag;}
      void set_state(control::state flag, bool value) { this->state_ = value ? (control::state)((int)this->state_ | (int)flag) : (control::state)((int)this->state_ & ~(int)flag); }
      intptr_t wnd_proc_(intptr_t hwnd, int msg, intptr_t wparam, intptr_t lparam, intptr_t handle);      
      void wm_child_activate(message& message);
      void wm_command(message& message);
      void wm_key_char(message& message);
      void wm_kill_focus(message& message);
      void wm_mouse_down(message& message);
      void wm_mouse_double_click(message& message);
      void wm_mouse_enter(message& message);
      void wm_mouse_leave(message& message);
      void wm_mouse_up(message& message);
      void wm_mouse_move(message& message);
      void wm_move(message& message);
      void wm_set_focus(message& message);
      void wm_mouse_wheel(message& message);
      void wm_set_text(message& message);
      void wm_size(message& message);
    };
    
    using ref_control = std::reference_wrapper<control>;
  }
}
