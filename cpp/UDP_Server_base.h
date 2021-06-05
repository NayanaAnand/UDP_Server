#ifndef UDP_SERVER_BASE_IMPL_BASE_H
#define UDP_SERVER_BASE_IMPL_BASE_H

#include <boost/thread.hpp>
#include <ossie/Component.h>
#include <ossie/ThreadedComponent.h>


class UDP_Server_base : public Component, protected ThreadedComponent
{
    public:
        UDP_Server_base(const char *uuid, const char *label);
        ~UDP_Server_base();

        void start() throw (CF::Resource::StartError, CORBA::SystemException);

        void stop() throw (CF::Resource::StopError, CORBA::SystemException);

        void releaseObject() throw (CF::LifeCycle::ReleaseError, CORBA::SystemException);

        void loadProperties();

    protected:

    private:
};
#endif // UDP_SERVER_BASE_IMPL_BASE_H
