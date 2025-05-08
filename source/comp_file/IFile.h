#pragma once
#include <memory>
#include <archive.h>

namespace wrappers
{
    namespace file
    {
        class IFile
        {
        public:
            virtual int decompress_archive(const char* filename)            = 0;
            virtual int recursive_decompression(struct archive *Archive, struct archive_entry *Archive_entry, const char* prefix) = 0;
            virtual archive_entry* render_archive_entry()                       = 0;
            virtual  ~IFile()                                                   = default;
            virtual int get_exit_code()                                         = 0;
            std::unique_ptr<std::fstream> file_stream                           = nullptr;
            std::string filename;
        };
    }
}
