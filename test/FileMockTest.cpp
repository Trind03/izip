#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include <comp_file/File.h>
#include <string>
#include <comp_file/FileIfc.h>
#include <comp_file/File.h>
//
// Created by Torstein on 27/07/2025.
//


class FileMock final : public CompFile::FileIfc
{
    public:
        explicit FileMock(std::string fileName)
        {
            this->_filename = fileName;
            this->_filesize = 4;
        }
        MOCK_METHOD(uint32_t,filesize,(),(override));
        MOCK_METHOD(std::string,filename,(),(override));
        MOCK_METHOD(std::string, filenameOnly,(),(override));

        FileMock& operator=(FileMock&)  = delete;
        FileMock& operator=(FileMock&&) = delete;
        FileMock(FileMock&)             = delete;
        FileMock(FileMock&&)            = delete;
};

class Context : public ::testing::Test
{
    public:
    void SetUp() override
    {
        _file = std::make_unique<CompFile::File>(TEST_TARGET_FILE);
    }

    void TearDown() override
    {
        _file = nullptr;
    }
    protected:
        std::unique_ptr<CompFile::FileIfc> _file;
};

TEST_F(Context, FileInit)
{
    //EXPECT_CALL(*_file,filenameOnly());
    EXPECT_EQ(_file->filename(), TEST_TARGET_FILE);
}
