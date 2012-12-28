#ifndef __TABLE_HPP__
#define __TABLE_HPP__

#include <array>
#include <detail/gen_seq.hpp>
#include <detail/seq_table.hpp>

// table<T,N> is equivalent to std::array<T,N>{{ f(0), f(1), ... f(N-1) }}
template<typename T, std::size_t N>
struct table : detail::seq_table<T, typename detail::gen_seq<N>::type>
{
  template<typename F>
  constexpr table( F f )
    : detail::seq_table<T, typename detail::gen_seq<N>::type>( f )
  {}
};

#endif
