#include "types.cpp"
#include "example_def.hpp"
#include "config.hpp"

namespace client { namespace parser {

BOOST_SPIRIT_INSTANTIATE(var_dec_type, iterator_type, context_type)

}}

namespace client {

const parser::var_dec_type& var_dec()
{
    return parser::var_dec;
}

}
