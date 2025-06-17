#pragma once
#include <gtest/gtest.h>
#include "comp_help/Help.h"

#define COMMON_SIZE 3
class comp_help : public ::testing::Test, public Izip::Wrappers::CompHelp::Help
{
public:
    void SetUp() override
    {

    }
    void TearDown() override
    {

    }
};

