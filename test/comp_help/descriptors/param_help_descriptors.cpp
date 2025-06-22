#include <gtest/gtest.h>
#include "helpTestFixture.h"
#include "universal/Spesifier.hpp"


// Tests descrip_messanger of index of version
TEST_F(helpTestFixture,version_descrip_messanger)
{
    ASSERT_EQ(helpTestInstance.param_message_descriptor(Izip::Universal::Spesifier::MYVERSION),
              helpTestInstance.PARAM_MESSAGE_DESCRIPTOR[Izip::Universal::Spesifier::MYVERSION]);
}

TEST_F(helpTestFixture,version_descrip_messanger_failure)
{
    ASSERT_EQ(helpTestInstance.param_message_descriptor(-1), "");
}

TEST_F(helpTestFixture,version_descrip_messanger_misreferance)
{
    ASSERT_NE(helpTestInstance.param_message_descriptor(-1),
              helpTestInstance.PARAM_MESSAGE_DESCRIPTOR[Izip::Universal::Spesifier::MYVERSION]);
}

// Tests descrip_messanger of index of file
TEST_F(helpTestFixture,FILE_descrip_messanger)
{
    ASSERT_EQ(helpTestInstance.param_message_descriptor(Izip::Universal::Spesifier::DECOMPRESS),
              helpTestInstance.PARAM_MESSAGE_DESCRIPTOR[Izip::Universal::Spesifier::DECOMPRESS]);
}

TEST_F(helpTestFixture,FILE_descrip_messanger_failure)
{
    ASSERT_EQ(helpTestInstance.param_message_descriptor(-1), "");
}

TEST_F(helpTestFixture,FILE_descrip_messanger_misreferance)
{
    ASSERT_NE(helpTestInstance.param_message_descriptor(-1),
              helpTestInstance.PARAM_MESSAGE_DESCRIPTOR[Izip::Universal::Spesifier::DECOMPRESS]);
}

