#include "ros/ros.h"
#include "plumbing_pub_sub/data.h"
void callback(const plumbing_pub_sub::data::ConstPtr& data)
{
    ROS_INFO("订阅的结构体信息：%s,%d,%.2f",data->name.c_str(),data->age,data->height);   //利用指针进行传递
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"sub_node");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("person_data",10,callback);

    ros::spin();
    return 0;
}
