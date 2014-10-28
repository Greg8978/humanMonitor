#ifndef OPRSBRIDGE_H
#define OPRSBRIDGE_H

#include <string>
#include "opaque-pub.h"
#include "mp-pub.h"
#include <sstream>
#include <stdio.h>
#include <string.h>

using namespace std;
class OprsBridge {

 public :
  OprsBridge(string robot);
    void connect(string name);
    void updateSupervisor(string message, int i, string newValue, string oldValue);
    void updateSupervisor(string message, int i, bool newValue, bool oldValue);
    void sendMessageOprs(std::string command, std::string agent, std::string strMessage, string value);


    
 private:
    
    string robot_;
    int mp_socket;
};

#endif
