#include "ros/ros.h"
#include "plumbing_pub_sub/data.h"

//发布自定义数据类型person

/*
流程：1.初始化ros节点
    2.创建节点句柄
    3.创建发布者对象
    4.设置消息类型

 */

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"pub_node");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<plumbing_pub_sub::data>("person_data",10);
    
    //编写发布逻辑
    //1.创建被发布的数据
    plumbing_pub_sub::data person;
    person.name = "mengxinpan";
    person.height = 181;
    person.age = 21;
    //2.设置发布频率
    ros::Rate rate(1);
    //3.循环发布
    while(ros::ok)
    {
        person.height+=1;
        pub.publish(person);
        rate.sleep();
        ros::spinOnce();
    }
    return 0;
}
