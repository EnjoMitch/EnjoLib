#ifndef STRCOLOUR_HPP
#define STRCOLOUR_HPP

#include <Util/Str.hpp>

namespace EnjoLib
{

class StrColour
{
    public:
        enum class Col : int
        {
            Black=30
            ,Red
            ,Green
            ,Yellow
            ,Blue
            ,Magenta
            ,Cyan
            ,White
        };
        
        enum class ColBright : int
        {
            Black=90
            ,Red
            ,Green
            ,Yellow
            ,Blue
            ,Magenta
            ,Cyan
            ,White
        };
        
        StrColour();
        virtual ~StrColour();
        
        static EnjoLib::Str GenErr(const EnjoLib::Str & txt);
        static EnjoLib::Str GenWarn(const EnjoLib::Str & txt);
        
        static EnjoLib::Str GenNorm(float val, int precision = 3);
        static EnjoLib::Str GenBright(float val, int precision = 3);
        
        static EnjoLib::Str GenNorm(float val, const EnjoLib::Str & txt);
        static EnjoLib::Str GenBright(float val, const EnjoLib::Str & txt);
        
        static EnjoLib::Str GenNorm(Col col, const EnjoLib::Str & txt);
        static EnjoLib::Str GenBright(ColBright col, const EnjoLib::Str & txt);
        
        static EnjoLib::Str Gen(int col, const EnjoLib::Str & txt);

    protected:
        static EnjoLib::Str startTxt(int col);

    private:
        static const char * endTxt;
};
    
}

#endif // STRCOLOUR_HPP
