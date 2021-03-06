// state_machine.hpp
// Copyright (c) 2014 Ben Hanson (http://www.benhanson.net/)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file licence_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#ifndef PARSERTL_STATE_MACHINE_HPP
#define PARSERTL_STATE_MACHINE_HPP

#include "enums.hpp"
#include <deque>
#include <map>
#include <vector>

namespace parsertl
{
    struct state_machine
    {
        struct entry
        {
            action _action;
            std::size_t _param;

            entry() :
                _action(error),
                _param(syntax_error)
            {
            }

            entry(const action action_, const std::size_t param_) :
                _action(action_),
                _param(param_)
            {
            }

            void clear()
            {
                _action = error;
                _param = syntax_error;
            }
        };

        typedef std::vector<entry> table;
        typedef std::vector<std::size_t> size_t_vector;
        typedef std::pair<std::size_t, size_t_vector> size_t_size_t_pair;
        typedef std::deque<size_t_size_t_pair> rules;

        table _table;
        std::size_t _columns;
        std::size_t _rows;
        rules _rules;
        size_t_vector _new_to_old;

        state_machine() :
            _columns(0),
            _rows(0)
        {
        }

        void clear()
        {
            _table.clear();
            _columns = _rows = 0;
            _rules.clear();
            _new_to_old.clear();
        }
    };
}

#endif
