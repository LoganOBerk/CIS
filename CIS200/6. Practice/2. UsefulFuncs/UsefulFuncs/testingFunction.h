#ifndef TESTINGFUNCTION_H
#define TESTINGFUNCTION_H

#include <iostream>
#include <vector>
#include <list>
#include <type_traits>
#include <iterator>
#include <sstream>
#include <string>


template <typename T, typename = void>
struct is_container : std::false_type {};

template <typename T>
struct is_container<T, std::void_t<decltype(std::begin(std::declval<T>())),
    decltype(std::end(std::declval<T>()))>> : std::true_type {};


template <typename T>
typename std::enable_if<!is_container<T>::value, bool>::type
compare(const T& a, const T& b) {
    return a == b;
}


template <typename Container>
typename std::enable_if<is_container<Container>::value, bool>::type
compare(const Container& a, const Container& b) {
    if (a.size() != b.size()) {
        return false;
    }

    auto it1 = std::begin(a);
    auto it2 = std::begin(b);
    while (it1 != std::end(a) && it2 != std::end(b)) {
        if (!compare(*it1, *it2)) {
            return false;
        }
        ++it1;
        ++it2;
    }
    return true;
}


template <typename Function>
bool compare(Function&& func, const std::string& expectedOutput) {
    std::stringstream ss;

   
    std::streambuf* orig_buf = std::cout.rdbuf(ss.rdbuf());

   
    std::forward<Function>(func)();

    
    std::cout.rdbuf(orig_buf);

   
    std::string actualOutput = ss.str();

    
    return actualOutput == expectedOutput;
}

#endif
