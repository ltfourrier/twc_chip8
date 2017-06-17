//
// Created by Laurent Fourrier on 2017-06-16.
// Copyright (c) 2017 Tiwind Software. All rights reserved.
//

#ifndef TWC_CHIP8_PARSER_H
#define TWC_CHIP8_PARSER_H

#include <vector>
#include <memory.h>
#include <program.h>
#include <instruction.h>

#include "lexer.h"

namespace c8 {
    namespace detail {
        struct label_definition {
            std::string label;
            c8::vm_address addr;
        };

        class parser {
        public:
            using definition = boost::variant<boost::blank, c8::instruction, label_definition>;

            parser(std::vector<token> const &tokens);

            definition parse_next();
            bool has_next() const;
        private:
            c8::vm_address _current_addr;
            std::vector<token> const &_tokens;
            std::vector<token>::const_iterator _token_it;
        };
    }
}

#endif //TWC_CHIP8_PARSER_H
