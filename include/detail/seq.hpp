#ifndef __DETAIL_SEQ_HPP__
#define __DETAIL_SEQ_HPP__

namespace detail
{
  /* seq is an argument pack container for a list of indices, 0 to
  sizeof...(Index). */
  template<std::size_t... Index> struct seq {};

  /* Given seq types s1 and s2, concat<s1,s2>::type is a seq type whose
  argument pack concatenates the argument packs of s1 and s2. */
  template<class S1, class S2> struct concat;

  /* Unpack the sequences and construct a new seq type concatenating the
  sequences. */
  template<std::size_t... I1, std::size_t... I2>
  struct concat<seq<I1...>, seq<I2...>> : seq<I1..., (sizeof...(I1)+I2)...>
  {
    using type = seq<I1..., (sizeof...(I1)+I2)...>;
  };
}

#endif
