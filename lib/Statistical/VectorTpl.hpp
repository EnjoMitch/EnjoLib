#ifndef VECTORTPL_H
#define VECTORTPL_H

#include <Util/Str.hpp>
#include <STD/Vector.hpp>

namespace EnjoLib
{
template<class T>
class VectorTpl : public std::vector<T>
{
    public:
        EnjoLib::Str ToStr() const; // TODO
        EnjoLib::Str Print(int precision = 0) const; // TODO
        EnjoLib::Str PrintScilab( const char * varName ) const;
        EnjoLib::Str PrintPython( const char * varName ) const;

        VectorTpl( const std::vector<T> & init );
        VectorTpl( const std::vector<bool> & init );
        VectorTpl( int n );
        VectorTpl( int n, const T & val );
        VectorTpl( const EnjoLib::Str & data );
        VectorTpl();
        virtual ~VectorTpl();
        
        T & atw(size_t idx);

        template<class U>
        void Init(const std::vector<U> & init);

        void Add(const T & val);
        void Add(const VectorTpl<T> & vec);
        
        std::vector<bool> ToVecBool() const;

        //! Length of vector
        T Len() const;
        //! Normalised copy of vector
        VectorTpl Norm() const;
        T SumSquares() const;
        T SumAbs() const;
        T Sum() const;
        T Mean() const;
        T MeanWeighted() const;
        T Max() const;
        T MaxAbs() const;
        T Min() const;

        const T & First() const;
        const T & Last() const;

        VectorTpl AdjustMean() const;
        VectorTpl Slice  (unsigned idx, unsigned len) const;
        VectorTpl SliceTS(unsigned idx, unsigned len) const;
        VectorTpl Diffs() const;
        VectorTpl LogSigned() const;

        VectorTpl & operator += (const VectorTpl & par);
        VectorTpl & operator -= (const VectorTpl & par);
        VectorTpl & operator /= (const T f);
        VectorTpl & operator *= (const T f);
        VectorTpl & operator += (const T f);
        VectorTpl & operator -= (const T f);

        VectorTpl operator + (const VectorTpl & par) const;
        VectorTpl operator - (const VectorTpl & par) const;
        VectorTpl operator - () const;
        VectorTpl operator + (const T f) const;
        VectorTpl operator - (const T f) const;
        VectorTpl operator * (const T f) const;
        VectorTpl operator / (const T f) const;
        bool operator > (const VectorTpl & par) const;
        bool operator < (const VectorTpl & par) const;
        
        void * operator new (size_t szz);



    protected:
    private:
        void SizesEqual( const VectorTpl & par, const char * functionName ) const;

        typedef typename std::vector<T>::const_iterator CIt;
        typedef typename std::vector<T>::iterator It;
};

template<class T>
template<class U>
void VectorTpl<T>::Init(const std::vector<U> & init)
{
    this->reserve(init.size());
    for (typename std::vector<U>::const_iterator it = init.begin(), itend = init.end(); it != itend; ++it)
        this->push_back(*it);
}
}

#endif // VECTORTPL_H
