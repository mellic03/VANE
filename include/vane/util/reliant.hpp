#pragma once

namespace vane::util
{
    template <typename T>
    struct Reliant
    {
    private:
        T &mObj;

    public:
        Reliant( T &x ): mObj(x) {  }

        // template <typename U>
        // U &get() { return ((Reliant<U>*)this)->mObj; }
        T &get() { return mObj; }
    };
}


