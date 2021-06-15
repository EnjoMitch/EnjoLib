#ifndef SAFEPTRBASE_HPP
#define SAFEPTRBASE_HPP

#include "../Util/NonCopyable.hpp"

namespace boost 
{ 
    namespace serialization
    {
        class access; 
    }
}

namespace EnjoLib {

template<class T>
struct DefaultPtrDeleter
{
     void operator()(T* ptr) const
     {
         delete ptr;
         // intentionally complex - simplification causes regressions
         typedef char type_must_be_complete[ sizeof(T)? 1: -1 ];
         (void) sizeof(type_must_be_complete);
     }
};

template<class T>
struct DefaultPtrDeleterArray
{
     void operator()(T* ptr) const
     {
         delete[] ptr;
         // intentionally complex - simplification causes regressions
         typedef char type_must_be_complete[ sizeof(T)? 1: -1 ];
         (void) sizeof(type_must_be_complete);
     }
};

template<class T, class Deleter=DefaultPtrDeleter<T>, class Base=NonCopyable>
class SafePtrBase : public Base
{
public:
    using value_type = T;
    using deleter = Deleter;

    virtual ~SafePtrBase()
    {
        // https://stackoverflow.com/questions/9954518/stdunique-ptr-with-an-incomplete-type-wont-compile
        if (m_ptr)
        {
            deleter()(m_ptr);
            //delete m_ptr;
                        // intentionally complex - simplification causes regressions
            //typedef char type_must_be_complete[ sizeof(T)? 1: -1 ];
            //(void) sizeof(type_must_be_complete);
        }
    }
    void Init(T * ptr)
    {
        if (m_ptr)
        {
            deleter()(m_ptr);
        }
        m_ptr = ptr;
    }
    
    T * release()
    {
        T * ptr = m_ptr;
        UnsetPtrMove();
        return ptr;
    }

    bool IsValid() const 
    {
        return m_ptr != nullptr;
    }
    virtual void CheckMe() const {}

    const T & Get() const
    {
        CheckMe();
        return *m_ptr;
    }
    T & GetRW()
    {
        CheckMe();
        return *m_ptr;
    }
    const T * get() const
    {
        return &Get();
    }
    T * get()
    {
        return &GetRW();
    }
    const T & operator*() const
    {
        return Get();
    }
    T & operator*()
    {
        return GetRW();
    }
    const T * operator->() const
    {
        return &Get();
    }
    T * operator->()
    {
        return &GetRW();
    }
protected:
    void UnsetPtrMove()
    {
        m_ptr = nullptr;
    }
    const T * GetProt() const
    {
        return m_ptr;
    }
    
private:
    T * m_ptr = nullptr;
    
    friend class boost::serialization::access;
    // When the class Archive corresponds to an output archive, the
    // & operator is defined similar to <<.  Likewise, when the class Archive
    // is a type of input archive the & operator is defined similar to >>.
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & GetRW();
    }
};
}

#endif // SAFEPTRBASE_HPP
