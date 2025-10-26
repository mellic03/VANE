#pragma once

#include <cstddef>


namespace vane
{
    class EdgeUpdate
    {
    private:
        size_t mTime;
        size_t mEdge;

    public:
        EdgeUpdate( size_t hz=60 ) { setRate(hz); }

        void setRate( size_t hz )
        {
            mTime = 0;
            mEdge = 1000000/hz;
        }

        bool update( size_t ms )
        {
            mTime += 1000*ms;

            if (mTime >= mEdge)
            {
                mTime -= mEdge;
                return true;
            }
            
            return false;
        }

    };
}

