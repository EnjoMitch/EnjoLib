#ifndef VECT_HPP
#define VECT_HPP

#include "IVecT.hpp"
#include "../Util/PimplThin.hpp"

namespace EnjoLib {
template <class T>
class VecT : public IVecT<T>
{
    public:
        typedef Iter<T>              iterator;
        typedef Iter<const T>        const_iterator;
        
        typedef int difference_type;

        const_iterator                                       begin() const override;
        const_iterator                                       end() const override;
        
        iterator                                      begin() override;
        iterator                                        end() override;
        const_iterator                                 cbegin() const override;
        const_iterator                                cend() const override;
        
        using value_type = T;
        
        VecT();
        VecT(int n);
        VecT(int n, const T & val);
        VecT( const stdfwd::vector<T> & init );
        VecT( const stdfwd::initializer_list<T> & init );
        VecT( const_iterator beg, const_iterator endd );
        
        virtual ~VecT();
        VecT( const VecT & other );
        VecT & operator=(const VecT & other);
        
        virtual const T * data() const override;
        virtual T * data() override;
        
        virtual const stdfwd::vector<T> & Data() const override;
        virtual stdfwd::vector<T> DataCopy() const override;
        virtual stdfwd::vector<T> & DataRW() override;
        
        virtual const T & at(size_t idx) const override;
        virtual const T & operator[](size_t idx) const override;
        virtual T & atw(size_t idx) override;
        virtual T & operator[](size_t idx) override;
        virtual void push_back(const T & val) override;
        virtual void emplace_back(const T & val) override;
        virtual size_t size() const override;
        virtual bool empty() const override;
        virtual void clear() override;
        
        virtual const T & First() const override;
        virtual const T & Last() const override;

        virtual T & First() override;
        virtual T & Last() override;
        
        virtual T & front() override;
        virtual T & back() override;
        
        bool Contains(const T & searched) const;
        
        virtual const T & front() const override;
        virtual const T & back() const override;        
        
    protected:

    private:
        PIMPL_FAST
};
}

#endif // VECT_HPP
