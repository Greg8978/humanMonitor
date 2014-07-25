
#ifndef HUMAN_H_
#define HUMAN_H_

// List.h code


//this class represents a human joint
#include "tf/LinearMath/Quaternion.h"


struct HumanJoint {
  humanMonitor::niut_GEN_POINT_3D position;
  tf::Quaternion orientation;
};

struct Human {
  HumanJoint joints[25];
};
#endif
