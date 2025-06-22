#include <gtest/gtest.h>
#include "helpTestFixture.h"
#include "universal/Spesifier.hpp"

using namespace Izip::Wrappers::CompHelp;

// Tests descrip_messanger of index of version
TEST_F(helpTestFixture,version_descrip_messanger)
{
    ASSERT_EQ(param_message_descriptor(Izip::Universal::Spesifier::MYVERSION),
              helpMessage::PARAM_MESSAGE_DESCRIPTOR[Izip::Universal::Spesifier::MYVERSION]);
}

TEST_F(helpTestFixture,version_descrip_messanger_failure)
{
    ASSERT_EQ(param_message_descriptor(-1), "");
}

TEST_F(helpTestFixture,version_descrip_messanger_misreferance)
{
    ASSERT_NE(param_message_descriptor(-1),
              helpMessage::PARAM_MESSAGE_DESCRIPTOR[Izip::Universal::Spesifier::MYVERSION]);
}

// Tests descrip_messanger of index of file
TEST_F(helpTestFixture,FILE_descrip_messanger)
{
    ASSERT_EQ(param_message_descriptor(Izip::Universal::Spesifier::DECOMPRESS),
              helpMessage::PARAM_MESSAGE_DESCRIPTOR[Izip::Universal::Spesifier::DECOMPRESS]);
}

TEST_F(helpTestFixture,FILE_descrip_messanger_failure)
{
    ASSERT_EQ(param_message_descriptor(-1), "");
}

TEST_F(helpTestFixture,FILE_descrip_messanger_misreferance)
{
    ASSERT_NE(param_message_descriptor(-1),
              helpMessage::PARAM_MESSAGE_DESCRIPTOR[Izip::Universal::Spesifier::DECOMPRESS]);
}

