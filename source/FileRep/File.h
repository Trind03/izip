#pragma once
#include <../FileRep/IFile.h>
#include <cstdint>

namespace FileRep
{
    class File : public IFile
    {
    public:
        explicit File() = default;
        explicit File(std::string filename);
        ~File() override = default;
        std::vector<unsigned char> readFileContent()    override;
        uint32_t        filesize()     	                override;
        std::string     filename()     	                override;
        std::string     filenameOnly() 	                override;
        std::string     algorithm()     	            override;
    };
}
