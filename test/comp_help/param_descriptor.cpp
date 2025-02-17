#include <gtest/gtest.h>
#include "param_descriptor.h"

// version
TEST_F(param_descriptor, EXpect_valid_the_same_param)
{
    ASSERT_EQ(param_view_descriptor(help::descriptor::spesifier::MYVERSION),
              PARAM_DESCRIPTOR[help::descriptor::MYVERSION]);
}

TEST_F(param_descriptor, Expect_not_correct_param)
{
    ASSERT_NE(param_view_descriptor(help::descriptor::spesifier::PRINT),
              PARAM_DESCRIPTOR[help::descriptor::spesifier::MYVERSION]);
}

TEST_F(param_descriptor,Expect_out_of_bound_index)
{
    ASSERT_EQ(param_view_descriptor(-1),"");
}

// File
TEST_F(param_descriptor, Expect_file_equals_file)
{
    ASSERT_EQ(param_view_descriptor(help::descriptor::spesifier::FILE),
              PARAM_DESCRIPTOR[help::descriptor::FILE]);
}

TEST_F(param_descriptor, Expect_version_Notequals_file)
{
    ASSERT_NE(param_view_descriptor(help::descriptor::spesifier::MYVERSION),
              PARAM_DESCRIPTOR[help::descriptor::spesifier::FILE]);
}


// Print
TEST_F(param_descriptor, Expect_print_equals_print)
{
    ASSERT_EQ(param_view_descriptor(help::descriptor::spesifier::PRINT),
              PARAM_DESCRIPTOR[help::descriptor::PRINT]);
}

TEST_F(param_descriptor, Expect_file_Notequals_print)
{
    ASSERT_NE(param_view_descriptor(help::descriptor::spesifier::FILE),
              PARAM_DESCRIPTOR[help::descriptor::spesifier::PRINT]);
}
