#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist


def move():
    speed_publisher = rospy.Publisher('turtle1/cmd_vel',Twist,queue_size=10)
    rospy.init_node('robot_move_topic',anonymous=True)
    rate = rospy.Rate(1)    #1Hz
    
    
    i=0
    while not rospy.is_shutdown():
        twist = Twist()
        twist.linear.x = 1.0
        speed_publisher.publish(twist)
        rate.sleep()
        i=i+1




if __name__ == '__main__':
    try:
        move()
    except rospy.ROSInterruptException:
          pass