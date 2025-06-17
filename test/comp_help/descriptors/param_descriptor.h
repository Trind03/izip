#include <Help.h>
#include <gtest/gtest.h>

class param_descriptor : public ::testing::Test, public Izip::Wrappers::CompHelp::Help
{
    void SetUp() override
    {

    }

    void TearDown() override
    {

    }

};
