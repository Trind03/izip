#include <archive_entry.h>
#include <IFile.h>
#include <ArchiveComputation.h>

archive_entry*
SoftArchive::RenderArchiveEntry(FileRep::IFile *File)
{
    archive_entry* p_archive_entry  = archive_entry_new();
    archive_entry_set_pathname(p_archive_entry,File->filename().c_str());

    return p_archive_entry;
}




