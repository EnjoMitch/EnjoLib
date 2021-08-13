#ifndef SSTREAM_HPP
#define SSTREAM_HPP

#include <Ios/Isstream.hpp>
#include <Ios/Osstream.hpp>

namespace EnjoLib {
    
class Sstream : public Isstream, public Osstream
{
    public:
        Sstream();
        virtual ~Sstream();

    protected:

    private:
};

}
#endif // SSTREAM_HPP
