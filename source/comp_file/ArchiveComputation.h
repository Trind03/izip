#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <IFile.h>
#include <archive_entry.h>
#include <File.h>

namespace CompFile
{
    struct ArchiveComputation
    {
        [[nodiscard]]
        static ArchiveComputation& getInstance()
        {
            static ArchiveComputation instance;
            return instance;
        }

        [[nodiscard]] int DecompressArchive(IFile *File) const;

        [[nodiscard]] archive_entry* RenderArchiveEntry(IFile *File) const;

        [[nodiscard]] int InteroptHandler(std::string_view msg,std::string_view dir);

        [[nodiscard]] int Compress(IFile& File);
        [[nodiscard]] int get_exit_code() const;

        std::string filename;
        std::string pathname;
        bool recursive  = false;
        mode_t UserPermissions = 0;
        int exit_code;
    private:
        ArchiveComputation();
    };
}

