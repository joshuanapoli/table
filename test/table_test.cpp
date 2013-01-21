//-----------------------------------------------------------------------------
// Examples and tests of the constant expression table library.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2013
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

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

typedef table<std::size_t, 2> test_table_type;
constexpr test_table_type test_table{times_two()};
static_assert( 0 == test_table[0], "test_table[0] should be equal 0 (2*0)" );
static_assert( 2 == test_table[1], "test_table[1] should be equal 2 (2*1)" );

static_assert( 2 == std::tuple_size<test_table_type>::value, "test table should have tuple interface" );


// Can construct a constexpr table using a class with a ctor taking an index as an argument.
struct times_three_t
{
  constexpr times_three_t( std::size_t n ) : n_( 3*n ) {}

  std::size_t n_;
};

constexpr table<times_three_t,5> times_three;
static_assert( times_three[3].n_ == 9, "times_three[3] should be 9" );
