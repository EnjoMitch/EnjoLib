#include "Zipping.hpp"

#include <fstream>


#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
//#include <boost/iostreams/filter/zlib.hpp>
#include <boost/iostreams/filter/gzip.hpp>
//#include <boost/iostreams/filter/lzma.hpp>


Zipping::Zipping()
{
}

Zipping::~Zipping()
{
}


void Zipping::UnzipFile(const std::string & zipFileName, std::ostream & sstrOut) const
{
    namespace bio = boost::iostreams;
    std::ifstream file(zipFileName, std::ios_base::binary);
    bio::filtering_streambuf<bio::input> in;
    //in.push(bio::zlib_decompressor());    // Windows
    in.push(bio::gzip_decompressor());      // Linux
    in.push(file);
    bio::copy(in, sstrOut);
}

