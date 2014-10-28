#include "humanMonitor/OprsBridge.h"

OprsBridge::OprsBridge(string robot) {
  robot_=robot;
}
void OprsBridge::connect(string name) {
    mp_socket=external_register_to_the_mp_prot(name.c_str(), 3300, STRINGS_PT); //oprs stuff

}

void OprsBridge::sendMessageOprs(std::string command, std::string agent, std::string strMessage, string value)  {
    std::string stringMessageBase="(AGENT-STATEMENT ";
	
    char dest[10]="OPRS_DB";
    char message[200];
  
  
    std::stringstream completeString;
  
    completeString<<"(HumanMonitor.message "<<command<<" "<<stringMessageBase<<robot_<<" "<<agent<<" "<<strMessage<<" "<<value<<"))";
  
    //  ROS_INFO("%s",completeString.str().c_str()); 
    
    strcpy(message,completeString.str().c_str());
	//  ROS_INFO("Return message %s",message);
    send_message_string(message,dest);
}

void OprsBridge::updateSupervisor(string message, int i, string newValue, string oldValue) {
    std::stringstream convert;
    convert<<i;
    string agent=convert.str();
    if (oldValue.size()>0) {
      sendMessageOprs("remove",agent,message,oldValue);
    }
    sendMessageOprs("add",agent, message,newValue);
}

void OprsBridge::updateSupervisor(string message, int i, bool newValue, bool oldValue) {
    std::stringstream convert;
    string convertedNM, convertedOM;
    if (newValue==true) {
	convertedNM="TRUE";
    }
    else {
	convertedNM="FALSE";
    }
    if (oldValue==true) {
	convertedOM="TRUE";
    }
    else {
	convertedOM="FALSE";
    }
    convert<<i;
    string agent=convert.str();
    sendMessageOprs("remove",agent,message, convertedOM);
    sendMessageOprs("add",agent, message, convertedNM);
}
