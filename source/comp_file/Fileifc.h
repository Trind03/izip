#pragma once
#include <string>

namespace Izip::compfile
{
    class Fileifc
    {
        public:
        Fileifc()          = default;
        virtual ~Fileifc() = default;

        virtual unsigned int filesize()         = 0;
        virtual std::string filename()     = 0;
        virtual std::string filenameOnly() = 0;

    protected:
        std::string _filename;
        unsigned int _filesize = 0;
    };
}
