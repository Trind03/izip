#pragma once
#include <string>
#include <fstream>
#include <archive.h>


namespace Izip::Wrappers::CompFile
{
    class File
    {
    public:
        static File& getInstance() {
            static File file;
            return file;
        }
        int
        decompress_archive(std::string_view filename);
        archive_entry*
        render_archive_entry();

        int
        recursive_decompression(std::string_view filename);

        int
        InteroptHandler(std::string_view msg,std::string_view dir);

        int
        copy_data(struct archive* arcive,struct archive* archivew);

        int
        FileCompress(std::string_view filename,mode_t FilePermissions);

        int
        get_exit_code();
        ~File() = default;

        std::string filename = "";
        std::string pathname = "";
        mode_t archive_type;
        bool recursive         { false };
        mode_t UserPermissions {   0   };
        private:
        int exit_code;
        File();
    };
}
