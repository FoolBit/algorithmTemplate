template <class T>
struct Heap
{
    T *arr;
    int size;

    Heap(int n)
    {
        arr = new T[n];
        size = 0;
    }

    ~Heap()
    {
        delete []arr;
    }

    T top()
    {
        return arr[0];
    }

    void shiftUp()
    {
        int p=size-1;
        int tmp=arr[p];
        int parent;
        while(p)
        {
            parent = (p-1)>>1;
            if(arr[parent]>tmp)
            {
                arr[p]=arr[parent];
                p = parent;
            }
            else
            {
                break;
            }
        }
        arr[p]=tmp;
    }

    void shiftDown()
    {
        int p=0;
        int tmp=arr[p];
        int child;
        child = (p<<1)+1;
        while(child<size)
        {
            if(child < size -1 && arr[child]>arr[child+1])
                ++child;

            if(tmp>arr[child])
            {
                arr[p]=arr[child];
                p=child;
                child = (p<<1)+1;
            }
            else
            {
                break;
            }
        }
        arr[p]=tmp;
    }

    void insert(T tmp)
    {
        arr[size++] = tmp;
        this->shiftUp();
    }

    void pop()
    {
        arr[0] = arr[--size];
        this->shiftDown();
    }
};