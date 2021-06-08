#ifndef MULTIDIMENSIONAL_TO_ONE_H
#define MULTIDIMENSIONAL_TO_ONE_H

#ifdef __cplusplus
extern "C" {
#endif

unsigned long two_to_one(
    unsigned long x,
    unsigned long y,
    unsigned long x_width);
void one_to_two(
    unsigned long idx,
    unsigned long *x,
    unsigned long *y,
    unsigned long x_width);

unsigned long three_to_one(
    unsigned long x,
    unsigned long y,
    unsigned long z,
    unsigned long x_width,
    unsigned long y_width);
void one_to_three(
    unsigned long idx,
    unsigned long *x,
    unsigned long *y,
    unsigned long *z,
    unsigned long x_width,
    unsigned long y_width);

unsigned long four_to_one(
    unsigned long x,
    unsigned long y,
    unsigned long z,
    unsigned long i,
    unsigned long x_width,
    unsigned long y_width,
    unsigned long z_width);
void one_to_four(
    unsigned long idx,
    unsigned long *x,
    unsigned long *y,
    unsigned long *z,
    unsigned long *i,
    unsigned long x_width,
    unsigned long y_width,
    unsigned long z_width);

unsigned long long two_to_one_l(
    unsigned long long x,
    unsigned long long y,
    unsigned long long x_width);
void one_to_two_l(
    unsigned long long idx,
    unsigned long long *x,
    unsigned long long *y,
    unsigned long long x_width);

unsigned long long three_to_one_l(
    unsigned long long x,
    unsigned long long y,
    unsigned long long z,
    unsigned long long x_width,
    unsigned long long y_width);
void one_to_three_l(
    unsigned long long idx,
    unsigned long long *x,
    unsigned long long *y,
    unsigned long long *z,
    unsigned long long x_width,
    unsigned long long y_width);

unsigned long long four_to_one_l(
    unsigned long long x,
    unsigned long long y,
    unsigned long long z,
    unsigned long long i,
    unsigned long long x_width,
    unsigned long long y_width,
    unsigned long long z_width);
void one_to_four_l(
    unsigned long long idx,
    unsigned long long *x,
    unsigned long long *y,
    unsigned long long *z,
    unsigned long long *i,
    unsigned long long x_width,
    unsigned long long y_width,
    unsigned long long z_width);

#ifdef __cplusplus
}
#endif

#endif
