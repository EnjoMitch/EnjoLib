#ifndef TOKENIZE_H
#define TOKENIZE_H

#include <Util/VecStr.hpp>
#include <Ios/Istream.hpp>

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
        VecStr GetLines(EnjoLib::Istream & is, bool excludeFirstLine = false) const;
        VecStr FilterLines(const VecStr & lines, char tagComment = '#') const;
        //VecStr GetLines(STDFWD::istream & is, bool excludeFirstLine = false) const;
        void WorkOnLines(const EnjoLib::Str & fileName, IWorksOnLine & worker, bool excludeFirstLine = false) const;
        void WorkOnLines(EnjoLib::Istream & is, IWorksOnLine & worker, bool excludeFirstLine = false) const;
    protected:
    private:
};
}
#endif // TOKENIZE_H
