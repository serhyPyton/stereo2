//
// Created by makarenko on 20.06.20.
//

#ifndef LAB2_READER_H
#define LAB2_READER_H

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include "CImg/CImg.hpp"

struct Shift{
    int x; //vert
    int y; //horiz
};

struct Pixel {
    int r, g, b;
};

namespace reader {

    std::vector<std::vector<Shift>> shift(size_t width, size_t height);

    std::vector<std::vector<Pixel>> img(std::string name);

}

namespace writer {

    void draw_line_v(const std::vector<int>& x, std::vector<std::vector<Pixel>>& img);
    void draw_line_h(const std::vector<int>& x, std::vector<std::vector<Pixel>>& img);
    void draw_cross(std::vector<std::vector<Pixel>>& img, int y, int x);

    void show_img(std::vector<std::vector<Pixel>>& L, std::vector<std::vector<Pixel>>& R);

    void test(std::vector<std::vector<Pixel>>& L, std::vector<std::vector<Pixel>>& R, const std::vector<std::vector<Shift>>& shift);

}
#endif //LAB2_READER_H
