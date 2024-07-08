//.1包含头文件
#include "ros/ros.h"
//2.程序入口main函数
int main(int argc,char *argv[]){

	//3.初始化ros节点（）
	ros::init(argc,argv,"hello_node");
	ROS_INFO("Hello_world");
	//4。输出日志
	return 0;
}
