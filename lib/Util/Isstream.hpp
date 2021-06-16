#ifndef ISSTREAM_HPP
#define ISSTREAM_HPP

#include <Util/Str.hpp>
#include <Template/SafePtr.hpp>

namespace EnjoLib {
    
class Isstream
{
    public:
        Isstream(const EnjoLib::Str & inp = "");
        virtual ~Isstream();
        
        stdfwd::istream & IStr();
        
        void str(const EnjoLib::Str & inp);
        EnjoLib::Str str() const;
        
        bool operator !() const;
        operator bool() const;
        
        template <class T> friend Isstream& operator >> (Isstream&, T & val);
                
        void PushVal(long long unsigned int * val);
        void PushVal(long unsigned int * val);
        void PushVal(unsigned int * val);
        void PushVal(int * val);
        void PushVal(bool * val);
        void PushVal(char * val);
        void PushVal(double * val);
        void PushVal(float * val);
        void PushVal(stdfwd::string * val);
        void PushVal(EnjoLib::Str * val);

    protected:

    private:
        SafePtr<std::istringstream> m_istream;
};

bool GetLine(Isstream& ifs, EnjoLib::Str & lineOut, const char token = ' ');

template <class T> Isstream& operator >> (Isstream& ifst, T & val)
{
    ifst.PushVal(&val);
    return ifst;
}

}
#endif // ISSTREAM_HPP
