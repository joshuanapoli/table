#ifndef __DETAIL_GEN_SEQ_HPP__
#define __DETAIL_GEN_SEQ_HPP__

#include <detail/seq.hpp>

namespace detail
{
  /* gen_seq<N>::type gives a seq type whose argument pack contains the
  sequence 0...N. Template instantiation depth is log2(N). Thanks to Xeo.
  http://stackoverflow.com/a/13073076/766900 */
  template<unsigned N> struct gen_seq : concat<typename gen_seq<N/2>::type, typename gen_seq<N-N/2>::type> { };
  template<> struct gen_seq<1> { using type = seq<0>; };
  template<> struct gen_seq<0> { using type = seq<>; };
}

#endif
