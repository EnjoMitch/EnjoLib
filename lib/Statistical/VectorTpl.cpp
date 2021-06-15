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

#include "VectorTpl.hpp"
#include "Assertions.hpp"
#include "../Util/CharManipulationsTplVec.hpp"
#include "../Util/Tokenizer.hpp"
#include <Util/Osstream.hpp>
#include <Util/Except.hpp>

//#include <STD/Algorithm.hpp>
#include <STD/Iostream.hpp>
#include <numeric>
#include <cmath>
#include <iomanip>

using namespace EnjoLib;

template<class T>
VectorTpl<T>::VectorTpl( const EnjoLib::Str & data )
{
    const Tokenizer tok;
    const CharManipulationsTplVec cman;
    Init(cman.ToNumbersVec<T>(tok.Tokenize(data)));
}

template<class T>
VectorTpl<T>::VectorTpl( const std::vector<T> & init )
{
    Init(init);
}

template<class T>
VectorTpl<T>::VectorTpl( const std::vector<bool> & init )
{
    Init(init);
}

template<class T>
VectorTpl<T>::VectorTpl( int n )
{
    this->reserve(n);
    for (int i = 0; i < n; ++i)
        this->push_back(0);
}

template<class T>
VectorTpl<T>::VectorTpl( int n, const T & val )
{
    this->reserve(n);
    for (int i = 0; i < n; ++i)
        this->push_back(val);
}

template<class T>
VectorTpl<T>::VectorTpl(){}

template<class T>
VectorTpl<T>::~VectorTpl(){}

template<class T>
T & VectorTpl<T>::atw(size_t idx)
{
    return this->at(idx);
}

template<class T>
std::vector<bool> VectorTpl<T>::ToVecBool() const
{
    std::vector<bool> ret(this->size());
    for (size_t i = 0; i < this->size(); ++i)
    {
        const T & thisVal = this->at(i);
        ret.at(i) = thisVal == 0 ? 0 : 1;
    }
    return ret;
}

template<class T>
void VectorTpl<T>::Add(const T & val)
{
    this->push_back(val);
}

template<class T>
void VectorTpl<T>::Add(const VectorTpl<T> & vec)
{
    for (CIt cit = vec.begin(), citend = vec.end(); cit != citend; ++cit) this->push_back(*cit);
}

template<class T>
EnjoLib::Str VectorTpl<T>::ToStr() const
{
    return this->Print();
}

template<class T>
EnjoLib::Str VectorTpl<T>::Print(int precision) const
{
    EnjoLib::Osstream ss;
    if (precision > 0)
    {
        ss.OStr() << std::setprecision(precision);
    }
    for (CIt cit = this->begin(), citend = this->end(); cit != citend; ++cit)
    {
        ss << *cit;
        if ( cit != this->end() - 1)
            ss << " ";
    }

    return ss.str();
}

template<class T>
EnjoLib::Str VectorTpl<T>::PrintPython( const char * varName ) const
{
    EnjoLib::Osstream ss;
    ss << varName << " = [ ";
    for (CIt cit = this->begin(), citend = this->end(); cit != citend; ++cit)
        ss << *cit << ", ";
    ss << " ];\n";
    return ss.str();
}

template<class T>
EnjoLib::Str VectorTpl<T>::PrintScilab( const char * varName ) const
{
    EnjoLib::Osstream ss;
    ss << "\n" << varName << " = [ ";
    for (CIt cit = this->begin(), citend = this->end(); cit != citend; ++cit)
        ss << *cit << " ";
    ss << " ];\n";
    return ss.str();
}

template<class T>
T VectorTpl<T>::Len() const
{
    return sqrt( SumSquares() );
}

template<class T>
VectorTpl<T> VectorTpl<T>::Norm() const
{
    T len = Len();
    if ( len == 0 )
        return VectorTpl();
    return VectorTpl(*this) /= Len();
}

template<class T>
T VectorTpl<T>::SumSquares() const
{
    T sumSquares = 0;
    for (CIt cit = this->begin(), citend = this->end(); cit != citend; ++cit)
        sumSquares += (*cit) * (*cit);

    return sumSquares;
}

template<class T>
T VectorTpl<T>::SumAbs() const
{
    T sumAbs = 0;
    for (CIt cit = this->begin(), citend = this->end(); cit != citend; ++cit)
        sumAbs += fabs(*cit);

    return sumAbs;
}

template<class T>
T VectorTpl<T>::Mean() const
{
    if ( this->empty() )
        return 0;
    const T & mean = Sum() / static_cast<T>(this->size());
    return mean;
}

template<class T>
T VectorTpl<T>::MeanWeighted() const
{
    if ( this->empty() )
        return 0;
    T sumWeighted = 0;
    T sumWeights = 0;
    for (unsigned i = 0; i < this->size(); ++i)
    {
        const T weight = (this->size() - i) / T(this->size());
        const T value = this->at(i);
        const T valWeighted = weight * value;
        sumWeighted += valWeighted;
        sumWeights += weight;
    }
    //const T mean = sumWeighted / (T) this->size();
    const T mean = sumWeighted / sumWeights;
    return mean;
}


template<class T>
VectorTpl<T> VectorTpl<T>::AdjustMean() const
{
    const T mean = Mean();
    const VectorTpl<T> & ret = operator - (mean);
    //std::cout << "mean = " << mean << std::endl;
    //std::cout << "ret = " << this->Print() << std::endl;
    return ret;
}

template<class T>
VectorTpl<T> VectorTpl<T>::Slice(unsigned idx, unsigned len) const
{
    const size_t minIdx = idx - len + 1;
    const size_t maxIdx = idx + 1;
    Assertions::IsTrue(idx < this->size(),  "Index exceeding the data len");
    Assertions::IsTrue(minIdx >= 0,         "Min index exceeding the data len");

    VectorTpl<T> ret(maxIdx - minIdx);
    for (size_t i = minIdx, j = 0; i < maxIdx; ++i, ++j)
    {
        //ret.Add(this->at(i));
        ret.at(j) = this->at(i);
    }
    return ret;
}

template<class T>
VectorTpl<T> VectorTpl<T>::SliceTS(unsigned idx, unsigned len) const
{
    VectorTpl<T> ret;
    return Slice(idx, len); // TODO
}

template<class T>
VectorTpl<T> VectorTpl<T>::Diffs() const
{
    VectorTpl<T> ret;
    ret.Add(0); // Add a leading zero, to ensure equal length for simplicity
    for (size_t i = 1; i < this->size(); ++i)
    {
        const T & diff = this->at(i) - this->at(i-1);
        ret.Add(diff);
    }
    return ret;
}

template<class T>
VectorTpl<T> VectorTpl<T>::LogSigned() const
{
    VectorTpl<T> ret;
    /// TODO: If the input is too small, the log has no effect. Make unit and divide before returning.
    //const T & mean = Mean();
    for (size_t i = 0; i < this->size(); ++i)
    {
        const T & val = this->at(i);
        const T & logArg = fabs(val) + 1;
        T valNew = log(logArg);
        if (val < 0 )
        {
            valNew = -valNew;
        }
        ret.Add(valNew);
    }
    return ret;
}

template<class T>
T VectorTpl<T>::Sum() const
{
    return std::accumulate(this->begin(), this->end(), 0.0);
}

template<class T>
T VectorTpl<T>::Max() const
{
    T mx = -100;
    for (CIt cit = this->begin(), citend = this->end(); cit != citend; ++cit)
    {
        if (mx == -100 || *cit > mx)
            mx = *cit;
    }
    return mx;
}
template<class T>
T VectorTpl<T>::MaxAbs() const
{
    T mx = -100;
    for (CIt cit = this->begin(), citend = this->end(); cit != citend; ++cit)
    {
        const T val = fabs(*cit);
        if (mx == -100 || val > mx)
            mx = val;
    }
    return mx;
}

template<class T>
T VectorTpl<T>::Min() const
{
    T mx = -100;
    for (CIt cit = this->begin(), citend = this->end(); cit != citend; ++cit)
    {
        if (mx == -100 || *cit < mx)
            mx = *cit;
    }
    return mx;
}

template<class T>
const T & VectorTpl<T>::First() const
{
    Assertions::NonEmpty(*this, "First");
    return this->front();
}

template<class T>
const T & VectorTpl<T>::Last() const
{
    Assertions::NonEmpty(*this, "Last");
    return this->back();
}

template<class T>
VectorTpl<T> & VectorTpl<T>::operator += (const T f)
{
    for (It it = this->begin(), itend = this->end(); it != itend; ++it)
        (*it) += f;

    return *this;
}

template<class T>
VectorTpl<T> & VectorTpl<T>::operator -= (const T f)
{
    for (It it = this->begin(), itend = this->end(); it != itend; ++it)
        (*it) -= f;

    return *this;
}

template<class T>
VectorTpl<T> & VectorTpl<T>::operator /= (const T f)
{
    for (It it = this->begin(), itend = this->end(); it != itend; ++it)
        (*it) /= f;

    return *this;
}

template<class T>
VectorTpl<T> & VectorTpl<T>::operator *= (const T f)
{
    for (It it = this->begin(), itend = this->end(); it != itend; ++it)
        (*it) *= f;

    return *this;
}

template<class T>
VectorTpl<T> & VectorTpl<T>::operator += (const VectorTpl<T> &  p)
{
    Assertions::SizesEqual(*this, p, "VectorTpl::+=");
    for (size_t i = 0; i < this->size(); ++i)
        this->at(i) += p[i];

    return *this;
}

template<class T>
VectorTpl<T> & VectorTpl<T>::operator -= (const VectorTpl<T> &  p)
{
    Assertions::SizesEqual(*this, p, "VectorTpl::-=");
    for (size_t i = 0; i < this->size(); ++i)
        this->at(i) -= p[i];

    return *this;
}

template<class T>
VectorTpl<T> VectorTpl<T>::operator + (const VectorTpl<T> &  p) const
{
    Assertions::SizesEqual(*this, p, "VectorTpl::+");
    return VectorTpl(*this) += p;
}

template<class T>
VectorTpl<T> VectorTpl<T>::operator - (const VectorTpl<T> &  p) const
{
    Assertions::SizesEqual(*this, p, "VectorTpl::-");
    return VectorTpl(*this) -= p;
}

template<class T>
VectorTpl<T> VectorTpl<T>::operator - () const
{
    VectorTpl neg(*this);
    for (It it = neg.begin(), itend = neg.end(); it != itend; ++it)
        (*it) = -(*it);
    return neg;
}

template<class T>
VectorTpl<T> VectorTpl<T>::operator - (const T f) const
{
    return VectorTpl(*this) -= f;
}

template<class T>
VectorTpl<T> VectorTpl<T>::operator + (const T f) const
{
    return VectorTpl(*this) += f;
}

template<class T>
VectorTpl<T> VectorTpl<T>::operator * (const T f) const
{
    return VectorTpl(*this) *= f;
}

template<class T>
VectorTpl<T> VectorTpl<T>::operator / (const T f) const
{
    return VectorTpl(*this) /= f;
}

template<class T>
bool VectorTpl<T>::operator > (const VectorTpl<T> &  p) const
{
    return Len() > p.Len();
}

template<class T>
bool VectorTpl<T>::operator < (const VectorTpl<T> &  p) const
{
    return Len() < p.Len();
}

template<class T>
void * VectorTpl<T>::operator new (size_t szz)
{
    //static_assert(false, "VectorTpl<T>::new not implemented!"); // C++11
    throw EnjoLib::ExceptRuntimeError("VectorTpl<T>::new not implemented!");
}


namespace EnjoLib {
    template class VectorTpl<float>;
    template class VectorTpl<double>;
    template class VectorTpl<uint64_t>;
}
