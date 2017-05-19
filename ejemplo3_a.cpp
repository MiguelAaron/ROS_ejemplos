#include <ros/ros.h>
#include <ejemplos/c2_msg1.h>
#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ejemplo1_a");
  ros::NodeHandle N;
  ros::Publisher Pub = N.advertise<ejemplos::c2_msg1>("mensaje", 1000);
  ros::Rate R(10);

  while(ros::ok())
  {
    ejemplos::c2_msg1 msj;
    msj.A = 1;
    msj.B = 2;
    msj.C = 3;
    Pub.publish(msj);
    ros::spinOnce();
    R.sleep();
  }
  return 0;
}
