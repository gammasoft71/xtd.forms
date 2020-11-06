#include <filesystem>
#include <xtd/xtd.forms>

using namespace std::filesystem;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Hello world (say)");
    
    button1.location({10, 10});
    button1.parent(*this);
    button1.text("Say...");
    button1.click += [&] {
      process::start(process_start_info().file_name(io::path::combine(io::path::get_temp_path(), "say.cmd")).arguments("\"Hello world\"").window_style(process_window_style::hidden)).wait_for_exit();
    };
  }
  
private:
  button button1;
};

int main() {
  std::vector<std::string> lines;
  if (environment::os_version().is_windows_platform()) lines = {
    "@echo off",
    "echo Dim Speak >> %TEMP%\\speak.vbs",
    "echo Set Speak=CreateObject(\"sapi.spvoice\") >> %TEMP%\\speak.vbs",
    "echo Speak.Speak %* >> %TEMP%\\speak.vbs",
    "%TEMP%\\speak.vbs",
    "del %TEMP%\\speak.vbs"
  };
  else if (environment::os_version().is_linux_platform()) lines = {
    "#!/bin/bash",
    "spd-say \"$*\""
  };
  else if (environment::os_version().is_macos_platform()) lines = {
    "#!/bin/bash",
    "say \"$*\""
  };
  file::write_all_lines(io::path::combine(io::path::get_temp_path(), "say.cmd"), lines);
  permissions(io::path::combine(io::path::get_temp_path(), "say.cmd"), perms::owner_all);
  
  application::run(form1());

  file::remove(io::path::combine(io::path::get_temp_path(), "say.cmd"));
}
