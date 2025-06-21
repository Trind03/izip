#include <gtest/gtest.h>
#include "helpTestFixture.h"
#include "universal/Spesifier.hpp"

// version
TEST_F(helpTestFixture, EXpect_valid_the_same_param)
{
    ASSERT_EQ(helpTestInstance.param_symbol_descriptor(Izip::Universal::Spesifier::MYVERSION),
              helpTestInstance.PARAM_DESCRIPTOR[Izip::Universal::Spesifier::MYVERSION]);
}

TEST_F(helpTestFixture, Expect_not_correct_param)
{
    ASSERT_NE(helpTestInstance.param_symbol_descriptor(Izip::Universal::Spesifier::PRINT),
              helpTestInstance.PARAM_DESCRIPTOR[Izip::Universal::Spesifier::MYVERSION]);
}

TEST_F(helpTestFixture,Expect_out_of_bound_index)
{
    ASSERT_EQ(helpTestInstance.param_symbol_descriptor(-1),"");
}

// File
TEST_F(helpTestFixture, Expect_file_equals_file)
{
    ASSERT_EQ(helpTestInstance.param_symbol_descriptor(Izip::Universal::Spesifier::DECOMPRESS),
              helpTestInstance.PARAM_DESCRIPTOR[Izip::Universal::Spesifier::DECOMPRESS]);
}

TEST_F(helpTestFixture, Expect_version_Notequals_file)
{
    ASSERT_NE(helpTestInstance.param_symbol_descriptor(Izip::Universal::Spesifier::MYVERSION),
              helpTestInstance.PARAM_DESCRIPTOR[Izip::Universal::Spesifier::DECOMPRESS]);
}


// Print
TEST_F(helpTestFixture, Expect_print_equals_print)
{
    ASSERT_EQ(helpTestInstance.param_symbol_descriptor(Izip::Universal::Spesifier::PRINT),
              helpTestInstance.PARAM_DESCRIPTOR[Izip::Universal::Spesifier::PRINT]);
}

TEST_F(helpTestFixture, Expect_file_Notequals_print)
{
    ASSERT_NE(helpTestInstance.param_symbol_descriptor(Izip::Universal::Spesifier::DECOMPRESS),
              helpTestInstance.PARAM_DESCRIPTOR[Izip::Universal::Spesifier::PRINT]);
}
