#include <stdlib.h>
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <sensor_msgs/LaserScan.h>
#include "TurtleOperator.hpp"


int main(int argc, char **argv) {
   TurtleOperator turtleOperator;

   ros::init(argc, argv, "move_turtle");

   ros::NodeHandle n;
   ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity", 1000);
   ros::Subscriber scan_sub = n.subscribe("/scan", 60, &TurtleOperator::scanCallback, &turtleOperator);

   ros::Rate loopRate(10);

   while( ros::ok() ) {
	geometry_msgs::Twist twist;
  
   	twist.linear.x = 0;
   	twist.linear.y = 0;
   	twist.linear.z = 0;

   	twist.angular.x = 0;
   	twist.angular.y = 0;
   	twist.angular.z = 0;

   
	if (turtleOperator.rotate()) {
     		twist.angular.z = 0.75;
	}else {
		twist.linear.x = 0.2;
	}
    pub.publish(twist);
    ROS_DEBUG_STREAM("Published twist");
    ros::spinOnce();

    loopRate.sleep();
   }

   return EXIT_SUCCESS;

}
