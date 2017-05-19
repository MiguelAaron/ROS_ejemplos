#include <ros/ros.h>
#include <std_msgs/String.h>

void respuesta(const std_msgs::String::ConstPtr& resp)
{
  ROS_INFO("Escucho: %s", resp->data.c_str());
}

int main(int argc, char **argv)
{
  ROS_INFO("Esperando...");
  ros::init(argc, argv, "ejemplo1_b");
  ros::NodeHandle N;
  ros::Subscriber Sub = N.subscribe("mensaje", 1000, respuesta);
  ros::spin();
  return 0;
}
