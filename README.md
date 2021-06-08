# One To N and N To One

This "library" demonstrates converting multi-dimensional coordinates to
one-dimensional coordinates (and back), up to 4 dimensions. If you examine the
source, it should become apparent how to apply this to more dimensions.

Note the Makefile only creates the UnitTests and the unit testing library is
added as a git submodule (so you need to do `git submodule update --init` to get
the unit testing framework).

# Notes for those who may be confused

`x_width` refers to the size of the first dimension of the array. So if it is
equivalent to 10, then this means that the first dimension contains values from
0-9 inclusive. Thus, a "width" is required for each of the `n-1` dimensions to
correctly calculate the required indices.
