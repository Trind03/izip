#include <array>
#include <string>
#include "IFile.h"
#define FILESUPPORT_SIZE 2

namespace wrappers
{
    namespace file
    {
        class File : public wrappers::file::IFile
        {
        public:
            File(std::string filename);
            int read_file() override;
            int extract_tarball(std::string filename, std::string output_dir) override;
            std::string filetype(std::string filename) override;
            int get_exit_code() override;
            ~File() override = default;
            std::unique_ptr<std::fstream> file_stream = nullptr;
            std::array<const char*, FILESUPPORT_SIZE> file_suport;

            enum file_support_index
            {
                TARBALL,
                ZIP
            };
        };
    }
}
