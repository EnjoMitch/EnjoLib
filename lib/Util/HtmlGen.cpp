#include "HtmlGen.hpp"
#include <Util/Osstream.hpp>

using namespace EnjoLib;

HtmlGen::HtmlGen(){}
HtmlGen::~HtmlGen(){}

EnjoLib::Str HtmlGen::GenHeader(const EnjoLib::Str & title, const EnjoLib::Str & bodyParams) const
{
    EnjoLib::Osstream html;

    html << "<!DOCTYPE html>\n";
    html << "<html>\n";
    html << "<head>\n";
    html << "<meta charset='UTF-8'>\n";
    html << "<title>" << title << "</title>\n";
    html << "</head>\n";
    html << "<body " << bodyParams << ">\n";

    return html.str();
}
EnjoLib::Str HtmlGen::GenFooter() const
{
    EnjoLib::Osstream html;

    html << "</body>\n";
    html << "</html>\n";

    return html.str();
}

EnjoLib::Str HtmlGen::GenScriptSrc(const EnjoLib::Str & scriptPath) const
{
    EnjoLib::Osstream html;
    html << "<script src='" << scriptPath << "'></script>\n";
    return html.str();
}

EnjoLib::Str HtmlGen::GenScriptListing(const EnjoLib::Str & scriptListing) const
{
    EnjoLib::Osstream html;
    html << "<script>\n" << scriptListing << "\n</script>\n";
    return html.str();
}

EnjoLib::Str HtmlGen::GenSpan(const EnjoLib::Str & content) const
{
    return GenNormalTagWithContent("span", content);
}

EnjoLib::Str HtmlGen::GenNormalTagWithContent(const EnjoLib::Str & tag, const EnjoLib::Str & content) const
{
    return "<" + tag + ">" + content + "</" + tag + ">\n";
}
