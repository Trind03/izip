#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <IFile.h>
#include <File.h>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>

namespace
{
    class FileInitTest
        : public ::testing::Test
    {
    public:
        void SetUp()    override;
        void TearDown() override;
        std::shared_ptr<FileRep::IFile> File_C   = nullptr;
        std::unique_ptr<FileRep::IFile> File_CXX = nullptr;
    };

    void FileInitTest::SetUp()
    {
        File_C   = std::make_shared<FileRep::File>(TEST_TARGET_FILE_C);
        File_CXX = std::make_unique<FileRep::File>(TEST_TARGET_FILE_CXX);
    }

    void FileInitTest::TearDown()
    {
        File_C   = nullptr;
        File_CXX = nullptr;
    }
}

TEST_F(FileInitTest, SingleFileEXTNameCheck)
{
    EXPECT_EQ(File_C->filename(),TEST_TARGET_FILE_C);
    EXPECT_EQ(File_C->filenameOnly(), TEST_TARGET_FILE_WT_EXT);
}

TEST_F(FileInitTest, MultiFileExtNameCheck)
{
    EXPECT_EQ(File_CXX->filename(),TEST_TARGET_FILE_CXX);
    EXPECT_EQ(File_CXX->filenameOnly(),TEST_TARGET_FILE_WT_EXT);
}

TEST_F(FileInitTest, SingleFileEXTSizeCheck)
{
    EXPECT_EQ(File_C->filesize(),TEST_TARGET_FILE_SIZE_C);
}

TEST_F(FileInitTest, MultiFileExtSizeCheck)
{
    EXPECT_EQ(File_CXX->filesize(),TEST_TARGET_FILE_SIZE_CXX);
}

TEST_F(FileInitTest, MultiFileExtFileContent)
{
    EXPECT_EQ(File_CXX->filesize(),TEST_TARGET_FILE_SIZE_CXX);
}

TEST_F(FileInitTest, SingleFileEXTFileContent)
{
    std::vector<unsigned char> buffer(TEST_TARGET_FILE_SIZE_C + 1);
    unsigned char *bufferBegin = buffer.data();
    std::fstream filestream(TEST_TARGET_FILE_C,std::ios::in);

    filestream.read(reinterpret_cast<char*>(bufferBegin),TEST_TARGET_FILE_SIZE_C);
    filestream.close();

    std::vector<unsigned char> file = File_C->readFileContent();

    EXPECT_TRUE(std::equal(buffer.begin(), buffer.end(), file.begin()));
}

TEST_F(FileInitTest, MultiFileEXTFileContent)
{
    std::vector<unsigned char> buffer(TEST_TARGET_FILE_SIZE_CXX + 1);
    unsigned char *bufferBegin = buffer.data();
    std::fstream filestream(TEST_TARGET_FILE_CXX,std::ios::in);

    filestream.read(reinterpret_cast<char *>(bufferBegin),TEST_TARGET_FILE_SIZE_CXX);
    filestream.close();

    std::vector<unsigned char> file = File_CXX->readFileContent();

    EXPECT_TRUE(std::equal(buffer.begin(), buffer.end(), file.begin()));
}