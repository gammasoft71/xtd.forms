#pragma once
#include <xtd/xtd.delegates>
#include <xtd/xtd.diagnostics>
#include <xtd/xtd.drawing>
#include <xtd/xtd.core>
#include <xtd/xtd.io>
#include <xtd/xtd.strings>
#include <xtd/forms/create_params.hpp>
#include <xtd/forms/window_messages.hpp>

#include "xtd/forms/layout/arranged_element_collection.hpp"
#include "xtd/forms/about_dialog.hpp"
#include "xtd/forms/anchor_styles.hpp"
#include "xtd/forms/appearance.hpp"
#include "xtd/forms/application.hpp"
#include "xtd/forms/application_context.hpp"
#include "xtd/forms/application_informations.hpp"
#include "xtd/forms/arrange_direction.hpp"
#include "xtd/forms/arrange_starting_position.hpp"
#include "xtd/forms/auto_size_mode.hpp"
#include "xtd/forms/background_worker.hpp"
#include "xtd/forms/boot_mode.hpp"
#include "xtd/forms/border_style.hpp"
#include "xtd/forms/bounds_specified.hpp"
#include "xtd/forms/button.hpp"
#include "xtd/forms/button_base.hpp"
#include "xtd/forms/buttons.hpp"
#include "xtd/forms/cancel_event_args.hpp"
#include "xtd/forms/cancel_event_handler.hpp"
#include "xtd/forms/check_box.hpp"
#include "xtd/forms/check_boxes.hpp"
#include "xtd/forms/check_state.hpp"
#include "xtd/forms/checked_list_box.hpp"
#include "xtd/forms/choice.hpp"
#include "xtd/forms/close_reason.hpp"
#include "xtd/forms/color_dialog.hpp"
#include "xtd/forms/color_picker.hpp"
#include "xtd/forms/combo_box.hpp"
#include "xtd/forms/combo_box_style.hpp"
#include "xtd/forms/common_dialog.hpp"
#include "xtd/forms/component.hpp"
#include "xtd/forms/container_control.hpp"
#include "xtd/forms/content_alignment.hpp"
#include "xtd/forms/control.hpp"
#include "xtd/forms/control_event_args.hpp"
#include "xtd/forms/control_event_handler.hpp"
#include "xtd/forms/countries.hpp"
#include "xtd/forms/country.hpp"
#include "xtd/forms/cursor.hpp"
#include "xtd/forms/cursors.hpp"
#include "xtd/forms/date_time_picker.hpp"
#include "xtd/forms/dialog_result.hpp"
#include "xtd/forms/do_work_event_args.hpp"
#include "xtd/forms/do_work_event_handler.hpp"
#include "xtd/forms/dock_style.hpp"
#include "xtd/forms/domain_up_down.hpp"
#include "xtd/forms/dot_matrix_display.hpp"
#include "xtd/forms/dot_matrix_style.hpp"
#include "xtd/forms/emoticon.hpp"
#include "xtd/forms/emoticons.hpp"
#include "xtd/forms/folder_browser_dialog.hpp"
#include "xtd/forms/font_dialog.hpp"
#include "xtd/forms/font_picker.hpp"
#include "xtd/forms/form.hpp"
#include "xtd/forms/form_border_style.hpp"
#include "xtd/forms/form_closed_event_args.hpp"
#include "xtd/forms/form_closed_event_handler.hpp"
#include "xtd/forms/form_closing_event_args.hpp"
#include "xtd/forms/form_closing_event_handler.hpp"
#include "xtd/forms/form_start_position.hpp"
#include "xtd/forms/form_window_state.hpp"
#include "xtd/forms/fourteen_segment_display.hpp"
#include "xtd/forms/group_box.hpp"
#include "xtd/forms/help_event_args.hpp"
#include "xtd/forms/help_event_handler.hpp"
#include "xtd/forms/ibutton_control.hpp"
#include "xtd/forms/image_list.hpp"
#include "xtd/forms/imessage_filter.hpp"
#include "xtd/forms/item_check_event_args.hpp"
#include "xtd/forms/item_check_event_handler.hpp"
#include "xtd/forms/iwin32_window.hpp"
#include "xtd/forms/key_event_args.hpp"
#include "xtd/forms/key_event_handler.hpp"
#include "xtd/forms/key_press_event_args.hpp"
#include "xtd/forms/key_press_event_handler.hpp"
#include "xtd/forms/keys.hpp"
#include "xtd/forms/label.hpp"
#include "xtd/forms/lcd_label.hpp"
#include "xtd/forms/list_box.hpp"
#include "xtd/forms/list_control.hpp"
#include "xtd/forms/main_menu.hpp"
#include "xtd/forms/menu.hpp"
#include "xtd/forms/menu_item.hpp"
#include "xtd/forms/message.hpp"
#include "xtd/forms/message_box.hpp"
#include "xtd/forms/message_box_buttons.hpp"
#include "xtd/forms/message_box_default_button.hpp"
#include "xtd/forms/message_box_icon.hpp"
#include "xtd/forms/message_box_options.hpp"
#include "xtd/forms/message_loop_callback.hpp"
#include "xtd/forms/mouse_buttons.hpp"
#include "xtd/forms/mouse_event_args.hpp"
#include "xtd/forms/mouse_event_handler.hpp"
#include "xtd/forms/nine_segment_display.hpp"
#include "xtd/forms/numeric_up_down.hpp"
#include "xtd/forms/open_file_dialog.hpp"
#include "xtd/forms/orientation.hpp"
#include "xtd/forms/paint_event_args.hpp"
#include "xtd/forms/paint_event_handler.hpp"
#include "xtd/forms/panel.hpp"
#include "xtd/forms/picture_box.hpp"
#include "xtd/forms/progress_bar.hpp"
#include "xtd/forms/progress_bar_style.hpp"
#include "xtd/forms/progress_changed_event_args.hpp"
#include "xtd/forms/progress_changed_event_handler.hpp"
#include "xtd/forms/radio_button.hpp"
#include "xtd/forms/radio_buttons.hpp"
#include "xtd/forms/run_worker_completed_event_args.hpp"
#include "xtd/forms/run_worker_completed_event_handler.hpp"
#include "xtd/forms/save_file_dialog.hpp"
#include "xtd/forms/screen.hpp"
#include "xtd/forms/scroll_bar.hpp"
#include "xtd/forms/scrollable_control.hpp"
#include "xtd/forms/selection_mode.hpp"
#include "xtd/forms/segment_style.hpp"
#include "xtd/forms/segments.hpp"
#include "xtd/forms/settings.hpp"
#include "xtd/forms/seven_segment_display.hpp"
#include "xtd/forms/shortcut.hpp"
#include "xtd/forms/sixteen_segment_display.hpp"
#include "xtd/forms/switch_button.hpp"
#include "xtd/forms/system_information.hpp"
#include "xtd/forms/tab_control.hpp"
#include "xtd/forms/tab_page.hpp"
#include "xtd/forms/text_box.hpp"
#include "xtd/forms/text_box_base.hpp"
#include "xtd/forms/texts.hpp"
#include "xtd/forms/tick_style.hpp"
#include "xtd/forms/timer.hpp"
#include "xtd/forms/track_bar.hpp"
#include "xtd/forms/up_down_base.hpp"
#include "xtd/forms/up_down_button.hpp"
#include "xtd/forms/user_control.hpp"
