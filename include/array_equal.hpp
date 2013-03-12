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

#ifndef __ARRAY_EQUAL_HPP__
#define __ARRAY_EQUAL_HPP__

#include <array_equal_predicate.hpp>

template<typename T0, std::size_t N0, typename T1, std::size_t N1>
constexpr bool array_equal(const std::array<T0,N0>& a0, const std::array<T1,N1>& a1)
{
  return array_equal_predicate<T0,N0,T1,N1>( a0, a1 )();
}

#endif
