#!/user/bin/env python3

import rospy
from plumbing_pub_sub.msg import data

if __name__ == "__main__":
    rospy.init_node("pub_node")
    
    pub = rospy.Publisher("person_data",data,queue_size=10)
    p = data()
    p.ageage = 21
    p.height = 183
    p.name = "MXP"

    rate = rospy.Rate(2)
    while( not rospy.is_shutdown()):
        pub.publish(p)
        rate.sleep()
        

