#ifndef CACHERAMELIB_H
#define CACHERAMELIB_H

#include "CacheRAMFunctional.hpp"
#include "Statistical/Assertions.hpp"

#include <STD/Map.hpp>
#include <functional>

namespace EnjoLib
{
template <class TKeyT, class TValueT>
class CacheRAM : public CacheRAMFunctional<TKeyT, TValueT>
{
    public:
        CacheRAM(){}
        virtual ~CacheRAM(){}

        using TKey = TKeyT;
        using TValue = TValueT;
        using Cit = typename std::map<TKey, TValue>::const_iterator;
        using It = typename std::map<TKey, TValue>::iterator;
        using Map = std::map<TKey, TValue>;

        const TValue & Add(const TKey & key, const TValue & val) override
        {
            m_cache[key] = val; // C++03 overwrites
            //m_cache.emplace(key, val); // C++11 - can be a bit faster - doesn't overwrite
            return m_cache[key];
        }

        bool Has(const TKey & key) const override
        {
            const Cit cit = m_cache.find(key);
            return cit != m_cache.end();
        }

        const TValue & Get(const TKey & key) const override
        {
             const Cit cit = m_cache.find(key);
             if (cit == m_cache.end())
             {
                 Assertions::Throw("missing key", "CacheRAM::Get()");
             }
             return cit->second;
        }
        
        Result<const TValue *> GetOpt(const TKey & key) const override
        {
            const Cit cit = m_cache.find(key);
            if (cit == m_cache.end())
            {
                return Result<const TValue *>(nullptr, false);
            }
            return Result<const TValue *>(&cit->second, true);
        }
        
        TValue & GetRW(const TKey & key) override
        {
            It cit = m_cache.find(key);
             if (cit == m_cache.end())
             {
                 Assertions::Throw("missing key", "CacheRAM::GetRW()");
             }
             return cit->second;
        }

        const TValue & GetOrCreate(const TKey & key, std::function<TValue(const TKey&)> funcConv) override
        {
             const Cit cit = m_cache.find(key);
             if (cit == m_cache.end())
             {
                 const TValue & val = funcConv(key);
                 Add(key, val);
                 return Get(key);
             }
             return cit->second;
        }
        
        const TValue & GetOrCreate (const TKey & key, const ICalcCacheRes<TKey, TValue> & calculatable) override
        {
             const Cit cit = m_cache.find(key);
             if (cit == m_cache.end())
             {
                 const TValue & val = calculatable.CalcForCache(key);
                 return Add(key, val);
             }
             return cit->second;
        }
        
        const TValue & GetAndVerify(const TKey & key, std::function<TValue(const TKey&)> funcConv) const override
        {
            const TValue & valGot = Get(key);
            const TValue & valGen = funcConv(key);

            if (valGot != valGen)
            {
                Assertions::Throw("valGot != valGen", "CacheRAM::GetAndVerify()");
            }

            return valGot;
        }
        
        const Map & GetMap() const override
        {
            return m_cache;
        }
        
        Map & GetMapRW() override
        {
            return m_cache;
        }

    protected:

    private:
        Map m_cache;
};
}

#endif // CACHERAMELIB_H
