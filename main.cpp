#include <iostream>
#include "example.hpp"

template<typename Parser, typename Attribute>
bool test(const std::string& str, Parser&& p, Attribute&& attr)
{
    using iterator_type = std::string::const_iterator;
    iterator_type in = str.begin();
    iterator_type end = str.end();

    bool ret = boost::spirit::x3::phrase_parse(in, end, p, boost::spirit::x3::ascii::space, attr);
    ret &= (in == end);
    return ret;

}

int main()
{
    client::ast::VariableDec attr;
    std::string const input("var foo : foo<bar, baz<bahama>>");

    try {
        std::cout << test(input, client::var_dec() , attr);
    } catch(boost::spirit::x3::expectation_failure<std::string::const_iterator> const& e) {
        std::cout << "Expected: " << e.which() << " at '" << std::string(e.where(), input.end()) << "'\n";
        return 255;
    }
}
