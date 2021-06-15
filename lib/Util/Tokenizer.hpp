#ifndef TOKENIZE_H
#define TOKENIZE_H

#include <Util/VecStr.hpp>
#include <3rdParty/stdfwd.hh>

namespace EnjoLib
{

class IWorksOnLine
{
public:
    virtual ~IWorksOnLine(){}
    virtual void Work(const EnjoLib::Str & line) = 0;
};

class Tokenizer
{
    public:
        Tokenizer();
        virtual ~Tokenizer();
        VecStr Tokenize(const EnjoLib::Str & line, char token = ' ') const;
        VecStr GetLines(const EnjoLib::Str & fileName, bool excludeFirstLine = false) const;
        VecStr GetLinesStr(const EnjoLib::Str & strData, bool excludeFirstLine = false) const;
        VecStr GetLines(EnjoLib::Ifstream & is, bool excludeFirstLine = false) const;
        VecStr GetLines(stdfwd::istream & is, bool excludeFirstLine = false) const;
        void WorkOnLines(const EnjoLib::Str & fileName, IWorksOnLine & worker, bool excludeFirstLine = false) const;
        void WorkOnLines(stdfwd::istream & is, IWorksOnLine & worker, bool excludeFirstLine = false) const;
    protected:
    private:
};
}
#endif // TOKENIZE_H
