/*
 * File:   MorseObjectReader.cpp
 * Author: Sami Alperen Akgün
 * E-mail: sami.akgun@ieee.metu.edu.tr
 * Created on 26 July, 2017
 */

#include "pdg/MorseObjectReader.h"

MorseObjectReader::MorseObjectReader(ros::NodeHandle& node, std::string topic) {

    ROS_INFO("[MorseObjectReader] Initializing");

    //sub_ = node.subscribe(topic, 1, &MorseObjectReader::CallbackObj, this);

    //ROS_INFO("[MorseObjectReader] Initialized");
    
}

////////////////////////////////////////////////////
/*void MorseObjectReader::init(ros::NodeHandle& node){
  
}*/
void MorseObjectReader::updateObjects(tf::TransformListener &listener) {
  //update 1st human, this should be extended for multi human
  updateObject(listener, "morse_object1", "bluecup_base");
  updateObject2(listener, "morse_object2", "plate_base");
  updateObject3(listener, "morse_object3", "fork_base");
}

////////////////////////////////////////////////////

void MorseObjectReader::updateObject(tf::TransformListener &listener, std::string objId, std::string objectBase) {
	
	tf::StampedTransform transform;	
	MovableObject* curObject;
	curObject = new MovableObject("object_bluecup");
	curObject->setName("bluecup");
	
	std::vector<double> objectOrientation;
  	bg::model::point<double, 3, bg::cs::cartesian> objectPosition;
	
  try{
    ros::Time now = ros::Time::now();
    listener.waitForTransform("/ref_objectbluecup", objectBase,
        now, ros::Duration(3.0));
        listener.lookupTransform("/ref_objectbluecup", objectBase,
        now, transform);
    
        //Human position
        objectPosition.set<0>(transform.getOrigin().x());
        objectPosition.set<1>(transform.getOrigin().y());
        objectPosition.set<2>(transform.getOrigin().z());

        //Human orientation
        //curHuman->orientation.push_back(tf::getRoll(transform.getRotation()));
        //curHuman->orientation.push_back(tf::getPitch(transform.getRotation()));
        objectOrientation.push_back(0.0);
        objectOrientation.push_back(0.0);
        objectOrientation.push_back(tf::getYaw(transform.getRotation()));
        
        curObject->setOrientation(objectOrientation);
        curObject->setPosition(objectPosition);
        curObject->setTime(now.toNSec());

        lastConfig_[objId] = curObject;

  }
  catch (tf::TransformException ex){
    ROS_ERROR("%s",ex.what());
  }
}

/////////////////////////////////////////////////////////


////////////////////////////////////////////////////

void MorseObjectReader::updateObject2(tf::TransformListener &listener, std::string objId2, std::string objectBase2) {
	
	tf::StampedTransform transform;	
	MovableObject* curObject;
	curObject = new MovableObject("object_plate");
	curObject->setName("plate");
	std::vector<double> objectOrientation2;
  	bg::model::point<double, 3, bg::cs::cartesian> objectPosition2;
	
  try{
    ros::Time now = ros::Time::now();
    listener.waitForTransform("/ref_objectplate", objectBase2,
        now, ros::Duration(3.0));
        listener.lookupTransform("/ref_objectplate", objectBase2,
        now, transform);
    

        //Human position
        objectPosition2.set<0>(transform.getOrigin().x());
        objectPosition2.set<1>(transform.getOrigin().y());
        objectPosition2.set<2>(transform.getOrigin().z());

        //Human orientation
        //curHuman->orientation.push_back(tf::getRoll(transform.getRotation()));
        //curHuman->orientation.push_back(tf::getPitch(transform.getRotation()));
        objectOrientation2.push_back(0.0);
        objectOrientation2.push_back(0.0);
        objectOrientation2.push_back(tf::getYaw(transform.getRotation()));
        
        curObject->setOrientation(objectOrientation2);
        curObject->setPosition(objectPosition2);
        curObject->setTime(now.toNSec());

        lastConfig_[objId2] = curObject;

  }
  catch (tf::TransformException ex){
    ROS_ERROR("%s",ex.what());
  }
}


/////////////////////////////////////////////////////

////////////////////////////////////////////////////

void MorseObjectReader::updateObject3(tf::TransformListener &listener, std::string objId3, std::string objectBase3) {
	
	tf::StampedTransform transform;	
	MovableObject* curObject;
	curObject = new MovableObject("object_fork");
	curObject->setName("fork");
	std::vector<double> objectOrientation3;
  	bg::model::point<double, 3, bg::cs::cartesian> objectPosition3;
	
  try{
    ros::Time now = ros::Time::now();
    listener.waitForTransform("/ref_objectfork", objectBase3,
        now, ros::Duration(3.0));
        listener.lookupTransform("/ref_objectfork", objectBase3,
        now, transform);

        //Human position
        objectPosition3.set<0>(transform.getOrigin().x());
        objectPosition3.set<1>(transform.getOrigin().y());
        objectPosition3.set<2>(transform.getOrigin().z());

        //Human orientation
        //curHuman->orientation.push_back(tf::getRoll(transform.getRotation()));
        //curHuman->orientation.push_back(tf::getPitch(transform.getRotation()));
        objectOrientation3.push_back(0.0);
        objectOrientation3.push_back(0.0);
        objectOrientation3.push_back(tf::getYaw(transform.getRotation()));
        
        curObject->setOrientation(objectOrientation3);
        curObject->setPosition(objectPosition3);
        curObject->setTime(now.toNSec());

        lastConfig_[objId3] = curObject;

  }
  catch (tf::TransformException ex){
    ROS_ERROR("%s",ex.what());
  }
}




