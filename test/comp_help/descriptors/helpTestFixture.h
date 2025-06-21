#include <gtest/gtest.h>
#include <Help.h>

class helpTestFixture : public ::testing::Test
{
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
public:
    Izip::Wrappers::CompHelp::Help helpTestInstance = Izip::Wrappers::CompHelp::Help::getInstance();
};
