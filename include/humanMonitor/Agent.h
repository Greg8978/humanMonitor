#ifndef AGENT_H
#define AGENT_H


#include "tf/transform_datatypes.h"
#include <map>
#include <string.h>

using namespace std;

const string RIGHT_HIP="R_HIP";
const string RIGHT_HAND="R_HAND";
const string LEFT_HAND="L_HAND";
const string TORSO="TORSO";
const string HEAD="HEAD";

struct AgentJoint {
    tf::Point position;
    tf::Quaternion orientation;
};
struct Agent {
    map<string,AgentJoint> joints;
};

#endif
