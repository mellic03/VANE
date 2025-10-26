#include <vane/core/service.hpp>
#include <vane/core/app.hpp>

using namespace vane;


VaneService::VaneService( VaneApp &V )
:   mApp(V), mPlat(V.platform())
{

}


void VaneService::setRate( size_t hz )
{
    mTime = 0;
    mEdge = 1000000/hz;
}


bool VaneService::_update( size_t ms )
{
    mTime += 1000*ms;

    if (mTime >= mEdge)
    {
        mTime -= mEdge;
        return true;
    }
    
    return false;
}