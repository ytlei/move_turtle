/********************************************************************
 *   MIT License
 *  
 *   Copyright (c) 2017 Yi-ting Lei
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 ********************************************************************/


/** @file moveTurtle.cpp
 *  @brief main program for moving turtle
 *
 *  A simple node to control Turtlebot motion. This program
 *  will make turtlebot move forward until it is 0.6 meters from an obstacle in
 *  front. It will then rotate 90 degrees and look to see if its clear of obstacles. 
 *  If not, it will continue to rotate until finds a clear path.
 *
 *  @author Yi-ting Lei
 *  @date   11/21/2017
*/

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
