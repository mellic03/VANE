#pragma once

#include <cstddef>
#include <cstdint>


namespace vane
{
    class VaneApp;
    class Platform;

    class VaneService
    {
    private:
        size_t mTime, mEdge;

    protected:
        VaneApp  &mApp;
        Platform &mPlat;

    public:
        VaneService( VaneApp& );
        virtual ~VaneService() = default;

        virtual void update() {  };
        virtual void preUpdate() {  };
        virtual void postUpdate() {  };
    
        void setRate( size_t hz );
        bool _update( size_t ms );

    };

}

