#pragma once
#include <archive.h>
#include <archive_entry.h>
#include <FileRep/IFile.h>


namespace SoftArchive
{
    [[nodiscard]] int Compress(FileRep::IFile *File);
    [[nodiscard]] int Decompress(FileRep::IFile *File);
    [[nodiscard]] archive_entry* RenderArchiveEntry(FileRep::IFile *File);
}