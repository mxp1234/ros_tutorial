import rospy
from plumbing_server_client.srv import *
import sys
#组织并提交请求，处理服务端的响应

if __name__ == "__main__":
    '''
    1.初始化ros节点
    2.创建客户端对象
    3.组织请求数据，发送请求
    4.处理响应(打印)
    
    '''
    #notice 优化实现1：动态参数命令行输入，利用sys库
    #sys库可以提供argv参数，“argv”即“argument value”的简写，是一个列表对象，其中存储的是在命令行调用 Python 脚本时提供的“命令行参数”。
    
    #notice 优化实现2：实现先启动客户端也不报异常。即启动客户端后检查客户端状态，如果没启动则客户端挂起。这在实际应用中非常关键。
    #ros内置了相关函数,cli.wait_for_service() 或采用rospy.wait_for_service("fuwu")

    if(len(sys.argv)!=3):  #检验参数数目是否正确
        rospy.loginfo("参数数目错误")
        sys.exit(1)
    num1 = int(sys.argv[1])
    num2 = int(sys.argv[2])  #注意argv保存的都是字符串
    
    rospy.init_node("client_node")

    cli = rospy.ServiceProxy("fuwu",addints)  #话题名称要保持一致
    cli.wait_for_service()
    # response = cli.call(17,5) #call函数返回response，与c++不同
    response = cli(num1,num2)
    rospy.loginfo("服务器返回的数据%d",response.sum)