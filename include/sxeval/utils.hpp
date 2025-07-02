#ifndef SXEVAL_UTILS_HPP
#define SXEVAL_UTILS_HPP

#include <type_traits>
#include <cmath>
#include <stdexcept>
#include <cstdio>

#define SXEVAL_PI 3.14159265358979323846


/* DEFINITIONS */

namespace sxeval {

template<typename T>
T StringToType(const std::string& s);

template<typename T>
inline bool Greater(const T& a, const T& b) {
    return a > b;
}

template<typename T>
inline bool Equal(const T& a, const T& b) {
    if constexpr (std::is_integral_v<T>) {
        return a == b;
    } else if constexpr (std::is_floating_point_v<T>) {
        return std::abs(a - b) <= std::numeric_limits<T>::epsilon();
    } else {
        static_assert(std::is_integral_v<T> || std::is_floating_point_v<T>,
            "Unsupported type for equal");
    }
}

template<typename T>
inline bool NotEqual(const T& a, const T& b) {
    return !Equal(a, b);
}

template<typename T>
inline bool GreaterOrEqual(const T& a, const T& b) {
    return Greater(a, b) || Equal(a, b);
}

template<typename T>
inline bool Less(const T& a, const T& b) {
    return !GreaterOrEqual(a, b);
}

template<typename T>
inline bool LessOrEqual(const T& a, const T& b) {
    return Less(a, b) || Equal(a, b);
}

template<typename T>
inline bool TypeToBool(const T& val) {
    if constexpr (std::is_integral_v<T>) {
        return val != 0;
    } else if constexpr (std::is_floating_point_v<T>) {
        return std::abs(val) > std::numeric_limits<T>::epsilon();
    } else {
        static_assert(std::is_integral_v<T> || std::is_floating_point_v<T>,
            "Unsupported type for TypeToBool");
    }
}

template<typename T>
inline bool LogicalAnd(const T& a, const T& b) {
    return TypeToBool(a) && TypeToBool(b);
}

template<typename T>
inline bool LogicalOr(const T& a, const T& b) {
    return TypeToBool(a) || TypeToBool(b);
}

template<typename T>
inline bool LogicalNot(const T& a) {
    return !TypeToBool(a);
}

template<typename T>
inline bool LogicalXor(const T& a, const T& b) {
    return TypeToBool(a) != TypeToBool(b);
}

template<typename T>
inline bool LogicalNand(const T& a, const T& b) {
    return !LogicalAnd(a, b);
}

template<typename T>
inline bool LogicalNor(const T& a, const T& b) {
    return !LogicalOr(a, b);
}

template<typename T>
inline bool LogicalXnor(const T& a, const T& b) {
    return !LogicalXor(a, b);
}

template<typename T>
inline T Modulo(const T& a, const T& b) {
    if constexpr (std::is_integral_v<T>) {
        return a % b;
    } else if constexpr (std::is_floating_point_v<T>) {
        return std::fmod(a, b);
    } else {
        static_assert(std::is_integral_v<T> || std::is_floating_point_v<T>,
            "Unsupported type for modulo");
    }
}

template<typename T>
inline T Absolute(const T& a) {
    if constexpr (std::is_unsigned_v<T>) {
        return a;
    } else if constexpr (std::is_integral_v<T>) {
        return std::abs(a);
    } else if constexpr (std::is_floating_point_v<T>) {
        return std::fabs(a);
    } else {
        static_assert(std::is_integral_v<T> || std::is_floating_point_v<T>,
            "Unsupported type for absolute");
    }
}

} /* namespace sxeval */


/* IMPLEMENTATIONS */

template<>
inline int sxeval::StringToType<int>(const std::string& s) {
    int res;
    if (sscanf(s.c_str(), "%d", &res) != 1) {
        throw std::invalid_argument("Invalid int string");
    }
    return res;
}

template<>
inline signed char sxeval::StringToType<signed char>(const std::string& s) {
    signed char res;
    if (sscanf(s.c_str(), "%hhd", &res) != 1) {
        throw std::invalid_argument("Invalid signed char string");
    }
    return res;
}

template<>
inline short int sxeval::StringToType<short int>(const std::string& s) {
    short int res;
    if (sscanf(s.c_str(), "%hd", &res) != 1) {
        throw std::invalid_argument("Invalid short int string");
    }
    return res;
}

template<>
inline long int sxeval::StringToType<long int>(const std::string& s) {
    long int res;
    if (sscanf(s.c_str(), "%ld", &res) != 1) {
        throw std::invalid_argument("Invalid long int string");
    }
    return res;
}

template<>
inline unsigned int sxeval::StringToType<unsigned int>(const std::string& s) {
    unsigned int res;
    if (sscanf(s.c_str(), "%u", &res) != 1) {
        throw std::invalid_argument("Invalid unsigned int string");
    }
    return res;
}

template<>
inline unsigned char sxeval::StringToType<unsigned char>(const std::string& s) {
    unsigned char res;
    if (sscanf(s.c_str(), "%hhu", &res) != 1) {
        throw std::invalid_argument("Invalid unsigned char string");
    }
    return res;
}

template<>
inline unsigned long int sxeval::StringToType<unsigned long int>(
    const std::string& s)
{
    unsigned long int res;
    if (sscanf(s.c_str(), "%lu", &res) != 1) {
        throw std::invalid_argument("Invalid unsigned long int string");
    }
    return res;
}

template<>
inline float sxeval::StringToType<float>(const std::string& s) {
    float res;
    if (sscanf(s.c_str(), "%f", &res) != 1) {
        throw std::invalid_argument("Invalid float string");
    }
    return res;
}

template<>
inline double sxeval::StringToType<double>(const std::string& s) {
    double res;
    if (sscanf(s.c_str(), "%lf", &res) != 1) {
        throw std::invalid_argument("Invalid double string");
    }
    return res;
}

template<>
inline long double sxeval::StringToType<long double>(const std::string& s)
{
    long double res;
    if (sscanf(s.c_str(), "%Lf", &res) != 1) {
        throw std::invalid_argument("Invalid long double string");
    }
    return res;
}

#endif /* SXEVAL_UTILS_HPP */
