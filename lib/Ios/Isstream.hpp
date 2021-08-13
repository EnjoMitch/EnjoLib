#ifndef ISSTREAM_HPP
#define ISSTREAM_HPP

#include <Ios/Istream.hpp>
#include <Util/Str.hpp>
#include <Template/SafePtr.hpp>

namespace EnjoLib {
    
class Isstream : public Istream
{
    public:
        Isstream(const EnjoLib::Str & inp = "");
        virtual ~Isstream();
        
        stdfwd::istream & IStr() override;
        const stdfwd::istream & IStr() const override;
        
        void str(const EnjoLib::Str & inp);
        EnjoLib::Str str() const;

    protected:

    private:
        SafePtr<std::istringstream> m_istream;
};

}
#endif // ISSTREAM_HPP
