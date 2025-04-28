cmake_minimum_required(VERSION 3.10)

set(FLAGS_FIX_LIB_COMMON -Wno-error=strict-prototypes
    -Wno-error=missing-prototypes -Wno-error=implicit-fallthrough
    -Wno-error=sign-conversion -Wno-error=sign-compare -Wno-error=padded)
set(FLAGS_FIX_LIB_GNU ${FLAGS_FIX_LIB_COMMON} -Wno-error=type-limits)
set(FLAGS_FIX_LIB_CLANG ${FLAGS_FIX_LIB_COMMON} -Wno-error=documentation-html
    -Wno-error=missing-variable-declarations
    -Wno-error=tautological-unsigned-zero-compare
    -Wno-error=covered-switch-default)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SUBDIRS RELATIVE ${CMAKE_SOURCE_DIR} */)
foreach(SUBDIR ${SUBDIRS})
    if (IS_DIRECTORY ${CMAKE_SOURCE_DIR}/${SUBDIR})
        file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/${SUBDIR}/*.cpp
            ${CMAKE_SOURCE_DIR}/${SUBDIR}/*.hpp)
        if (SOURCES)
            string(REPLACE "/" "_" TARGET_NAME ${SUBDIR})
            message(STATUS "Adding example: ${TARGET_NAME}")

            # Executable
            add_executable(${TARGET_NAME} ${SOURCES})

			# Flags
			target_compile_options(${TARGET_NAME} PRIVATE
			$<$<CXX_COMPILER_ID:AppleClang>:-O3 -Wall -Wextra -Werror
				-Wfloat-equal -Wundef -Wcast-align -Wwrite-strings -Wconversion
				-Wunreachable-code -Wpedantic -Wshadow -Wwrite-strings
				-Wcast-qual -Wstrict-aliasing -Wpointer-arith -Wformat=2
				-Weverything -Wextra-semi -Wmissing-prototypes
				-Wunreachable-code-aggressive -Wimplicit-fallthrough
				-Wloop-analysis -Wrange-loop-analysis -Wcomma -Wmove
				-Wconditional-uninitialized -Wassign-enum
				-Wunused-exception-parameter -Wcovered-switch-default
				-Wno-error=c++98-compat -Wno-error=c++98-compat-pedantic
				${FLAGS_FIX_LIB_CLANG}>
			$<$<CXX_COMPILER_ID:GNU>:-O3 -Wall -Wextra -Werror -Wfloat-equal
				-Wundef -Wcast-align -Wwrite-strings -Wconversion
				-Wunreachable-code -Wpedantic -Wshadow -Wwrite-strings
				-Wcast-qual -Wstrict-aliasing -Wpointer-arith -Wformat=2
				-Wimplicit-fallthrough
				${FLAGS_FIX_LIB_GNU}>
			)
			if(SXEVAL_DEBUG)
				target_compile_options(${TARGET_NAME} PRIVATE -DSXEVAL_DEBUG)
			endif()

			# Link Libraries
			target_link_libraries(${TARGET_NAME} PRIVATE sxeval)
        endif()
    endif()
endforeach()
