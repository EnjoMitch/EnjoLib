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

#include "Matrix.hpp"
#include "Assertions.hpp"
#include "../Util/ProtocolCreator.h"
#include "../Util/Tokenizer.hpp"
#include "../Util/VecD.hpp"
#include <Util/Except.hpp>
#include <Util/PimplDeleter.hpp>

#include <Util/Osstream.hpp>
#include <Util/CoutBuf.hpp>
#include <STD/VectorCpp.hpp>

using namespace EnjoLib;

struct Matrix::Impl
{
    Impl(){}
    Impl(const std::vector<VecD> & dat) : dat(dat) {}
    Impl(const Matrix::Impl & impl) : dat(impl.dat) {}
    std::vector<VecD> dat;
};
PIMPL_DELETER(Matrix)

Matrix::Matrix()
: m_impl(new Impl())
{
}

Matrix::Matrix(int n)
: m_impl(new Impl())
{
    this->reserve(n);
    for (int i = 0; i < n; ++i)
        push_back( VecD(n) );
}

Matrix::Matrix(int n, int m)
: m_impl(new Impl())
{
    this->reserve(n);
    for (int i = 0; i < n; ++i)
        push_back( VecD(m) );
}

Matrix::Matrix(const stdfwd::vector<VecD> & vec)
: m_impl(new Impl(vec))
{

}

Matrix::~Matrix()
{
}

VecD & Matrix::atw(size_t idx)
{
    return at(idx);
}

void Matrix::Add(const VecD & vec)
{
    push_back( vec );
}

int Matrix::GetNRows() const
{
    return size();
}

int Matrix::GetNCols() const
{
    if ( empty() )
        return 0;
    return this->operator[](0).size();
}

/*
int Matrix::GetNCols() const
{
    if ( size() == 0 )
        return 0;
    return this->operator[](0).size();
}
*/

EnjoLib::Str Matrix::Print() const // TODO
{
    EnjoLib::Osstream ss;
    //ss << "\n"; // breaks file exchange
    for ( Matrix::const_iterator it = begin(); it != end(); ++it)
        ss << it->Print() << "\n";
    return ss.str();
}

EnjoLib::Str Matrix::PrintScilab( const char * varName ) const // TODO
{
    EnjoLib::Osstream ss;
    ss << "\n" << varName << " = [ ";
    for ( Matrix::const_iterator it = begin(); it != end(); ++it)
        ss << it->Print() << "\n";
    ss << " ];\n";
    return ss.str();
}

EnjoLib::Str Matrix::SizeStr() const
{
    EnjoLib::Osstream oss;
    oss << "(" << GetNRows() << ", " << GetNCols() << ")";
    return oss.str();
}

EnjoLib::Str Matrix::ToStr() const
{
    ProtocolCreator pcc('M');
    for ( Matrix::const_iterator it = begin(); it != end(); ++it)
    {
        pcc.AddStr(it->Print());
    }
    return pcc.Get();
}
void Matrix::FromStr(const EnjoLib::Str & data)
{
    clear();
    const Tokenizer tok;
    const VecStr & lines = tok.Tokenize(data, 'M');
    for (size_t i = 0; i < lines.size(); ++i)
    {
        const Str & line = lines.at(i);
        Add(VecD(line));
    }
}

Matrix Matrix::T() const
{
    const int nrows = GetNRows();
    const int ncols = GetNCols();
    Matrix t(ncols, nrows);
    for ( int i = 0; i < nrows; ++i )
        for ( int j = 0; j < ncols; ++j )
            t[j][i] = at(i)[j];
    return t;
}

Matrix Matrix::FilterByMaskD(const EnjoLib::VecD & mask) const
{
    Assertions::SizesEqual(at(0), mask.size(), "Matrix::FilterByMask");

    Matrix ret;
    ret.reserve(size());
    const size_t maskSize = mask.size();
    for (size_t i = 0; i < this->size(); ++i)
    {
        VecD row;
        row.reserve(maskSize);
        for (size_t j = 0; j < maskSize; ++j)
        {
            const double weight = mask.at(j);
            row.push_back(at(i).at(j) * weight);
            //row.push_back(this->operator[](i)[j]);
        }
        ret.Add(row);
    }
    return ret;
}
Matrix & Matrix::FilterByMaskMeD(const EnjoLib::VecD & mask)
{
    *this = FilterByMaskD(mask);
    return *this;
}

Matrix Matrix::FilterByMask(const std::vector<bool> & mask) const
{
    Assertions::SizesEqual(at(0), mask.size(), "Matrix::FilterByMask");

    Matrix ret;
    ret.reserve(size());
    const size_t maskSize = mask.size();
    for (size_t i = 0; i < this->size(); ++i)
    {
        VecD row;
        row.reserve(maskSize);
        for (size_t j = 0; j < maskSize; ++j)
        {
            if (mask.at(j))
            {
                row.push_back(at(i).at(j));
                //row.push_back(this->operator[](i)[j]);
            }
        }
        ret.Add(row);
    }
    return ret;
}

Matrix & Matrix::FilterByMaskMe(const std::vector<bool> & mask)
{
    *this = FilterByMask(mask);
    return *this;
}

VecD Matrix::Flatten() const
{
    const int nrows = GetNRows();
    const int ncols = GetNCols();
    VecD flat;
    flat.reserve(nrows * ncols);
    for ( int i = 0; i < nrows; ++i )
        for ( int j = 0; j < ncols; ++j )
            flat.push_back(this->operator[](i)[j]);
    return flat;
}

Matrix & Matrix::TMe()
{
    *this = T();
    return *this;
}

Matrix Matrix::operator * (const Matrix & par) const
{
    Assertions::CanMultiply( *this, par, "Matrix::operator *" );
    Matrix prod(GetNRows(), par.GetNCols());
    const int nrows = prod.GetNRows();
    const int ncols = prod.GetNCols();
    const int ncolsThis = GetNCols();
    for (int i = 0; i < nrows; ++i)
        for (int j = 0; j < ncols; ++j)
        {
            double prodSum = 0;
            for (int ai = 0; ai < ncolsThis; ++ai )
            {
                //prodSum += at(i).at(ai) * par.at(ai).at(j);
                prodSum += this->operator[](i)[ai] * par[ai][j];
            }
            prod[i][j] = prodSum;
        }
    return prod;
}

/*
// Against inheriting from std::
void * Matrix::operator new (size_t szz)
{
    //static_assert(false, "VectorTpl<T>::new not implemented!"); // C++11
    throw EnjoLib::ExceptRuntimeError("Matrix::new not implemented!");
}
*/

Matrix Matrix::AdjustMeanRows() const
{
    const Matrix & ret = AdjustMean(*this);
    return ret;
}

Matrix Matrix::AdjustMeanCols() const
{
    const Matrix & ret = AdjustMean(T());
    return ret.T();
}

Matrix Matrix::ApplyMeanRows(const VecD & mean) const
{
    return ApplyMean(*this, mean);
}

Matrix Matrix::ApplyMeanCols(const VecD & mean) const
{
    const Matrix & mulT = T();
    return ApplyMean(mulT, mean);
}

Matrix Matrix::ApplyMean(const Matrix & mat2Apply, const VecD & mean) const
{
    Matrix ret;
    Assertions::SizesEqual(mean, mat2Apply.size(), "Matrix::ApplyMean");
    for (size_t row = 0; row < mat2Apply.size(); ++row)
    {
        const VecD & apl = mat2Apply.at(row) + mean.at(row);
        ret.push_back(apl);
    }
    return ret;
}

Matrix Matrix::AdjustMean(const Matrix & mat2Apply) const
{
    if (mat2Apply.GetNCols() == 1)
    {
        ELO
        LOG << "Warning at Matrix::AdjustMean(): Matrix of one column returns 0\n";
    }
    Matrix ret;
    for ( int i = 0; i < mat2Apply.GetNRows(); ++i )
    {
        const VecD & apl = mat2Apply.at(i);

        Assertions::SizesEqual(apl, size(), "Matrix::AdjustMean");
        ret.push_back( apl.AdjustMean() );
    }
    return ret;
}

Matrix Matrix::AdjustMeanCols(const VecD & mean) const
{
    Matrix ret;
    for ( int i = 0; i < GetNRows(); ++i )
    {
        const VecD & apl = at(i);

        Assertions::SizesEqual(apl, mean, "Matrix::AdjustMean");
        ret.push_back( apl - mean );
    }
    return ret;
}

VecD Matrix::GetCol(int colNum) const
{
    VecD ret;
    for (int i = 0; i < GetNRows(); ++i)
    {
        ret.Add(at(i).at(colNum));
    }
    return ret;
}

const VecD & Matrix::at(size_t idx) const
{
    return GetImpl().dat.at(idx);
}
VecD & Matrix::at(size_t idx)
{
    return GetImplRW().dat.at(idx);
}

void Matrix::push_back(const VecD & val)
{
    GetImplRW().dat.push_back(val);
}

const VecD & Matrix::operator[](size_t idx) const
{
    return GetImpl().dat[idx];
}

VecD & Matrix::operator[](size_t idx)
{
    return GetImplRW().dat[idx];
}

size_t Matrix::size() const
{
    return GetImpl().dat.size();
}

bool Matrix::empty() const
{
    return GetImpl().dat.empty();
}
void Matrix::reserve(size_t siz)
{
    return GetImplRW().dat.reserve(siz);
}
void Matrix::clear()
{
    return GetImplRW().dat.clear();
}
const VecD & Matrix::First() const
{
    Assertions::NonEmpty(*this, "First");
    return GetImpl().dat.front();
}
const VecD & Matrix::Last() const
{
    Assertions::NonEmpty(*this, "Last");
    return GetImpl().dat.back();
}
VecD & Matrix::First()
{
    Assertions::NonEmpty(*this, "First");
    return GetImplRW().dat.front();
}
VecD & Matrix::Last()
{
    Assertions::NonEmpty(*this, "Last");
    return GetImplRW().dat.back();
}

Matrix::Matrix(const Matrix & mat)
: m_impl(new Impl(mat.GetImpl().dat))
{

}
Matrix & Matrix::operator = (const Matrix & mat)
{
    GetImplRW() = mat.GetImpl();
    return *this;
}

void Matrix::rem(size_t idx)
{
    m_impl->dat.erase(m_impl->dat.begin() + idx);
}

Matrix::iterator Matrix::begin()          {return iterator(&m_impl->dat[0]);}
Matrix::iterator Matrix::end()            {return iterator(&m_impl->dat[size()]);}
Matrix::const_iterator Matrix::begin() const    {return const_iterator(&m_impl->dat[0]);}
Matrix::const_iterator Matrix::end()   const    {return const_iterator(&m_impl->dat[size()]);}
Matrix::const_iterator Matrix::cbegin() const   {return begin();}
Matrix::const_iterator Matrix::cend()   const   {return end();}

/*
Matrix::const_iterator                                       Matrix::begin() const {return const_iterator(&m_impl->dat[0]);}
Matrix::const_iterator                                       Matrix::end() const {return const_iterator(&m_impl->dat[size()]);}

Matrix::iterator                                       Matrix::begin() {return iterator(&m_impl->dat[0]);}
Matrix::iterator                                       Matrix::end(){return iterator(&m_impl->dat[size()]);}

Matrix::const_iterator                                 Matrix::cbegin() const {return const_iterator(&m_impl->dat[0]);}
Matrix::const_iterator                                 Matrix::cend() const {return const_iterator(&m_impl->dat[size()]);}

Matrix::reverse_iterator                               Matrix::rbegin(){return reverse_iterator(&m_impl->dat[size() - 1]);}
Matrix::reverse_iterator                               Matrix::rend(){return reverse_iterator(&m_impl->dat[-1]);}

Matrix::const_reverse_iterator                         Matrix::crbegin() const {return const_reverse_iterator(&m_impl->dat[size() - 1]);}
Matrix::const_reverse_iterator                         Matrix::crend() const {return const_reverse_iterator(&m_impl->dat[-1]);}
*/