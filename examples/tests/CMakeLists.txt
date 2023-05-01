# 1. Project Name
project(tests)

# 2. Project Env (Include/Lib Path, C/CXX/LD FLAGS)

# 3. Project Build
set(BIN_NAME "tests")
file(GLOB SRC_FILES "*.h" "*.cpp" "../*.h" "../*.cpp")

add_executable(${BIN_NAME} ${SRC_FILES})
set_target_properties(${BIN_NAME} PROPERTIES OUTPUT_NAME adss.${BIN_NAME})

# target_link_libraries(${BIN_NAME} xxx)

# 4. Project Install
install(TARGETS ${BIN_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})
