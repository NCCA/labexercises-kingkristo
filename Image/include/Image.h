#ifndef TEST_H_
#define TEST_H_
#include <stdint.h>
#include <stddef.h>
//Gives us smart pointers 
#include <memory>
#include <string>

//plain old data, doesn't need to be a class
struct RGBA
{
    union
    {
        struct
        {
            //default to black with full alpha
            unsigned char r = 0;
            unsigned char g = 0;
            unsigned char b = 0;
            unsigned char a =255;
        };
        uint32_t pixels;
    };

    RGBA() = default;

    RGBA(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a)
    {
        r = _r;
        g = _g;
        b = _b;
        a = _a;
    }

};

class Image
{
    public:
        Image()=default;
        Image(size_t _w, size_t _h);
        Image(size_t _w, size_t _h, unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a);
        //const to make read only
        //accessor
        size_t width() const;
        size_t height() const;
        RGBA getPixel (size_t _x, size_t _y);
        bool write(const std::string &_fname) const;
        void setPixel(size_t _x, size_t _y, RGBA _p);

    private:
        //attribute
        size_t m_width=0;
        size_t m_height=0;
        //unique pointer to RGBA pixels
        std::unique_ptr<RGBA []> m_pixels;

};

#endif