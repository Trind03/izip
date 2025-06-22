#include <gtest/gtest.h>
#include <comp_help/Help.h>

class CompHelpTest : public ::testing::Test {
    public:
    void SetUp() {}
    void TearDown() {}
};

TEST_F(CompHelpTest, CompHelp_buffer_param_message_desc_size)
{
    constexpr int zero = 0;
    int Buffersize = Izip::Wrappers::CompHelp::helpMessage::PARAM_MESSAGE_DESCRIPTOR.size();
    EXPECT_EQ(PARAM_LENGTH,Buffersize);
    EXPECT_NE(zero,Buffersize);

}