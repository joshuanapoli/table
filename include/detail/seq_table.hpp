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
    template<typename F>
    constexpr seq_table( F f )
      : std::array<T, sizeof...(Index)>{{f(Index)...}}
    {}
  };
}

#endif
