#include <gtest/gtest.h>
#include <array>
#include "Help.h"
#include "Ihelp.h"
#define COMMON_SIZE 3
class comp_help : public ::testing::Test, public help::Help
{
public:
    void SetUp() override
    {

    }
    void TearDown() override
    {

    }
};

