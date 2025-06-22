#include <gtest/gtest.h>
#include "helpTestFixture.h"
#include "universal/Spesifier.hpp"

using namespace Izip::Wrappers::CompHelp;

// version
TEST_F(helpTestFixture, EXpect_valid_the_same_param)
{
    ASSERT_EQ(param_symbol_descriptor(Izip::Universal::Spesifier::MYVERSION),
              helpMessage::PARAM_DESCRIPTOR[Izip::Universal::Spesifier::MYVERSION]);
}



TEST_F(helpTestFixture,Expect_out_of_bound_index)
{
    ASSERT_EQ(param_symbol_descriptor(-1),"");
}

// File
TEST_F(helpTestFixture, Expect_file_equals_file)
{
    ASSERT_EQ(param_symbol_descriptor(Izip::Universal::Spesifier::DECOMPRESS),
        helpMessage::PARAM_DESCRIPTOR[Izip::Universal::Spesifier::DECOMPRESS]);
}

TEST_F(helpTestFixture, Expect_version_Notequals_file)
{
    ASSERT_NE(param_symbol_descriptor(Izip::Universal::Spesifier::MYVERSION),
              helpMessage::PARAM_DESCRIPTOR[Izip::Universal::Spesifier::DECOMPRESS]);
}