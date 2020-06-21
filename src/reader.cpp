//
// Created by makarenko on 20.06.20.
//

#include "reader.h"

namespace reader {
    std::vector<std::vector<Shift>> shift(size_t width, size_t height)
    {
        auto shifts = std::vector<std::vector<Shift>>(height, std::vector<Shift>(width));
        auto file = std::ifstream("../files/result.txt");
        std::string row;
        size_t x = 0;
        while(std::getline(file, row)) {
            size_t y=0;
            std::stringstream ss(row);
            std::string numb;
            while (!ss.eof()) {
                ss >> numb;
                shifts[x][y].x = std::stoi(numb); //not shure about order
                ss >> numb;
                shifts[x][y].y = std::stoi(numb);
                y += 1;
            }
            x++;
        }
        return shifts;
    }

    std::vector<std::vector<Pixel>> img(std::string name)
    {
        using namespace cimg_library;

        std::vector<std::vector<Pixel>> img;
        CImg<unsigned char> image(name.c_str());
        int height = image.height();
        int width = image.width();
        img.resize(height);
        for (auto& row : img){
            row.resize(width);
        }
        for (int i=0; i<height; i++){
            for (int j=0; j<width; j++){
                img[i][j].r = (int)image.atXY(j, i, 0, 0);
                img[i][j].g = (int)image.atXY(j, i, 0, 1);
                img[i][j].b = (int)image.atXY(j, i, 0, 2);
            }
        }
        return img;
    }

}