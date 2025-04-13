#include <string>
#include <vector>
#include <fstream>
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
            void read_file() override;
            std::string filetype() override;
            int get_exit_code() override;
            ~File() override = default;
            std::unique_ptr<std::fstream> file_stream = nullptr;
            std::string filename = "";
            std::vector<char> m_data();
            std::ifstream::pos_type get_filesize(const char* filename) override;
        };
    }
}
