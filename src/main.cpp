#include <iostream>
#include <armadillo>
#include <math.h>

#include "reader.h"
#include "util.h"

int main() {

    auto L = reader::img("../files/L.png");
    auto R = reader::img("../files/R.png");

    auto shifts = reader::shift(L.size(), L[0].size());

    size_t quality = 0;
    arma::mat F_fin;
    for (int it = 0; it < 500; it++) {
        auto mat = arma::mat(7, 9);
        for (int i = 0; i < 7; i++) {
            auto pt = util::random(shifts);  //take random point
            mat.at(i, 0) = pt[0].x * pt[1].x;
            mat.at(i, 1) = pt[0].x * pt[1].y;
            mat.at(i, 2) = pt[0].x;
            mat.at(i, 3) = pt[0].y * pt[1].x;
            mat.at(i, 4) = pt[0].y * pt[1].y;
            mat.at(i, 5) = pt[0].y;
            mat.at(i, 6) = pt[1].x;
            mat.at(i, 7) = pt[1].y;
            mat.at(i, 8) = 1;
        }
        arma::mat null = arma::null(mat, 0.01); //nullspace
        arma::mat F0 = arma::reshape(null.col(0), 3, 3).t();
        arma::mat F1 = arma::reshape(null.col(1), 3, 3).t();

        arma::vec P = arma::vec( 4);
        P[0] = arma::det(F1);
        P[1] = arma::det(F1) * arma::trace(F1.i()*F0);
        P[2] = arma::det(F0) * arma::trace(F0.i()*F1);
        P[3] = arma::det(F0);
        arma::cx_vec roots = arma::roots(P); //solve cubic equation
        for (int r=0; r<3; r++)
        {
            if (roots[r].imag() != 0.)
            {
                continue;
            }

            arma::mat F = F0 + roots[r].real()*F1;  //final F for one iteration
            if (arma::det(F) > 1E-15 || arma::rank(F) != 2)
            {
                continue;
            }
            /////////////////// estimate quality

            size_t hits = 0;
            for (size_t i=25; i<L.size()-25; ++i)
            {
                for (size_t j=25; j<L[0].size()-25; ++j)
                {
                    arma::mat x_l = {double(i), double(j), 1};
                    arma::mat x_r = {double(i + shifts[i][j].x), double(j + shifts[i][j].y), 1};
                    arma::mat err = arma::abs(x_r*F*x_l.t());
                    if (err[0] < 1E-3)
                    {
                        hits++;
                    }
                }
            }
            if (hits > quality)
            {
                quality = hits;
                F_fin = F;
            }

            ///////////////////
        }

    }
    std::cout << "quality "<< double(quality/((L.size()-50.)*(L[0].size()-25.))) << "\n";
    std::cout << F_fin;

    for (int i=0; i < 20; ++i) //draw 20 epipolar lines
    {
        auto pt = util::random(shifts);
        writer::draw_cross(L, pt[0].x, pt[0].y);
        writer::draw_cross(R, pt[1].x, pt[1].y);

        arma::mat x0 = {double(pt[0].x), double(pt[0].y), 1.};
        arma::mat M = F_fin*x0.t(); //epipolar line eq

        arma::mat line = { -M[1]/M[0], -M[2]/M[0]};
        arma::mat y_ord = arma::ones(2, L[0].size());
        for(int i=0; i<L[0].size(); ++i)
        {
            y_ord.at(0, i) = i;
        }
        arma::mat x_ord = line*y_ord;
        auto v_x_ord = std::vector<int>(L[0].size());
        for(int i=0; i<L[0].size(); ++i)
        {
            v_x_ord[i] = x_ord[i];
        }
        writer::draw_line_h(v_x_ord, R);

        line = { -M[0]/M[1], -M[2]/M[1]};
        x_ord = arma::ones(2, L[0].size());
        for(int i=0; i<L.size(); ++i)
        {
            x_ord.at(0, i) = i;
        }
        y_ord = line*x_ord;
        auto v_y_ord = std::vector<int>(L.size());
        for(int i=0; i<L.size(); ++i)
        {
            v_y_ord[i] = y_ord[i];
        }
        writer::draw_line_v(v_y_ord, R);
    }
    writer::show_img(L, R);

    return 0;
}
