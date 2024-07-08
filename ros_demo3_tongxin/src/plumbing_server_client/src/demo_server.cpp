#include "ros/ros.h"
#include "plumbing_server_client/addints.h"
/*服务端实现，解析客户端提交的数据，再运算产生相应

//note:
1.头文件
2.ros节点
3.节点句柄
4.创建服务对象  
5.处理请求，产生相应 
6.spin（）
*/
//notice :当先启动客户端时，会请求异常。
//现在的需求是：先启动客户端，不会出现异常，而是挂起。
//在ros中，有一些内置函数，能让客户端启动后挂起，等待服务端启动。

bool callback(plumbing_server_client::addints::Request &request,
                plumbing_server_client::addints::Response &response)  //  &表示的是引用，建议飕飕c++
{
    //1.处理请求
    int num1 = request.num1;
    int num2 = request.num2;
    ROS_INFO("受到的数据num1=%d，num2=%d",num1,num2);
    //2.组织相应
    int sum = num1+num2;
    response.sum = sum;
    return true;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"server_node");
    ros::NodeHandle nh;
    ros::ServiceServer svr = nh.advertiseService("fuwu",callback);  //service也需要有一个主题名字
    ros::spin();
    return 0;
}
