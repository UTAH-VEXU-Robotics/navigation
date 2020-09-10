//
// Created by utah on 9/8/20.
//

#ifndef NAVIGATION_ROBOTCONTROLLER_H
#define NAVIGATION_ROBOTCONTROLLER_H

#include "../include/FieldAnalyzer.h"

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

class RobotController{
private:
  RobotController();
  static RobotController* _instance;
  ros::NodeHandle n;
  ros::Subscriber _markersSub;
  ros::Publisher _moveBaseSimplePublish;

  static void _markersCallback(const visualization_msgs::MarkerArray::ConstPtr&);
//  FieldAnalyzer _analyzer;
//  navigation::Field _field;

  MoveBaseClient* _client;
  geometry_msgs::PoseStamped _target_pose;
  static void _activeCallback();
  static void _feedbackCallback(const move_base_msgs::MoveBaseFeedbackConstPtr&);
  static void _doneCallback(const actionlib::SimpleClientGoalState &,
                           const move_base_msgs::MoveBaseResultConstPtr &);
  boost::function<void (const actionlib::SimpleClientGoalState &, const move_base_msgs::MoveBaseResultConstPtr &)> _simpleDoneCallback;
  boost::function<void ()> _simpleActiveCallback;
  boost::function<void (const move_base_msgs::MoveBaseFeedbackConstPtr &)> _simpleFeedbackCallback;

public:
  static RobotController* getController();
  static geometry_msgs::PoseStamped generatePose(const double &x, const double &y, const double &yaw);
  void run();
  void move_base(const geometry_msgs::PoseStamped &);
};


#endif //NAVIGATION_ROBOTCONTROLLER_H
