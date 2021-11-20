#ifndef CENTROID_H
#define CENTROID_H

#include <Template/IIterable.hpp>

namespace EnjoLib
{
//template<class T> class VectorTpl;

template<class T>
class Centroid
{
    public:
        Centroid();
        virtual ~Centroid();
        T Calc(const IIterable<T> & vec) const;

    protected:

    private:
};
}

#endif // CENTROID_H
