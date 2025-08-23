#include <App.h>
#include <Help.h>
#include <spdlog/spdlog.h>
#include <softarchive/ArchiveComputation.h>
#include <archive.h>
#include <FileRep/File.h>
#include <macros/aliases.h>
#include <universal/exit_codes.hpp>
#include <FileRep/IFile.h>


int App::Start(const int argc, char **argv) const
{
    CLI11_PARSE(*Arg_parser, argc, Arg_parser->ensure_utf8(argv));
    // TODO Refactor this later to support multi threading depending on the workload.
    // if (!(DecompressTargets.empty() && !(CompressTargets.empty()))) {
    //     spdlog::warn("Both compression settings cant be used at the same time, sry.");
    //     return resolve(Universal::EXIT_CODE::INVALID_ARG);
    // }
    if (!(DecompressTargets.empty()))
    {
        for (FileRep::File File : DecompressTargets)
        {
            if (SoftArchive::Decompress(&File) != resolve(Universal::EXIT_CODE::SUCCESS))
            {
                spdlog::error("Failed to decompress archive {}", File.filename());
                return resolve(Universal::EXIT_CODE::ALGORITHMIC_FAILURE);
            }
        }
    }
    else if (!(CompressTargets.empty()))
    {
        for (FileRep::File File : CompressTargets)
        {
            if (SoftArchive::Compress(&File) != resolve(Universal::EXIT_CODE::SUCCESS))
            {
                spdlog::error("Failed to compress archive {}", File.filename());
                return resolve(Universal::EXIT_CODE::ALGORITHMIC_FAILURE);
            }
        }
    }

    else
    {
        spdlog::warn("No valid arguments passed");
        return resolve(Universal::EXIT_CODE::INVALID_ARG);
    }
    return resolve(Universal::EXIT_CODE::SUCCESS);
}

int App::GetExitCode() const
{
    return exit_code;
}