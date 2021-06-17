#ifndef ZIPPING_H
#define ZIPPING_H

#include <3rdParty/stdfwd.hh>

class Zipping
{
    public:
        Zipping();
        virtual ~Zipping();
        void UnzipFile(const std::string & zipFileName, std::ostream & sstrOut) const;

    protected:
    private:
};

#endif // ZIPPING_H
