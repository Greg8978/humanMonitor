#ifndef MATHFUNCTIONS_H
#define MATHFUNCTIONS_H

#include <math.h>       /* sqrt */
#include "tf/transform_datatypes.h"
#include "humanMonitor/Agent.h"
#include "humanMonitor/TRBuffer.h"

using namespace std;
class MathFunctions {

 public:
    static bool  isFacing(AgentJoint agentJoint, tf::Point point, double angleThreshold);
    static void multiplyMatrices4x4(double* result,double* mat1, double* mat2);
    static double dist3D(tf::Point point1, tf::Point joint2);
    static double dist2D(tf::Point joint1, tf::Point joint2);
};

#endif
