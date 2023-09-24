cmake_minimum_required(VERSION 3.0)

project(CMakeTest)

set(APP_DIR "${CMAKE_CURRENT_LIST_DIR}/src")
set(SOURCES "${APP_DIR}/main.cpp" "${APP_DIR}/libs/spokeperson.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)