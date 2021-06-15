#ifndef BIMAPBASE_HPP
#define BIMAPBASE_HPP

#include <Template/SafePtr.hpp>

namespace EnjoLib
{
    template <class T, class U>
    class BimapBase
    {
        public:
            BimapBase(){}
            virtual ~BimapBase(){}
            
            virtual void Add(const T & one, const U & two) = 0;
            virtual bool Has1(const T & one) const = 0;
            virtual bool Has2(const U & one) const = 0;
            virtual U Get1(const T & one) const = 0;
            virtual T Get2(const U & one) const = 0;

        protected:

        private:
    };
}

#endif // BIMAPBASE_HPP
