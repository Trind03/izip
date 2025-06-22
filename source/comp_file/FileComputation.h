#pragma once
#include <string>
#include <archive.h>


namespace Izip::Wrappers::CompFile
{
    struct FileComputation
    {
        static FileComputation& getInstance()
        {
            static FileComputation instance;
            return instance;
        }

        int
        decompress_archive(std::string_view filename);

        archive_entry*
        render_archive_entry();

        int
        InteroptHandler(std::string_view msg,std::string_view dir);


        int
        FileCompress(std::string_view filename,mode_t FilePermissions);

        int
        get_exit_code()const;

        std::string filename;
        std::string pathname;
        bool recursive         { false };
        mode_t UserPermissions {   0   };
        int exit_code;
    private:
        FileComputation();
    };
}

