//
// Created by Torstein on 15/06/2025.
//

#include <archive.h>
#include <fstream>
#include <archive_entry.h>
#include <FileComputation.h>
#include <universal/exit_codes.hpp>
#include <FileIfc.h>
#include <vector>
#include <spdlog/spdlog.h>
#include <CLI/Validators.hpp>

namespace CompFile {
    [[nodiscard]]
    int FileComputation::compress(FileIfc& File,std::string_view algorithm)
    {
        spdlog::info(fmt::format("Compressing file {}",File.filename()));
        std::string filename                 = File.filenameOnly();
        mode_t permission                    = S_IRUSR | S_IWUSR;
        int exit_code                        = static_cast<int>(Universal::EXIT_CODE::SUCCESS);
        archive* currentArchive              = archive_write_new();
        archive_entry* current_archive_entry = archive_entry_new();

        // Initialize archive
        archive_write_set_format_pax_restricted(currentArchive);


        // Initialize algorithm
        switch (algorithm.length())
        {
            case 4:
                filename = fmt::format("{}.tar.xz",filename);
                archive_write_open_filename(currentArchive,filename.c_str());
                break;

            default:
                filename = fmt::format("{}.tar.xz",filename);
                if (filename != "0")
                {
                    exit_code = archive_write_open_filename(currentArchive,filename.c_str());
                    break;
                }
                spdlog::error("Result from removing extention failed.");
                std::terminate();
        }


        // Initializing entry
        archive_entry_set_pathname(current_archive_entry,
            fmt::format("{}.tar.xz",filename).c_str());

        archive_entry_set_pathname(current_archive_entry,filename.c_str());
        archive_entry_set_size(current_archive_entry,File.filesize());
        archive_entry_set_filetype(current_archive_entry, AE_IFREG);
        archive_entry_set_perm(current_archive_entry, permission);

        if (exit_code != static_cast<int>(Universal::EXIT_CODE::SUCCESS))
            spdlog::error("Entry init failure!");

        exit_code = archive_write_header(currentArchive,current_archive_entry);
        archive_write_data(currentArchive,algorithm.data(),File.filesize());

        if (exit_code != static_cast<int>(Universal::EXIT_CODE::SUCCESS))
            spdlog::error(
                fmt::format("Something sus happened, exit code: {}",exit_code));

        archive_entry_free(current_archive_entry);
        archive_write_free(currentArchive);
        spdlog::info(fmt::format("Compressed file: {}. Freeing resources.",filename));
        return 0;
    }
}