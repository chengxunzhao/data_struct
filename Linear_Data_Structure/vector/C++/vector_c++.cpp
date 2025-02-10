#include "vector_c++.h"

template <typename T>
inline Vector<T>::Vector(int capacity, int size, T v) : _capacity(capacity)
{
    _elem = new T[_capacity];
    for (_size = 0; _size < size; _size++)
    {
        _elem[_size] = v;
    }
}

template <typename T>
Vector<T>::Vector(T const *A, Rank n)
{
    CopyFrom(A, 0, n);
}

template <typename T>
Vector<T>::Vector(T const *A, Rank begin, Rank end)
{
    CopyFrom(A, begin, end);
}

template <typename T>
Vector<T>::Vector(Vector<T> const &V)
{
    CopyFrom(V._elem, 0, V._size);
}

template <typename T>
Vector<T>::Vector(Vector<T> const &v, Rank begin, Rank end)
{
    CopyFrom(v._elem, begin, end);
}

template <typename T>
Vector<T>::~Vector()
{
    delete []_elem;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T> const & v)
{
// TODO: 在此处插入 return 语句
    if (_elem)
    {
        delete []_elem;
    }
    CopyFrom(v._elem, 0, v._size);
    return *this;
}

template <typename T>
void Vector<T>::CopyFrom(T const *A, Rank begin, Rank end) /* A[begin, end) */
{
    _elem = new T[_capacity = 2 * (end - begin)];  /* 初始2倍空间 */
    _size = 0;
    // for (_size; _size < end - begin; _size++)
    // {
    //     _elem[_size] = A[begin + _size];
    // }
    while (begin < end)
    {
        _elem[_size++] = A[begin++];
    }
}

template <typename T>
void Vector<T>::expand()
{
    if (_size < _capacity)
    {
        return;
    }
    if (_capacity < DEFAULT_CAPACITY)
    {
        _capacity = DEFAULT_CAPACITY;
    }
    if (_capacity > 1024)
    {
        _capacity = _capacity * 1.5;
    }
    else
    {
        _capacity = _capacity * 2;
    }
    T* old_elem = _elem;
    _elem = new T[_capacity];
    for (Rank size = 0; size < _size; size++)
    {
        _elem[size] = old_elem[size];
    }
    delete [] old_elem;
}

class A{
    virtual void a(){};
};

void A::b ()
{

}
