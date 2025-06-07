#include <iostream>
#include <print>
#include "Problems/problem30.cpp"

int main() {
    std::print("{}", problem30::findSubstring("barfoofoobarthefoobarman", { "bar", "foo", "the" }));
    return 0;
}