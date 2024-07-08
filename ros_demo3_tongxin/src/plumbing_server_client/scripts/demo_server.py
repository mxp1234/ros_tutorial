#! /user/bin/env python
import rospy
from plumbing_server_client.srv import addints,addintsRequest,addintsResponse
# 服务端：解析客户端请求（两个数字），再产生相应。

#参数：输入参数是请求数据，返回值是相应数据.和c++实现有较大差距
def callback(request):
    num1 = int(request.num1)
    type1 = type(request.num1) 
    num2 = int(request.num2)
    sum = num1+num2
    response = addintsResponse()
    response.sum = sum   
    rospy.loginfo("type类型是%s",type1) 
    return response

if __name__ == "__main__":
    rospy.init_node("server_node")
    server = rospy.Service("fuwu",addints,callback,10)
    rospy.loginfo("服务器启动了")
    rospy.spin()
