#include <cstring>
#include <limits>
#include <cstdlib>
#include <algorithm>
template<typename T>
class ArrayHandler {
private:
    size_t _size;
    size_t _count;
    T* _array;
    T _max;
    T _min;
public:
    ArrayHandler(size_t size = 10) {
    _size=size;
    _array=new T[_size];
    _max=std::numeric_limits<T>::min();
    _min=std::numeric_limits<T>::max();
    _count=0;

    }

    void AppendElem(T elem) {
    if(_count==_size){
        _size=_size*3;
        T* temp_arr=new T[_size];
        std::memcpy(temp_arr,_array,(_count)*sizeof(T));
        delete[] _array;
        _array=temp_arr;
    }
    _array[_count]=elem;

    if(elem>_max)
        _max=elem;
    if(elem<_min)
        _min=elem;
    _count++;
    }
    T compare (const T * a, const T * b){
        return ( *a - *b );
        }

    bool IsContains(T elem) {
       
        std::qsort(_array[0], _count,sizeof(T), compare);
        return std::binary_search(_array[0], _array[_count], elem);
    }

    T GetMax() {
        return _max;
    }

    T GetMin() {
        return _min;
    }

    ~ArrayHandler() {
        delete[]_array;

    }

};