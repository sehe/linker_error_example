#include "config.hpp"
#include "types_def.hpp"

namespace client {namespace parser {

BOOST_SPIRIT_INSTANTIATE(type_type, iterator_type, context_type);

BOOST_SPIRIT_INSTANTIATE(class_type_type, iterator_type, context_type);

}}


namespace client {

const parser::class_type_type& class_type()
{
    return parser::class_type;
}
const parser::type_type& type()
{
    return parser::type;
}

}