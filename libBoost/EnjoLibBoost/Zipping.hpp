#ifndef ZIPPING_H
#define ZIPPING_H

#include <Ios/Osstream.hpp>
#include <3rdParty/stdfwd.hh>

class Zipping
{
    public:
        Zipping();
        virtual ~Zipping();
        void UnzipFile(const std::string & zipFileName, EnjoLib::Osstream & sstrOut) const;

    protected:
    private:
};

#endif // ZIPPING_H
