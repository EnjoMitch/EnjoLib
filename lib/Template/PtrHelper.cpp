#include "PtrHelper.hpp"

#include <Util/Except.hpp>
#include <Util/Str.hpp>
#include <cstring>

PtrHelper::PtrHelper(){}
PtrHelper::~PtrHelper(){}

long PtrHelper::GetMinSize(const char * src, long maxSize)
{
    const size_t typeSz = strlen(src);
    size_t minSz = maxSize;
    if (typeSz < minSz)
    {
        minSz = typeSz;
    }
    return minSz;
}

void PtrHelper::Copy(char * dst, const char * src, long maxSize)
{
    const size_t minSz = GetMinSize(src, maxSize);
    memcpy(dst, src, minSz);
}

void PtrHelper::ThrowIfCondMet(bool condition, const char * typeName, const char * subTypeName)
{
    if (condition)
    {
        const EnjoLib::Str msg = EnjoLib::Str(typeName) + "<" + subTypeName + ">: Not initialized!";
        throw EnjoLib::ExceptRuntimeError(msg);
    }
}

void PtrHelper::ThrowIfCondMet(bool condition, const char * typeName)
{
    if (condition)
    {
        const EnjoLib::Str msg = EnjoLib::Str(typeName) + "<" + "Unknown"+ ">: Not initialized!";
        throw EnjoLib::ExceptRuntimeError(msg + " BACKTRACE!");
    }
}
