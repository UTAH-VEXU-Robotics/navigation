//
// Created by utah on 8/31/20.
//

#include <move_base/move_base.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/connection_monitor.h>
#include <visualization_msgs/MarkerArray.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

#include <iostream>

#include "../include/RobotController.h"


RobotController::RobotController(){
  _markersSub = n.subscribe("field/markers", 50, _markersCallback);
  _moveBaseSimplePublish = n.advertise<geometry_msgs::PoseStamped>("move_base_simple/goal",50);

  _client = new MoveBaseClient( "move_base", true); // true -> don't need ros::spin()
  _client->waitForServer(ros::Duration(5,0));
  if(_client->isServerConnected()){ ROS_INFO_STREAM( "RobotController has connected to move_base server"); }
  else{ ROS_WARN_STREAM( "RobotController has NOT connected to move_base server"); }
  _target_pose = geometry_msgs::PoseStamped();
  _simpleDoneCallback = _doneCallback;
  _simpleActiveCallback = _activeCallback;
  _simpleFeedbackCallback = _feedbackCallback;
}

RobotController* RobotController::_instance = nullptr;

RobotController* RobotController::getController(){
  if(!_instance){
    _instance = new RobotController();
  }
  return _instance;
}

void RobotController::_markersCallback(const visualization_msgs::MarkerArray::ConstPtr& imarkers){
//  std::cout << "Markers Callback\n";
//  visualization_msgs::MarkerArray markers;
//  markers.markers = imarkers->markers;
//  getController()->_analyzer.run(markers);
//  getController()->_field = _analyzer
}

void RobotController::_activeCallback(){
  std::cout << "Active Callback\n";
}

void RobotController::_feedbackCallback(const move_base_msgs::MoveBaseFeedbackConstPtr & feedback){
//  std::cout << "Feedback Callback\n";
}

void RobotController::_doneCallback(const actionlib::SimpleClientGoalState & state, const move_base_msgs::MoveBaseResultConstPtr & result){
  std::cout << "Done Callback\n";
}

geometry_msgs::PoseStamped RobotController::generatePose(const double &x, const double &y, const double &yaw){
  geometry_msgs::PoseStamped pose;
  pose.header.stamp = ros::Time::now();
  pose.header.frame_id = "world";
  pose.pose.position.x = x;
  pose.pose.position.y = y;
  pose.pose.position.z = 0.0;
  tf2::Quaternion q;
  q.setRPY( 0, 0, yaw );
  pose.pose.orientation = tf2::toMsg(q);
//  ROS_INFO_STREAM(pose);
  return pose;
}

void RobotController::run(){}


void RobotController::move_base(const geometry_msgs::PoseStamped &target_pose){

  if(!_client->isServerConnected()){ ROS_WARN_STREAM( "RobotController is no longer connected to the move_base server"); }

  _target_pose.header = target_pose.header;
  _target_pose.pose = target_pose.pose;
  //publishing this may interfere with move base
  //_moveBaseSimplePublish.publish(_target_pose);

  auto goal = move_base_msgs::MoveBaseGoal();
  goal.target_pose = _target_pose;

  _client->sendGoal(goal, _simpleDoneCallback, _simpleActiveCallback, _simpleFeedbackCallback);

  _client->waitForResult();
}


int main(int argc, char** argv){
  ROS_INFO_STREAM("starting robot_controller");
  ros::init(argc, argv, "robot_controller");
  RobotController* controller = RobotController::getController();

  controller->move_base(RobotController::generatePose( -1.49853229523, 1.40196585655,2.2738924));

  while(ros::ok()){
    controller->run();
    ros::spin();
  }
}

/**
---
header:
  seq: 5
  stamp:
    secs: 1051
    nsecs: 438000000
  frame_id: "world"
pose:
  position:
    x: -1.49853229523
    y: 1.40196585655
    z: 0.0
  orientation:
    x: 0.0
    y: 0.0
    z: 0.907354011743
    w: 0.420367336236
---

class RobotController{
  private:
  ros::NodeHandle n;
  ros::Subscriber _markersSub;
  ros::Publisher _basePublish;
  visualization_msgs::MarkerArray _markers;

  static void markersCallback(const visualization_msgs::MarkerArray::ConstPtr& imarkers){
    std::cout << "markers callback\n";
    getController()->_markers.markers = imarkers->markers;
  }
  RobotController(){
    _markersSub = n.subscribe("field/markers", 50, markersCallback);
    _basePublish = n.advertise<geometry_msgs::PoseStamped>("field/move_base",50);
  }

  static RobotController* _instance;

  public:
  static RobotController* getController(){
    if(!RobotController::_instance) {
      RobotController::_instance = new RobotController();
    }
    return RobotController::_instance;
  }
};

int main(int argc, char** argv){
  RobotController* controller = RobotController::getController();
  ros::init(argc, argv, "robot_controller");



  std::cout << "starting robot_controller\n";



  while(ros::ok()){
    ros::spin();
  }
}
*/