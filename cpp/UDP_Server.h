#ifndef UDP_SERVER_I_IMPL_H
#define UDP_SERVER_I_IMPL_H

#include "UDP_Server_base.h"

class UDP_Server_i : public UDP_Server_base
{
    ENABLE_LOGGING
    public:
        UDP_Server_i(const char *uuid, const char *label);
        ~UDP_Server_i();

        void constructor();

        int serviceFunction();

    protected:
};

#endif // UDP_SERVER_I_IMPL_H
