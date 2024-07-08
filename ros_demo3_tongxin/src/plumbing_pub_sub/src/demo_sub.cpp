#include "ros/ros.h"
#include "std_msgs/String.h" //ros中文本类型std—msgs/string.h
#include "sstream"  //字符串拼接用的库

/*订阅方实现
1.头文件
2.初始化ros节点
3.创建节点句柄（句柄就是实例）
4.创建订阅者对象
5.利用回调函数处理订阅数据,
*/
//对常量指针的引用
void traceback(const std_msgs::String::ConstPtr &msg) //为什么传的是msg的地址，而且为什么是const类型？？
{
    ROS_INFO("订阅消息内容：%s",msg->data.c_str());

}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"sub_node");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("topic",10,traceback);  //需要与发布方一个话题

    ros::spin();  //回头一次，处理回调函数。如果没有他，只执行一次回调函数
    // std_msgs::String msg; //msg理解为是std_msgs.String类型的变量

    return 0;
}
