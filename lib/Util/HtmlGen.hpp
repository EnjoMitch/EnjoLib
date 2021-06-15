#ifndef HTMLGEN_H
#define HTMLGEN_H

#include <Util/Str.hpp>

namespace EnjoLib
{
class HtmlGen
{
    public:
        HtmlGen();
        virtual ~HtmlGen();

        EnjoLib::Str GenNormalTagWithContent(const EnjoLib::Str & tag, const EnjoLib::Str & content) const;

        EnjoLib::Str GenHeader(const EnjoLib::Str & title, const EnjoLib::Str & bodyParams = "") const;
        EnjoLib::Str GenSpan(const EnjoLib::Str & content) const;
        EnjoLib::Str GenFooter() const;
        EnjoLib::Str GenScriptSrc(const EnjoLib::Str & scriptPath) const;
        EnjoLib::Str GenScriptListing(const EnjoLib::Str & scriptListing) const;

    protected:

    private:

};
}


#endif // HTMLGEN_H
