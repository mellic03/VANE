#pragma once

#include <vector>
#include <cstring>


namespace vane::DSA
{
    template <typename T>
    class ctig_set
    {
    public:
        int find( const T& );
        bool contains( const T& );
        void insert( const T& );
        void erase( const T& );

        auto begin() { return mItems.begin(); }
        auto end() { return mItems.end(); }

    private:
        std::vector<T> mItems;

    };
}


template <typename T>
int vane::DSA::ctig_set<T>::find( const T &x )
{
    for (int i=0; i<mItems.size(); i++)
        if (mItems[i]==x) return i;
    return -1;
}

template <typename T>
bool vane::DSA::ctig_set<T>::contains( const T &x )
{
    return find(x) != -1;
}

template <typename T>
void vane::DSA::ctig_set<T>::insert( const T &x )
{
    if (!contains(x))
        mItems.push_back(x);
}

template <typename T>
void vane::DSA::ctig_set<T>::erase( const T &x )
{
    int i = find(x);
    if (i == -1) return;
    memcpy(&(mItems[i]), &(mItems.back()), sizeof(T));
    mItems.back() = T();
    mItems.pop_back();
}
