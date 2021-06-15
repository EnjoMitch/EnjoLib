#include "CacheCleanupPolFactory.hpp"

using namespace EnjoLib;

CacheCleanupPolFactory:: CacheCleanupPolFactory(){}
CacheCleanupPolFactory::~CacheCleanupPolFactory(){}

class CCPMaxRam : public CacheRAMCleanupPolBase
{
public:

};

CacheRAMCleanupPolBase * CacheCleanupPolFactory::CreateDefault()
{
    return new CCPMaxRam();
}
