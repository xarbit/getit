cmake_minimum_required(VERSION 3.12)

include(FetchContent)


# ------------------------------------------------------------------------------
# Macro to use the FetchContent_MakeAvailable command in version below 3.14
#
if(${CMAKE_VERSION} VERSION_LESS 3.14)
    macro(FetchContent_MakeAvailable NAME)
        FetchContent_GetProperties(${NAME})
        if(NOT ${NAME}_POPULATED)
            FetchContent_Populate(${NAME})
            add_subdirectory(${${NAME}_SOURCE_DIR} ${${NAME}_BINARY_DIR})
        endif()
    endmacro()
endif()

# ------------------------------------------------------------------------------
# Trompeloeil
FetchContent_Declare(
    extern_trompeloeil

    GIT_REPOSITORY https://github.com/rollbear/trompeloeil.git
    GIT_TAG        v35)
FetchContent_MakeAvailable(extern_trompeloeil)

# ------------------------------------------------------------------------------
# Catch2
FetchContent_Declare(
    extern_catch2

    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v2.10.2)
FetchContent_MakeAvailable(extern_catch2)
