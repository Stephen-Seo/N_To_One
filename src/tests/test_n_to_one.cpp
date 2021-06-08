#include <catch.hpp>

#include "../n_to_one.h"

struct Indices {
    unsigned long long x;
    unsigned long long y;
    unsigned long long z;
    unsigned long long i;
};

TEST_CASE("two_to_one", "n_to_one") {
    unsigned long x = 5;
    unsigned long y = 4;
    unsigned long x_width = 10;

    CHECK(two_to_one(x, y, x_width) == 45);

    x = 3;
    CHECK(two_to_one(x, y, x_width) == 43);

    y = 7;
    CHECK(two_to_one(x, y, x_width) == 73);
}

TEST_CASE("one_to_two", "n_to_one") {
    unsigned long x;
    unsigned long y;
    unsigned long x_width = 10;
    unsigned long idx = 45;

    one_to_two(idx, &x, &y, x_width);
    CHECK(x == 5);
    CHECK(y == 4);

    idx = 43;
    one_to_two(idx, &x, &y, x_width);
    CHECK(x == 3);
    CHECK(y == 4);

    idx = 73;
    one_to_two(idx, &x, &y, x_width);
    CHECK(x == 3);
    CHECK(y == 7);
}

TEST_CASE("three_to_one", "n_to_one") {
    unsigned long x = 5;
    unsigned long y = 4;
    unsigned long z = 3;
    unsigned long x_width = 10;
    unsigned long y_width = 10;

    CHECK(three_to_one(x, y, z, x_width, y_width) == 345);

    x = 3;
    z = 7;
    CHECK(three_to_one(x, y, z, x_width, y_width) == 743);

    x = 1;
    y = 5;
    z = 9;
    CHECK(three_to_one(x, y, z, x_width, y_width) == 951);
}

TEST_CASE("one_to_three", "n_to_one") {
    unsigned long x;
    unsigned long y;
    unsigned long z;
    unsigned long x_width = 10;
    unsigned long y_width = 10;
    unsigned long idx = 123;

    one_to_three(idx, &x, &y, &z, x_width, y_width);
    CHECK(x == 3);
    CHECK(y == 2);
    CHECK(z == 1);

    idx = 957;
    one_to_three(idx, &x, &y, &z, x_width, y_width);
    CHECK(x == 7);
    CHECK(y == 5);
    CHECK(z == 9);

    idx = 482;
    one_to_three(idx, &x, &y, &z, x_width, y_width);
    CHECK(x == 2);
    CHECK(y == 8);
    CHECK(z == 4);
}

TEST_CASE("four_to_one", "n_to_one") {
    unsigned long x = 1;
    unsigned long y = 2;
    unsigned long z = 3;
    unsigned long i = 4;
    unsigned long x_width = 10;
    unsigned long y_width = 10;
    unsigned long z_width = 10;

    CHECK(four_to_one(x, y, z, i, x_width, y_width, z_width) == 4321);

    y_width = 5;
    // 1 + 2 * 10 + 3 * 10 * 5 + 4 * 10 * 5 * 10 == 2171
    CHECK(four_to_one(x, y, z, i, x_width, y_width, z_width) == 2171);

    y_width = 10;
    x = 9;
    y = 7;
    z = 4;
    i = 2;
    CHECK(four_to_one(x, y, z, i, x_width, y_width, z_width) == 2479);
}

TEST_CASE("one_to_four", "n_to_one") {
    unsigned long x;
    unsigned long y;
    unsigned long z;
    unsigned long i;
    unsigned long x_width = 10;
    unsigned long y_width = 10;
    unsigned long z_width = 10;
    unsigned long idx = 1234;

    one_to_four(idx, &x, &y, &z, &i, x_width, y_width, z_width);
    CHECK(x == 4);
    CHECK(y == 3);
    CHECK(z == 2);
    CHECK(i == 1);

    y_width = 5;
    // x = 4, y = 3, z = 1234 / 10 / 5 % 10 == 4, i = 1234 / 10 / 5 / 10 == 2
    one_to_four(idx, &x, &y, &z, &i, x_width, y_width, z_width);
    CHECK(x == 4);
    CHECK(y == 3);
    CHECK(z == 4);
    CHECK(i == 2);

    y_width = 10;
    idx = 7125;
    one_to_four(idx, &x, &y, &z, &i, x_width, y_width, z_width);
    CHECK(x == 5);
    CHECK(y == 2);
    CHECK(z == 1);
    CHECK(i == 7);
}

TEST_CASE("n=2 objects long", "n_to_one") {
    Indices indices[5*4];
    unsigned long x;
    unsigned long y;
    unsigned long idx;

    for(idx = 0; idx < 5*4; ++idx) {
        one_to_two(idx, &x, &y, 5);
        indices[idx].x = x;
        indices[idx].y = y;
    }

    for(y = 0; y < 4; ++y) {
        for(x = 0; x < 5; ++x) {
            idx = two_to_one(x, y, 5);
            REQUIRE(idx < 5*4);
            CHECK(indices[idx].x == x);
            CHECK(indices[idx].y == y);
        }
    }
}

TEST_CASE("n=3 objects long", "n_to_one") {
    Indices indices[5*4*3];
    unsigned long x;
    unsigned long y;
    unsigned long z;
    unsigned long idx;

    for(idx = 0; idx < 5*4*3; ++idx) {
        one_to_three(idx, &x, &y, &z, 5, 4);
        indices[idx].x = x;
        indices[idx].y = y;
        indices[idx].z = z;
    }

    for(z = 0; z < 3; ++z) {
        for(y = 0; y < 4; ++y) {
            for(x = 0; x < 5; ++x) {
                idx = three_to_one(x, y, z, 5, 4);
                REQUIRE(idx < 5*4*3);
                CHECK(indices[idx].x == x);
                CHECK(indices[idx].y == y);
                CHECK(indices[idx].z == z);
            }
        }
    }
}

TEST_CASE("n=4 objects long", "n_to_one") {
    Indices indices[5*4*3*2];
    unsigned long x;
    unsigned long y;
    unsigned long z;
    unsigned long i;
    unsigned long idx;

    for(idx = 0; idx < 5*4*3*2; ++idx) {
        one_to_four(idx, &x, &y, &z, &i, 5, 4, 3);
        indices[idx].x = x;
        indices[idx].y = y;
        indices[idx].z = z;
        indices[idx].i = i;
    }

    for(i = 0; i < 2; ++i) {
        for(z = 0; z < 3; ++z) {
            for(y = 0; y < 4; ++y) {
                for(x = 0; x < 5; ++x) {
                    idx = four_to_one(x, y, z, i, 5, 4, 3);
                    REQUIRE(idx < 5*4*3*2);
                    CHECK(indices[idx].x == x);
                    CHECK(indices[idx].y == y);
                    CHECK(indices[idx].z == z);
                    CHECK(indices[idx].i == i);
                }
            }
        }
    }
}

TEST_CASE("two_to_one_l", "n_to_one") {
    unsigned long long x = 5;
    unsigned long long y = 4;
    unsigned long long x_width = 10;

    CHECK(two_to_one_l(x, y, x_width) == 45);

    x = 3;
    CHECK(two_to_one_l(x, y, x_width) == 43);

    y = 7;
    CHECK(two_to_one_l(x, y, x_width) == 73);
}

TEST_CASE("one_to_two_l", "n_to_one") {
    unsigned long long x;
    unsigned long long y;
    unsigned long long x_width = 10;
    unsigned long long idx = 45;

    one_to_two_l(idx, &x, &y, x_width);
    CHECK(x == 5);
    CHECK(y == 4);

    idx = 43;
    one_to_two_l(idx, &x, &y, x_width);
    CHECK(x == 3);
    CHECK(y == 4);

    idx = 73;
    one_to_two_l(idx, &x, &y, x_width);
    CHECK(x == 3);
    CHECK(y == 7);
}

TEST_CASE("three_to_one_l", "n_to_one") {
    unsigned long long x = 5;
    unsigned long long y = 4;
    unsigned long long z = 3;
    unsigned long long x_width = 10;
    unsigned long long y_width = 10;

    CHECK(three_to_one_l(x, y, z, x_width, y_width) == 345);

    x = 3;
    z = 7;
    CHECK(three_to_one_l(x, y, z, x_width, y_width) == 743);

    x = 1;
    y = 5;
    z = 9;
    CHECK(three_to_one_l(x, y, z, x_width, y_width) == 951);
}

TEST_CASE("one_to_three_l", "n_to_one") {
    unsigned long long x;
    unsigned long long y;
    unsigned long long z;
    unsigned long long x_width = 10;
    unsigned long long y_width = 10;
    unsigned long long idx = 123;

    one_to_three_l(idx, &x, &y, &z, x_width, y_width);
    CHECK(x == 3);
    CHECK(y == 2);
    CHECK(z == 1);

    idx = 957;
    one_to_three_l(idx, &x, &y, &z, x_width, y_width);
    CHECK(x == 7);
    CHECK(y == 5);
    CHECK(z == 9);

    idx = 482;
    one_to_three_l(idx, &x, &y, &z, x_width, y_width);
    CHECK(x == 2);
    CHECK(y == 8);
    CHECK(z == 4);
}

TEST_CASE("four_to_one_l", "n_to_one") {
    unsigned long long x = 1;
    unsigned long long y = 2;
    unsigned long long z = 3;
    unsigned long long i = 4;
    unsigned long long x_width = 10;
    unsigned long long y_width = 10;
    unsigned long long z_width = 10;

    CHECK(four_to_one_l(x, y, z, i, x_width, y_width, z_width) == 4321);

    y_width = 5;
    // 1 + 2 * 10 + 3 * 10 * 5 + 4 * 10 * 5 * 10 == 2171
    CHECK(four_to_one_l(x, y, z, i, x_width, y_width, z_width) == 2171);

    y_width = 10;
    x = 9;
    y = 7;
    z = 4;
    i = 2;
    CHECK(four_to_one_l(x, y, z, i, x_width, y_width, z_width) == 2479);
}

TEST_CASE("one_to_four_l", "n_to_one") {
    unsigned long long x;
    unsigned long long y;
    unsigned long long z;
    unsigned long long i;
    unsigned long long x_width = 10;
    unsigned long long y_width = 10;
    unsigned long long z_width = 10;
    unsigned long long idx = 1234;

    one_to_four_l(idx, &x, &y, &z, &i, x_width, y_width, z_width);
    CHECK(x == 4);
    CHECK(y == 3);
    CHECK(z == 2);
    CHECK(i == 1);

    y_width = 5;
    // x = 4, y = 3, z = 1234 / 10 / 5 % 10 == 4, i = 1234 / 10 / 5 / 10 == 2
    one_to_four_l(idx, &x, &y, &z, &i, x_width, y_width, z_width);
    CHECK(x == 4);
    CHECK(y == 3);
    CHECK(z == 4);
    CHECK(i == 2);

    y_width = 10;
    idx = 7125;
    one_to_four_l(idx, &x, &y, &z, &i, x_width, y_width, z_width);
    CHECK(x == 5);
    CHECK(y == 2);
    CHECK(z == 1);
    CHECK(i == 7);
}

TEST_CASE("n=2 objects long long", "n_to_one") {
    Indices indices[5*4];
    unsigned long long x;
    unsigned long long y;
    unsigned long long idx;

    for(idx = 0; idx < 5*4; ++idx) {
        one_to_two_l(idx, &x, &y, 5);
        indices[idx].x = x;
        indices[idx].y = y;
    }

    for(y = 0; y < 4; ++y) {
        for(x = 0; x < 5; ++x) {
            idx = two_to_one_l(x, y, 5);
            REQUIRE(idx < 5*4);
            CHECK(indices[idx].x == x);
            CHECK(indices[idx].y == y);
        }
    }
}

TEST_CASE("n=3 objects long long", "n_to_one") {
    Indices indices[5*4*3];
    unsigned long long x;
    unsigned long long y;
    unsigned long long z;
    unsigned long long idx;

    for(idx = 0; idx < 5*4*3; ++idx) {
        one_to_three_l(idx, &x, &y, &z, 5, 4);
        indices[idx].x = x;
        indices[idx].y = y;
        indices[idx].z = z;
    }

    for(z = 0; z < 3; ++z) {
        for(y = 0; y < 4; ++y) {
            for(x = 0; x < 5; ++x) {
                idx = three_to_one_l(x, y, z, 5, 4);
                REQUIRE(idx < 5*4*3);
                CHECK(indices[idx].x == x);
                CHECK(indices[idx].y == y);
                CHECK(indices[idx].z == z);
            }
        }
    }
}

TEST_CASE("n=4 objects long long", "n_to_one") {
    Indices indices[5*4*3*2];
    unsigned long long x;
    unsigned long long y;
    unsigned long long z;
    unsigned long long i;
    unsigned long long idx;

    for(idx = 0; idx < 5*4*3*2; ++idx) {
        one_to_four_l(idx, &x, &y, &z, &i, 5, 4, 3);
        indices[idx].x = x;
        indices[idx].y = y;
        indices[idx].z = z;
        indices[idx].i = i;
    }

    for(i = 0; i < 2; ++i) {
        for(z = 0; z < 3; ++z) {
            for(y = 0; y < 4; ++y) {
                for(x = 0; x < 5; ++x) {
                    idx = four_to_one_l(x, y, z, i, 5, 4, 3);
                    REQUIRE(idx < 5*4*3*2);
                    CHECK(indices[idx].x == x);
                    CHECK(indices[idx].y == y);
                    CHECK(indices[idx].z == z);
                    CHECK(indices[idx].i == i);
                }
            }
        }
    }
}
