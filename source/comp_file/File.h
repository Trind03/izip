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
            archive* read_load_archive(const char* filename) override;
            archive_entry* render_archive_entry() override;
            int write_file_to_disk(struct archive* myarchive,struct archive_entry* entry) override;
            int get_exit_code() override;
            ~File() override = default;

            std::unique_ptr<std::fstream> file_stream = nullptr;
            std::string filename = "";
            std::vector<char> m_data;
            int exit_code;
        };
    }
}
