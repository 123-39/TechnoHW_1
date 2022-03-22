#include <iostream>
#include <gtest/gtest.h>

extern "C" {
#include "data.h"
}
int add(int a, int b) {
    return a + b;
}

TEST(TEST_FIRST, CREATING_BASE){
    int base_size = 5;
    MyKinopoisk *Base = allocate_struct(base_size);
    Output_base(Base, base_size);
    EXPECT_NE(Base->Release_year, nullptr);
    free(Base);
}
TEST(TEST_SECOND, NOT_NULL_POINTER){
    int base_size = 5;
    MyKinopoisk *Base = allocate_struct(base_size);
    EXPECT_NE(Base, nullptr);
    free(Base);
}
TEST(TEST_THIRD, CORRECT_DATA){
    int base_size = 5;
    MyKinopoisk *Base = allocate_struct(base_size);
    Create_base(Base, base_size);
    EXPECT_GE(Base[base_size].Release_year,1922);
    EXPECT_LE(Base[base_size].Release_year,2022);
    free(Base);
}
TEST(TEST_FOURS, LESS_BASE){
    int base_size = 5;
    MyKinopoisk *Base = allocate_struct(base_size);
    Create_base(Base, base_size);
    int base_rec_size = 0;
    MyKinopoisk *Base_rec = allocate_struct(base_size);
    Recomendation(Base, base_size, Base_rec, &base_rec_size);
    EXPECT_LE(base_rec_size, base_size);
    free(Base);
    free(Base_rec);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

