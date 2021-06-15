#ifndef ISTR_HPP
#define ISTR_HPP

#include <Template/SafePtr.hpp>
//#include <Template/SafePtrFast.hpp>
#include <3rdParty/stdfwd.hh>
#include <cstddef>

namespace boost { namespace serialization
{
    class access; }
}

namespace EnjoLib
{
class Ofstream;
class Ifstream;
class StrImpl;
class Str
{
    public:
        Str();
        Str(const char crr);
        Str(const char * str);
        Str(size_t num, const char crr);
        Str(const std::string & str);
        Str(const Str & str);
        virtual ~Str();

        Str & operator=(const Str & str);
        //static PStr Create(const std::string & str);
        const char * c_str() const;
        //const char * GetData() const;
        std::string str() const;
        std::string & strRW();
        const std::string & strRef() const;
        size_t size() const;
        size_t length() const;
        bool empty() const;
        const char & at(size_t i) const;
        char & at(size_t i);
        const char & operator[](size_t i) const;
        char & operator[](size_t i);
        void pop_back();

        const char & front() const;
        char & front();
        const char & back() const;
        char & back();

        friend bool  operator== (const EnjoLib::Str& str, const EnjoLib::Str& strOther);
        friend bool  operator!= (const EnjoLib::Str& str, const EnjoLib::Str& strOther);
        friend bool  operator< (const EnjoLib::Str& str, const EnjoLib::Str& strOther);
        friend EnjoLib::Str operator+ (const EnjoLib::Str& str, const EnjoLib::Str& strOther);
        friend EnjoLib::Str&  operator+= (EnjoLib::Str& str, const EnjoLib::Str& strOther);
        friend std::ostream& operator<<(std::ostream& os,  const EnjoLib::Str& str);
        friend std::istream& operator>>(std::istream& os,  EnjoLib::Str& str);
        
        friend EnjoLib::Ofstream& operator<<(EnjoLib::Ofstream& os,  const EnjoLib::Str& str);
        friend EnjoLib::Ifstream& operator>>(EnjoLib::Ifstream& os,        EnjoLib::Str& str);

    protected:

    private:
        friend class boost::serialization::access;
        // When the class Archive corresponds to an output archive, the
        // & operator is defined similar to <<.  Likewise, when the class Archive
        // is a type of input archive the & operator is defined similar to >>.
        template<class Archive>
        void serialize(Archive & ar, const unsigned int version)
        {
            ar & m_pimp;
        }
        struct pimpl_deleter { void operator()(StrImpl*) const; };

        //SafePtr<StrImpl> m_pimp;
        SafePtr<StrImpl, pimpl_deleter> m_pimp;
};

bool  operator== (const EnjoLib::Str& str, const EnjoLib::Str& strOther);
bool  operator!= (const EnjoLib::Str& str, const EnjoLib::Str& strOther);
bool  operator<  (const EnjoLib::Str& str, const EnjoLib::Str& strOther);
EnjoLib::Str  operator+ (const EnjoLib::Str& str, const EnjoLib::Str& strOther);
EnjoLib::Str& operator+= (EnjoLib::Str& str, const EnjoLib::Str& strOther);
std::ostream& operator<<(std::ostream& os,  const EnjoLib::Str& str);
std::istream& operator>>(std::istream& os,  EnjoLib::Str& str);
EnjoLib::Ofstream& operator<<(EnjoLib::Ofstream& os,  const EnjoLib::Str& str);
EnjoLib::Ifstream& operator>>(EnjoLib::Ifstream& os,        EnjoLib::Str& str);

}

#endif // ISTR_HPP
