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
            virtual archive* read_load_archive(const char* filename)            = 0;
            virtual int write_file_to_disk(struct archive* myarchive,struct archive_entry* entry)           = 0;
            virtual archive_entry* render_archive_entry()                       = 0;
            virtual  ~IFile()                                                   = default;
            virtual int get_exit_code()                                         = 0;
            std::unique_ptr<std::fstream> file_stream                           = nullptr;
            std::string filename;
        };
    }
}
