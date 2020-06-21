//
// Created by makarenko on 20.06.20.
//

#ifndef LAB2_UTIL_H
#define LAB2_UTIL_H

#include <random>
#include <iostream>
#include <array>

namespace
{
    struct Rand
    {
        Rand(int from, int to)
        {
            distribution = std::uniform_int_distribution<int>(from, to);
        }

        auto operator()()
        {
            return distribution(generator);
        }

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution;
    };

    Rand gen(0, 2000);
}

namespace util
{
    template <typename T>
    auto random(const std::vector<std::vector<T>>& vec)
    {
        int x = gen() % (vec.size() - 50) + 25; //25 - step from sides;
        int y = gen() % (vec.size() - 50) + 25;
        auto l_pt = T{x, y};
        auto r_pt = T{x + vec[x][y].x, y + vec[x][y].y};
        return std::array<T, 2>{l_pt, r_pt};
    }


}

#endif //LAB2_UTIL_H
