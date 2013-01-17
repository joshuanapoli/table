//-----------------------------------------------------------------------------
// generator for counting sequence template argument pack 
//-----------------------------------------------------------------------------
//
// Copyright (c) 2013
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef __DETAIL_GEN_SEQ_HPP__
#define __DETAIL_GEN_SEQ_HPP__

#include <detail/seq.hpp>

namespace detail
{
  // gen_seq<N>::type gives a seq type whose argument pack contains the
  // sequence 0...N. Template instantiation depth is log2(N).
  // 
  // Acknowledgement: This is based on Andrew Tomazos Fathomling's question and
  // Xeo's answer at http://stackoverflow.com/a/13073076/766900
  //
  template<unsigned N> struct gen_seq : concat<typename gen_seq<N/2>::type, typename gen_seq<N-N/2>::type> { };
  template<> struct gen_seq<1> { using type = seq<0>; };
  template<> struct gen_seq<0> { using type = seq<>; };
}

#endif
