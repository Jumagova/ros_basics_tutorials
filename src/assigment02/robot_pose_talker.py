#!/usr/bin/env python
import rospy
from turtlesim.msg import Pose

def pose_callback(message):
    rospy.loginfo(rospy.get_caller_id() + "the pose is x:%s y:%s",message.x,message.y)

def pose_listener():
    rospy.init_node('robot_pose_talker',anonymous=True)
    rospy.Subscriber('turtle1/pose',Pose,pose_callback)
    rospy.spin()

if __name__ == '__main__':
    pose_listener()