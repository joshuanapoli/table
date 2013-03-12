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

#ifndef __ARRAY_CAT_HPP__
#define __ARRAY_CAT_HPP__

#include <array_cat_element.hpp>
#include <table.hpp>

template<typename T, std::size_t N0, std::size_t N1>
constexpr std::array<T,N0+N1> array_cat(const std::array<T,N0>& a0, const std::array<T,N1>& a1)
{
  return table<T,N0+N1>( array_cat_element<T,N0,N1>(a0, a1) );
}

template<typename T, std::size_t N0, std::size_t N1, std::size_t N2>
constexpr std::array<T,N0+N1+N2> array_cat(const std::array<T,N0>& a0, const std::array<T,N1>& a1, const std::array<T,N2>& a2)
{
  return array_cat( array_cat( a0, a1 ), a2 );
}

#endif
