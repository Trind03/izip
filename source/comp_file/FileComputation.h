#pragma once
#include <string>
#include <archive.h>
#include <fstream>
#include <Fileifc.h>

namespace Izip::Wrappers::CompFile
{
    struct FileComputation
    {
        [[nodiscard]]
        static FileComputation& getInstance()
        {
            static FileComputation instance;
            return instance;
        }

        [[nodiscard]] int decompress_archive(std::string_view filename);

        [[nodiscard]] archive_entry* render_archive_entry();

        [[nodiscard]] int InteroptHandler(std::string_view msg,std::string_view dir);

        [[nodiscard]] int compress(compfile::Fileifc& File,std::string_view algorithm);
        std::vector<char> readFileContent(compfile::Fileifc& File);
        [[nodiscard]] int get_exit_code() const;

        std::string filename;
        std::string pathname;
        bool recursive  = false;
        mode_t UserPermissions = 0;
        int exit_code;
    private:
        FileComputation();
    };
}

