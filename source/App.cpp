#include <App.h>
#include <Help.h>
#include <spdlog/spdlog.h>
#include <fmt/os.h>
#include <FileComputation.h>
#include "File.h"

int App::start(int argc, char **argv)
  {
  CLI11_PARSE(*Arg_parser, argc, Arg_parser->ensure_utf8(argv));
  CompFile::File File(this->fileComputation.filename);
    this->exit_code = this->fileComputation.compress(File,"");


  return exit_code;
}

int App::get_exit_code() const { return exit_code; }
/*
if (!(File.filename.empty())) {
  spdlog::info(fmt::format("detected file: {}", File.filename));
  File.decompress_archive(File.filename);
}*/
