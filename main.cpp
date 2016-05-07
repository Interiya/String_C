#include "gtest/gtest.h"
#include "String.h"

TEST(String, EQ){
    ASSERT_TRUE(String("asd") == String("asd"));
};
TEST(String, noEQ){
    ASSERT_TRUE(String("asd") != String("ard"));
};
TEST(String, Char){
    String a("asd");
    ASSERT_TRUE(a[0] == 'a');
    ASSERT_TRUE(a[1] == 's');
    ASSERT_TRUE(a[2] == 'd');
};
TEST(String, Change){
    String a("asd");
    a[0] = 's';
    ASSERT_TRUE(a == String("ssd"));
};
TEST(String, Add_1){
    ASSERT_TRUE((String("asD") + String("Dsa")) == String("asDDsa"));
};
TEST(String, Add_2){
    ASSERT_TRUE((String("asD") += String("Dsa")) == String("asDDsa"));
};
int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
