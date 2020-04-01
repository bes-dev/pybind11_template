cmake_minimum_required(VERSION 2.8.12)
set(PROJECT_NAME pybind11_template)
project(${PROJECT_NAME})

find_package(OpenCV REQUIRED)
MESSAGE( " *** OpenCV_INCLUDE_DIRS : " ${OpenCV_INCLUDE_DIRS} )
MESSAGE( " *** OpenCV_LIB_DIRS : " ${OpenCV_LIB_DIRS} )
MESSAGE( " *** OpenCV_LIBS : " ${OpenCV_LIBS} )

include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/pybind11/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/)

include_directories(${OpenCV_INCLUDE_DIRS})
LINK_DIRECTORIES(
  ${OpenCV_LIB_DIR}
)

add_subdirectory(pybind11)
pybind11_add_module(${PROJECT_NAME} SHARED src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS})
