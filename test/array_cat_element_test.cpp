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

#define BOOST_TEST_MODULE array_cat_element_test
#include <boost/test/unit_test.hpp>
#include <array_cat_element.hpp>

BOOST_AUTO_TEST_CASE( array_cat_element_function_operator_should_generate_concatenated_sequence )
{
  typedef std::array<int,2> array2_type;
  array2_type a{{1,2}};
  array2_type b{{3,4}};
  array_cat_element<int,2,2> cat{a,b};
  BOOST_CHECK_EQUAL(cat(0),1);
  BOOST_CHECK_EQUAL(cat(1),2);
  BOOST_CHECK_EQUAL(cat(2),3);
  BOOST_CHECK_EQUAL(cat(3),4);
}
