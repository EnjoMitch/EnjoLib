#ifndef CACHECLEANUPPOLFACTORY_HPP
#define CACHECLEANUPPOLFACTORY_HPP

#include "CacheRAMCleanupPolBase.hpp"

namespace EnjoLib
{
class CacheCleanupPolFactory
{
    public:
        CacheCleanupPolFactory();
        virtual ~CacheCleanupPolFactory();

        static CacheRAMCleanupPolBase * CreateDefault();

    protected:

    private:
};
}
#endif // CACHECLEANUPPOLFACTORY_HPP
