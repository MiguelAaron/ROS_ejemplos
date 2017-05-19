#include <ros/ros.h>
#include <ejemplos/c2_msg1.h>

void respuesta(const ejemplos::c2_msg1::ConstPtr& msj)
{
  ROS_INFO("Escucho: [%d] [%d] [%d]", msj->A, msj->B, msj->C);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ejemplo1_b");
  ros::NodeHandle N;
  ros::Subscriber Sub = N.subscribe("mensaje", 1000, respuesta);
  ros::spin();
  return 0;
}
