/** @file TurtleOperator.cpp
 *  @brief Implementation of class TurtleOperator methods
 *
 *  Implemenation of callback function in TurtleOperator.
 *  Scan through ranges array see if it's smaller than desired distance
 *
 *  @author Yi-ting Lei
 *  @date   04/18/2017
*/


#include <stdlib.h>
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include "TurtleOperator.hpp"


/*
TurtleOperator::TurtleOperator() :: turn(false) {
   operatorPublisher = nodeHandle.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop",100);
   ros::Subscriber scan_sub = nodeHandle.subscribe("scan", 100, &scanCallback);

}
*/

void TurtleOperator::scanCallback (const sensor_msgs::LaserScan::ConstPtr& scan_msg) {


	//distance = *min_element(scan_msg->ranges.begin(), scan_msg->ranges.end());
  for (unsigned int i=0; i< scan_msg->ranges.size(); i++) {   
               if (scan_msg->ranges[i] < 1) {
			//ROS_INFO_STREAM("callback");
			turn = true;
			ROS_DEBUG_STREAM("range " << scan_msg->ranges[i] << " less than 5m");
                   //distance = scan_msg->ranges[i];  
                   //angle = ((double)i*scan_msg->angle_increment) + scan_msg->angle_min;
                   //turtleOperator.rotate();
			return;
               }
               //std::cout << distance <<" ------ "<< angle << std::endl; 
   }
   turn = false;
   ROS_DEBUG_STREAM("no obstacle");
   return;
}



/*
void TurtleOperator::moveForward() {
   geometry_msgs::Twist twist;
  
   twist.linear.x = 0.2;
   twist.linear.y = 0;
   twist.linear.z = 0;

   twist.angular.x = 0;
   twist.angular.y = 0;
   twist.angular.z = 0;

   ROS_INFO_STREAM("Publish move");
   this->operatorPublisher.publish(twist);
  
}
*/
bool TurtleOperator::rotate() {
	return turn;
   /*geometry_msgs::Twist twist;

   twist.linear.x = 0;
   twist.linear.y = 0;
   twist.linear.z = 0;

   twist.angular.x = 0;
   twist.angular.y = 0;
   twist.angular.z = 0.75;

   ROS_INFO_STREAM("Publish rotate");
   this->operatorPublisher.publish(twist);
*/
}


