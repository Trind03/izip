#include <gtest/gtest.h>
#include "general_message.h"

TEST_F(General_message, get_program_description)
{
    ASSERT_EQ(general_message_descriptor(help::descriptor::general_spesifier::PROGRAM_DESCRIPTION),
              GENERAL_MESSAGE[help::descriptor::general_spesifier::PROGRAM_DESCRIPTION]);
}

TEST_F(General_message, invalid_index)
{
    ASSERT_NE(general_message_descriptor(help::descriptor::general_spesifier::PROGRAM_DESCRIPTION), "");
}

TEST_F(General_message, Expect_invalid_indexation)
{
    ASSERT_EQ(general_message_descriptor(-1), "");
}
