#include "EnumStringMap.hpp"
#include <Util/Str.hpp>
#include <Util/PimplDeleter.hpp>
#include <Template/Array.hpp>

#include <STD/Map.hpp>
#include <STD/VectorCpp.hpp>

using namespace EnjoLib;

/// TODO: Use Bimap?
struct EnumStringMap::Impl
{
    std::map<unsigned int, Str> mapEnum;
    std::map<Str, unsigned int> mapName;
};
PIMPL_DELETER(EnumStringMap)

EnumStringMap::EnumStringMap()
: m_impl(new Impl())
{}

EnumStringMap::~EnumStringMap(){}

void EnumStringMap::Add( unsigned int enumId, const Str & name )
{
    GetImplRW().mapEnum[enumId] = name;
    GetImplRW().mapName[name]   = enumId;
}

const Str & EnumStringMap::at(unsigned int enumId) const
{
    return GetImpl().mapEnum.at( enumId );
}

unsigned int EnumStringMap::atRev(const Str & name) const
{
     return GetImpl().mapName.at( name );
}

const Str & EnumStringMap::operator[](unsigned int enumId) const
{
    return at( enumId );
}

bool EnumStringMap::Has(unsigned int enumId) const
{
    return GetImpl().mapEnum.find(enumId) != GetImpl().mapEnum.end();
}
bool EnumStringMap::HasName(const Str & name) const
{
    return GetImpl().mapName.find(name) != GetImpl().mapName.end();
}

size_t EnumStringMap::size() const
{
    return GetImpl().mapEnum.size();
}
const std::map<unsigned int, Str> & EnumStringMap::Data() const
{
    return GetImpl().mapEnum;
}
const std::map<Str, unsigned int> & EnumStringMap::DataInv() const
{
    return GetImpl().mapName;
}

Array<Str> EnumStringMap::GetNames() const
{
    std::vector<Str> ret;
    for (value_type::const_iterator it = GetImpl().mapEnum.begin(); it != GetImpl().mapEnum.end(); ++it)
    {
        ret.push_back(it->second);
    }
    return ret;
}
