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

## System dependencies are found with CMake's conventions
#find_package(Boost REQUIRED COMPONENTS system)

## Generate messages in the 'msg' folder
#add_message_files(
#        FILES
#)

## Generate added messages and services with any dependencies listed here
#generate_messages(
#        DEPENDENCIES
#        std_msgs geometry_msgs # Or other packages containing msgs
#)

###########
## Build ##
###########

## Specify additional locations of header files


## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
catkin_install_python(PROGRAMS
#        scripts/republisher.py
        DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
        )


#add_executable(move_base_client src/MoveBaseClient.cpp)
#target_link_libraries(move_base_client ${catkin_LIBRARIES})
##add_dependencies(move_base_client roscpp)
#
#add_executable(robot_controller src/RobotController.cpp )
#target_link_libraries(robot_controller ${catkin_LIBRARIES})
##add_dependencies(robot_controller roscpp)
#
#add_executable(field_analyzer src/FieldAnalyzer.cpp )
#target_link_libraries(field_analyzer ${catkin_LIBRARIES})
##add_dependencies(field_analyzer roscpp)


