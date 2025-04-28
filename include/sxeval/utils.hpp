#ifndef SXEVAL_UTILS_HPP
#define SXEVAL_UTILS_HPP


/* DEFINITIONS */

namespace sxeval {

template<typename T>
T stringToType(const char* str);

} /* namespace sxeval */


/* IMPLEMENTATIONS */

template<>
inline int sxeval::stringToType<int>(const char* str) {
    int res;
    if (sscanf(str, "%d", &res) != 1) {
        throw std::invalid_argument("Invalid integer string");
    }
    return res;
}

template<>
inline signed char sxeval::stringToType<signed char>(const char* str) {
    signed char res;
    if (sscanf(str, "%hhd", &res) != 1) {
        throw std::invalid_argument("Invalid signed char string");
    }
    return res;
}

template<>
inline short int sxeval::stringToType<short int>(const char* str) {
    short int res;
    if (sscanf(str, "%hd", &res) != 1) {
        throw std::invalid_argument("Invalid short int string");
    }
    return res;
}

template<>
inline long int sxeval::stringToType<long int>(const char* str) {
    long int res;
    if (sscanf(str, "%ld", &res) != 1) {
        throw std::invalid_argument("Invalid long int string");
    }
    return res;
}

template<>
inline unsigned int sxeval::stringToType<unsigned int>(const char* str) {
    unsigned int res;
    if (sscanf(str, "%u", &res) != 1) {
        throw std::invalid_argument("Invalid unsigned int string");
    }
    return res;
}

template<>
inline unsigned char sxeval::stringToType<unsigned char>(const char* str) {
    unsigned char res;
    if (sscanf(str, "%hhu", &res) != 1) {
        throw std::invalid_argument("Invalid unsigned char string");
    }
    return res;
}

template<>
inline unsigned long int sxeval::stringToType<unsigned long int>(const char* str) {
    unsigned long int res;
    if (sscanf(str, "%lu", &res) != 1) {
        throw std::invalid_argument("Invalid unsigned long int string");
    }
    return res;
}

template<>
inline float sxeval::stringToType<float>(const char* str) {
    float res;
    if (sscanf(str, "%f", &res) != 1) {
        throw std::invalid_argument("Invalid float string");
    }
    return res;
}

template<>
inline double sxeval::stringToType<double>(const char* str) {
    double res;
    if (sscanf(str, "%lf", &res) != 1) {
        throw std::invalid_argument("Invalid double string");
    }
    return res;
}

template<>
inline long double sxeval::stringToType<long double>(const char* str) {
    long double res;
    if (sscanf(str, "%Lf", &res) != 1) {
        throw std::invalid_argument("Invalid long double string");
    }
    return res;
}

#endif /* SXEVAL_UTILS_HPP */
