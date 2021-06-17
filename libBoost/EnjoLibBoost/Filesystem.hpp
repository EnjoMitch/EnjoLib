#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <Util/Str.hpp>
#include <Util/VecStr.hpp>

namespace EnjoLib
{
class Filesystem
{
public:
    Filesystem();
    virtual ~Filesystem();
    bool CreateDirIfNotExists(const Str & dir) const;
    bool CreateDir(const Str & dir) const;
    bool IsDir(const Str & dir) const;
    bool Copy(const Str & srcPath, const Str & dstPath, bool overwrite = true) const;
    Str GetFilePath(const Str & dir, const Str & fileName) const;
    VecStr ListDir(const Str & dir, const Str & contains = "") const;

protected:
private:
};
}


#endif // FILESYSTEM_H
