#include "SimSpace.h"

template <class T>
SimSpace<T>::SimSpace(int MaxSpaceSize)
{
    NumberOfNodes = MaxSpaceSize;
    node = new SimNode<T> [NumberOfNodes];
    for (int i=0;i<NumberOfNodes-1;i++)
    {
        node[i].link=i+1;
    }
    node[NumberOfNodes-1].link=-1;
}

template <class T>
int SimSpace<T>::Allocate()
{
   if (first==-1) return -1;
   int i=first;
   first=node[i].link;
   return i;
};

template <class T>
void SimSpace<T>::Deallocate(int& i)
{
   node[i].link=first;
   first=i;
   i=-1;
}




