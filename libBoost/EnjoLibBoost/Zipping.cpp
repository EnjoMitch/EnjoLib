#include "Zipping.hpp"

#include <sstream> // Fixes Boost 1.71 bug under Clang
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
//#include <boost/iostreams/filter/zlib.hpp>
#include <boost/iostreams/filter/gzip.hpp>
//#include <boost/iostreams/filter/lzma.hpp>

#include <Ios/Ifstream.hpp>


Zipping::Zipping()
{
}

Zipping::~Zipping()
{
}

void Zipping::UnzipFile(const std::string & zipFileName, EnjoLib::Ostream & sstrOut) const
{
    namespace bio = boost::iostreams;
    EnjoLib::Ifstream file(zipFileName, std::ios_base::binary);
    bio::filtering_streambuf<bio::input> in;
    //in.push(bio::zlib_decompressor());    // Windows
    in.push(bio::gzip_decompressor());      // Linux
    in.push(file.IStr());
    bio::copy(in, sstrOut.OStr());
}
