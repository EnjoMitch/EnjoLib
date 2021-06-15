#include "EnumStringMap.hpp"
#include <Util/PimplDeleter.hpp>
#include <STD/Map.hpp>

struct EnumStringMap::Impl
{
    std::map<unsigned int, EnjoLib::Str> mapEnum;
};
PIMPL_DELETER(EnumStringMap)

EnumStringMap::EnumStringMap()
: m_impl(new Impl())
{}

EnumStringMap::~EnumStringMap(){}

void EnumStringMap::Add( unsigned int enumId, const EnjoLib::Str & name )
{
    GetImplRW().mapEnum[enumId] = name;
}

const EnjoLib::Str & EnumStringMap::at(unsigned int enumId) const
{
    return GetImpl().mapEnum.at( enumId );
}

const EnjoLib::Str & EnumStringMap::operator[](unsigned int enumId) const
{
    return at( enumId );
}

size_t EnumStringMap::size() const
{
    return GetImpl().mapEnum.size();
}
const stdfwd::map<unsigned int, EnjoLib::Str> & EnumStringMap::Data() const
{
    return GetImpl().mapEnum;
}
