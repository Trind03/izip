#include <App.h>
#include <Help.h>
#include <spdlog/spdlog.h>
#include <ArchiveComputation.h>
#include <archive.h>
#include <File.h>
#include <macros/aliases.h>
#include <universal/exit_codes.hpp>
#include <IFile.h>


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
        for (CompFile::File File : DecompressTargets)
        {
            if (Computation.DecompressArchive(&File) != resolve(Universal::EXIT_CODE::SUCCESS))
            {
                spdlog::error("Failed to decompress archive {}", File.filename());
                return resolve(Universal::EXIT_CODE::ALGORITHMIC_FAILURE);
            }
        }
    }
    else if (!(CompressTargets.empty()))
    {
        for (CompFile::File File : CompressTargets)
        {
            if (Computation.Compress(File) != resolve(Universal::EXIT_CODE::SUCCESS))
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