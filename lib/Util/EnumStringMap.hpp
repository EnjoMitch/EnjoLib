#ifndef ENUMSTRINGMAP_H
#define ENUMSTRINGMAP_H

#include <Util/Pimpl.hpp>
#include <Util/Str.hpp>
#include <Template/ArrayFwd.hpp>
#include <3rdParty/stdfwd.hh>

namespace EnjoLib {

class EnumStringMap // : public std::map<unsigned int, Str>
{
    public:
        EnumStringMap();
        virtual ~EnumStringMap();

        bool Has(unsigned int enumId) const;
        bool HasName(const Str & name) const;

        const Str & at(unsigned int enumId) const;
        const Str & operator[](unsigned int enumId) const;

        unsigned int atRev(const Str & name) const;
        size_t size() const;

        Array<Str> GetNames() const;
        const   STDFWD::map<unsigned int, Str> & Data() const;
        const   STDFWD::map<Str, unsigned int> & DataInv() const;

        typedef STDFWD::map<unsigned int, Str> value_type;

        template <class T> T ToType(unsigned int enumId) const;
        template <class T> T ToType(const Str & name)    const;


    protected:
        /// Use this to add all elements of the enum in your class
        void Add( unsigned int enumId, const Str & name );
    private:
        PIMPL
};

template <class T>
T EnumStringMap::ToType(unsigned int enumId) const
{
    return static_cast<T>(enumId);
}

template <class T>
T EnumStringMap::ToType(const Str & name) const
{
    return ToType<T>(atRev(name));
}

}
#endif // ENUMSTRINGMAP_H
