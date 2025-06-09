#pragma once
#include <archive.h>

namespace wrappers::file
{
    class IFile
    {
    public:
        virtual int
        decompress_archive(std::string_view filename) = 0;
        virtual int
        recursive_decompression(std::string_view filename) = 0;
        virtual archive_entry*

        render_archive_entry() = 0;
        virtual ~IFile() = default;
        virtual int
        get_exit_code() = 0;
        std::string filename;
        bool recursive {false};
    };
}
