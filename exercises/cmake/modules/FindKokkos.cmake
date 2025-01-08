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

# find Kokkos as an already existing target
if(TARGET Kokkos::kokkos)
    return()
endif()

# find Kokkos as installed
find_package(Kokkos CONFIG)
if(Kokkos_FOUND)
    message(STATUS "Kokkos provided as installed: ${Kokkos_DIR} (version \"${Kokkos_VERSION}\")")

    return()
endif()

# find Kokkos as an existing source directory
set(
    CexaKokkosTutorials_KOKKOS_SOURCE_DIR
    "${CMAKE_CURRENT_SOURCE_DIR}/../../vendor/kokkos"
    CACHE
    PATH
    "Path to the local source directory of Kokkos"
)
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
    URL https://github.com/kokkos/kokkos/releases/download/4.5.01/kokkos-4.5.01.zip
    SOURCE_DIR ${CexaKokkosTutorials_KOKKOS_SOURCE_DIR}
)
FetchContent_MakeAvailable(kokkos)
set(Kokkos_FOUND True)
