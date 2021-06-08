#include "n_to_one.h"

unsigned long two_to_one(
        unsigned long x,
        unsigned long y,
        unsigned long x_width) {
    return x + y * x_width;
}

void one_to_two(
        unsigned long idx,
        unsigned long *x,
        unsigned long *y,
        unsigned long x_width) {
    *x = idx % x_width;
    *y = idx / x_width;
}

unsigned long three_to_one(
        unsigned long x,
        unsigned long y,
        unsigned long z,
        unsigned long x_width,
        unsigned long y_width){
    return x + y * x_width + z * x_width * y_width;
}

void one_to_three(
        unsigned long idx,
        unsigned long *x,
        unsigned long *y,
        unsigned long *z,
        unsigned long x_width,
        unsigned long y_width) {
    *x = idx % x_width;
    *y = (idx / x_width) % y_width;
    *z = idx / x_width / y_width;
}

unsigned long four_to_one(
        unsigned long x,
        unsigned long y,
        unsigned long z,
        unsigned long i,
        unsigned long x_width,
        unsigned long y_width,
        unsigned long z_width) {
    return x + y * x_width + z * x_width * y_width + i * x_width * y_width * z_width;
}
void one_to_four(
        unsigned long idx,
        unsigned long *x,
        unsigned long *y,
        unsigned long *z,
        unsigned long *i,
        unsigned long x_width,
        unsigned long y_width,
        unsigned long z_width) {
    *x = idx % x_width;
    *y = (idx / x_width) % y_width;
    *z = ((idx / x_width) / y_width) % z_width;
    *i = ((idx / x_width) / y_width) / z_width;
}

unsigned long long two_to_one_l(
        unsigned long long x,
        unsigned long long y,
        unsigned long long x_width) {
    return x + y * x_width;
}

void one_to_two_l(
        unsigned long long idx,
        unsigned long long *x,
        unsigned long long *y,
        unsigned long long x_width) {
    *x = idx % x_width;
    *y = idx / x_width;
}

unsigned long long three_to_one_l(
        unsigned long long x,
        unsigned long long y,
        unsigned long long z,
        unsigned long long x_width,
        unsigned long long y_width){
    return x + y * x_width + z * x_width * y_width;
}

void one_to_three_l(
        unsigned long long idx,
        unsigned long long *x,
        unsigned long long *y,
        unsigned long long *z,
        unsigned long long x_width,
        unsigned long long y_width) {
    *x = idx % x_width;
    *y = (idx / x_width) % y_width;
    *z = idx / x_width / y_width;
}

unsigned long long four_to_one_l(
        unsigned long long x,
        unsigned long long y,
        unsigned long long z,
        unsigned long long i,
        unsigned long long x_width,
        unsigned long long y_width,
        unsigned long long z_width) {
    return x + y * x_width + z * x_width * y_width + i * x_width * y_width * z_width;
}
void one_to_four_l(
        unsigned long long idx,
        unsigned long long *x,
        unsigned long long *y,
        unsigned long long *z,
        unsigned long long *i,
        unsigned long long x_width,
        unsigned long long y_width,
        unsigned long long z_width) {
    *x = idx % x_width;
    *y = (idx / x_width) % y_width;
    *z = ((idx / x_width) / y_width) % z_width;
    *i = ((idx / x_width) / y_width) / z_width;
}
