#ifndef __VECTOR_CPP_H__
#define __VECTOR_CPP_H__

#include <iostream>

typedef int Rank;
#define DEFAULT_CAPACITY 10

template <typename T> class Vector
{
public:
    Vector(int capacity = DEFAULT_CAPACITY, int size = 0, T v = 0);
    Vector(T const* A, Rank n);
    Vector(T const* A, Rank begin, Rank end);
    Vector(Vector<T> const& V);
    Vector(Vector<T> const& v, Rank begin, Rank end);
    ~Vector();

    Vector<T>& operator= (Vector<T> const& v);
private:
    void CopyFrom(T const* A, Rank begin, Rank end);
    void expand();

private:
    Rank _size;      /* use size */
    int  _capacity;  /* total size */
    T*   _elem;      /* data area */
};
#endif