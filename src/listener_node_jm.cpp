#include "ros/ros.h"
#include "std_msgs/String.h"

using namespace ros;

void chatterCallback (const std_msgs::String::ConstPtr& msg){
    ROS_INFO("[Listener] I Heard [%s]\n",msg->data.c_str());
}

int main (int argc, char **argv){
    init(argc,argv,"listener_node_jm");
    NodeHandle node;
    Subscriber sub = node.subscribe ("chatter",1000,chatterCallback);
    spin();
    return 0;
}

