#include "pch_test.h"

#include <Template/CacheRAM.hpp>
#include <Template/CacheRAMBare.hpp>
#include <Template/CacheRAMThreadSafe.hpp>
#include <Util/Str.hpp>
#include <UnitTest++/UnitTest++.h>
#include <STD/Iostream.hpp>
#include <tuple>

using namespace EnjoLib;

static void CacheSimpe(CacheRAMBase<int, float> & cache)
{
    using Cache = CacheRAMBase<int, float>;
    const Cache::TKey key = 1;
    const Cache::TValue val = 0.5;

    CHECK_EQUAL(false, cache.Has(key));
    cache.Add(key, val);
    CHECK_EQUAL(true,  cache.Has(key));

    if (cache.Has(key))
    {
        const Cache::TValue valFound = cache.Get(key);
        CHECK_EQUAL(val, valFound);
    }

    //const float valFound = cache.Get(10000); // This should crash
}

TEST(Cache_simple)
{
    CacheRAM<int, float> cache;
    CacheSimpe(cache);
}

TEST(CacheRAMThreadSafe_simple)
{
    CacheRAMThreadSafe<int, float> cache;
    CacheSimpe(cache);
}

TEST(Cache_overwrite)
{
    CacheRAM<int, float> cache;
    
    using Cache = CacheRAMBase<int, float>;
    const Cache::TKey key = 1;
    const Cache::TValue val1 = 0.5;
    const Cache::TValue val2 = 1.0;

    cache.Add(key, val1);
    CHECK_EQUAL(val1, cache.Get(key));
    
    cache.Add(key, val2);
    CHECK_EQUAL(val2, cache.Get(key));
}

static float GenerateInt(const std::tuple<int, EnjoLib::Str> & inp)
{
    const int & integ = std::get<0>(inp);
    const EnjoLib::Str & str = std::get<1>(inp);
    if (str.empty())
    {
        return 10 * integ;
    }
    else
    {
        return integ / 0.1;
    }
}

static float GenerateIntIncr(const std::tuple<int, EnjoLib::Str> & inp)
{
    int ret = std::get<0>(inp);
    return ++ret;
}

TEST(Cache_create)
{
    using Cache = CacheRAM<std::tuple<int, EnjoLib::Str>, float>;
    Cache cache;
    const Cache::TKey key = std::make_tuple(1, "");

    std::function<decltype(GenerateInt)> f_conv = &GenerateInt;

    CHECK_EQUAL(false, cache.Has(key));
    const Cache::TValue & val = cache.GetOrCreate(key, f_conv);
    CHECK_EQUAL(true,  cache.Has(key));

    if (cache.Has(key))
    {
        const Cache::TValue valFound = cache.Get(key);
        CHECK_EQUAL(val, valFound);
        CHECK_EQUAL(f_conv(key), valFound);
    }

    const Cache::TValue & valFound = cache.GetAndVerify(key, f_conv);
    CHECK_EQUAL(f_conv(key), valFound);

    //const float valFound = cache.Get(10000); // This should crash
}

TEST(Cache_verify)
{
    using Cache = CacheRAM<std::tuple<int, EnjoLib::Str>, float>;
    Cache cache;
    const Cache::TKey key = std::make_tuple(1, "");

    std::function<decltype(GenerateIntIncr)> f_conv = &GenerateIntIncr;
    const Cache::TValue & valCreated = cache.GetOrCreate(key, f_conv);
    CHECK(valCreated == f_conv(key));
    //const Cache::TValue & valFound = cache.GetAndVerify(key, f_conv);
    cache.GetAndVerify(key, f_conv);
}

TEST(Cache_create_non_functional)
{
    using TKey = std::tuple<int, EnjoLib::Str>;
    using TVal = float;
    using Cache = CacheRAMBare<TKey, TVal>;
    Cache cache;
    const Cache::TKey key = std::make_tuple(1, "");

    class Calc : public ICalcCacheRes<Cache::TKey, Cache::TValue>
    {
        public:
         Cache::TValue CalcForCache(const Cache::TKey & key) const override
         {
             return GenerateIntIncr(key);
         }
    };
    
    CHECK_EQUAL(false, cache.Has(key));
    const Cache::TValue & val = cache.GetOrCreate(key, Calc());
    CHECK_EQUAL(true,  cache.Has(key));

    if (cache.Has(key))
    {
        const Cache::TValue valFound = cache.Get(key);
        CHECK_EQUAL(val, valFound);
        CHECK_EQUAL(Calc().CalcForCache(key), valFound);
    }
}
