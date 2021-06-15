#ifndef ITERS2_HPP
#define ITERS2_HPP

#include <cstddef>

namespace EnjoLib {
template <typename T>
class Iter {
   public:
       
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;
    
    Iter(T * ptr): ptr(ptr){}
    Iter operator++() { ++ptr; return *this; }
    Iter operator+ (difference_type dif) const { return ptr + dif; }
    Iter operator- (difference_type dif) const { return ptr - dif; }
    difference_type operator- (const Iter & other) const { return ptr - other.ptr; }
    bool operator!=(const Iter & other) const { return ptr != other.ptr; }
    bool operator==(const Iter & other) const { return ptr == other.ptr; }
    const T& operator*() const { return *ptr; }
    const T* operator->() const { return ptr; }
    T& operator*()  { return *ptr; }
    T* operator->() { return ptr; }
     
   private:
     T* ptr;
   };
}

#endif // ITERS2_HPP
