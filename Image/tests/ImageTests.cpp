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
    Image img(250,150,255,0,0,255);
    ASSERT_EQ(img.width(),250);
    ASSERT_EQ(img.height(),150);

    for (size_t x=0; x<img.width(); x++)
    {
        for (size_t y=0; y<img.height(); y++)
        {
            auto pixel = img.getPixel(x,y);
            ASSERT_EQ(pixel.r,255);
            ASSERT_EQ(pixel.g,0);
            ASSERT_EQ(pixel.b,0);
            ASSERT_EQ(pixel.a,255);
        }
    }
}

TEST(IMAGE,writeToFile)
{
    Image img(500, 500, 255, 127, 64, 255);
    ASSERT_TRUE(img.write("test.png"));
}

TEST(IMAGE,setpixel)
{
    Image img(100,100,255,255,255,255);
    for(int i = 0; i<img.width(); i++)
    {
      //  img.setPixel(i,30,{255,0,0,266});
      //  img.setPixel(i,31,{255,0,0,266});
      //  img.setPixel(i,32,{255,0,0,266});
    // img.setPixel(i,33,{255,0,0,266});

    }
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