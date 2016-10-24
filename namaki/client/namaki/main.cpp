#include "client.h"

int main()
{
    Namaki::Client namaki("*", 5558);

    //::google::protobuf::ShutdownProtobufLibrary();
    return 0;
}
