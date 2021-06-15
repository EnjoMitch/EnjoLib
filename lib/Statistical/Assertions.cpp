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

#include "Assertions.hpp"
#include "VectorTpl.hpp"
#include "Matrix.hpp"
#include "../Util/VecD.hpp"

#include <Util/CharManipulations.hpp>
#include <Util/Except.hpp>
#include <Util/Osstream.hpp>

using namespace EnjoLib;

void Assertions::CanMultiply( const Matrix & m1, const Matrix & m2, const char * identifier  )
{
    const size_t m1cols = m1.GetNCols();
    const size_t m2rows = m2.GetNRows();
    if ( m1cols != m2rows )
    {
        EnjoLib::Osstream oss;
        oss << "Can't multiply matrices of sizes " << m1.SizeStr() << " and " << m2.SizeStr() << " at\n" << identifier << "\n";
        throw EnjoLib::ExceptInvalidArg( oss.str() );
    }
}
void Assertions::Square( const Matrix & m, const char * identifier )
{
    const size_t msz = m.size();
    for (Matrix::const_iterator it = m.begin(); it != m.end(); ++it)
    {
        const size_t its = it->size();
        if ( its != msz )
        {
            const EnjoLib::Str msg = EnjoLib::Str("Matrix not square at\n") + identifier + "()\n";
            throw EnjoLib::ExceptInvalidArg( msg.c_str() );
        }
            
    }
}
void Assertions::NonEmpty( const Matrix & mat, const char * identifier )
{
    if (mat.empty())
    {
        const EnjoLib::Str msg = EnjoLib::Str("Empty matrix at\n") + identifier + "()\n";
        throw EnjoLib::ExceptInvalidArg(  msg.c_str() );
    }
}
void Assertions::SizesEqual( size_t sz, size_t refSize, const char * identifier )
{
    if ( sz != refSize )
    {
        EnjoLib::Osstream oss;
        oss << "Incompatible sizes of: " << sz << " & " << refSize << ", at:\n" << identifier << "()\n";
        throw EnjoLib::ExceptInvalidArg(oss.str());
    }
}

void Assertions::SizesAtLeast( size_t sz, size_t refSize, const char * identifier )
{
    if ( sz < refSize )
    {
        EnjoLib::Osstream oss;
        oss << "Size of: " << sz << " is smaller than expected " << refSize << ", at:\n" << identifier << "()\n";
        throw EnjoLib::ExceptInvalidArg(oss.str());
    }
}

void Assertions::IsTrue( bool cond, const char * identifier )
{
    if ( ! cond )
    {
        EnjoLib::Osstream oss;
        oss << "Condition is false, at:\n" << identifier << "()\n";
        throw EnjoLib::ExceptInvalidArg(oss.str());
    }
}

void Assertions::IsFalse( bool cond, const char * identifier )
{
    if ( cond )
    {
        EnjoLib::Osstream oss;
        oss << "Condition is true, at:\n" << identifier << "()\n";
        throw EnjoLib::ExceptInvalidArg(oss.str());
    }
}

void Assertions::Throw(const char * msg, const char * identifier)
{
    const EnjoLib::Str msgStr = EnjoLib::Str(msg) + identifier + "()\n";
    throw EnjoLib::ExceptInvalidArg( msgStr.c_str() );
}

void Assertions::Throw(const char * msg, int val, const char * identifier)
{
    throw EnjoLib::ExceptInvalidArg( (EnjoLib::Str(msg) + CharManipulations().ToStr(val) + '\n' + identifier + "()\n"));
}

/*
template<class T>
void Assertions::SizesEqual( const VectorTpl<T> & v1, const VectorTpl<T> & v2, const char * identifier ) const
{
    if ( v1.size() != v2.size() )
        throw EnjoLib::ExceptInvalidArg( EnjoLib::Str("Incompatible sizes at\n") + identifier + "()\n");
}

template<class T>
void Assertions::AtLeast2Dimensions( const VectorTpl<T> & v, const char * identifier ) const
{
    if ( v.size() < 2 )
        throw EnjoLib::ExceptInvalidArg( EnjoLib::Str("Dimension must be at least 2\n") + identifier + "()\n");
}
*/

void Assertions::NonEmpty( const VecD & v1, const char * identifier )
{
    if (v1.empty())
        Throw("Empty vector at", identifier);
}
void Assertions::SizesEqual( const VecD & v1, const VecD & v2, const char * identifier )
{
    const size_t vs1 = v1.size();
    const size_t vs2 = v2.size();
    return SizesEqual(vs1, vs2, identifier);
}
void Assertions::SizesEqual( const VecD & v1, size_t refSize, const char * identifier )
{
    const size_t vs1 = v1.size();
    return SizesEqual(vs1, refSize, identifier);
}
void Assertions::AtLeast2Dimensions( const VecD & v, const char * identifier )
{
    const size_t vs1 = v.size();
    if ( vs1 < 2 )
        Throw("Dimension must be at least 2", identifier);
}

void Assertions::IndexInBounds( size_t idx, size_t szz, const char * identifier )
{
    if (idx >= szz)
    {
        Assertions::Throw(identifier, "Index above size");
    }
}