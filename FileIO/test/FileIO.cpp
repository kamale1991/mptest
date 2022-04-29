#include "../include/FileIO.h"
#include "gtest/gtest.h"

namespace FileIO {    
    TEST(sample, test) {
        int a = 1;
        int golden = 1;
        EXPECT_EQ(a, golden);
    }
}