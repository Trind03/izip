#include <gtest/gtest.h>
#include "param_help_descriptors.h"

#include "universal/Spesifier.hpp"


// Tests descrip_messanger of index of version
TEST_F(comp_help,version_descrip_messanger)
{
    ASSERT_EQ(comp_help::param_message_descriptor(Izip::Universal::Spesifier::MYVERSION),
              comp_help::PARAM_MESSAGE_DESCRIPTOR[Izip::Universal::Spesifier::MYVERSION]);
}

TEST_F(comp_help,version_descrip_messanger_failure)
{
    ASSERT_EQ(comp_help::param_message_descriptor(-1), "");
}

TEST_F(comp_help,version_descrip_messanger_misreferance)
{
    ASSERT_NE(comp_help::param_message_descriptor(-1),
              comp_help::PARAM_MESSAGE_DESCRIPTOR[Izip::Universal::Spesifier::MYVERSION]);
}

// Tests descrip_messanger of index of file
TEST_F(comp_help,FILE_descrip_messanger)
{
    ASSERT_EQ(comp_help::param_message_descriptor(Izip::Universal::Spesifier::DECOMPRESS),
              comp_help::PARAM_MESSAGE_DESCRIPTOR[Izip::Universal::Spesifier::DECOMPRESS]);
}

TEST_F(comp_help,FILE_descrip_messanger_failure)
{
    ASSERT_EQ(comp_help::param_message_descriptor(-1), "");
}

TEST_F(comp_help,FILE_descrip_messanger_misreferance)
{
    ASSERT_NE(comp_help::param_message_descriptor(-1),
              comp_help::PARAM_MESSAGE_DESCRIPTOR[Izip::Universal::Spesifier::DECOMPRESS]);
}


// Tests descrip_messanger of index of print
TEST_F(comp_help,PRINT_descrip_messanger)
{
    ASSERT_EQ(comp_help::param_message_descriptor(Izip::Universal::Spesifier::PRINT),
              comp_help::PARAM_MESSAGE_DESCRIPTOR[Izip::Universal::Spesifier::PRINT]);
}

TEST_F(comp_help,PRINT_descrip_messanger_failure)
{
    ASSERT_EQ(comp_help::param_message_descriptor(-1), "");
}

TEST_F(comp_help,PRINT_descrip_messanger_misreferance)
{
    ASSERT_NE(comp_help::param_message_descriptor(-1),
              comp_help::PARAM_MESSAGE_DESCRIPTOR[Izip::Universal::Spesifier::PRINT]);
}
