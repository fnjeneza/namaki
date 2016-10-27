#include "connector.h"
#include <iostream>
#include "messages.h"

int main()
{

    Namaki::Connector c;
    c.receive();
    //::google::protobuf::ShutdownProtobufLibrary();
    return 0;
}
