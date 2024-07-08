import rospy 
from std_msgs.msg import String


def callback(msg):
    rospy.loginfo("%s",msg.data)

if __name__ =="__main__":
    rospy.init_node("sub_node")
    sub = rospy.Subscriber("topic",String,callback=callback,queue_size=10)
    #回头
    rospy.spin()
