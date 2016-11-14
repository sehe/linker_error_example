#ifndef KYLE_TYPES_DEF_HPP
#define KYLE_TYPES_DEF_HPP

#include "types.hpp"


namespace client { namespace parser {
namespace x3 = boost::spirit::x3;


typedef x3::rule<struct lambda_type_class, ast::LambdaType> lambda_type_type;


const class_type_type class_type = "class_type";
const lambda_type_type lambda_type = "lambda_type";
const type_type type = "type";

auto const identifier = +x3::alnum;

auto const type_def =
        (lambda_type | class_type);

auto const lambda_type_def =
        ("(" > -(type % ",") > ")" > "=>" > type)
        | x3::repeat(1)[class_type] >> "=>" > type;


auto const class_type_def =
        (identifier % "::") >> -("<" > type % "," > ">");


BOOST_SPIRIT_DEFINE(
        lambda_type,
        class_type,
        type
)

namespace {
    template <typename Seq, size_t N>
        using field_at = boost::fusion::basic_iterator<boost::fusion::struct_iterator_tag, boost::fusion::random_access_traversal_tag, Seq, N>;
    template <typename Seq, size_t N, size_t M>
        using fields   = boost::fusion::iterator_range<field_at<Seq, N>, field_at<Seq, M> >;

    using Attributes = fields<client::ast::VariableDec, 1, 2>;
    using Context  = x3::context<x3::skipper_tag, x3::char_class<boost::spirit::char_encoding::ascii, x3::space_tag> const, x3::unused_type>;
}

template bool parse_rule<std::string::const_iterator, Context, fields<client::ast::VariableDec, 1, 2> >(
    decltype(type),
    std::string::const_iterator &, 
    std::string::const_iterator const &,
    Context const &,
    Attributes &);

}}


#endif //KYLE_TYPES_DEF_HPP
