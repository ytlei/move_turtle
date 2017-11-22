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

/** @file TurtleOperator.hpp
 *  @brief Definition of class TurtleOperator
 *
 *  This file contains definitions of class TurtleOperator which subscribes to
 *  /scan topic and uses range info to determine if robot is close to
 *  obstacle
 *
 *  @author Yi-ting Lei
 *  @date   11/21/2017
 */

#ifndef INCLUDE_TURTLEOPERATOR_HPP_
#define INCLUDE_TURTLEOPERATOR_HPP_

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

/**
 *  @brief Class definition of TurtleOperator class
 */

class TurtleOperator {
public:
	TurtleOperator() :
			turn(false) {
	}
	;
	void scanCallback(const sensor_msgs::LaserScan::ConstPtr&);
	bool rotate();
private:
	bool turn;
};

#endif  // INCLUDE_TURTLEOPERATOR_HPP_
