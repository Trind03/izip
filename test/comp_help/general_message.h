#include <gtest/gtest.h>
#include <Help.h>
#include <Ihelp.h>

class General_message : public ::testing::Test, public help::Help
{
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
};
