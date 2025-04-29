#ifndef SXEVAL_UTILS_HPP
#define SXEVAL_UTILS_HPP

#define SXEVAL_EPSILON 0.000001

#include <type_traits>


/* DEFINITIONS */

namespace sxeval {

template<typename T>
T StringToType(const char* str);

template<typename T>
inline bool Greater(const T& a, const T& b) {
    if constexpr (std::is_integral_v<T>) {
        return a > b;
    } else if constexpr (std::is_floating_point_v<T>) {
        return (a - b) > static_cast<T>(SXEVAL_EPSILON);
    } else {
        static_assert(std::is_integral_v<T> || std::is_floating_point_v<T>,
            "Unsupported type for greater");
    }
}

template<typename T>
inline bool Less(const T& a, const T& b) {
    return !Greater(b, a);
}

template<typename T>
inline bool Equal(const T& a, const T& b) {
    return !Greater(a, b) && !Greater(b, a);
}

template<typename T>
inline bool NotEqual(const T& a, const T& b) {
    return !Equal(a, b);
}

template<typename T>
inline bool LessOrEqual(const T& a, const T& b) {
    return Less(a, b) || Equal(a, b);
}

template<typename T>
inline bool GreaterOrEqual(const T& a, const T& b) {
    return Greater(a, b) || Equal(a, b);
}

template<typename T>
inline bool TypeToBool(const T& val) {
    if constexpr (std::is_integral_v<T>) {
        return val != 0;
    } else if constexpr (std::is_floating_point_v<T>) {
        return std::abs(val) > static_cast<T>(SXEVAL_EPSILON);
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

} /* namespace sxeval */


/* IMPLEMENTATIONS */

template<>
inline int sxeval::StringToType<int>(const char* str) {
    int res;
    if (sscanf(str, "%d", &res) != 1) {
        throw std::invalid_argument("Invalid integer string");
    }
    return res;
}

template<>
inline signed char sxeval::StringToType<signed char>(const char* str) {
    signed char res;
    if (sscanf(str, "%hhd", &res) != 1) {
        throw std::invalid_argument("Invalid signed char string");
    }
    return res;
}

template<>
inline short int sxeval::StringToType<short int>(const char* str) {
    short int res;
    if (sscanf(str, "%hd", &res) != 1) {
        throw std::invalid_argument("Invalid short int string");
    }
    return res;
}

template<>
inline long int sxeval::StringToType<long int>(const char* str) {
    long int res;
    if (sscanf(str, "%ld", &res) != 1) {
        throw std::invalid_argument("Invalid long int string");
    }
    return res;
}

template<>
inline unsigned int sxeval::StringToType<unsigned int>(const char* str) {
    unsigned int res;
    if (sscanf(str, "%u", &res) != 1) {
        throw std::invalid_argument("Invalid unsigned int string");
    }
    return res;
}

template<>
inline unsigned char sxeval::StringToType<unsigned char>(const char* str) {
    unsigned char res;
    if (sscanf(str, "%hhu", &res) != 1) {
        throw std::invalid_argument("Invalid unsigned char string");
    }
    return res;
}

template<>
inline unsigned long int sxeval::StringToType<unsigned long int>(
    const char* str)
{
    unsigned long int res;
    if (sscanf(str, "%lu", &res) != 1) {
        throw std::invalid_argument("Invalid unsigned long int string");
    }
    return res;
}

template<>
inline float sxeval::StringToType<float>(const char* str) {
    float res;
    if (sscanf(str, "%f", &res) != 1) {
        throw std::invalid_argument("Invalid float string");
    }
    return res;
}

template<>
inline double sxeval::StringToType<double>(const char* str) {
    double res;
    if (sscanf(str, "%lf", &res) != 1) {
        throw std::invalid_argument("Invalid double string");
    }
    return res;
}

template<>
inline long double sxeval::StringToType<long double>(const char* str) {
    long double res;
    if (sscanf(str, "%Lf", &res) != 1) {
        throw std::invalid_argument("Invalid long double string");
    }
    return res;
}

#endif /* SXEVAL_UTILS_HPP */
