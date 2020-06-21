//
// Created by makarenko on 21.06.20.
//

#include "reader.h"

namespace writer
{
    using namespace cimg_library;

    void draw_line_h(const std::vector<int>& x, std::vector<std::vector<Pixel>>& img)
    {
        size_t height = img.size();
        size_t width = img[0].size();
        for(int i=0; i< x.size(); i++){
            if (x[i] > 0 && x[i] < height) {
                img[x[i]][i].r = 255;
                img[x[i]][i].g = 0;
            }
        }
    }
    void draw_line_v(const std::vector<int>& x, std::vector<std::vector<Pixel>>& img)
    {
        size_t height = img.size();
        size_t width = img[0].size();
        for(int j=0; j< x.size(); j++){
            if (x[j] > 0 && x[j] < width) {
                img[j][x[j]].r = 255;
                img[j][x[j]].g = 0;
            }
        }
    }

    void show_img(std::vector<std::vector<Pixel>>& L, std::vector<std::vector<Pixel>>& R)
    {
        size_t height = L.size();
        size_t width = L[0].size();
        CImg<unsigned char> image_l(width, height, 1, 3, 0);
        for(int i=0; i< width; i++){
            for(int j=0; j< height; j++){
                image_l.atXY(i, j, 0, 0) = L[j][i].r;
                image_l.atXY(i, j, 0, 1) = L[j][i].g;
                image_l.atXY(i, j, 0, 2) = L[j][i].b;
            }
        }
        CImg<unsigned char> image_r(width, height, 1, 3, 0);
        for(int i=0; i< width; i++){
            for(int j=0; j< height; j++){
                image_r.atXY(i, j, 0, 0) = R[j][i].r;
                image_r.atXY(i, j, 0, 1) = R[j][i].g;
                image_r.atXY(i, j, 0, 2) = R[j][i].b;
            }
        }
        image_l.save("left.bmp");
        image_r.save("right.bmp");
      /*  CImgDisplay main_disp(image_l,"Click a point");
        while (!main_disp.is_closed()) {
            main_disp.wait();
        }*/
    }

    void draw_cross(std::vector<std::vector<Pixel>>& img, int y, int x)
    {
        int height = img.size();
        int width = img[0].size();
        for(int i=y-3; i< y+3; i++) {
            for(int j=x-3; j< x+3; j++) {
                if (i<0 || j<0 || i>=height || j>=width)
                    continue;
                img[i][j].r = 255;
                img[i][j].g = 0;
                img[i][j].b = 0;
            }
        }
    }

    void test(std::vector<std::vector<Pixel>>& L, std::vector<std::vector<Pixel>>& R, const std::vector<std::vector<Shift>>& shift)
    {
        size_t height = L.size();
        size_t width = L[0].size();
        CImg<unsigned char> image(width, height, 1, 3, 0);
        for(int i=0; i< width; i++){
            for(int j=0; j< height; j++){
                image.atXY(i, j, 0, 0) = L[j][i].r;
                image.atXY(i, j, 0, 1) = L[j][i].g;
                image.atXY(i, j, 0, 2) = L[j][i].b;
            }
        }
        CImgDisplay main_disp(image,"Click a point");
        while (!main_disp.is_closed()) {
            if (main_disp.button() && main_disp.mouse_y()>=0) {
                int x = main_disp.mouse_y();
                int y = main_disp.mouse_x();
                ////////////
                draw_cross(R, x+shift[x][y].x, y+shift[x][y].y);
                CImg<unsigned char> image_t(width, height, 1, 3, 0);
                for(int i=0; i< width; i++){
                    for(int j=0; j< height; j++){
                        image_t.atXY(i, j, 0, 0) = R[j][i].r;
                        image_t.atXY(i, j, 0, 1) = R[j][i].g;
                        image_t.atXY(i, j, 0, 2) = R[j][i].b;
                    }
                }
                CImgDisplay tmp_disp(image_t,"Click a point");
                while (!tmp_disp.is_closed()) {
                    tmp_disp.wait();
                }
                ///////////
            }
            main_disp.wait();
        }
    }
}
