#include <gtest/gtest.h>
#include "general_message.h"
#include "universal/Spesifier.hpp"
TEST_F(General_message, get_program_description)
{
    ASSERT_EQ(general_message_descriptor(Izip::Universal::GeneralSpesifier::PROGRAM_DESCRIPTION),
              GENERAL_MESSAGE[Izip::Universal::GeneralSpesifier::PROGRAM_DESCRIPTION]);
}

TEST_F(General_message, invalid_index)
{
    ASSERT_NE(general_message_descriptor(Izip::Universal::GeneralSpesifier::PROGRAM_DESCRIPTION), "");
}

TEST_F(General_message, Expect_invalid_indexation)
{
    ASSERT_EQ(general_message_descriptor(-1), "");
}
