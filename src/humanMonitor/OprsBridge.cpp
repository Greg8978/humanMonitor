#include "humanMonitor/OprsBridge.h"

void OprsBridge::connect(string name) {
    mp_socket=external_register_to_the_mp_prot(name.c_str(), 3300, STRINGS_PT); //oprs stuff
    
}

void OprsBridge::sendMessageOprs(std::string command, std::string agent, std::string strMessage)  {
    std::string stringMessageBase="(AGENT-STATEMENT PR2_ROBOT ";
	
    char dest[10]="OPRS_DB";
    char message[200];
  
  
    std::stringstream completeString;
  
    completeString<<"(HumanMonitor.message "<<command<<" "<<stringMessageBase<<agent<<" "<<strMessage<<"))";
  
    //  ROS_INFO("%s",completeString.str().c_str()); 
    
    strcpy(message,completeString.str().c_str());
	//  ROS_INFO("Return message %s",message);
    send_message_string(message,dest);
}

void OprsBridge::updateSupervisor(string message, int i, string newMessage, string oldMessage) {
    std::stringstream convert;
    convert<<i;
    string agent=convert.str();
    if (oldMessage.size()>0) {
	sendMessageOprs("remove",agent,oldMessage);
    }
    sendMessageOprs("add",agent, newMessage);
}

void OprsBridge::updateSupervisor(string message, int i, bool newMessage, bool oldMessage) {
    std::stringstream convert;
    string convertedNM, convertedOM;
    if (newMessage==true) {
	convertedNM="TRUE";
    }
    else {
	convertedNM="FALSE";
    }
    if (oldMessage==true) {
	convertedOM="TRUE";
    }
    else {
	convertedOM="FALSE";
    }
    convert<<i;
    string agent=convert.str();
    sendMessageOprs("remove",agent,convertedOM);
    sendMessageOprs("add",agent, convertedNM);
}
