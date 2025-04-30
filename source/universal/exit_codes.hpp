#pragma once

namespace Izip::Universal
{
    enum EXIT_CODE
    {
        SUCCESS = 0,
        FAILURE = 1,

        INVALID_ARG = 114,
        INVLAID_FILE = 137,

        OUT_OF_BOUND = 120,
        REMOVAL_DIR_ERROR = 125,
    };
}
