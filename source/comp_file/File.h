#pragma once
#include <Fileifc.h>

namespace Izip::compfile
{
    class File final : public Fileifc
    {
    public:
        explicit File(std::string filename);
        unsigned int    filesize()     override;
        std::string     filename()     override;
        std::string     filenameOnly() override;
    };
}