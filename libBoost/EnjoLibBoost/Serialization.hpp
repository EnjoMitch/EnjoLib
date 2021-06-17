#ifndef SERIALIZATION_H
#define SERIALIZATION_H

// include headers that implement a archive in simple text format
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
//#include <boost/iostreams/filter/zlib.hpp>
//#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/filter/lzma.hpp>
//#include <boost/iostreams/filter/zstd.hpp>

#include <3rdParty/stdfwd.hh>
#include <fstream>
#include <sstream>

namespace EnjoLib
{

template<class Stream, class T>
class SerializationLowLevel
{
public:
        void ArchiveFSBinary(Stream & out, const T & t) const;
        T    RestoreFSBinary(Stream & in)  const;
        void ArchiveFSText(Stream & out, const T & t) const;
        T    RestoreFSText(Stream & in)  const;
        void ArchiveFS(bool binary, Stream & out, const T & t) const;
        T    RestoreFS(bool binary, Stream & in)  const;
};

template<class T>
class Serialization
{
    public:
        Serialization(bool binary = true);
        void ArchiveZipped(const std::string & serializedFileName, const T & t) const;
        T    RestoreZipped(const std::string & serializedFileName) const;
        T    Restore(const std::string & serializedFileName) const;
        void Archive(const std::string & serializedFileName, const T & t) const;

        T           RestoreString(const std::string & text) const;
        std::string ArchiveString(const T & t) const;

    protected:

    private:
        bool m_binary = true;
};



template<class T>
Serialization<T>::Serialization(bool binary)
: m_binary(binary)
{
}

template<class Stream, class T>
void SerializationLowLevel<Stream, T>::ArchiveFS(bool binary, Stream & out, const T & t) const
{
    if (binary)
        ArchiveFSBinary(out, t);
    else
        ArchiveFSText(out, t);
}

template<class Stream, class T>
T SerializationLowLevel<Stream, T>::RestoreFS(bool binary, Stream & in)  const
{

    if (binary)
        return RestoreFSBinary(in);
    else
        return RestoreFSText(in);
}

template<class Stream, class T>
void SerializationLowLevel<Stream, T>::ArchiveFSBinary(Stream & out, const T & t) const
{
    boost::archive::binary_oarchive oa(out);
    oa << t;
}

template<class Stream, class T>
T SerializationLowLevel<Stream, T>::RestoreFSBinary(Stream & in)  const
{
    T t;
    {
        boost::archive::binary_iarchive ia(in);
        ia >> t;
    }   // save data to archive
    return t;
}

template<class Stream, class T>
void SerializationLowLevel<Stream, T>::ArchiveFSText(Stream & out, const T & t) const
{
    boost::archive::text_oarchive oa(out);
    oa << t;
}

template<class Stream, class T>
T SerializationLowLevel<Stream, T>::RestoreFSText(Stream & in)  const
{
    T t;
    {
        boost::archive::text_iarchive ia(in);
        ia >> t;
    }   // save data to archive
    return t;
}

template<class T>
void Serialization<T>::ArchiveZipped(const std::string & serializedFileName, const T & t) const
{
    namespace bio = boost::iostreams;
    std::ofstream file(serializedFileName, std::ios_base::binary);
    bio::filtering_streambuf<bio::output> out;
    //out.push(bio::zlib_compressor()); // Windows TODO
    //out.push(bio::gzip_compressor());   // POSIX   TODO
    //out.push(bio::zstd_compressor());   // POSIX   TODO
    out.push(bio::lzma_compressor());   // POSIX   TODO
    out.push(file);
    SerializationLowLevel<decltype(out), T>().ArchiveFSBinary(out, t); // Only binary is possible
}

template<class T>
T Serialization<T>::RestoreZipped(const std::string & serializedFileName) const
{
    namespace bio = boost::iostreams;
    std::ifstream file(serializedFileName, std::ios_base::binary);
    bio::filtering_streambuf<bio::input> in;
    //in.push(bio::zlib_decompressor());     // Windows TODO
    //in.push(bio::gzip_decompressor());  // POSIX   TODO
    //in.push(bio::zstd_decompressor());  // POSIX   TODO
    in.push(bio::lzma_decompressor());  // POSIX   TODO
    in.push(file);
    return SerializationLowLevel<decltype(in), T>().RestoreFSBinary(in); // Only binary is possible
}

template<class T>
void Serialization<T>::Archive(const std::string & serializedFileName, const T & t) const
{
    std::ofstream ofs(serializedFileName); // std::ostringstream ofs(serializedFileName);
    SerializationLowLevel<decltype(ofs), T>().ArchiveFS(m_binary, ofs, t);
}

template<class T>
T Serialization<T>::Restore(const std::string & serializedFileName) const
{
    std::ifstream ifs(serializedFileName);
    return SerializationLowLevel<decltype(ifs), T>().RestoreFS(m_binary, ifs);
}

template<class T>
T Serialization<T>::RestoreString(const std::string & text) const
{
    std::istringstream iss(text);
    return SerializationLowLevel<decltype(iss), T>().RestoreFS(false, iss);
}
template<class T>
std::string Serialization<T>::ArchiveString(const T & t) const
{
    std::ostringstream oss;
    SerializationLowLevel<decltype(oss), T>().ArchiveFS(false, oss, t);
    return oss.str();
}

}
#endif // SERIALIZATION_H
