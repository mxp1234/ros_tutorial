#include "ros/ros.h"

/* 
需要实现参数的新增和修改。
需求：首先设置机器人的共享参数：包括类型，半径
     再修改参数。

实现：通过两套api实现
    ros::nodeHandle
        setParam()
    ros::param
        set
    */
int main(int argc, char *argv[])
{
    ros::init(argc,argv,"set_node");

    ros::NodeHandle nh;
    //方法1:nodehandle("key"，“value”)
    nh.setParam("type","benz");
    nh.setParam("radius",0.13);
    //方法2.param
    ros::param::set("type_1","xuyan");
    ros::param::set("radius",0.15);
//参数修改:只需要继续调用setParam 或 set函数，保证key名称为修改的那个，value会覆盖
    //方法1：
    nh.setParam("type","nima");
    ros::param::set("radius",0.2);


    return 0;
}
