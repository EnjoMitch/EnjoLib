#include "Tokenizer.hpp"

#include <Ios/Isstream.hpp>
#include <Ios/Ifstream.hpp>

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

VecStr Tokenizer::GetLines(EnjoLib::Istream & is, bool excludeFirstLine) const
{
    Str line;
    VecStr lines;
    if (excludeFirstLine)
        GetLine(is, line);
    while (GetLine(is, line))
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
    return WorkOnLines(file, worker, excludeFirstLine);
}

void Tokenizer::WorkOnLines(EnjoLib::Istream & is, IWorksOnLine & worker, bool excludeFirstLine) const
{
    Str line;
    VecStr lines;
    if (excludeFirstLine)
        GetLine(is, line);
    while (GetLine(is, line))
    {
        worker.Work(line);
    }
}
