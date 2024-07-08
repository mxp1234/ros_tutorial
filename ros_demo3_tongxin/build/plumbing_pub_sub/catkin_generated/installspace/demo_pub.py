#!/user/bin/env python3

import rospy

from std_msgs.msg import String  #发布的消息类型
if __name__=="__main__":

    rospy.init_node("pub_node")
    pub = rospy.Publisher("topic",String,queue_size=10)
    #创建数据
    msg = String()
    #指定发布频率
    rate = rospy.Rate(12)
    #设置计时器
    count = 0
    while not rospy.is_shutdown():
        count+=1
        msg.data = "hello" + str(count)
        pub.publish(msg)   #注意发布的数据类型的是msg而不是msg。data，订阅者提取的时候也要取一个data属性
        rate.sleep()
        rospy.loginfo("发布信息%s",msg.data)