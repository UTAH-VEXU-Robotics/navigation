//
// Created by utah on 9/8/20.
//

#ifndef FIELD_ANALYZER_H
#define FIELD_ANALYZER_H

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

#include "ChangeUp.h"

class FieldAnalyzer{
private:

  ros::NodeHandle n;
  ros::ServiceClient _getWorldPropertiesClient;
  gazebo_msgs::GetWorldProperties _getWorldProperties;
  ros::ServiceClient _getModelPropertiesClient;
  gazebo_msgs::GetModelProperties _getModelProperties;
  ros::ServiceClient _getModelStateClient;
  gazebo_msgs::GetModelState _getModelState;

  /*
  visualization_msgs::MarkerArray _markers;
  navigation::Field _field;
  navigation::Action _action;

  std_msgs::ColorRGBA black;
  std_msgs::ColorRGBA grey;
  std_msgs::ColorRGBA white;
  std_msgs::ColorRGBA red;
  std_msgs::ColorRGBA green;
  std_msgs::ColorRGBA blue;
  std_msgs::ColorRGBA purple;
  std_msgs::ColorRGBA yellow;
  std_msgs::ColorRGBA orange;
//*/

  FieldAnalyzer();
  static FieldAnalyzer* _instance;

public:

  static FieldAnalyzer* get();

//  void run();
};


#endif //NAVIGATION_ROBOTCONTROLLER_H
