#include "Filesystem.hpp"
#include <string>
#include <algorithm>
#ifndef BOOST_NO_CXX11_SCOPED_ENUMS
#define BOOST_NO_CXX11_SCOPED_ENUMS
#endif
#include <boost/filesystem.hpp>
#undef BOOST_NO_CXX11_SCOPED_ENUMS

using namespace boost::filesystem;
using namespace EnjoLib;

Filesystem::Filesystem(){}
Filesystem::~Filesystem(){}

bool Filesystem::CreateDirIfNotExists(const Str & dir) const
{
    if (IsDir(dir))
        return true;
    return CreateDir(dir.c_str());
}

bool Filesystem::CreateDir(const Str & dir) const
{
    if (!dir.empty())
    {
        boost::filesystem::path bfsdir(dir.c_str());
        return boost::filesystem::create_directories(bfsdir);
    }
    return false;
}

bool Filesystem::IsDir(const Str & dir) const
{
    return boost::filesystem::is_directory(dir.c_str());
}

Str Filesystem::GetFilePath(const Str & dir, const Str & fileName) const
{
    boost::filesystem::path cppFile(dir.c_str());
    Str cppFilePath = cppFile.parent_path().string();
    boost::filesystem::path fileNamePath =  cppFilePath.str() + '/' + fileName.str();
    return fileNamePath.string();
}

bool Filesystem::Copy(const Str & srcPath, const Str & dstPath, bool overwrite) const
{
    path src(srcPath.c_str());
    path dst(dstPath.c_str());
    if (exists (src))
    {
        if (! overwrite)
            return false;
        remove (dstPath.c_str());
    }
    copy_file (src, dst);
    return true;
}

VecStr Filesystem::ListDir(const Str & dir, const Str & contains) const
{
    VecStr files;
    if (not is_directory(dir.c_str()))
    {
        return files;
    }
    std::vector<directory_entry> v; // To save the file names in a vector.
    copy(directory_iterator(dir.c_str()), directory_iterator(), back_inserter(v));
    for (std::vector<directory_entry>::const_iterator itr = v.begin(); itr != v.end(); ++itr)
    {
        if (not is_regular_file(itr->status()))
        {
            continue;
        }
        const Str & fileName = itr->path().filename().c_str();
        if (not contains.empty())
        {
            if (fileName.str().find(contains.str()) == std::string::npos)
            {
                continue;
            }
        }
        files.push_back(fileName);
    }
    std::sort(files.DataRW().begin(), files.DataRW().end());
    return files;
}

