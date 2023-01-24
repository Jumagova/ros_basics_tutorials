#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

using namespace ros;

int main (int argc, char **argv){
    init(argc,argv,"talker_node_jm");
    NodeHandle n;
    Publisher chatter_publisher = n.advertise<std_msgs::String>("chatter",1000);
    Rate loop_rate(0.5);

    int count = 0;
    while (ok()){
        std_msgs::String msg;
        std::stringstream ss;
        ss << "Hello World" << count;
        msg.data = ss.str();
        ROS_INFO("[Talker] I published %s \n",msg.data.c_str());
        chatter_publisher.publish(msg);
        spinOnce();
        loop_rate.sleep();
        count++;
    }
    return 0;
}