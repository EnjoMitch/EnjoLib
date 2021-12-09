#include "Zipping.hpp"

#include <sstream> // Fixes Boost 1.71 bug under Clang
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>

#ifdef WIN32
    #include <boost/iostreams/filter/zlib.hpp>
    #define DECOMPRESSOR1 	zlib_decompressor
#else
    #include <boost/iostreams/filter/gzip.hpp>
    #define DECOMPRESSOR1 	gzip_decompressor
#endif // WIN32

#include <Ios/Ifstream.hpp>

using namespace EnjoLibBoost;

Zipping::Zipping()
{
}

Zipping::~Zipping()
{
}

void Zipping::UnzipFile(const EnjoLib::Str & zipFileName, EnjoLib::Ostream & sstrOut) const
{
    namespace bio = boost::iostreams;
    EnjoLib::Ifstream file(zipFileName, std::ios_base::binary);
    bio::filtering_streambuf<bio::input> in;
    in.push(bio::DECOMPRESSOR1());
    in.push(file.IStr());
    bio::copy(in, sstrOut.OStr());
}
