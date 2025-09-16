#ifndef SXEVAL_UTILS_HPP
#define SXEVAL_UTILS_HPP

#include <type_traits>
#include <cmath>
#include <stdexcept>
#include <cstdio>

#define SXEVAL_PI 3.14159265358979323846


/* DEFINITIONS */

namespace sxeval {

/**
 * @brief Convert a string to a type T.
 * @tparam T The type to convert to.
 * @param s The string to convert.
 * @return The converted value of type T.
 * @throws std::invalid_argument if the string cannot be converted to the type T.
 */
template<typename T>
T StringToType(const std::string& s);

/**
 * @brief Check if a is greater than b.
 * @tparam T The type of the values.
 * @param a The first value.
 * @param b The second value.
 * @return True if a is greater than b, false otherwise.
 */
template<typename T>
inline bool Greater(const T& a, const T& b) {
    return a > b;
}

/**
 * @brief Check if a is equal to b.
 * @tparam T The type of the values.
 * @param a The first value.
 * @param b The second value.
 * @return True if a is equal to b, false otherwise.
 */
template<typename T>
inline typename std::enable_if<std::is_integral<T>::value, bool>::type
Equal(const T& a, const T& b) {
        return a == b;
}

/**
 * @brief Check if a is equal to b.
 * @tparam T The type of the values.
 * @param a The first value.
 * @param b The second value.
 * @return True if a is equal to b, false otherwise.
 */
template<typename T>
inline typename std::enable_if<std::is_floating_point<T>::value, bool>::type
Equal(const T& a, const T& b) {
    return std::abs(a - b) <= std::numeric_limits<T>::epsilon();
}

/**
 * @brief Check if a is not equal to b.
 * @tparam T The type of the values.
 * @param a The first value.
 * @param b The second value.
 * @return True if a is not equal to b, false otherwise.
 */
template<typename T>
inline bool NotEqual(const T& a, const T& b) {
    return !Equal<T>(a, b);
}

/**
 * @brief Check if a is greater than or equal to b.
 * @tparam T The type of the values.
 * @param a The first value.
 * @param b The second value.
 * @return True if a is greater than or equal to b, false otherwise.
 */
template<typename T>
inline bool GreaterOrEqual(const T& a, const T& b) {
    return Greater<T>(a, b) || Equal<T>(a, b);
}

/**
 * @brief Check if a is less than b.
 * @tparam T The type of the values.
 * @param a The first value.
 * @param b The second value.
 * @return True if a is less than b, false otherwise.
 */
template<typename T>
inline bool Less(const T& a, const T& b) {
    return !GreaterOrEqual<T>(a, b);
}

/**
 * @brief Check if a is less than or equal to b.
 * @tparam T The type of the values.
 * @param a The first value.
 * @param b The second value.
 * @return True if a is less than or equal to b, false otherwise.
 */
template<typename T>
inline bool LessOrEqual(const T& a, const T& b) {
    return Less<T>(a, b) || Equal<T>(a, b);
}

/**
 * @brief Convert a type T to a boolean value.
 * @tparam T The type to convert.
 * @param val The value to convert.
 * @return True if the value is non-zero, false otherwise.
 * @note For floating point types, it checks if the absolute value is greater than
 * the machine epsilon.
 */
template<typename T>
inline typename std::enable_if<std::is_integral<T>::value, bool>::type
TypeToBool(const T& val) {
    return val != 0;
}

/**
 * @brief Convert a type T to a boolean value.
 * @tparam T The type to convert.
 * @param val The value to convert.
 * @return True if the value is non-zero, false otherwise.
 * @note For floating point types, it checks if the absolute value is greater than
 * the machine epsilon.
 */
template<typename T>
inline typename std::enable_if<std::is_floating_point<T>::value, bool>::type
TypeToBool(const T& val) {
    return std::abs(val) > std::numeric_limits<T>::epsilon();
}

/**
 * @brief Perform a logical and operations on types T.
 * @tparam T The type of the values.
 * @param a The first value.
 * @param b The second value.
 * @return The result of the logical and operation.
 */
template<typename T>
inline bool LogicalAnd(const T& a, const T& b) {
    return TypeToBool<T>(a) && TypeToBool<T>(b);
}

/**
 * @brief Perform a logical or operation on types T.
 * @tparam T The type of the values.
 * @param a The first value.
 * @param b The second value.
 * @return The result of the logical or operation.
 */
template<typename T>
inline bool LogicalOr(const T& a, const T& b) {
    return TypeToBool<T>(a) || TypeToBool<T>(b);
}

/**
 * @brief Perform a logical not operation on type T.
 * @tparam T The type of the value.
 * @param a The value to negate.
 * @return The negated value.
 */
template<typename T>
inline bool LogicalNot(const T& a) {
    return !TypeToBool<T>(a);
}

/**
 * @brief Perform a logical xor operation on types T.
 * @tparam T The type of the values.
 * @param a The first value.
 * @param b The second value.
 * @return True if a and b are different, false otherwise.
 */
template<typename T>
inline bool LogicalXor(const T& a, const T& b) {
    return TypeToBool<T>(a) != TypeToBool<T>(b);
}

/**
 * @brief Perform a logical nand operation on types T.
 * @tparam T The type of the values.
 * @param a The first value.
 * @param b The second value.
 * @return True if a and b are not both true, false otherwise.
 */
template<typename T>
inline bool LogicalNand(const T& a, const T& b) {
    return !LogicalAnd<T>(a, b);
}

/**
 * @brief Perform a logical nor operation on types T.
 * @tparam T The type of the values.
 * @param a The first value.
 * @param b The second value.
 * @return True if a and b are not both true, false otherwise.
 */
template<typename T>
inline bool LogicalNor(const T& a, const T& b) {
    return !LogicalOr<T>(a, b);
}

/**
 * @brief Perform a logical xnor operation on types T.
 * @tparam T The type of the values.
 * @param a The first value.
 * @param b The second value.
 * @return True if a and b are both true or both false, false otherwise.
 */
template<typename T>
inline bool LogicalXnor(const T& a, const T& b) {
    return !LogicalXor<T>(a, b);
}

/**
 * @brief Perform a modulo operation on types T.
 * @tparam T The type of the values.
 * @param a The first value.
 * @param b The second value.
 * @return The result of the modulo operation.
 * @throws std::invalid_argument if b is zero.
 */
template<typename T>
inline typename std::enable_if<std::is_integral<T>::value, T>::type
Modulo(const T& a, const T& b) {
    return a % b;
}

/**
 * @brief Perform a modulo operation on types T.
 * @tparam T The type of the values.
 * @param a The first value.
 * @param b The second value.
 * @return The result of the modulo operation.
 * @throws std::invalid_argument if b is zero.
 */
template<typename T>
inline typename std::enable_if<std::is_floating_point<T>::value, T>::type
Modulo(const T& a, const T& b) {
    return std::fmod(a, b);
}

/**
 * @brief Perform an absolute value operation on types T.
 * @tparam T The type of the value.
 * @param a The value to get the absolute value of.
 * @return The absolute value of a.
 * @note For unsigned types, it returns the value itself. For integral types,
 * it uses std::abs, and for floating point types, it uses std::fabs.
 */
template<typename T>
inline typename std::enable_if<std::is_unsigned<T>::value, T>::type
Absolute(const T& a) {
    return a;
}

/**
 * @brief Perform an absolute value operation on types T.
 * @tparam T The type of the value.
 * @param a The value to get the absolute value of.
 * @return The absolute value of a.
 * @note For unsigned types, it returns the value itself. For integral types,
 * it uses std::abs, and for floating point types, it uses std::fabs.
 */
template<typename T>
inline typename std::enable_if<std::is_integral<T>::value, T>::type
Absolute(const T& a) {
    return std::abs(a);
}

/**
 * @brief Perform an absolute value operation on types T.
 * @tparam T The type of the value.
 * @param a The value to get the absolute value of.
 * @return The absolute value of a.
 * @note For unsigned types, it returns the value itself. For integral types,
 * it uses std::abs, and for floating point types, it uses std::fabs.
 */
template<typename T>
inline typename std::enable_if<std::is_floating_point<T>::value, T>::type
Absolute(const T& a) {
    return std::fabs(a);
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
