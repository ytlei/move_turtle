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

/** @file TurtleOperator.cpp
 *  @brief Implementation of class TurtleOperator methods
 *
 *  Implemenation of callback function in TurtleOperator.
 *  Scan through ranges array see if it's smaller than desired distance
 *
 *  @author Yi-ting Lei
 *  @date   11/21/2017
 */

#include <stdlib.h>
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include "TurtleOperator.hpp"

void TurtleOperator::scanCallback(
		const sensor_msgs::LaserScan::ConstPtr& scan_msg) {
	for (unsigned int i = 0; i < scan_msg->ranges.size(); i++) {
		if (scan_msg->ranges[i] < 1) {
			turn = true;
			ROS_DEBUG_STREAM(
					"range " << scan_msg->ranges[i] << " less than 5m");
			return;
		}
	}
	turn = false;
	ROS_DEBUG_STREAM("no obstacle");
	return;
}

bool TurtleOperator::rotate() {
	return turn;
}

