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

#ifndef __ARRAY_EQUAL_PREDICATE_HPP__
#define __ARRAY_EQUAL_PREDICATE_HPP__

#include <array>

template<typename T0, std::size_t N0, typename T1, std::size_t N1>
class array_equal_predicate
{
public:
  typedef bool result_type;

  constexpr array_equal_predicate(const std::array<T0,N0>&, const std::array<T1,N1>&) {}

  constexpr bool operator()() { return false; }
};

template<typename T0, typename T1, std::size_t N>
class array_equal_predicate<T0,N,T1,N>
{
public:
  typedef bool result_type;

  constexpr array_equal_predicate(const std::array<T0,N>& a0, const std::array<T1,N>& a1)
    : a0_(a0)
    , a1_(a1)
  {}

  constexpr bool operator()(std::size_t index = 0)
  {
    return index == N || ( a0_[index] == a1_[index] && (*this)(index+1) );
  }

private:
  const std::array<T0,N>& a0_;
  const std::array<T1,N>& a1_;
};

#endif
