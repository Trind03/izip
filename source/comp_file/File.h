#pragma once
#include <string>
#include <fstream>
#include <archive.h>
#include "IFile.h"


namespace Izip::Wrappers::CompFile
{
    class File final : public Izip::Wrappers::CompFile::IFile
    {
    public:
        File();
        int
        decompress_archive(std::string_view filename) override;
        archive_entry*
        render_archive_entry() override;

        int
        recursive_decompression(std::string_view filename) override;

        int
        InteroptHandler(std::string_view msg,std::string_view dir) override;

        int
        copy_data(struct archive* arcive,struct archive* archivew);

        int
        get_exit_code() override;
        ~File() override = default;

        std::string filename = "";
        std::string pathname = "";
        mode_t archive_type;
        int exit_code;
    };
}
