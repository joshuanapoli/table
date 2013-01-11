#define BOOST_TEST_MODULE table_test
#include <boost/test/unit_test.hpp>
#include <table.hpp>

struct times_two
{
  constexpr std::size_t operator()( std::size_t x ) { return x*2; }
};

BOOST_AUTO_TEST_CASE( table_should_generate_values )
{
  constexpr table<std::size_t, 5> actual_array{ times_two{} };

  std::array<std::size_t,5> expected_array{{0,2,4,6,8}};

  BOOST_CHECK_EQUAL_COLLECTIONS
    ( actual_array.begin(), actual_array.end()
    , expected_array.begin(), expected_array.end()
    );
}

constexpr table<std::size_t, 2> test_table{times_two()};
static_assert( 0 == test_table[0], "test_table[0] should be equal 0 (2*0)" );
static_assert( 2 == test_table[1], "test_table[1] should be equal 2 (2*1)" );
