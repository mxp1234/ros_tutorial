import rospy
from plumbing_pub_sub.msg import data


def callback(data):
    rospy.loginfo("%s,%d,%.2f",data.name,data.age,data.height)


if __name__=="__main__":

    rospy.init_node("sub_node")
    sub = rospy.Subscriber("person_data",data,callback=callback)
    rospy.spin()
    