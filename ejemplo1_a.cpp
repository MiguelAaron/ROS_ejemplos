#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ejemplo1_a");
  ros::NodeHandle N;
  ros::Publisher Pub = N.advertise<std_msgs::String>("mensaje", 1000);
  ros::Rate R(10);

  while(ros::ok())
  {
    std_msgs::String M;
    std::stringstream S;
    S << "Soy el nodo ejemplo1_a";
    M.data = S.str();
    ROS_INFO("%s", M.data.c_str());
    Pub.publish(M);
    ros::spinOnce();
    R.sleep();
  }
  return 0;
}
