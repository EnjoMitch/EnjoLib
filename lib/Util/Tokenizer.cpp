#include "Tokenizer.hpp"

#include <Util/Isstream.hpp>
#include <Util/Ifstream.hpp>

#include <STD/Istream.hpp>

using namespace std;
using namespace EnjoLib;

Tokenizer::Tokenizer(){}
Tokenizer::~Tokenizer(){}

VecStr Tokenizer::Tokenize(const Str & line, char token) const
{
    VecStr ret;
    Isstream ss(line);
    Str s;

    while (GetLine(ss, s, token))
    {
        ret.push_back(s);
    }
    return ret;
}

VecStr Tokenizer::GetLines(const Str & fileName, bool excludeFirstLine) const
{
    Ifstream file(fileName.c_str(), false); /// TODO
    return GetLines(file, excludeFirstLine);
}

VecStr Tokenizer::GetLines(EnjoLib::Ifstream & is, bool excludeFirstLine) const
{
    return GetLines(is.IStr(), excludeFirstLine);
}

VecStr Tokenizer::GetLines(istream & is, bool excludeFirstLine) const
{
    string line;
    VecStr lines;
    if (excludeFirstLine)
        getline(is, line);
    while (getline(is, line))
    {
        lines.push_back(line);
    }
    return lines;
}

VecStr Tokenizer::GetLinesStr(const Str & strData, bool excludeFirstLine) const
{
    return Tokenize(strData, '\n');
}

void Tokenizer::WorkOnLines(const Str & fileName, IWorksOnLine & worker, bool excludeFirstLine) const
{
    Ifstream file(fileName.c_str());
    return WorkOnLines(file.IStr(), worker, excludeFirstLine);
}

void Tokenizer::WorkOnLines(istream & is, IWorksOnLine & worker, bool excludeFirstLine) const
{
    string line;
    VecStr lines;
    if (excludeFirstLine)
        getline(is, line);
    while (getline(is, line))
    {
        worker.Work(line);
    }
}
