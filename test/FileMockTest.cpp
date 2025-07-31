//
// Created by Torstein on 27/07/2025.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include <comp_file/File.h>
#include <string>
#include <comp_file/IFile.h>
#include <comp_file/ArchiveComputation.h>
#include <macros/aliases.h>
#include "universal/exit_codes.hpp"
#include "universal/Spesifier.hpp"

namespace
{
    class FileMock : public CompFile::File
    {
    public:
        explicit FileMock(std::string fileName)
        {
            this->_filename = std::move(fileName);
            this->_filesize = 15;
        }
        MOCK_METHOD(uint32_t,           filesize,(),         (override));
        MOCK_METHOD(std::string,        filename,(),         (override));
        MOCK_METHOD(std::string,        filenameOnly,(),     (override));
        MOCK_METHOD(std::vector<unsigned char>,  readFileContent,(),  (override));


        FileMock& operator=(FileMock&)  = delete;
        FileMock& operator=(FileMock&&) = delete;
        FileMock(FileMock&)             = delete;
        FileMock(FileMock&&)            = delete;
    };

    class Context : public ::testing::Test
    {
    public:
       void SetUp() override {
           fileMock = std::make_unique<FileMock>("junk.tar");
       }

        void TearDown() override {

       }
        std::unique_ptr<CompFile::IFile> fileMock = nullptr;
    };
}

TEST_F(Context, DISABLED_FileInit)
{
    int status = 0;
    std::string filename = "archive_test.tar";
    std::string filenamewtext = "archive_test";

    CompFile::ArchiveComputation ArchiveComputation = CompFile::ArchiveComputation::getInstance();
    FileMock file(filename);

    EXPECT_CALL(file, filename).Times(2)
        .WillOnce(testing::Return("junk.tar"));

    EXPECT_CALL(file, filenameOnly).Times(0).WillOnce(   testing::Return(filenamewtext));
    EXPECT_CALL(file, readFileContent).Times(2);

    status = ArchiveComputation.DecompressArchive(&file);

    EXPECT_EQ(status, resolve(Universal::EXIT_CODE::SUCCESS));

}
