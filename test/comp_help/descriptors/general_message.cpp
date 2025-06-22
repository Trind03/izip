#include <gtest/gtest.h>
#include "helpTestFixture.h"
#include "universal/Spesifier.hpp"

using namespace Izip::Wrappers::CompHelp;

TEST_F(helpTestFixture, get_program_description)
{
    ASSERT_EQ(general_message_descriptor(Izip::Universal::GeneralSpesifier::PROGRAM_DESCRIPTION),
              helpMessage::GENERAL_MESSAGE[Izip::Universal::GeneralSpesifier::PROGRAM_DESCRIPTION]);
}

TEST_F(helpTestFixture, invalid_index)
{
    ASSERT_NE(general_message_descriptor(Izip::Universal::GeneralSpesifier::PROGRAM_DESCRIPTION), "");
}

TEST_F(helpTestFixture, Expect_invalid_indexation)
{
    ASSERT_EQ(general_message_descriptor(-1), "");
}
