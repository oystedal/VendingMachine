#include <gtest/gtest.h>

#include "CoinChanger.hpp"

class CoinChangerTest : public ::testing::Test
{
protected:
    CoinChangerTest()
    {

    }

    CoinChanger changer;
};

TEST_F(CoinChangerTest, change_is_empty_when_zero)
{
    ASSERT_EQ(changer.change(0).size(), 0);
}

TEST_F(CoinChangerTest, change_one_when_one)
{   auto result = changer.change(1);
    EXPECT_EQ(result.size(), 1);
    ASSERT_TRUE(!result.empty());
    ASSERT_EQ(result[0], 1);
}

TEST_F(CoinChangerTest, difference_is_two){
    auto result = changer.change(2);
    EXPECT_EQ(result.size(), 2);
    ASSERT_EQ(result[0], 1);
    ASSERT_EQ(result[1], 1);
}

TEST_F(CoinChangerTest, difference_is_three){
    auto result = changer.change(3);
    EXPECT_EQ(result.size(), 3);
    ASSERT_EQ(result[0], 1);
    ASSERT_EQ(result[1], 1);
    ASSERT_EQ(result[2], 1);
}

TEST_F(CoinChangerTest, difference_is_four){
    auto result = changer.change(4);
    EXPECT_EQ(result.size(), 4);
    ASSERT_EQ(result[0], 1);
    ASSERT_EQ(result[1], 1);
    ASSERT_EQ(result[2], 1);
    ASSERT_EQ(result[3], 1);

}

TEST_F(CoinChangerTest, difference_is_five){
    auto result = changer.change(5);
    EXPECT_EQ(result.size(), 1);
    ASSERT_EQ(result[0], 5);
}

TEST_F(CoinChangerTest, difference_is_six){

    auto result = changer.change(6);
    EXPECT_EQ(result.size(), 2);
    ASSERT_EQ(result[0], 5);
    ASSERT_EQ(result[1], 1);
}

TEST_F(CoinChangerTest, difference_is_nine){

    auto result = changer.change(9);
    EXPECT_EQ(result.size(), 5);
    ASSERT_EQ(result[0], 5);
    ASSERT_EQ(result[1], 1);
    ASSERT_EQ(result[2], 1);
    ASSERT_EQ(result[3], 1);
    ASSERT_EQ(result[4], 1);
}

TEST_F(CoinChangerTest, difference_is_ten){
    auto result = changer.change(10);
    EXPECT_EQ(result.size(), 1);
    ASSERT_EQ(result[0], 10);
}


TEST_F(CoinChangerTest, difference_is_eleven){
    auto result = changer.change(11);
    EXPECT_EQ(result.size(), 2);
    ASSERT_EQ(result[0], 10);
    ASSERT_EQ(result[1], 1);
}

TEST_F(CoinChangerTest, difference_is_fifteen){
    auto result = changer.change(15);
    EXPECT_EQ(result.size(), 2);
    ASSERT_EQ(result[0], 10);
    ASSERT_EQ(result[1], 5);
}

TEST_F(CoinChangerTest, difference_if_sixteen){
    auto result = changer.change(16);
    EXPECT_EQ(result.size(), 3);
    ASSERT_EQ(result[0], 10);
    ASSERT_EQ(result[1], 5);
    ASSERT_EQ(result[2], 1);
}

