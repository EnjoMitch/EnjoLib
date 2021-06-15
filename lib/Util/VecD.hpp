#ifndef VECD_HPP
#define VECD_HPP

#include "../Template/IVecT.hpp"
#include "../Template/Iters2.hpp"
#include "../3rdParty/stdfwd.hh"
#include "../Util/PimplThin.hpp"

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
class VecD : public IVecT<double>
{
    public:
        using value_type = double;

        VecD();
        //VecD( const stdfwd::initializer_list<float> & init );
        VecD( const stdfwd::initializer_list<double> & init );
        VecD( const stdfwd::vector<bool> & init );
        VecD( int n );
        VecD( int n, const double & val );
        VecD( const stdfwd::string & data );
        VecD( const Str & data );

        VecD( const stdfwd::vector<double> & init );
        VecD( const stdfwd::vector<float> & init );
        VecD( const VecF & init );
        virtual ~VecD();
        VecD( const VecD & other );
        VecD & operator=(const VecD & other);

        EnjoLib::Str ToStr() const; // TODO
        EnjoLib::Str Print(int precision = 0) const; // TODO
        EnjoLib::Str PrintScilab( const char * varName ) const;
        EnjoLib::Str PrintPython( const char * varName ) const;

        const double * data() const override;
        double * data() override;
        const stdfwd::vector<double> & Data() const override;
        stdfwd::vector<double> DataCopy() const override;
        stdfwd::vector<double> & DataRW() override;

        void Add(double val);

        //! Length of vector
        double Len() const;
        //! Normalised copy of vector
        VecD Norm() const;
        double SumSquares() const;
        double SumAbs() const;
        double Sum() const;
        double Mean() const;
        double MeanWeighted() const;
        double Max() const;
        double MaxAbs() const;
        double Min() const;

        VecD AdjustMean() const;
        VecD Slice  (unsigned idx, unsigned len) const;
        VecD SliceTS(unsigned idx, unsigned len) const;
        VecD Diffs() const;
        VecD LogSigned() const;

        stdfwd::vector<bool> ToVecBool() const;

        VecD & operator += (const VecD & par);
        VecD & operator -= (const VecD & par);
        VecD & operator /= (const double f);
        VecD & operator *= (const double f);
        VecD & operator += (const double f);
        VecD & operator -= (const double f);

        VecD operator + (const VecD & par) const;
        VecD operator - (const VecD & par) const;
        VecD operator - () const;
        VecD operator + (const double f) const;
        VecD operator - (const double f) const;
        VecD operator * (const double f) const;
        VecD operator / (const double f) const;
        bool operator > (const VecD & par) const;
        bool operator < (const VecD & par) const;
        bool operator != (const VecD & par) const;
        
        bool operator == (const VecD & par) const;


        const double & at(size_t idx) const override;
        double & at(size_t idx);
        double & atw(size_t idx) override;
        const double & operator[](size_t idx) const override;
        double & operator[](size_t idx) override;
        void push_back(const double & val) override;
        void emplace_back(const double & val) override;
        size_t size() const override;
        bool empty() const override;
        virtual void clear() override;

        const double & First() const override;
        const double & Last() const override;

        double & First() override;
        double & Last() override;
        
        double & front() override;
        double & back() override;
        
        const double & front() const override;
        const double & back() const override;

        void reserve(size_t siz);

        VecD & operator = (size_t idx);
        
        IITER_IMPL

        //typedef blRawIterator<double>              iterator;
        //typedef blRawIterator<const double>        const_iterator;

        //typedef blRawReverseIterator<double>       reverse_iterator;
        //typedef blRawReverseIterator<const double> const_reverse_iterator;
        
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
