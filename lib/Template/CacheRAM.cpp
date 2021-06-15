#include "CacheRAM.hpp"

using namespace EnjoLib;

/*
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

TEST(Cache_create)
{
    using Cache = CacheRAM<std::tuple<int, EnjoLib::Str>, float>;
    Cache cache;
    const Cache::Key key = std::make_tuple(1, "");
    
    std::function<decltype(GenerateInt)> f_conv = &GenerateInt;
    
    CHECK_EQUAL(false, cache.Has(key));
    const Cache::Val & val = cache.GetOrCreate(key, f_conv);
    CHECK_EQUAL(true,  cache.Has(key));
    
    if (cache.Has(key))
    {
        const Cache::Val valFound = cache.Get(key);
        CHECK_EQUAL(val, valFound);
        CHECK_EQUAL(f_conv(key), valFound);
    }
    
    //const float valFound = cache.Get(10000); // This should crash
}
*/
