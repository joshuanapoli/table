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

#ifndef __TABLE_HPP__
#define __TABLE_HPP__

#include <array>
#include <detail/gen_seq.hpp>
#include <detail/seq_table.hpp>

// table<T,N> is equivalent to std::array<T,N>{{ f(0), f(1), ... f(N-1) }}
template<typename T, std::size_t N>
struct table : detail::seq_table<T, typename detail::gen_seq<N>::type>
{
  constexpr table()
    : detail::seq_table<T, typename detail::gen_seq<N>::type>()
  {}

  template<typename F>
  constexpr table( F f )
    : detail::seq_table<T, typename detail::gen_seq<N>::type>( f )
  {}
};

// Tuple interface to class template array.
namespace std
{
  /// tuple_size
  template<typename _Tp> 
    class tuple_size;

  template<typename _Tp, std::size_t _Nm>
    struct tuple_size<table<_Tp, _Nm>>
    : public integral_constant<std::size_t, _Nm> { };

  /// tuple_element
  template<std::size_t _Int, typename _Tp>
    class tuple_element;

  template<std::size_t _Int, typename _Tp, std::size_t _Nm>
    struct tuple_element<_Int, table<_Tp, _Nm> >
    { typedef _Tp type; };
}

#endif
