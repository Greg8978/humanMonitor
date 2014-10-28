
RobotReader::RobotReader(string name) {
    this->name=name;
}

void RobotReader::getRobotJointLocation(tf::TransformListener &listener, std::string joint){
    tf::StampedTransform transform;
    std::string jointId = "/";
    jointId.append(joint);
    try{
        ros::Time now = ros::Time::now();
        listener.waitForTransform("/map", jointId,
                              now, ros::Duration(3.0));
        listener.lookupTransform("/map", jointId,
                              now, transform);
        m_RobotLastTime = now.toNSec();
        m_RobotLastConfig.joints[joint].position.setX(transform.getOrigin().x());
        m_RobotLastConfig.joints[joint].position.setY(transform.getOrigin().y());
	m_RobotLastConfig.joints[joint].position.setZ(transform.getOrigin().z());
        // We put these in a ring buffer:
        //m_RobotRBufffer.push_back(m_RobotLastTime, m_RobotLastConfig);

    }    
    catch (tf::TransformException ex){
        ROS_ERROR("%s",ex.what());
    }
}



void RobotReader::updateRobot(tf::TransformListener &listener){
    if(this->name=="PR2") {
    getRobotJointLocation(listener, "torso_lift_link");
    getRobotJointLocation(listener, "r_gripper_l_finger_link");
    getRobotJointLocation(listener, "l_gripper_l_finger_link");
    }
    else if(this->name=="SPENCER") {
	getRobotJointLocation(listener, "torso_lift_link");
    
    }

 }
