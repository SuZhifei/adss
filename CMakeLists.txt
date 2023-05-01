# 0. CMake Defs
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
cmake_policy(VERSION 3.5)

# 1. Project Name
project(adss)

# 2. Env (Include/Lib Path, C/CXX/LD FLAGS)
# SET(CMAKE_C_COMPILER	"clang")
# SET(CMAKE_CXX_COMPILER	"clang++")
SET(CMAKE_C_FLAGS	"${CMAKE_C_FLAGS} -Wall -std=c99")
SET(CMAKE_CXX_FLAGS	"${CMAKE_CXX_FLAGS}-Wall -std=c++17")

if("${CMAKE_INSTALL_PREFIX}" STREQUAL "")
	SET(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/dist)
endif()

SET(CMAKE_INSTALL_INCLUDEDIR ${CMAKE_INSTALL_PREFIX}/include)
SET(CMAKE_INSTALL_LIBDIR ${CMAKE_INSTALL_PREFIX}/lib)
SET(CMAKE_INSTALL_BINDIR ${CMAKE_INSTALL_PREFIX}/bin)
SET(CMAKE_INSTALL_ETCDIR ${CMAKE_INSTALL_PREFIX}/etc)
SET(CMAKE_INSTALL_DOCDIR ${CMAKE_INSTALL_PREFIX}/doc)

include_directories(includes)
include_directories(${CMAKE_SOURCE_DIR}/3rdparty/include)
include_directories(${CMAKE_SOURCE_DIR}/resources/protobuf)

link_directories(${CMAKE_SOURCE_DIR}/3rdparty/lib)

# 3. Project Build
#NA

# 4. Sub Projects
add_subdirectory(3rdparty)
add_subdirectory(includes)
add_subdirectory(src)
add_subdirectory(examples)

# 5. Project Install
# N/A
