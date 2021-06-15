#ifndef ARRAY_H
#define ARRAY_H

#include <Template/IIterable.hpp>
#include <Template/SafePtrCpy.hpp>
#include <Template/SafePtr.hpp>
#include <Statistical/Assertions.hpp>

namespace EnjoLib {

template <class T>
class Array : public IIterable<T>
{
    public:
        Array()
        : m_ptr(nullptr)
        {
            //T * dataNew = new T[1]();
            //m_ptr.Init(dataNew);
            //m_sz = 0;
        }
        Array(const T & val)
        : m_ptr(nullptr)
        {
            m_sz = 1;
            T * dataNew = new T[m_sz]();
            m_ptr.Init(dataNew);
            atw(0) = val;
        }
        /*
        Array(T * val) // bad idea - all the pointers have to be array types []
        : m_ptr(val)
        {
            m_sz = 1;
        }
        */
        template <class Cont>
        Array(const Cont & container)
        : Array()
        {
            InitContainer(container);
        }
        virtual ~Array()
        {
            Delete();
        }
        
        Array(const Array & other)
        {
            Cpy(other);
        }
        Array & operator = (const Array & other)
        {   /// TODO: prevent self assignment and do copy-swap
            Cpy(other);
            return *this;
        }
        Array(Array && other)
        : m_ptr(other.m_ptr.release())
        , m_sz(other.m_sz)
        {
        }
        
        template <class Cont>
        void InitContainer(const Cont & container)
        {
            const unsigned size = container.size();
            const T * data = container.data();
            Init(data, size);
        }
        
        void Init(const T * data, unsigned size)
        {
            T * dataNew = new T[size]();
            Delete();
            m_ptr.Init(dataNew);
            // TODO: use memcpy
            for (unsigned i = 0; i < size; ++i)
            {
                dataNew[i] = data[i];
            }
            m_sz = size;
        }
        
        const T & at(size_t i) const override
        {
            Assertions::IndexInBounds(i, m_sz, "Array");
            return data()[i];
        }
        T & atw(size_t i)
        {
            Assertions::IndexInBounds(i, m_sz, "Array");
            return data()[i];
        }
        
        const T & front() const
        {
            return at(0);
        }
        const T & back() const
        {
            return at(m_sz - 1);
        }
        T & front()
        {
            return atw(0);
        }
        T & back()
        {
            return atw(m_sz - 1);
        }
        
        size_t size() const override
        {
            return m_sz;
        }
        
        void clear()
        {
            m_ptr.Init(nullptr);
            m_sz = 0;
        }
        
        const T * data() const
        {
            return m_ptr.get();
        }
        
        T * data()
        {
            return m_ptr.get();
        }

        IITER_IMPL_TEMPLATE

    protected:

    private:
        void Cpy(const Array & other)
        {
            InitContainer(other);
        }

        void Delete() 
        {
        }
        
        friend class boost::serialization::access;
        template<class Archive> 
        void serialize(Archive & ar, const unsigned int version); /// TODO: Do other templates this way, including PIMPL, etc.
    
        SafePtr<T, DefaultPtrDeleterArray<T>> m_ptr;
        unsigned m_sz = 0;
};

template <class T> typename Array<T>::iterator       Array<T>::begin()        {return iterator(      m_ptr.IsValid() ? &m_ptr.get()[0]      : nullptr);}
template <class T> typename Array<T>::iterator       Array<T>::end()          {return iterator(      m_ptr.IsValid() ? &m_ptr.get()[size()] : nullptr);}
template <class T> typename Array<T>::const_iterator Array<T>::begin()  const {return const_iterator(m_ptr.IsValid() ? &m_ptr.get()[0]      : nullptr);}
template <class T> typename Array<T>::const_iterator Array<T>::end()    const {return const_iterator(m_ptr.IsValid() ? &m_ptr.get()[size()] : nullptr);}
template <class T> typename Array<T>::const_iterator Array<T>::cbegin() const {return begin();}
template <class T> typename Array<T>::const_iterator Array<T>::cend()   const {return end();  }

#define AR2VEC(inp, out) { out.reserve(inp.size()); for (const auto & val : inp) out.push_back(val); }
}

#endif // ARRAY_H
