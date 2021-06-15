/*
Modified BSD License

This file originates from:
http://sf.net/projects/enjomitchsorbit

Copyright (c) 2002, David "Daver" Rowbotham
Copyright (c) 2011, Szymon "Enjo" Ender
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

#ifndef CHAR_MANIPULATIONS_HPP_INCLUDED
#define CHAR_MANIPULATIONS_HPP_INCLUDED

#include <Util/Str.hpp>
#include <Util/VecStr.hpp>
#include <3rdParty/stdfwd.hh>

namespace EnjoLib
{
class CharManipulations
{
public:
	/// Author - David "Daver" Rowbotham
	//void char_replace_s(char *src, char lookfor, char replacewith, size_t maxlength);
	/// Author - Szymon Ender
	EnjoLib::Str Replace(const EnjoLib::Str & in, const EnjoLib::Str & lookFor, const EnjoLib::Str & replaceWith ) const;
	EnjoLib::Str Trim(const EnjoLib::Str & in ) const;
	EnjoLib::Str ToStr(double d, unsigned precision) const; // Don't use!
	EnjoLib::Str ToStr(int i) const;
	EnjoLib::Str MakeLeadingZeroes(int d, unsigned numZeroes) const;
	bool StartsWith(const EnjoLib::Str & str, const EnjoLib::Str & prefix) const;
	bool Contains(const EnjoLib::Str & str, const EnjoLib::Str & toFind) const;
	//bool EndsWith(const EnjoLib::Str & str, const EnjoLib::Str & sufffix) const;
	bool EndsWith(const Str & str, const Str & sufffix) const;
	stdfwd::pair<Str, Str> GetFileNameExtension(const Str & fileWithExt) const;
	bool ToDouble(const EnjoLib::Str & in, double * d) const;
	double ToDouble(const EnjoLib::Str & in) const;
	int ToInt(const EnjoLib::Str & in) const;
	bool ToInt(const EnjoLib::Str & in, int * i) const;
	

    VecStr EndsWith(const VecStr & files, const Str & sufffix) const;
	
	Str ToUpper(Str in) const;
	Str ToLower(Str in) const;
	EnjoLib::Str GetLineSeparator(unsigned num, char sep = '-') const;

private:
};
}

#endif
