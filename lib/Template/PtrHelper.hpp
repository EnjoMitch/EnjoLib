#ifndef PTRHELPER_H
#define PTRHELPER_H

//#include <cstddef> // size_t

class PtrHelper
{
    public:
        PtrHelper();
        virtual ~PtrHelper();

        static void Copy(char * dst, const char * src, long maxSize);
        static long GetMinSize(const char * str, long maxSize);
        static void ThrowIfCondMet(bool condition, const char * typeName);
        static void ThrowIfCondMet(bool condition, const char * typeName, const char * subTypeName);

    protected:

    private:
};

#endif // PTRHELPER_H
