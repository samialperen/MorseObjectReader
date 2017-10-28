/* 
 * File:   MorseObjectReader.h
 * Author: Sami Alperen AKGÜN
 * E-mail: sami.akgun@ieee.metu.edu.tr
 *
 * Created on 26 July, 2017
 */

#ifndef MORSEOBJECTREADER
#define MORSEOBJECTREADER

//This class reads topic from Ar_track_alvar and converts data into toaster-lib type.

#include "ObjectReader.h"
#include <ros/ros.h>
#include <string>
#include "geometry_msgs/PoseStamped.h"
#include "tf/transform_listener.h"
#include <math.h>
#include <sys/time.h>
#include <ostream>
#include "visualization_msgs/Marker.h"
#include "gazebo_msgs/ModelStates.h"


class MorseObjectReader : public ObjectReader {
	
public:
    MorseObjectReader(ros::NodeHandle& node, std::string topic);

    void updateObjects(tf::TransformListener &listener);
    void updateObject(tf::TransformListener &listener, std::string objId, std::string objectBase);
    void updateObject2(tf::TransformListener &listener, std::string objId2, std::string objectBase2);     
    void updateObject3(tf::TransformListener &listener, std::string objId3, std::string objectBase3);          


private:
    ros::Subscriber sub_;
    
    void CallbackObj(const geometry_msgs::PoseStamped::ConstPtr& msg);
    
};
#endif	/* MORSEOBJECTREADER */

