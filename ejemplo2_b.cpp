#include<ros/ros.h>
#include<ejemplos/c2_srv1.h>
#include<cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "Cliente_3_enteros");

  if(argc != 4)
  {
    ROS_INFO("Usar: Cliente_3_enteros A B C");
    return 0;
  }

  ros::NodeHandle n;
  ros::ServiceClient cliente = n.serviceClient<ejemplos::c2_srv1>("agregar_3_enteros");
  ejemplos::c2_srv1 srv;
  srv.request.A = atoll(argv[1]);
  srv.request.B = atoll(argv[2]);
  srv.request.C = atoll(argv[3]);

  if(cliente.call(srv))
  {
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  }
  else
  {
    ROS_ERROR("Fallo al llamar servicio agregar_3_enteros");
    return 1;
  }
  return 0;
}
