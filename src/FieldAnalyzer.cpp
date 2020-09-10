//
// Created by utah on 8/31/20.
//

#include "../include/FieldAnalyzer.h"


FieldAnalyzer* FieldAnalyzer::_instance = nullptr;

FieldAnalyzer* FieldAnalyzer::get(){
  if(!_instance){
    _instance = new FieldAnalyzer();
  }
  return _instance;
}


//*
FieldAnalyzer::FieldAnalyzer(){
  /*
  black.r = 0;
  black.g = 0;
  black.b = 0;
  black.a = 1;
  grey.r = 100;
  grey.g = 100;
  grey.b = 100;
  grey.a = 1;
  white.r = 255;
  white.g = 255;
  white.b = 255;
  white.a = 1;
  red.r = 255;
  red.g = 0;
  red.b = 0;
  red.a = 1;
  green.r = 0;
  green.g = 255;
  green.b = 0;
  green.a = 1;
  blue.r = 0;
  blue.g = 0;
  blue.b = 255;
  blue.a = 1;
  purple.r = 128;
  purple.g = 0;
  purple.b = 128;
  purple.a = .8;
  yellow.r = 255;
  yellow.g = 255;
  yellow.b = 0;
  yellow.a = 1;
  orange.r = 255;
  orange.g = 165;
  orange.b = 0;
  orange.a = 1;
//*/

  _getWorldPropertiesClient = n.serviceClient<gazebo_msgs::GetWorldProperties>("/gazebo/get_world_properties");
  _getModelPropertiesClient = n.serviceClient<gazebo_msgs::GetModelProperties>("/gazebo/get_model_properties");
  _getModelStateClient = n.serviceClient<gazebo_msgs::GetModelProperties>("/gazebo/get_model_state");

  _getWorldPropertiesClient.call(_getWorldProperties);
  std::vector<std::string> model_names = _getWorldProperties.response.model_names;

  for(auto&& model_name: model_names){
    if(model_name!=""){
      _getModelProperties.request.model_name = model_name;
      _getModelPropertiesClient.call(_getModelProperties);
      std::string relative_entity_name = _getModelProperties.response.body_names.at(0);

      ros::Duration(1).sleep();

      _getModelState.request.model_name = "robot";
      _getModelState.request.relative_entity_name = "base_link";
//      ROS_INFO_STREAM( model_name + ":" + relative_entity_name );
      _getModelStateClient.call(_getModelState);
      geometry_msgs::PoseStamped pose;
      pose.header = _getModelState.response.header;
      pose.pose = _getModelState.response.pose;
      ROS_INFO_STREAM( _getModelState.response.status_message );
    }
  }
}

//void FieldAnalyzer::run(){
//  std::cout << "hi\n";
//}
 //*/


int main(int argc, char** argv){
  ROS_INFO_STREAM("starting robot_controller");
  ros::init(argc, argv, "robot_controller");
  FieldAnalyzer* analyzer = FieldAnalyzer::get();

  while(ros::ok()){
    ros::spin();
  }
}

