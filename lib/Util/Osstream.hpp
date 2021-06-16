#ifndef OSSTREAM_HPP
#define OSSTREAM_HPP

#include <Util/Str.hpp>
#include <Template/SafePtr.hpp>

namespace EnjoLib {
    
class Osstream
{
    public:
        Osstream();
        virtual ~Osstream();
        
        stdfwd::ostream & OStr();
        
        EnjoLib::Str Str() const;
        EnjoLib::Str str() const;
        
        void Add(const EnjoLib::Str & str); // TODO: Remove?
        
        void AddVal(long unsigned int val);
        void AddVal(long long unsigned int val);
        void AddVal(unsigned int val);
        void AddVal(long int val);
        void AddVal(int val);
        void AddVal(char val);
        void AddVal(double val);
        void AddVal(const char * val);
        void AddVal(const stdfwd::string & val);
        void AddVal(const EnjoLib::Str & str);
        
        template <class T> Osstream& operator << (const T & val);

    protected:

    private:
        SafePtr<std::ostringstream> m_ostream;
};

template <class T> Osstream& Osstream::operator << (const T & val)
{
    this->AddVal(val);
    return *this;
}

const char NL2 = '\n';

}
#endif // OSSTREAM_HPP
