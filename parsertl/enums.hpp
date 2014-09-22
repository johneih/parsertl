// enums.hpp
// Copyright (c) 2014 Ben Hanson (http://www.benhanson.net/)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file licence_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#ifndef PARSERTL_ENUMS_HPP
#define PARSERTL_ENUMS_HPP

namespace parsertl
{
enum action {error, shift, reduce, go_to, accept};
enum error_type {unknown_token, syntax_error};
}

#endif