//-----------------------------------------------------------------------------
// map a counting sequence template argument pack to an array initializer
//-----------------------------------------------------------------------------
//
// Copyright (c) 2013
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef __DETAIL_SEQ_TABLE_HPP__
#define __DETAIL_SEQ_TABLE_HPP__

namespace detail
{
  template<typename T, typename Seq>
  struct seq_table;
  
  template<typename T, std::size_t... Index>
  struct seq_table<T, seq<Index...>> : std::array<T, sizeof...(Index)>
  {
  public:
    constexpr seq_table()
      : std::array<T, sizeof...(Index)>{{T(Index)...}}
    {}

    template<typename F>
    constexpr seq_table( F f )
      : std::array<T, sizeof...(Index)>{{f(Index)...}}
    {}
  };
}

#endif
