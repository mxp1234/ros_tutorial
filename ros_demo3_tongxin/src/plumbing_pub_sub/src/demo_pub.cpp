#include "ros/ros.h"
#include "std_msgs/String.h" //ros中文本类型std—msgs/string.h
#include "sstream"  //字符串拼接用的库
/*发布方实现
1.头文件
2.初始化ros节点
3.创建节点句柄
4.创建分布者对象
5.编写发布逻辑并发布数据
*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"pub_node");

    ros::NodeHandle nh;
    //创建发布者
    ros::Publisher pub = nh.advertise<std_msgs::String>("topic",10);   //<>里面是消息类型，括号里面是话题，与堆栈长度两个参数

    //先创建被发布消息
    std_msgs::String msg;
    //设置发布频率10HZ
    ros::Rate rate(10);
    //设置编号
    int count=0;
    //编写循环
    while (ros::ok())  //当这个节点还存在
    {
        count++;
        //字符串拼接数字
        std::stringstream ss;
        ss <<"mengxinpan ---> " << count;

        msg.data = ss.str();
        pub.publish(msg);
        //添加日志
        ROS_INFO("发布的数据是：%s",ss.str().c_str());
        rate.sleep();
    }
    

    return 0;
}
