#include "Image.h"
#include <gtest/gtest.h>

//default construction
TEST(RGBA,ctor)
{
    RGBA a;
    //r must be public to access directly like this
    ASSERT_EQ(a.r, 0);
    ASSERT_EQ(a.g, 0);
    ASSERT_EQ(a.b, 0);
    ASSERT_EQ(a.a, 255);

}

//user constructor
TEST(RGBA,userctor)
{
    RGBA a(255, 128, 64, 55);
    ASSERT_EQ(a.r, 255);
    ASSERT_EQ(a.g, 128);
    ASSERT_EQ(a.b, 64);
    ASSERT_EQ(a.a, 55);
}

//excersises, note this is a different test suite (image not RGBA)
// Test #1
TEST(IMAGE,construct)
{
    Image img;
    ASSERT_EQ(img.width(),0);
    ASSERT_EQ(img.height(),0);
}

// Test #2
TEST(IMAGE,constructUser)
{
    Image img(50,50);
}
/*
// Test #3
TEST(IMAGE,getPixelDefault)
// Test #4
TEST(Image,constructWithColour)
//# TEST 5
TEST(Image,clear)
// # Test 6
TEST(IMAGE,setPixel)
// # Test 7
TEST(IMAGE,setPixelRGBA)
// # test 8
TEST(IMAGE,save)*/