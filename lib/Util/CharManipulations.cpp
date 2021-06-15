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

#include "CharManipulations.hpp"
#include "CharManipulationsTpl.hpp"
#include <Util/Except.hpp>

#include <STD/Ostream.hpp>
#include <STD/Algorithm.hpp>
#include <cstdlib>

using namespace EnjoLib;

VecStr CharManipulations::EndsWith(const VecStr & files, const Str & sufffix) const
{
    VecStr ret;
    //for (const EnjoLib::Str & file : files)
    for (int i = 0; i < int(files.size()); ++i)
    {
        const Str & file = files.at(i);
        if (CharManipulations().EndsWith(file, sufffix))
            ret.push_back(file);
    }
    return ret;
}


/*
void CharManipulations::char_replace_s(char *src, char lookfor, char replacewith, size_t maxlength)
{
    char *src_ptr = src;
    unsigned counter = 0;
    while( *src_ptr != NULL && counter < maxlength )
    {
        if(*src_ptr == lookfor)
            *src_ptr = replacewith;
        ++src_ptr;
        ++counter;
    }
}
*/

EnjoLib::Str CharManipulations::Replace(const EnjoLib::Str & in, const EnjoLib::Str & lookFor, const EnjoLib::Str & replaceWith ) const
{
    //replace(baseDirNoZ.begin(), baseDirNoZ.end(), '\\', '/');
    std::string out = in.str();
    size_t pos;
    while ( (pos = out.find(lookFor.c_str())) != std::string::npos )
    {
        out.replace(pos, lookFor.size(), replaceWith.c_str());
    }
    return out;
}

bool CharManipulations::StartsWith(const EnjoLib::Str & str, const EnjoLib::Str & prefix) const
{
    if (prefix.size() > str.size())
        return false;
    return std::equal(prefix.strRef().begin(), prefix.strRef().end(), str.strRef().begin());
}

bool CharManipulations::EndsWith(const Str & str, const Str & sufffix) const
{
    if (sufffix.size() > str.size())
        return false;
    return std::equal(sufffix.strRef().begin(), sufffix.strRef().end(), str.strRef().end() - sufffix.size());
}

bool CharManipulations::Contains(const EnjoLib::Str & str, const EnjoLib::Str & toFind) const
{
    return (str.str().find(toFind.c_str()) != std::string::npos);
}

std::pair<Str, Str> CharManipulations::GetFileNameExtension(const Str & fileWithExt) const
{
    std::size_t found = fileWithExt.str().find_last_of(".");
    if (found == std::string::npos)
        return std::pair<Str, Str>();
    return make_pair(fileWithExt.str().substr(0,found), fileWithExt.str().substr(found+1));
}


EnjoLib::Str CharManipulations::Trim(const EnjoLib::Str & in ) const
{
    //in.size();
    EnjoLib::Str mod = in;
    while (StartsWith(mod, " "))
    {
        mod = mod.strRef().substr(1);
    }
    while (EndsWith(mod, " "))
    {
        mod = mod.strRef().substr(0, mod.size() - 1);
    }
    return mod;
}

EnjoLib::Str CharManipulations::ToStr(double d, unsigned precision) const
{
    EnjoLib::Osstream ss;
    ss.OStr().setf(std::ios::fixed);
    ss.OStr().precision(precision);
    ss << d;
    return ss.str();
}

EnjoLib::Str CharManipulations::ToStr(int i) const
{
    EnjoLib::Osstream ss;
    ss << i;
    return ss.str();
}

EnjoLib::Str CharManipulations::MakeLeadingZeroes(int d, unsigned numZeroes) const
{
    EnjoLib::Osstream oss;
    oss << d;
    EnjoLib::Str ret = oss.str();
    while (ret.size() < numZeroes)
    {
        ret = '0' + ret;
    }
    return ret;
}

bool CharManipulations::ToDouble(const EnjoLib::Str & in, double * d) const
{
    return CharManipulationsTpl().ToNumber<double>(in, d);
}

double CharManipulations::ToDouble(const EnjoLib::Str & in) const
{
    return CharManipulationsTpl().ToNumber<double>(in);
}

int CharManipulations::ToInt(const EnjoLib::Str & in) const
{
    return CharManipulationsTpl().ToNumber<int>(in);
}

bool CharManipulations::ToInt(const EnjoLib::Str & in, int * i) const
{
    return CharManipulationsTpl().ToNumber<int>(in, i);
}

Str CharManipulations::ToUpper(Str in) const
{
    std::transform(in.strRef().begin(), in.strRef().end(), in.strRW().begin(), ::toupper);
    return in;
}

Str CharManipulations::ToLower(Str in) const
{
    std::transform(in.strRef().begin(), in.strRef().end(), in.strRW().begin(), ::tolower);
    return in;
}

EnjoLib::Str CharManipulations::GetLineSeparator(unsigned num, char sep) const
{
    return EnjoLib::Str(num, sep) + '\n';
}
