#include <string>
#include <vector>
#include <fstream>
#include <archive.h>
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
            File();
            int decompress_archive(const char* filename) override;
            archive_entry* render_archive_entry() override;

            int copy_data(struct archive* arcive,struct archive* archivew);
            int get_exit_code() override;
            ~File() override = default;

            std::unique_ptr<std::fstream> file_stream = nullptr;
            std::string filename = "";
            std::vector<char> m_data;
            int exit_code;
        };
    }
}
