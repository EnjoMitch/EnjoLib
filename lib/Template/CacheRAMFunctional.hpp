#ifndef CACHERAMFUNCTIONAL_HPP
#define CACHERAMFUNCTIONAL_HPP

#include "CacheRAMBase.hpp"
#include <functional>

namespace EnjoLib
{
template <class TKeyT, class TValueT>
class CacheRAMFunctional : public CacheRAMBase<TKeyT, TValueT>
{
    public:
        CacheRAMFunctional(){}
        virtual ~CacheRAMFunctional(){}
        
        using TKey = TKeyT;
        using TValue = TValueT;
        
        virtual const TValue & GetOrCreate (const TKey & key, std::function<TValue(const TKey&)> funcConv) = 0;
        virtual const TValue & GetAndVerify(const TKey & key, std::function<TValue(const TKey&)> funcConv) const = 0;

    protected:

    private:
};
}

#endif // CACHERAMFUNCTIONAL_HPP
