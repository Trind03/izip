#include <string>
#include <vector>
#include <fstream>
#include <archive.h>
#include "IFile.h"


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

            int
            recursive_decompression(struct archive *Archive, struct archive_entry *Archive_entry, const char* prefix) override;

            int copy_data(struct archive* arcive,struct archive* archivew);
            int get_exit_code() override;
            ~File() override = default;

            std::string filename = "";
            std::string pathname = "";
            mode_t  archive_type;
            int exit_code;
        };
    }
}
