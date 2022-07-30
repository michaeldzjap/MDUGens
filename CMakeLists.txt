cmake_minimum_required (VERSION 2.8.12)
get_filename_component(PROJECT MDUGens NAME_WE)
message(STATUS "Project name is ${PROJECT}")
project (${PROJECT})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${CMAKE_SOURCE_DIR}/memory/include)
include_directories(${CMAKE_SOURCE_DIR}/MDAudio/include)
# include_directories(${CMAKE_SOURCE_DIR}/TPTFilter/include)
include_directories(${MD_AUDIO_PATH}/include)
include_directories(${MD_AUDIO_PATH}/include/interfaces)
include_directories(${MD_AUDIO_PATH}/include/memory)
include_directories(${SC_PATH}/include/plugin_interface)
include_directories(${SC_PATH}/include/common)
include_directories(${SC_PATH}/common)

set(CMAKE_SHARED_MODULE_PREFIX "")
if(APPLE OR WIN32)
    set(CMAKE_SHARED_MODULE_SUFFIX ".scx")
endif()

option(SUPERNOVA "Build plugins for supernova" OFF)
if(SUPERNOVA)
    include_directories(${SC_PATH}/external_libraries/nova-tt)
    # actually just boost.atomic
    include_directories(${SC_PATH}/external_libraries/boost)
    include_directories(${SC_PATH}/external_libraries/boost_lockfree)
    include_directories(${SC_PATH}/external_libraries/boost-lockfree)
endif()

option(CPP11 "Build with c++11." ON)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_COMPILER_IS_CLANG 1)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG)
    add_definitions(-fvisibility=hidden)

    include (CheckCCompilerFlag)
    include (CheckCXXCompilerFlag)

    CHECK_C_COMPILER_FLAG(-msse HAS_SSE)
    CHECK_CXX_COMPILER_FLAG(-msse HAS_CXX_SSE)

    if(HAS_SSE)
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -msse")
    endif()
    if(HAS_CXX_SSE)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse")
    endif()

    CHECK_C_COMPILER_FLAG(-msse2 HAS_SSE2)
    CHECK_CXX_COMPILER_FLAG(-msse2 HAS_CXX_SSE2)

    if(HAS_SSE2)
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -msse2")
    endif()
    if(HAS_CXX_SSE2)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse2")
    endif()

    CHECK_C_COMPILER_FLAG(-mfpmath=sse HAS_FPMATH_SSE)
    CHECK_CXX_COMPILER_FLAG(-mfpmath=sse HAS_CXX_FPMATH_SSE)

    if(HAS_FPMATH_SSE)
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mfpmath=sse")
    endif()
    if(HAS_CXX_FPMATH_SSE)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mfpmath=sse")
    endif()

    if(NATIVE)
        add_definitions(-march=native)
    endif()

    if(CPP11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
        if(CMAKE_COMPILER_IS_CLANG)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
        endif()
    endif()
endif()
if(MINGW)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mstackrealign")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mstackrealign")
endif()

# Hacky: OSX plugins should install in PLUGIN_DIR
macro(BUILD_PLUGIN PLUGIN_NAME PLUGIN_SOURCES)
    add_library(${PLUGIN_NAME} MODULE ${PLUGIN_SOURCES})
    if(SUPERNOVA)
        add_library(${PLUGIN_NAME}_supernova MODULE ${PLUGIN_SOURCES})

        set_property(TARGET ${PLUGIN_NAME}_supernova
                     PROPERTY COMPILE_DEFINITIONS SUPERNOVA)
    endif()
endmacro()

# # 1 - Build MDAudio UGens
# include("${CMAKE_CURRENT_SOURCE_DIR}/ReverseDelay/src/sourcelist.cmake")
# BUILD_PLUGIN(ReverseDelay "${REVERSE_DELAY_SOURCES}")
include("${MD_AUDIO_PATH}/src/sourcelist.cmake")
list(TRANSFORM MD_AUDIO_SOURCES PREPEND "${MD_AUDIO_PATH}/src/")

include("${CMAKE_CURRENT_SOURCE_DIR}/MDAudio/src/sourcelist.cmake")

set(MD_AUDIO_SOURCES_TOTAL ${MD_AUDIO_SOURCES} ${MD_AUDIO_SC_SOURCES})
BUILD_PLUGIN(MDAudio "${MD_AUDIO_SOURCES_TOTAL}")

# 2 - Build TPTFilter UGens
# include("${CMAKE_CURRENT_SOURCE_DIR}/TPTFilter/src/sourcelist.cmake")
# list(TRANSFORM TPT_FILTER_SOURCES PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/TPTFilter/src/")
#
# BUILD_PLUGIN(TPTFilter "${TPT_FILTER_SOURCES}")

# 3 - Build SOSBank UGens
BUILD_PLUGIN(SOSBank "SOSBank/SOSBank.cpp")
