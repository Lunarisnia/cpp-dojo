cmake_minimum_required(VERSION 3.0)

project(CarGame)

set(SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/src")
set(LIBS_DIR "${SRC_DIR}/libs")
# set(SOURCES "${SRC_DIR}/main.cpp ${LIBS_DIR}/cursor.cpp ${LIBS_DIR}/game.cpp ${LIBS_DIR}/player.cpp ${LIBS_DIR}/road.cpp")
# set(SOURCES_FILES "src/main.cpp src/libs/cursor.cpp src/libs/game.cpp src/libs/player.cpp src/libs/road.cpp")
# set(SOURCES "${SRC_DIR}/main.cpp")

# Why the fuck does this work???
add_executable(${PROJECT_NAME} src/main.cpp src/libs/cursor.cpp src/libs/game.cpp src/libs/player.cpp src/libs/road.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)