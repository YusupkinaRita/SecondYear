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
    std::memcpy(temp_arr,_array,(_size/3)*sizeof(T));
    delete[] _array;
    _array=temp_arr;
    }
    _array[_count]=elem;

    if(_array[_count]>_max)
    _max=_array[_count];
    if(_array[_count]<_min)
    _min=_array[_count];
    _count++;

    }
    T compare (const void * a, const void * b){
        return ( *(T*)a - *(T*)b );
        }

    bool IsContains(T elem) {
       
        std::qsort(_array[0], _count,sizeof(T), compare);

        return std::binary_search(_array[0], _array[_count], elem);
        //for(size_t i=0;i<_count;i++){
        //    if(_array[i]==elem)
        //   return true;
        //}
        
        
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