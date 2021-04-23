#ifndef SIMSPACE_H_INCLUDED
#define SIMSPACE_H_INCLUDED
template <class T> class SimSpace;

template <class T>
class SimNode
{
   friend class SimSpace<T>;
   private:
       T data;
       int link;
};

template <class T>
class SimSpace
{
    public:
        SimSpace(int MaxSpaceSize);
        ~SimSpace(){delete[] node;};
        int Allocate();
        void Deallocate(int& i);
    protected:

    private:
        int NumberOfNodes,first;
        SimNode<T> *node;
};



#endif // SIMSPACE_H_INCLUDED
