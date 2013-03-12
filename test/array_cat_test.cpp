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

#define BOOST_TEST_MODULE array_cat_test
#include <boost/test/unit_test.hpp>
#include <array_cat.hpp>

BOOST_AUTO_TEST_CASE( array_cat_should_join_arrays )
{
  typedef std::array<int,2> array2_type;

  constexpr auto actual_array = array_cat(array2_type{{1,2}},array2_type{{3,4}});
  constexpr std::array<int,4> expected_array{{1,2,3,4}};

  BOOST_CHECK_EQUAL_COLLECTIONS
    ( actual_array.begin(), actual_array.end()
    , expected_array.begin(), expected_array.end()
    );
}
