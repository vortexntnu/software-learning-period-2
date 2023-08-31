cmake_minimum_required(VERSION 3.5)
project(example_publisher)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -Wno-unused-local-typedefs -fopenmp)
endif()

# find dependencies
find_package(ament_cmake  REQUIRED)
find_package(rclcpp       REQUIRED)
find_package(std_msgs     REQUIRED)
find_package(example_msgs REQUIRED)

# add include
include_directories(include)

# add publisher executable
add_executable(${PROJECT_NAME}_node 
  src/example_publisher.cpp
)
ament_target_dependencies(${PROJECT_NAME}_node 
  rclcpp 
  std_msgs
  example_msgs
)

# Let ros2 run find the executables
install(
  DIRECTORY include/
  DESTINATION include
)
INSTALL(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

install(TARGETS
  ${PROJECT_NAME}_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()
