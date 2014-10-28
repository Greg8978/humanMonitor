#ifndef MONITORS_H
#define MONITORS_H

#include <string>
#include <map>
#include "humanMonitor/Agent.h"
#include "humanMonitor/TRBuffer.h"
#include "humanMonitor/MathFunctions.h"

class Monitors {
    
 public:
    Monitors();
    
    string computeDistance(Agent m_agentLastConfig, Agent m_robotLastConfig, string joint, double *distValue);
    string computeAgentPose(Agent m_agentsLastConfig);
    map<string,bool> computeHandDistance(Agent m_agentsLastConfig, Agent m_robotLastConfig);
    bool computeMotion(TRBuffer<Agent >  confBuffer, string joint);
    bool computeOrientationToRobot(Agent m_agentsLastConfig, Agent m_robotLastConfig, string joint);
    




 private:
  double far;
  double close;

  double distLHandToGripper;
  double distRHandToGripper;
  double distHandExtended;





};

#endif
