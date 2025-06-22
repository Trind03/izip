#include <spdlog/spdlog.h>
#include <archive.h>
#include <archive_entry.h>
#include <FileComputation.h>
#include <universal/exit_codes.hpp>
#include <macros/aliases.h>

using namespace Izip::Universal;

archive_entry*
Izip::Wrappers::CompFile::FileComputation::render_archive_entry()
{
    archive_entry* p_archive_entry;

    p_archive_entry = archive_entry_new();
    archive_entry_set_pathname(p_archive_entry,this->filename.c_str());

    return p_archive_entry;
}

int
Izip::Wrappers::CompFile::FileComputation::decompress_archive(std::string_view filename)
{
    std::array<char,1024> buffer;
    int status_code   = resolve(EXIT_CODE::SUCCESS);
    int ArchiveStatus = 0;
    int flags         = 0;

    flags  = ARCHIVE_EXTRACT_TIME;
    flags |= ARCHIVE_EXTRACT_ACL;
    flags |= ARCHIVE_EXTRACT_PERM;
    flags |= ARCHIVE_EXTRACT_FFLAGS;


    archive_entry* current_archive_entry;
    archive* processed_archive;
    archive* current_archive;

    spdlog::debug("Initializing handler");

    current_archive         = archive_read_new();
    processed_archive       = archive_write_disk_new();
    current_archive_entry   = render_archive_entry();

    spdlog::debug("Archive handlers initialized!");

    archive_read_support_format_all(current_archive);
    archive_read_support_filter_all(current_archive);

    archive_write_disk_set_options(processed_archive,flags);
    archive_write_disk_set_standard_lookup(processed_archive);


    if (archive_read_open_filename(current_archive, filename.data(), buffer.size()) == ARCHIVE_OK)
    {
        spdlog::info("File opened successfully!");
    }
    else
    {
        spdlog::error("File opening failure.");
    }

    spdlog::info("Processing supplied folder!");

    for(;;)
    {
        ArchiveStatus = archive_read_next_header(current_archive,&current_archive_entry);

        if (ArchiveStatus == ARCHIVE_EOF)
            break;

        pathname = archive_entry_pathname(current_archive_entry);
        unsigned short EntryType = archive_entry_filetype(current_archive_entry);

        if (EntryType == AE_IFDIR) {
            spdlog::info(fmt::format("Creating new directory: {}", pathname));
            mkdir(pathname.c_str(),UserPermissions);
        }
        archive_read_data(current_archive,buffer.data(),buffer.size());

        if ( ArchiveStatus == ARCHIVE_RETRY ) {
            spdlog::error("Unexpected error arrised from parsing header");
            return ArchiveStatus;
        }

        if ( ArchiveStatus == ARCHIVE_WARN ) {
            spdlog::warn("Unexpected warning arrised from parsing header");
            return ArchiveStatus;
        }


        archive_write_header(processed_archive,current_archive_entry);
        archive_write_data(processed_archive,buffer.data(),buffer.size());
    }

    archive_read_close(current_archive);
    archive_read_free(current_archive);
    archive_write_close(processed_archive);
    archive_write_free(processed_archive);

    return status_code;
}
