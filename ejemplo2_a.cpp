#include<ros/ros.h>
#include<ejemplos/c2_srv1.h>

bool add(ejemplos::c2_srv1::Request &req,
         ejemplos::c2_srv1::Response &res)
{
  res.sum = req.A + req.B + req.C;
  ROS_INFO("Solicitud: A=%ld, B=%ld, C=%ld", (int)req.A, (int)req.B, (int)req.C);
  ROS_INFO("Enviando la respuesta: [%ld]", (int)res.sum);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "Servidor_3_enteros");
  ros::NodeHandle n;
  ros::ServiceServer serv = n.advertiseService("agregar_3_enteros", add);
  ROS_INFO("Listo para agregar 3 enteros.");
  ros::spin();

  return 0;
}
