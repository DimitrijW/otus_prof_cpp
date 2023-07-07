#include <gtest/gtest.h>
#include "lib.h"


TEST(VERSION, simple)
{
    ASSERT_EQ(version(), 1);
    ASSERT_NE(version(), 0);
}

