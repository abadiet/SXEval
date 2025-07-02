cmake_minimum_required(VERSION 3.10)

# Download/Update librairies if needed
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
	# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodules update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --remote --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --remote --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()
if(
	NOT EXISTS "${PROJECT_SOURCE_DIR}/benchmark/others/tinyexpr"
	OR NOT EXISTS "${PROJECT_SOURCE_DIR}/benchmark/others/chibi-scheme"
)
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

set(BUILD_SHARED_LIBS OFF)
add_subdirectory(others/chibi-scheme)
