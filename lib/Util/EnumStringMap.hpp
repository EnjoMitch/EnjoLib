#ifndef ENUMSTRINGMAP_H
#define ENUMSTRINGMAP_H

#include <Util/Pimpl.hpp>
#include <Util/Str.hpp>
#include <3rdParty/stdfwd.hh>

class EnumStringMap// : public std::map<unsigned int, EnjoLib::Str>
{
    public:
        EnumStringMap();
        virtual ~EnumStringMap();
        
        const EnjoLib::Str & at(unsigned int enumId) const;
        const EnjoLib::Str & operator[](unsigned int enumId) const;
        size_t size() const;
        const stdfwd::map<unsigned int, EnjoLib::Str> & Data() const;
        
        typedef stdfwd::map<unsigned int, EnjoLib::Str> value_type;
        
    protected:
        /// Use this to add all elements of the enum in your class
        void Add( unsigned int enumId, const EnjoLib::Str & name );
    private:
        PIMPL
};

#endif // ENUMSTRINGMAP_H
