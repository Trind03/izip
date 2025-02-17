#include <spdlog/spdlog.h>
#include <archive.h>
#include <memory>
#include "File.h"
#include <string>
#include "exit_codes.hpp"

namespace wrappers
{
    namespace file
    {
        File::File(std::string filename) : file_suport({"tar","zip"})
        {
            file_stream = std::make_unique<std::fstream>(filename);
        }
        std::string File::filetype(std::string filename)
        {
            return "";
        }
        int File::get_exit_code()
        {
            return EXIT_CODE::SUCCESS;
        }

        int File::extract_tarball(std::string filename,std::string output_dir)
        {
            struct archive_entry* entry;
            struct archive* input_file;
            struct archive* output_file;
            input_file = archive_read_new();

            archive_read_support_filter_all(input_file);
            archive_read_support_format_all(input_file);

            if ((archive_read_open_filename(input_file,filename.c_str(),1240)))
            {
                spdlog::error("Error occured during extraction, did u effect the file?");
                return EXIT_CODE::FAILURE;
            }

            return EXIT_CODE::SUCCESS;
        }

        int File::read_file()
        {
            return EXIT_CODE::SUCCESS;
        }
    }
}
