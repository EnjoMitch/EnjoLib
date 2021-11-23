#ifndef ZIPPING_H
#define ZIPPING_H

#include <Ios/Osstream.hpp>

namespace EnjoLibBoost
{

class Zipping
{
    public:
        Zipping();
        virtual ~Zipping();
        void UnzipFile(const EnjoLib::Str & zipFileName, EnjoLib::Ostream & sstrOut) const;

    protected:
    private:
};
}

#endif // ZIPPING_H
