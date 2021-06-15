#ifndef BIMAP_H
#define BIMAP_H

#include <Util/BimapBase.hpp>
#include <STD/Map.hpp>
#include "Statistical/Assertions.hpp"

namespace EnjoLib
{
    template <class T, class U>
    class Bimap : public BimapBase<T, U>
    {
        public:
            Bimap(){}
            virtual ~Bimap(){}
            void Add(const T & one, const U & two);
            bool Has1(const T & one) const;
            bool Has2(const U & one) const;
            U Get1(const T & one) const;
            T Get2(const U & one) const;

        protected:

        private:
            std::map<T, U> m_map1;
            std::map<U, T> m_map2;
    };

    
    template <class T, class U>
    void Bimap<T, U>::Add(const T & one, const U & two)
    {
        m_map1[one] = two;
        m_map2[two] = one;
    }

    template <class T, class U>
    bool Bimap<T, U>::Has1(const T & one) const
    {
        return m_map1.count(one);
    }

    template <class T, class U>
    bool Bimap<T, U>::Has2(const U & one) const
    {
        return m_map2.count(one);
    }

    template <class T, class U>
    U Bimap<T, U>::Get1(const T & one) const
    {
        if (not Has1(one))
        {
            Assertions::Throw("No such element. Check Has1 first!", "Bimap");
        }
        auto it = m_map1.find(one);
        return it->second;
    }

    template <class T, class U>
    T Bimap<T, U>::Get2(const U & one) const
    {
        if (not Has2(one))
        {
            Assertions::Throw("No such element. Check Has2 first!", "Bimap");
        }
        auto it = m_map2.find(one);
        return it->second;
    }
}


#endif // BIMAP_H
