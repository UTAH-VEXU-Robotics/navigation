//
// Created by utah on 8/31/20.
//

#include <move_base/move_base.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/connection_monitor.h>
#include <visualization_msgs/MarkerArray.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <gazebo_msgs/ModelStates.h>
#include <gazebo_msgs/GetWorldProperties.h>
#include <gazebo_msgs/GetModelProperties.h>
#include <gazebo_msgs/GetModelState.h>
#include <iostream>

int main(int argc, char** argv){
  ROS_INFO_STREAM("starting robot_controller");
  ros::init(argc, argv, "robot_controller");

  ros::NodeHandle n;
  ros::ServiceClient _getModelStateClient;
  gazebo_msgs::GetModelState _getModelState;


  while(ros::ok()){
    _getModelState.request.model_name = "robot";
    _getModelState.request.relative_entity_name = "base_link";
    _getModelStateClient.call(_getModelState);
    ros::spin();
  }
}

