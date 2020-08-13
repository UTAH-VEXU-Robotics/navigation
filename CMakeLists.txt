cmake_minimum_required(VERSION 3.0.2)
project(navigation)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED)

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


#add_executable(utah_navigation src/tf_broadcast.cpp)
#target_link_libraries(utah_navigation ${catkin_LIBRARIES})
#add_dependencies(utah_navigation roscpp)



