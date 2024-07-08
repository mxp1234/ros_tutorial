#include "ros/ros.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");  //解决乱码问题
    ros::init(argc,argv,"hello");
    ROS_INFO("haha,我草");
    return 0;
}
