//
// Created by utah on 8/31/20.
//


#include <move_base/move_base.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/connection_monitor.h>

#include <iostream>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> Client;

void activeCallback(){
  std::cout << "Active Callback\n";
}
void feedbackCallback(const move_base_msgs::MoveBaseFeedbackConstPtr & feedback){
//  std::cout << "Feedback Callback\n";
}
void doneCallback(const actionlib::SimpleClientGoalState & state, const move_base_msgs::MoveBaseResultConstPtr & result){
  std::cout << "Done Callback\n";
}

void moveBaseCallback(const geometry_msgs::PoseStamped::ConstPtr& pose){

  Client client( "move_base", true); // true -> don't need ros::spin()

  if(client.isServerConnected()){
    std::cout << "MoveBaseSimpleActionClient has connected to move_base server" << "\n";
  }

  client.waitForServer();

  boost::function<void (const actionlib::SimpleClientGoalState &, const move_base_msgs::MoveBaseResultConstPtr &)>
      simpleDoneCallback = doneCallback;
  boost::function<void ()> simpleActiveCallback = activeCallback;
  boost::function<void (const move_base_msgs::MoveBaseFeedbackConstPtr &)> simpleFeedbackCallback = feedbackCallback;

  auto goal = move_base_msgs::MoveBaseGoal();
  goal.target_pose.header.stamp = ros::Time::now();
  goal.target_pose.header.frame_id = "world";
  goal.target_pose.pose.position.x = -.513;
  goal.target_pose.pose.position.y = .7332;
  goal.target_pose.pose.position.z = 0.0;

  goal.target_pose.pose.orientation.x = 0.0;
  goal.target_pose.pose.orientation.y = 0.0;
  goal.target_pose.pose.orientation.z = .97;
  goal.target_pose.pose.orientation.w = .23;

  client.sendGoal(goal, simpleDoneCallback, simpleActiveCallback, simpleFeedbackCallback);

  client.waitForResult();
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "move_base_client");
  ros::NodeHandle n;

  ROS_INFO_STREAM("starting move_base_client");
  ros::Subscriber sub = n.subscribe("field/move_base", 50, moveBaseCallback);

  Client client( "move_base", true); // true -> don't need ros::spin()

  if(client.isServerConnected()){
    std::cout << "MoveBaseSimpleActionClient has connected to move_base server" << "\n";
  }

  client.waitForServer();

  boost::function<void (const actionlib::SimpleClientGoalState &, const move_base_msgs::MoveBaseResultConstPtr &)>
      simpleDoneCallback = doneCallback;
  boost::function<void ()> simpleActiveCallback = activeCallback;
  boost::function<void (const move_base_msgs::MoveBaseFeedbackConstPtr &)> simpleFeedbackCallback = feedbackCallback;

  auto goal = move_base_msgs::MoveBaseGoal();
  goal.target_pose.header.stamp = ros::Time::now();
  goal.target_pose.header.frame_id = "world";
  goal.target_pose.pose.position.x = -.513;
  goal.target_pose.pose.position.y = .7332;
  goal.target_pose.pose.position.z = 0.0;

  goal.target_pose.pose.orientation.x = 0.0;
  goal.target_pose.pose.orientation.y = 0.0;
  goal.target_pose.pose.orientation.z = .97;
  goal.target_pose.pose.orientation.w = .23;

  client.sendGoal(goal, simpleDoneCallback, simpleActiveCallback, simpleFeedbackCallback);

  client.waitForResult();
}