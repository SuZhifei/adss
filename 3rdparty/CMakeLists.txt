
# 0. CMake Defs
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
cmake_policy(VERSION 3.5)

# 1. Project Name
project(3rdparty)

# 2. Env (Include/Lib Path, C/CXX/LD FLAGS)

# 4. Sub Projects

# 5. Project Install0
file(GLOB LIBS lib/linux-arm/*.so*)
install(FILES ${LIBS} DESTINATION ${CMAKE_INSTALL_LIBDIR})

