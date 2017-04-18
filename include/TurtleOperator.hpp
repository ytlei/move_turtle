/** @file TurtleOperator.hpp
 *  @brief Definition of class TurtleOperator
 *
 *  This file contains definitions of class TurtleOperator which subscribes to
 *  /scan topic and uses range info to determine if robot is close to
 *  obstacle
 *
 *  @author Yi-ting Lei
 *  @date   04/18/2017
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
    TurtleOperator():turn(false){};
    //virtual ~TurtleOperator() {};
    void scanCallback (const sensor_msgs::LaserScan::ConstPtr&);
    //void moveForward();
    bool rotate();
  private:
 
    //float x_value;
    bool turn;
};


#endif  // INCLUDE_TURTLEOPERATOR_HPP_