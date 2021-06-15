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

#ifndef MATRIX_H
#define MATRIX_H

#include "../Template/Iters2.hpp"
#include "../3rdParty/stdfwd.hh"
#include "../Util/PimplThin.hpp"

#include <cstddef>
//#include <new>

namespace EnjoLib
{
class VecD;
class Str;
class Matrix// : public stdfwd::vector<VecD>
{
    public:
        EnjoLib::Str ToStr() const;
        void FromStr(const EnjoLib::Str & data);
        EnjoLib::Str Print() const;
        EnjoLib::Str PrintScilab( const char * varName ) const;
        EnjoLib::Str SizeStr() const;
        Matrix();
        Matrix(int n);
        Matrix(int n, int m);
        Matrix(const stdfwd::vector<VecD> & vec);

        virtual ~Matrix();

        Matrix(const Matrix & mat);
        Matrix & operator = (const Matrix & mat);
        
        VecD & atw(size_t idx);

        void Add(const VecD & vec);

        Matrix T() const;
        Matrix & TMe();
        Matrix AdjustMeanRows() const;
        Matrix AdjustMeanCols() const;
        Matrix AdjustMeanCols(const VecD & mean) const;
        Matrix ApplyMeanCols(const VecD & mean) const;
        Matrix ApplyMeanRows(const VecD & mean) const;
        VecD Flatten() const;
        VecD GetCol(int colNum) const;
        int GetNRows() const;
        int GetNCols() const;
        Matrix FilterByMask(const stdfwd::vector<bool> & mask) const;
        Matrix & FilterByMaskMe(const stdfwd::vector<bool> & mask);
        Matrix FilterByMaskD(const VecD & mask) const;
        Matrix & FilterByMaskMeD(const VecD & mask);

        Matrix operator * (const Matrix & par) const;
        //void * operator new (size_t szz); // Against inheriting from std

        const VecD & at(size_t idx) const;
        VecD & at(size_t idx);
        const VecD & operator[](size_t idx) const;
        VecD & operator[](size_t idx);
        size_t size() const;
        bool empty() const;
        void reserve(size_t siz);
        void rem(size_t idx);
        void push_back(const VecD & val);
        void clear();
        const VecD & First() const;
        const VecD & Last() const;
        VecD & First();
        VecD & Last();

        /*
        typedef blRawIterator<VecD>              iterator;
        typedef blRawIterator<const VecD>        const_iterator;

        typedef blRawReverseIterator<VecD>       reverse_iterator;
        typedef blRawReverseIterator<const VecD> const_reverse_iterator;

        const_iterator                                 begin() const;
        const_iterator                                 end() const;

        iterator                                       begin();
        iterator                                       end();

        const_iterator                                 cbegin() const;
        const_iterator                                 cend() const;

        reverse_iterator                               rbegin();
        reverse_iterator                               rend();

        const_reverse_iterator                         crbegin() const;
        const_reverse_iterator                         crend() const;
        */
        
        typedef Iter<const VecD>        const_iterator;
        typedef Iter<VecD>              iterator;
        
        const_iterator                                      begin() const ;
        const_iterator                                       end() const ;
        
        iterator                                        begin() ;
        iterator                                        end() ;
        const_iterator                                 cbegin() const ;
        const_iterator                                 cend() const ;

    protected:
    private:
        Matrix ApplyMean(const Matrix & mat2Apply, const VecD & mean) const;
        Matrix AdjustMean(const Matrix & mat2Apply) const;

        PIMPL_THIN
};
}
#endif // MATRIX_H
