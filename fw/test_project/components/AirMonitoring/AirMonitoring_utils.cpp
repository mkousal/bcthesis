#include "AirMonitoring_utils.hpp"

namespace Am {

void setTaskChecker(uint8_t flag) {
    taskStatus |= flag;
}

bool getTaskChecker(uint8_t flag) {
    if ((taskStatus & flag) == flag)
        return true;
    else
        return false;
}

void resetTaskChecker(uint8_t flag, bool all) {
    if (all)
        taskStatus = 0;
    else
        taskStatus &= ~flag;
}

void messageReceived(const uint8_t *message, size_t length, ttn_port_t port)
{
    printf("Message of %d bytes received on port %d:", length, port);
    for (int i = 0; i < length; i++)
        printf(" %02x", message[i]);
    printf("\n");
}

}   // namespace Am