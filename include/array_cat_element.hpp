//-----------------------------------------------------------------------------
// constant expression table library
//-----------------------------------------------------------------------------
//
// Copyright (c) 2013
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef __ARRAY_CAT_ELEMENT_HPP__
#define __ARRAY_CAT_ELEMENT_HPP__

#include <array>

// array_cat_element is a function object that looks up an element by index in
// the concatenation of two arrays.
template<typename T, std::size_t N0, std::size_t N1>
class array_cat_element
{
public:
  constexpr array_cat_element(const std::array<T,N0>& a0, const std::array<T,N1>& a1)
    : a0_( a0 )
    , a1_( a1 )
  {}

  constexpr T operator()(std::size_t index)
  {
    return index < N0 ? a0_.at(index) : a1_.at(index-N0);
  }

private:
  const std::array<T,N0>& a0_;
  const std::array<T,N1>& a1_;
};

#endif
