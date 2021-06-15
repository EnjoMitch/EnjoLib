#ifndef CACHERAMBASE_H
#define CACHERAMBASE_H

#include <3rdParty/stdfwd.hh>
#include "CacheCleanupPolFactory.hpp"
#include "CacheRAMCleanupPolBase.hpp"
#include <Template/SafePtr.hpp>
#include <Util/Result.hpp>

namespace EnjoLib
{
    
template <class TKeyT, class TValueT>
struct ICalcCacheRes
{
    virtual TValueT CalcForCache(const TKeyT & st) const = 0;
    virtual ~ICalcCacheRes(){}
};


template <class TKeyT, class TValueT>
class CacheRAMBase
{
    public:
        CacheRAMBase()
        : m_ccp(CacheCleanupPolFactory::CreateDefault())
        {
        }
        virtual ~CacheRAMBase(){}

        using TKey = TKeyT;
        using TValue = TValueT;
        using Map = stdfwd::map<TKey, TValue>;

        virtual const TValue & Add(const TKey & key, const TValue & val) = 0;
        virtual bool Has(const TKey & key) const = 0;
        virtual Result<const TValue *> GetOpt(const TKey & key) const = 0;
        virtual const TValue & Get(const TKey & key) const = 0;
        virtual const TValue & GetOrCreate (const TKey & key, const ICalcCacheRes<TKey, TValue> & calculatable) = 0;
        virtual TValue & GetRW(const TKey & key) = 0;
        virtual const Map & GetMap() const = 0;
        virtual Map & GetMapRW() = 0;
        
        virtual void SetCacheCleaupPolicy(CacheRAMCleanupPolBase * ccp)
        {
            m_ccp.Init(ccp);
        }
        virtual const CacheRAMCleanupPolBase & GetCacheCleaupPolicy() const
        {
            return *m_ccp;
        }
    protected:


    private:
        SafePtr<CacheRAMCleanupPolBase> m_ccp;
};

template <class TKeyT, class TValueT> using CacheRAMBasePtr = SafePtr<CacheRAMBase<TKeyT, TValueT>>;
}

#endif // CACHERAMBASE_H
