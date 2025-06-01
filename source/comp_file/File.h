#include <string>
#include <vector>
#include <fstream>
#include <archive.h>
#include "IFile.h"


namespace wrappers
{
    namespace file
    {
        class File final : public wrappers::file::IFile
        {
        public:
            File();
            int
            decompress_archive(std::string_view filename) override;
            archive_entry*
            render_archive_entry() override;

            int
            recursive_decompression(std::string_view filename) override;

            // mode_t get_archive_type(std::string_view filename) override;

            int
            copy_data(struct archive* arcive,struct archive* archivew);

            //int is_valid(struct archive *MyArchive) override;

            int
            get_exit_code() override;
            ~File() override = default;

            std::string filename = "";
            std::string pathname = "";
            mode_t archive_type;
            int exit_code;
        };
    }
}
