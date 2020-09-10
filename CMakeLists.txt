cmake_minimum_required(VERSION 3.0.2)
project(navigation)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
        roscpp
        rospy
        std_msgs
        sensor_msgs
        move_base
        move_base_msgs
        actionlib
        actionlib_msgs
        )

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(field_analyzer src/FieldAnalyzer.cpp )
target_link_libraries(field_analyzer ${catkin_LIBRARIES})
#add_dependencies(field_analyzer roscpp)


