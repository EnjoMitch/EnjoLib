#ifndef CACHERAMTHREADSAFE_HPP
#define CACHERAMTHREADSAFE_HPP

#include "CacheRAMBase.hpp"
#include "CacheRAM.hpp"
#include <mutex>

namespace EnjoLib
{
template <class TKeyT, class TValueT>
class CacheRAMThreadSafe : public CacheRAMFunctional<TKeyT, TValueT>
{
    public:
        CacheRAMThreadSafe(){}
        virtual ~CacheRAMThreadSafe(){}

        using TKey = TKeyT;
        using TValue = TValueT;
        using Lock = std::lock_guard<std::mutex>;

        const TValue & Add(const TKey & key, const TValue & val) override
        {
            const Lock lock(mtx);
            return m_cacheRAM.Add(key, val);
        }

        bool Has(const TKey & key) const override
        {
            const Lock lock(mtx);
            return m_cacheRAM.Has(key);
        }

        const TValue & Get(const TKey & key) const override
        {
            const Lock lock(mtx);
            return m_cacheRAM.Get(key);
        }
        
        Result<const TValue *> GetOpt(const TKey & key) const override
        {
            const Lock lock(mtx);
            return m_cacheRAM.GetOpt(key);
        }
        
        TValue & GetRW(const TKey & key) override
        {
            const Lock lock(mtx);
            return m_cacheRAM.GetRW(key);
        }

        const TValue & GetOrCreate(const TKey & key, std::function<TValue(const TKey&)> funcConv) override
        {
             const Lock lock(mtx);
             return m_cacheRAM.GetOrCreate(key, funcConv);
        }
        
        const TValue & GetOrCreate(const TKey & key, const ICalcCacheRes<TKey, TValue> & calculatable) override
        {
             const Lock lock(mtx);
             return m_cacheRAM.GetOrCreate(key, calculatable);
        }

        const TValue & GetAndVerify(const TKey & key, std::function<TValue(const TKey&)> funcConv) const override
        {
            const Lock lock(mtx);
            return m_cacheRAM.GetAndVerify(key, funcConv);
        }
        
        const std::map<TKey, TValue> & GetMap() const override
        {
            const Lock lock(mtx);
            return m_cacheRAM.GetMap();
        }
        
        std::map<TKey, TValue> & GetMapRW() override
        {
            const Lock lock(mtx);
            return m_cacheRAM.GetMapRW();
        }

    protected:

    private:
        CacheRAM<TKey, TValue> m_cacheRAM;
        mutable std::mutex mtx;
};
}

#endif // CACHERAMTHREADSAFE_HPP
