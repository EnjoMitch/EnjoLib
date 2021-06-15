#ifndef CORRADEPOINTERFWD_H_INCLUDED
#define CORRADEPOINTERFWD_H_INCLUDED

namespace Corrade { namespace Containers {
    template <class T> class Pointer;
}
}

template<class T>
using CorPtr = Corrade::Containers::Pointer<T>;

#endif // CORRADEPOINTERFWD_H_INCLUDED
