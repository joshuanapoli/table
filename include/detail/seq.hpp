//-----------------------------------------------------------------------------
// counting sequence template argument pack
//-----------------------------------------------------------------------------
//
// Copyright (c) 2013
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef __DETAIL_SEQ_HPP__
#define __DETAIL_SEQ_HPP__

namespace detail
{
  // seq is an argument pack container for a list of indices, 0 to
  // sizeof...(Index).
  // 
  // Acknowledgement: This is based on Andrew Tomazos Fathomling's question and
  // Xeo's answer at http://stackoverflow.com/a/13073076/766900
  //
  template<std::size_t... Index> struct seq {};

  // Given seq types s1 and s2, concat<s1,s2>::type is a seq type whose
  // argument pack concatenates the argument packs of s1 and s2.
  template<class S1, class S2> struct concat;

  // Unpack the sequences and construct a new seq type concatenating the
  // sequences.
  template<std::size_t... I1, std::size_t... I2>
  struct concat<seq<I1...>, seq<I2...>> : seq<I1..., (sizeof...(I1)+I2)...>
  {
    using type = seq<I1..., (sizeof...(I1)+I2)...>;
  };
}

#endif
