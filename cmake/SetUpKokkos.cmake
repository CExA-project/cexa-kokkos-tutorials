# Setup Kokkos as either an external dependency, or an inlined dependency. In
# the former, Kokkos has already been compiled and installed, and its install
# path is given to CMake with `Kokkos_ROOT` option. In the later, Kokkos
# sources are either already present as a Git submodule, or they are downloaded
# by this script using CMake `FetchContent`; in either case Kokkos sources are
# located in `/vendor/kokkos` and compiled along with the project, which means
# that Kokkos options must be passed at configuration time. If the option
# `CMAKE_DISABLE_FIND_PACKAGE_Kokkos` is `ON`, then no installed instance of
# Kokkos will be used, and only the inline build of Kokkos will take place.
# Conversely, if the option `CMAKE_REQUIRE_FIND_PACKAGE_Kokkos` is `ON`, then
# only an installed instance of Kokkos will be used.
#
# See
# https://kokkos.org/kokkos-core-wiki/get-started/integrating-kokkos-into-your-cmake-project.html#supporting-both-external-and-embedded-kokkos

# set CMAKE_BUILD_TYPE if not defined
if(NOT CMAKE_BUILD_TYPE)
    set(default_build_type "RelWithDebInfo")
    message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
    set(
        CMAKE_BUILD_TYPE
        "${default_build_type}"
        CACHE
        STRING
        "Choose the type of build, options are: Debug, Release, RelWithDebInfo and MinSizeRel."
        FORCE
    )
endif()

set(
    CexaKokkosTutorials_KOKKOS_SOURCE_DIR
    "${CMAKE_CURRENT_LIST_DIR}/../vendor/kokkos"
    CACHE
    PATH
    "Path to the local source directory of Kokkos"
)

# find Kokkos as an already existing target
if(TARGET Kokkos::kokkos)
    return()
endif()

# find Kokkos as installed
find_package(Kokkos QUIET)
if(Kokkos_FOUND)
    message(STATUS "Kokkos provided as installed: ${Kokkos_DIR} (version \"${Kokkos_VERSION}\")")

    return()
endif()

# find Kokkos as an existing source directory
if(EXISTS "${CexaKokkosTutorials_KOKKOS_SOURCE_DIR}/CMakeLists.txt")
    message(STATUS "Kokkos provided as a source directory: ${CexaKokkosTutorials_KOKKOS_SOURCE_DIR}")

    add_subdirectory("${CexaKokkosTutorials_KOKKOS_SOURCE_DIR}" kokkos)
    set(Kokkos_FOUND True)

    return()
endif()

# download Kokkos from release and find it
message(STATUS "Kokkos downloaded: ${CexaKokkosTutorials_KOKKOS_SOURCE_DIR}")

include(FetchContent)

FetchContent_Declare(
    kokkos
    DOWNLOAD_EXTRACT_TIMESTAMP ON
    URL https://github.com/kokkos/kokkos/releases/download/4.6.01/kokkos-4.6.01.tar.gz
    URL_HASH SHA256=b9d70e4653b87a06dbb48d63291bf248058c7c7db4bd91979676ad5609bb1a3a
    SOURCE_DIR ${CexaKokkosTutorials_KOKKOS_SOURCE_DIR}
)
FetchContent_MakeAvailable(kokkos)
