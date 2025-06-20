#include <gtest/gtest.h>
#include "param_descriptor.h"

#include "universal/Spesifier.hpp"

// version
TEST_F(param_descriptor, EXpect_valid_the_same_param)
{
    ASSERT_EQ(param_symbol_descriptor(Izip::Universal::Spesifier::MYVERSION),
              PARAM_DESCRIPTOR[Izip::Universal::Spesifier::MYVERSION]);
}

TEST_F(param_descriptor, Expect_not_correct_param)
{
    ASSERT_NE(param_symbol_descriptor(Izip::Universal::Spesifier::PRINT),
              PARAM_DESCRIPTOR[Izip::Universal::Spesifier::MYVERSION]);
}

TEST_F(param_descriptor,Expect_out_of_bound_index)
{
    ASSERT_EQ(param_symbol_descriptor(-1),"");
}

// File
TEST_F(param_descriptor, Expect_file_equals_file)
{
    ASSERT_EQ(param_symbol_descriptor(Izip::Universal::Spesifier::DECOMPRESS),
              PARAM_DESCRIPTOR[Izip::Universal::Spesifier::DECOMPRESS]);
}

TEST_F(param_descriptor, Expect_version_Notequals_file)
{
    ASSERT_NE(param_symbol_descriptor(Izip::Universal::Spesifier::MYVERSION),
              PARAM_DESCRIPTOR[Izip::Universal::Spesifier::DECOMPRESS]);
}


// Print
TEST_F(param_descriptor, Expect_print_equals_print)
{
    ASSERT_EQ(param_symbol_descriptor(Izip::Universal::Spesifier::PRINT),
              PARAM_DESCRIPTOR[Izip::Universal::Spesifier::PRINT]);
}

TEST_F(param_descriptor, Expect_file_Notequals_print)
{
    ASSERT_NE(param_symbol_descriptor(Izip::Universal::Spesifier::DECOMPRESS),
              PARAM_DESCRIPTOR[Izip::Universal::Spesifier::PRINT]);
}
