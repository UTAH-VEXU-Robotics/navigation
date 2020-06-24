#!/usr/bin/env python
import roslib
import rospy
from nav_msgs.msg import Odometry
from nav_msgs.msg import OccupancyGrid
from tf.msg import tfMessage
from geometry_msgs.msg import Twist

itf    = tfMessage()
igrid  = OccupancyGrid()

def callback2(msg):
    #print(msg.?)
    itf = msg

def callback4(msg):
    #print(msg.?)
    igrid = msg

def main():
    rospy.init_node('NavigationNode', anonymous=True)

    pub2 = rospy.Publisher('/simulation_robot/tf', tfMessage, queue_size=10)
    rospy.Subscriber('/tf',                        tfMessage, callback2)

    pub4 = rospy.Publisher('/simulation_robot/OccupancyGrid', OccupancyGrid, queue_size=10)
    rospy.Subscriber('/map', OccupancyGrid, callback4)

    rate = rospy.Rate(10)  # 10hz
    while not rospy.is_shutdown():
        #tf
        #rospy.loginfo(itf)
        pub2.publish(itf)

        #grid
        #rospy.loginfo(igrid)
        pub4.publish(igrid)

        #sleep
        rate.sleep()

if __name__ == '__main__':
    main()