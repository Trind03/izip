#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <comp_file/FileIfc.h>
#include <archive.h>

namespace CompFile
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

        [[nodiscard]] archive_entry* render_archive_entry() const;

        [[nodiscard]] int InteroptHandler(std::string_view msg,std::string_view dir);

        [[nodiscard]] int compress(CompFile::FileIfc& File,std::string_view algorithm);
        std::vector<char> readFileContent(CompFile::FileIfc& File);
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

