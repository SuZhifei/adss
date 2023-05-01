# 1. Project Name

project(src)

# 2. Project Env (Include/Lib Path, C/CXX/LD FLAGS)

# 3. Project Build
set(BIN_NAME "adss")

file(GLOB_RECURSE SRC_FILES *.cpp
    ${CMAKE_SOURCE_DIR}/resources/*.c*)

add_executable(${BIN_NAME} ${SRC_FILES})
set_target_properties(${BIN_NAME} PROPERTIES OUTPUT_NAME ${BIN_NAME})
target_link_libraries(${BIN_NAME} protobuf)

# 4. Project Install
install(TARGETS ${BIN_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})
