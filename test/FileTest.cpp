#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <comp_file/FileIfc.h>
#include <comp_file/File.h>


namespace
{
    class FileInitTest : public ::testing::Test
    {
    public:
        void SetUp()    override;
        void TearDown() override;
        std::shared_ptr<CompFile::File> _file = nullptr;
    };

    void FileInitTest::SetUp()
    {
        _file = nullptr;
        _file = std::make_shared<CompFile::File>(TEST_TARGET_FILE);
    }

    void FileInitTest::TearDown()
    {
        _file = nullptr;
    }
}

TEST_F(FileInitTest, FileBasicInit)
{
    EXPECT_EQ(_file->filename(),TEST_TARGET_FILE);
}