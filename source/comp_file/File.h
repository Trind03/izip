#include <string>
#include <vector>
#include "IFile.h"
#define FILESUPPORT_SIZE 2
const int BLOCK_SIZE = 32;


namespace wrappers
{
    namespace file
    {
        class File : public wrappers::file::IFile
        {
        public:
            File(std::string filename);
            int extract_tarball(std::string filename,std::string output_dir) override;
            int read_file() override;
            std::string filetype() override;
            int get_exit_code() override;
            ~File() override = default;
            std::unique_ptr<std::fstream> file_stream = nullptr;
            std::string filename = "";
            std::vector<char> m_data();
        };

        enum file_support_index
        {
            TARBALL,
            ZIP
        };
    }
}
