cmake_minimum_required(VERSION 3.10)

set(TARGET_NAME "benchmark")

# Sources
file(GLOB_RECURSE SOURCES src/*.cpp src/*.hpp)

# Executable
add_executable(${TARGET_NAME} ${SOURCES})

# Flags
set(CHIBI_FLAGS -Wno-undef -Wno-old-style-cast -Wno-zero-as-null-pointer-constant)
set(GUILE_FLAGS -Wno-sign-conversion)
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
	-Wno-c++98-compat -Wno-c++98-compat-pedantic
	-Wno-padded -Wno-cast-function-type-strict
	-Wno-cast-function-type-mismatch -Wno-exit-time-destructors
	-Wno-global-constructors
	${CHIBI_FLAGS} ${GUILE_FLAGS}>
$<$<CXX_COMPILER_ID:GNU>:-O3 -Wall -Wextra -Werror -Wfloat-equal
	-Wundef -Wcast-align -Wwrite-strings -Wconversion
	-Wunreachable-code -Wpedantic -Wshadow -Wwrite-strings
	-Wcast-qual -Wstrict-aliasing -Wpointer-arith -Wformat=2
	-Wimplicit-fallthrough -Wno-padded -Wno-cast-function-type-strict
	-Wno-cast-function-type-mismatch -Wno-exit-time-destructors
	-Wno-global-constructors
	${CHIBI_FLAGS} ${GUILE_FLAGS}>
)

# Download/Update librairies if needed
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
	# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
		message(STATUS "Downloading git submodules...")
		execute_process(
			COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
			WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
		)
    endif()
endif()
if(
	NOT EXISTS "${PROJECT_SOURCE_DIR}/benchmark/others/tinyexpr"
	OR NOT EXISTS "${PROJECT_SOURCE_DIR}/benchmark/others/chibi-scheme"
)
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please download submodules and try again.")
endif()

# Libraries
find_package(PkgConfig REQUIRED)
pkg_check_modules(GUILE REQUIRED guile-3.0)
target_include_directories(${TARGET_NAME} PRIVATE ${GUILE_INCLUDE_DIRS})
target_link_directories(${TARGET_NAME} PRIVATE ${GUILE_LIBRARY_DIRS})

add_subdirectory(others/chibi-scheme)

target_link_libraries(${TARGET_NAME} PRIVATE  ${GUILE_LIBRARIES} libchibi-scheme sxeval)
