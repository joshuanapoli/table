table
=====

This C++11 library builds constant expression lookup tables given a generating
function. The table class builds a std::array constant expression with element
values initialized by mapping a generator function over the array index values.
table<T,N>(f) is equivalent to array<T,N>{{f(0),f(1),...,f(N-1)}}. Here is an
example:

```c++
#include <table.hpp>

struct times_two {
  constexpr std::size_t operator()(std::size_t x) {return x*2;}
};

constexpr table<std::size_t, 2> test_table{times_two()};

static_assert( 0 == test_table[0], "test_table[0] should be equal 0 (2*0)" );
static_assert( 2 == test_table[1], "test_table[1] should be equal 2 (2*1)" );
```

Note that the rules for constant expressions prohibit function pointers and
lambda objects, so the generating function for a constexpr table must be given
as a function object.

Lookup table constants were traditionally baked into C and C++ programs through
code generation. They usually look something like this:

```c
static uint32_t crc32_lut[256] = { 0x00000000, 0x77073096, 0xee0e612c, ... };
```

The generated table adds some noise to the sources to the application. It can
not be verified without its code generated. Furthermore, the code generation
complicates the build. A constant expression lookup table generated at compile
time solves these problems. The opaque values of the constant expression table
do not need to appear in the source code. The table can be validated during the
build using static assertions. The C++ compiler does all of the work, so there
is no need to involve a custom code generation tool into the build process.

The implementation of this table library uses the "index trick" to build
the initialized array values. A template argument pack is constructed with the
index values <0, 1, 2, ..., N-1>. To avoid the compiler's maximum template
instantiation depth, a divide-and-conquer approach is taken to cosntructing the
index argument pack.


Copyright
=========

This library is available under the Boost Software License.

Copyright (C) 2013 Joshua Napoli
Distributed under the Boost Software License, Version 1.0. 
(See Accompanying File LICENSE_1_0.Txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
