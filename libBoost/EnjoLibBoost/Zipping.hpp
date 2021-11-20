#ifndef ZIPPING_H
#define ZIPPING_H

#include <Ios/Osstream.hpp>

class Zipping
{
    public:
        Zipping();
        virtual ~Zipping();
        void UnzipFile(const std::string & zipFileName, EnjoLib::Ostream & sstrOut) const;

    protected:
    private:
};

#endif // ZIPPING_H
