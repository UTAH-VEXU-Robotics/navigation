# navigation

### Summary:
everything chassis control and
odometry
gets data from robot and the strategy
package
sends data to the tracking package
and robot

### v1:
- built in non/holonomic velocity
controller
- basic robot visulization_msgs for
rviz
- gazebo support (manual urdf)

### Feature Ideas:
- configurable actionlib recovery
actions
- configurable output for velocity
controller (PID / motion profile)
- pathfollower more specific and
better tuned to vex
- robot urdf generator for
different robot types
- easily tune PID and odometry
values with qt stuff
- automatic urdf robot generator
- visual odometry with realsense
- visual odometry with qr code
thing
- send data to other robot about
odometry
- check out https://github.com/GuiRitter/OpenBase and https://github.com/YugAjmera/navros_pkg
