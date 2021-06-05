#include <iostream>
#include "ossie/ossieSupport.h"

#include "UDP_Server.h"
int main(int argc, char* argv[])
{
    UDP_Server_i* UDP_Server_servant;
    Component::start_component(UDP_Server_servant, argc, argv);
    return 0;
}

