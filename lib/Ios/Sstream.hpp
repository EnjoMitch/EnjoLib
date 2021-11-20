#ifndef SSTREAM_HPP
#define SSTREAM_HPP

#include <Ios/Istream.hpp>
#include <Ios/Ostream.hpp>
#include <Template/SafePtrFast.hpp>

//#define STD_SSTREAM

#if defined(STD_EL) || defined(STD_SSTREAM)
    #define STD_SSTREAM_FINAL
    
    #include <STD/Sstream.hpp>
#endif

namespace EnjoLib {

class Sstream :  
#ifdef STD_SSTREAM_FINAL
    public std::stringstream
#else
    public Istream, public Ostream
#endif // STD_SSTREAM_FINAL
{
    public:
        Sstream();
        virtual ~Sstream();
        
        void SetStr(const EnjoLib::Str & inp);
        Str ToStr() const;
        
#ifdef STD_SSTREAM_FINAL
    std::istream & IStr() { return *this; }
    std::ostream & OStr() { return *this; }
    const std::ostream & OStr() const { return *this; }
    const std::istream & IStr() const { return *this; }
#else
    stdfwd::ostream & OStr() override;
    stdfwd::istream & IStr() override;
    const stdfwd::ostream & OStr() const override;
    const stdfwd::istream & IStr() const override;
#endif // STD_SSTREAM_FINAL

    protected:

    private:
        SafePtrFast<std::stringstream> m_sstream;
};

}
#endif // SSTREAM_HPP
