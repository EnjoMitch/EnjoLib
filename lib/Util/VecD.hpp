#ifndef VECD_HPP
#define VECD_HPP

#include "../Template/IVecT.hpp"
#include "../Template/Iters2.hpp"
#include "../3rdParty/stdfwd.hh"
#include "../Util/PimplThin.hpp"
#include <Math/FP.hpp>

namespace boost
{
    namespace serialization
    {
        class access;
    }
}

namespace EnjoLib {
class VecF;
class Str;
class VecD : public IVecT<FP>
{
    public:
        using value_type = FP;

        VecD();
        //VecD( const STDFWD::initializer_list<float> & init );
        VecD( const STDFWD::initializer_list<value_type> & init );
        VecD( const STDFWD::vector<bool> & init );
        VecD( const IIterable<value_type> & init );
        explicit VecD( int n );
        explicit VecD( int n, const value_type & val );
        VecD( const STDFWD::string & data );
        VecD( const Str & data );

        VecD( const STDFWD::vector<value_type> & init );
#ifdef EL_FLOATING_POINT_LOW_PRECISION
        VecD( const STDFWD::vector<double> & init );
#else
        VecD( const STDFWD::vector<float> & init );
#endif
        VecD( const VecF & init );
        virtual ~VecD();
        VecD( const VecD & other );
        VecD & operator=(const VecD & other);

        EnjoLib::Str ToStr() const; // TODO
        EnjoLib::Str Print(int precision = 0) const; // TODO
        EnjoLib::Str PrintScilab( const char * varName ) const;
        EnjoLib::Str PrintPython( const char * varName ) const;

        const value_type * data() const override;
        value_type * data() override;
        const STDFWD::vector<value_type> & Data() const override;
        STDFWD::vector<value_type> DataCopy() const override;
        STDFWD::vector<value_type> & DataRW() override;

        void Add(value_type val);

        //! Length of vector
        value_type Len() const;
        //! Normalised copy of vector
        VecD Norm() const;
        value_type SumSquares() const;
        value_type SumAbs() const;
        value_type Sum() const;
        value_type Mean() const;
        value_type MeanWeighted() const;
        value_type Max() const;
        value_type MaxAbs() const;
        value_type Min() const;

        VecD Abs() const;
        VecD AdjustMean() const;
        VecD Slice  (unsigned idx, unsigned len) const;
        VecD SliceTS(unsigned idx, unsigned len) const;
        VecD Diffs() const;
        VecD Smooth(unsigned numToSmooth) const;
        VecD LogSigned() const;

        STDFWD::vector<bool> ToVecBool() const;
        STDFWD::vector<double> ToVecDouble() const;
        VecF ToVecF() const;

        VecD & operator += (const VecD & par);
        VecD & operator -= (const VecD & par);
        VecD & operator *= (const VecD & par);
        VecD & operator /= (const VecD & par);
        VecD & operator *= (const value_type f);
        VecD & operator /= (const value_type f);
        VecD & operator += (const value_type f);
        VecD & operator -= (const value_type f);

        VecD operator + (const VecD & par) const;
        VecD operator - (const VecD & par) const;
        VecD operator * (const VecD & par) const;
        VecD operator / (const VecD & par) const;
        VecD operator - () const;
        VecD operator + (const value_type f) const;
        VecD operator - (const value_type f) const;
        VecD operator * (const value_type f) const;
        VecD operator / (const value_type f) const;
        bool operator > (const VecD & par) const;
        bool operator < (const VecD & par) const;
        bool operator != (const VecD & par) const;

        bool operator == (const VecD & par) const;
        bool operator == (const IVecT<value_type> & par) const override;


        const value_type & at(size_t idx) const override;
        value_type & at(size_t idx);
        value_type & atw(size_t idx) override;
        const value_type & operator[](size_t idx) const override;
        value_type & operator[](size_t idx) override;
        void push_back(const value_type & val) override;
        void emplace_back(const value_type & val) override;

        void pop_front() override;
        void pop_back() override;
        void push_front(const value_type & val) override;
        void emplace_front(const value_type & val) override;

        size_t size() const override;
        bool empty() const override;
        virtual void clear() override;

        const value_type & First() const override;
        const value_type & Last() const override;

        value_type & First() override;
        value_type & Last() override;

        value_type & front() override;
        value_type & back() override;

        const value_type & front() const override;
        const value_type & back() const override;

        void reserve(size_t siz);

        VecD & operator = (size_t idx);

        IITER_IMPL

        //typedef blRawIterator<value_type>              iterator;
        //typedef blRawIterator<const value_type>        const_iterator;

        //typedef blRawReverseIterator<value_type>       reverse_iterator;
        //typedef blRawReverseIterator<const value_type> const_reverse_iterator;

        //iterator erase( const_iterator pos );

        //iterator                                       begin() ;
        //iterator                                       end() ;

        //const_iterator                                 cbegin() const ;
        //const_iterator                                 cend() const ;

        //reverse_iterator                               rbegin() ;
        //reverse_iterator                               rend() ;

        //const_reverse_iterator                         crbegin() const ;
        //const_reverse_iterator                         crend() const ;

        friend class boost::serialization::access;
        // When the class Archive corresponds to an output archive, the
        // & operator is defined similar to <<.  Likewise, when the class Archive
        // is a type of input archive the & operator is defined similar to >>.
        template<class Archive>
        void serialize(Archive & ar, const unsigned int version)
        {
            ar & DataRW();
        }

    protected:

    private:

    PIMPL_FAST
};
}

#endif // VECD_HPP
