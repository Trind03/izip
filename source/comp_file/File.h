#pragma once
#include <FileIfc.h>
#include <cstdint>

namespace CompFile
{
    class File : public FileIfc
    {
    public:
        explicit File() = default;
        explicit File(std::string filename);
        ~File() override = default;
        std::vector<char> readFileContent() override;
        uint32_t        filesize()     	    override;
        std::string     filename()     	    override;
        std::string     filenameOnly() 	    override;
    };
}
