/*
Modified BSD License

This file is a part of Statistical package and originates from:
http://sf.net/projects/enjomitchsorbit

Copyright (c) 2012, Szymon "Enjo" Ender
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef VECTORUTIL_H
#define VECTORUTIL_H

#include <cstddef>

namespace EnjoLib
{
class VecD;
template<class T> class IVecT;
template<class T> class VectorTpl;
class Matrix;

class Assertions
{
    public:
        static void NonEmpty( const Matrix & v1,    const char * identifier );
        template<class T> static void IsEqual( const T & val1, const T & val2, const char * identifier );

        template<class T> static void NonEmpty( const IVecT<T> & v1, const char * identifier );
        template<class T> static void SizesEqual( const IVecT<T> & v1, const IVecT<T> & v2, const char * identifier );
        template<class T> static void SizesEqual( const IVecT<T> & v1, size_t refSize, const char * identifier );
        template<class T> static void AtLeast2Dimensions( const IVecT<T> & v, const char * identifier );

        static void NonEmpty( const VecD & v1, const char * identifier );
        static void SizesEqual( const VecD & v1, const VecD & v2, const char * identifier );
        static void SizesEqual( const VecD & v1, size_t refSize, const char * identifier );
        static void AtLeast2Dimensions( const VecD & v, const char * identifier );

        template<class T> static void NonEmpty( const VectorTpl<T> & v1, const char * identifier );
        template<class T> static void SizesEqual( const VectorTpl<T> & v1, const VectorTpl<T> & v2, const char * identifier );
        template<class T> static void SizesEqual( const VectorTpl<T> & v1, size_t refSize, const char * identifier );
        template<class T> static void AtLeast2Dimensions( const VectorTpl<T> & v, const char * identifier );
        template<class C> static void IndexInBoundsContainer( size_t idx, const C & container, const char * identifier );


        static void SizesEqual( size_t sz, size_t refSize, const char * identifier );
        static void SizesAtLeast( size_t sz, size_t refSize, const char * identifier );
        template<class T> static void IsNonZero( T val, const char * identifier );
        static void Square( const Matrix & m, const char * identifier );
        static void CanMultiply( const Matrix & m1, const Matrix & m2, const char * identifier );
        static void IsTrue( bool cond, const char * identifier );
        static void IsFalse( bool cond, const char * identifier );
        static void Throw(const char * msg, const char * identifier);
        static void Throw(const char * msg, int val, const char * identifier);
        static void IndexInBounds( size_t idx, size_t szz, const char * identifier );


        static bool In(double a, double between, double c);
        static constexpr bool InFast(double a, double between, double c) { return (a < between && between <= c); }
    protected:
    private:
};


    template<class T>
    void Assertions::IsEqual( const T & val1, const T & val2, const char * identifier )
    {
        if (val1 != val2)
            Throw("Not equal at: ", identifier);
    }

    template<class T>
    void Assertions::NonEmpty( const IVecT<T> & v1, const char * identifier )
    {
        if (v1.empty())
            Throw("Empty vector at", identifier);
    }
    template<class T>
    void Assertions::SizesEqual( const IVecT<T> & v1, const IVecT<T> & v2, const char * identifier )
    {
        const size_t vs1 = v1.size();
        const size_t vs2 = v2.size();
        return SizesEqual(vs1, vs2, identifier);
    }
    template<class T>
    void Assertions::SizesEqual( const IVecT<T> & v1, size_t refSize, const char * identifier )
    {
        const size_t vs1 = v1.size();
        return SizesEqual(vs1, refSize, identifier);
    }
    template<class T>
    void Assertions::AtLeast2Dimensions( const IVecT<T> & v, const char * identifier )
    {
        const size_t vs1 = v.size();
        if ( vs1 < 2 )
            Throw("Dimension must be at least 2", identifier);
    }

    template<class T>
    void Assertions::NonEmpty( const VectorTpl<T> & v1, const char * identifier )
    {
        if (v1.empty())
            Throw("Empty vector at", identifier);
    }
    template<class T>
    void Assertions::SizesEqual( const VectorTpl<T> & v1, const VectorTpl<T> & v2, const char * identifier )
    {
        const size_t vs1 = v1.size();
        const size_t vs2 = v2.size();
        return SizesEqual(vs1, vs2, identifier);
    }
    template<class T>
    void Assertions::SizesEqual( const VectorTpl<T> & v1, size_t refSize, const char * identifier )
    {
        const size_t vs1 = v1.size();
        return SizesEqual(vs1, refSize, identifier);
    }
    template<class T>
    void Assertions::AtLeast2Dimensions( const VectorTpl<T> & v, const char * identifier )
    {
        const size_t vs1 = v.size();
        if ( vs1 < 2 )
            Throw("Dimension must be at least 2", identifier);
    }

    template<class T>
    void Assertions::IsNonZero( T val, const char * identifier )
    {
        if ( val == 0 )
            Throw("Zero value", identifier);
    }

    template<class C>
    void EnjoLib::Assertions::IndexInBoundsContainer( size_t idx, const C & container, const char * identifier )
    {
        if (idx >= container.size())
        {
            Assertions::Throw(identifier, "Index above size");
        }
    }
}
#endif // VECTORUTIL_H
