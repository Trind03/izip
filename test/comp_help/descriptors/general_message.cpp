#include <gtest/gtest.h>
#include "helpTestFixture.h"
#include "universal/Spesifier.hpp"

TEST_F(helpTestFixture, get_program_description)
{
    ASSERT_EQ(helpTestInstance.general_message_descriptor(Izip::Universal::GeneralSpesifier::PROGRAM_DESCRIPTION),
              helpTestInstance.GENERAL_MESSAGE[Izip::Universal::GeneralSpesifier::PROGRAM_DESCRIPTION]);
}

TEST_F(helpTestFixture, invalid_index)
{
    ASSERT_NE(helpTestInstance.general_message_descriptor(Izip::Universal::GeneralSpesifier::PROGRAM_DESCRIPTION), "");
}

TEST_F(helpTestFixture, Expect_invalid_indexation)
{
    ASSERT_EQ(helpTestInstance.general_message_descriptor(-1), "");
}
