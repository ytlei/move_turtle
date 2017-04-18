#include <stdlib.h>
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <sensor_msgs/LaserScan.h>
//#include <turtlebot_node/TurtlebotSensorState>


class TurtleOperator {
  public:
    TurtleOperator();
    virtual ~TurtleOperator() {};

    void moveForward();
    void rotate();
  private:
    ros::NodeHandle nodeHandle;
    ros::Publisher operatorPublisher;
    float x_value;
};
//void scanCallback (const sensor_msgs::LaserScan::ConstPtr& scan_msg) {
/*
void scanCallback (const sensor_msgs::LaserScan::ConstPtr& scan_msg) { 
   geometry_msgs::Twist vel; //DeclaraciÃ³n de la variable global vel
   ros::NodeHandle n;
   ros::Publisher vel_pub_=n.advertise<geometry_msgs::twist>("cmd_vel", 1);
   ros::Time ahora;
   double minDist=10; 
   double angle; 
   double speed=0.5;

   for (unsigned int i=0;i< scan_msg->ranges.size();i++){   

     angle = ((double)i*scan_msg->angle_increment)+scan_msg->angle_min;

     if (scan_msg->ranges[i]< minDist){
       minDist=scan_msg->ranges[i];      
       std::cout << minDist << std::endl;          
     }
   } 

   if( minDist<=0.6){

            vel.linear.x = 0.0;//velocidad de avance
            vel.angular.z = 0.0;//velocidad de giro
            vel_pub_.publish(vel);
   }else {


            speed=0.5*speed;
            vel.linear.x = speed;//velocidad de avance
            vel.angular.z = 0.0;//velocidad de giro
            vel_pub_.publish(vel);
            //std::cout << speed << std::endl;  

   }
}
*/
double angle; 
double distance=10;

void scanCallback (const sensor_msgs::LaserScan::ConstPtr& scan_msg) {

   for (unsigned int i=0; i< scan_msg->ranges.size(); i++) {   
               if (scan_msg->ranges[i] < distance) {
			ROS_INFO_STREAM("callback");
                   distance = scan_msg->ranges[i];  
                   angle = ((double)i*scan_msg->angle_increment) + scan_msg->angle_min;
                   //turtleOperator.rotate();
               }
               std::cout << distance <<" ------ "<< angle << std::endl; 
   }
}



int main(int argc, char **argv) {

/*
  ros::init(argc, argv, "DistanceObstacle");
std::cout << "Starting......" << std::endl;

  ros::NodeHandle n;
  ros::Publisher vel_pub_=n.advertise<geometry_msgs::Twist>("cmd_vel", 1);
  ros::Subscriber scan_sub = n.subscribe("scan", 1, scanCallback);

  ros::spin(); //Mantiene la suscripción al topic hasta que se reciba "Ctrl+C"
  return 0;
*/
   ros::init(argc, argv, "move_turtle");

   
   TurtleOperator turtleOperator;

   
   std::cout << "Starting to spin …" << std::endl;

   ros::Rate loopRate(10);

   while( ros::ok() ) {
	if(distance>5 ) {
		turtleOperator.moveForward();
	}else {
		turtleOperator.rotate();
	}
    
    ROS_INFO("Published twist");
    loopRate.sleep();
   }

   return EXIT_SUCCESS;

}

TurtleOperator::TurtleOperator() : x_value(0.1) {
   operatorPublisher = nodeHandle.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop",1);
   ros::Subscriber scan_sub = nodeHandle.subscribe("scan", 10, scanCallback);

}

void TurtleOperator::moveForward() {
  geometry_msgs::Twist twist;
  
   twist.linear.x = x_value;
   twist.linear.y = 0;
   twist.linear.z = 0;

   twist.angular.x = 0;
   twist.angular.y = 0;
   twist.angular.z = 0;

   ROS_INFO_STREAM("Publish move");
   this->operatorPublisher.publish(twist);
  
}

void TurtleOperator::rotate() {
   geometry_msgs::Twist twist;

   twist.linear.x = 0;
   twist.linear.y = 0;
   twist.linear.z = 0;

   twist.angular.x = 0;
   twist.angular.y = 0;
   twist.angular.z = 0.6;

   ROS_INFO_STREAM("Publish rotate");
   this->operatorPublisher.publish(twist);
}

