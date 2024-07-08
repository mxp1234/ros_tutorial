#include "ros/ros.h"
#include "plumbing_server_client/addints.h"

//如何实现参数的动态提交？
    //1.格式  rosrun  包名  代码名  12  34
    //2.节点执行时，需要获取命令中的参数（利用argc，argv），并组织进requenst 

//notice :当先启动客户端时，会请求异常。（理论上是服务器先启动）
//现在的需求是：先启动客户端，不会出现异常，而是挂起。
//在ros中，有一些内置函数，能让客户端启动后挂起，等待服务端启动。
//两种方法：cli.waitforservice
//2. ros::service::waitforservice("服务话题名")

int main(int argc, char*argv[])   //如果需要实现参数动态设置，需要使用到传入main 的两个参数
{
    //注意argc是参数个数，argv是具体的参数值。argc包括第一个参数程序名。c++程序执行时，直接在程序名参数后面添加两个参数即作为argv【1】，argv【2】

    if(argc!=3){
        ROS_INFO("提交参数个数不对");
        return 1;
    }
   

    /*客户端：用户提交两个整数，并处理相应的结果*/
    setlocale(LC_ALL,"");

    //初始化节点
    ros::init(argc,argv,"client_node");

    //初始化句柄
    ros::NodeHandle nh;

    //创建一个客户端对象
    ros::ServiceClient cli  =  nh.serviceClient<plumbing_server_client::addints>("fuwu"); //服务话题名
    
    //提交请求,首先构建数据
    plumbing_server_client::addints data;
    data.request.num1 = atoi(argv[1]);
    data.request.num2 = atoi(argv[2]);

    //调用判断服务器状态的函数，实现挂起功能
    //1.函数1.
    cli.waitForExistence();

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
