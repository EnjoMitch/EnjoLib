#ifndef OSSTREAM_HPP
#define OSSTREAM_HPP

#include <Ios/Ostream.hpp>
#include <Util/Str.hpp>
#include <Template/SafePtr.hpp>

namespace EnjoLib {
    
class Osstream : public Ostream
{
    public:
        Osstream();
        virtual ~Osstream();
        
        stdfwd::ostream & OStr() override;
        const stdfwd::ostream & OStr() const override;
        
        EnjoLib::Str Str() const;
        EnjoLib::Str str() const;

    protected:

    private:
        SafePtr<std::ostringstream> m_ostream;
};

}
#endif // OSSTREAM_HPP
