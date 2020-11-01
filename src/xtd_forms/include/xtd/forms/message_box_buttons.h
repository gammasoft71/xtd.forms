#pragma once
#include <xtd/forms/message_dialog_buttons.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies constants defining which buttons to display on a message_box.
    /// @remarks This enumeration is used by the message_box class.
    using message_box_buttons = message_dialog_buttons;
  }
}
