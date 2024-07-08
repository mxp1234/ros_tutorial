#include "ros/ros.h"
#include "plumbing_server_client/addints.h"

int main(int argc, char*argv[])   //如果需要实现参数动态设置，需要使用到传入main 的两个参数
{
    /*客户端：用户提交两个整数，并处理相应的结果*/
    setlocale(LC_ALL,"");
    //初始化节点
    ros::init(argc,argv,"client_node");
    //初始化句柄
    ros::NodeHandle nh;
    //创建一个客户端对象
    ros::ServiceClient cli  =  nh.serviceClient<plumbing_server_client::addints>("fuwu");
    
    //提交请求,首先构建数据
    plumbing_server_client::addints data;
    data.request.num1 = 100;
    data.request.num2 = 200;
    //提交请求并处理响应
    bool flag = cli.call(data);  //将请求内容提交是调用call函数，返回一个布尔类型，表示是否提交成功
    if(flag){
        ROS_INFO("响应成功");
        ROS_INFO("相应内容为：%d",data.response.sum);
    }
    else{
        ROS_INFO("failed");

    }

    return 0;
}
