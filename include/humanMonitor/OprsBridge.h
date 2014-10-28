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
    void connect(string name);
    void updateSupervisor(string message, int i, string newMessage, string oldMessage);
    void updateSupervisor(string message, int i, bool newMessage, bool oldMessage);
    

    
 private:
    void sendMessageOprs(std::string command, std::string agent, std::string strMessage);
    

    int mp_socket;
};

#endif
