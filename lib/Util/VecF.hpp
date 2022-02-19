#ifndef VECF_HPP
#define VECF_HPP

#include "../Template/IVecT.hpp"
#include "../3rdParty/stdfwd.hh"
#include "../Template/Iters2.hpp"
#include <Util/Str.hpp>
#include "PimplThin.hpp"

namespace EnjoLib {
class VecF : public IVecT<float>
{
    public:
        VecF();
        explicit VecF( int n );
        explicit VecF( int n, float val );
        VecF( const STDFWD::initializer_list<double> & init );
        VecF( const STDFWD::vector<float> & init );
        VecF( const STDFWD::vector<double> & init );
        VecF( const IVecT<float> & init );
        virtual ~VecF();
        VecF( const VecF & other );
        VecF & operator=(const VecF & other);

        EnjoLib::Str ToStr() const; // TODO
        EnjoLib::Str Print(int precision = 0) const; // TODO
        EnjoLib::Str PrintScilab( const char * varName ) const;
        EnjoLib::Str PrintPython( const char * varName ) const;


        const float * data() const override;
        float * data() override;
        const STDFWD::vector<float> & Data() const override;
        STDFWD::vector<float> DataCopy() const override;
        STDFWD::vector<float> & DataRW() override;

        void Add(float val);

        //! Length of vector
        float Len() const;
        //! Normalised copy of vector
        VecF Norm() const;
        float SumSquares() const;
        float SumAbs() const;
        float Sum() const;
        float Mean() const;
        float MeanWeighted() const;
        float Max() const;
        float MaxAbs() const;
        float Min() const;

        VecF Abs() const;
        VecF AdjustMean() const;
        VecF Slice  (unsigned idx, unsigned len) const;
        VecF SliceTS(unsigned idx, unsigned len) const;
        VecF Diffs() const;
        VecF Smooth(unsigned numToSmooth) const;
        VecF LogSigned() const;

        const float & at(size_t idx) const override;
        float & at(size_t idx);
        float & atw(size_t idx) override;
        const float & operator[](size_t idx) const override;
        float & operator[](size_t idx) override;
        void push_back(const float & val) override;
        void emplace_back(const float & val) override;

        void pop_front() override;
        void pop_back() override;
        void push_front(const float & val) override;
        void emplace_front(const float & val) override;

        size_t size() const override;
        bool empty() const override;
        virtual void clear() override;

        void reserve(size_t siz);

        STDFWD::vector<bool> ToVecBool() const;

        VecF & operator += (const VecF & par);
        VecF & operator -= (const VecF & par);
        VecF & operator *= (const VecF & par);
        VecF & operator /= (const VecF & par);
        VecF & operator += (const float f);
        VecF & operator -= (const float f);
        VecF & operator *= (const float f);
        VecF & operator /= (const float f);

        VecF operator + (const VecF & par) const;
        VecF operator - (const VecF & par) const;
        VecF operator * (const VecF & par) const;
        VecF operator / (const VecF & par) const;
        VecF operator - () const;
        VecF operator + (const float f) const;
        VecF operator - (const float f) const;
        VecF operator * (const float f) const;
        VecF operator / (const float f) const;
        bool operator > (const VecF & par) const;
        bool operator < (const VecF & par) const;
        bool operator != (const VecF & par) const;

        bool operator == (const IVecT<float> & par) const override;

        const float & First() const override;
        const float & Last() const override;

        float & First() override;
        float & Last() override;

        float & front() override;
        float & back() override;

        const float & front() const override;
        const float & back() const override;

        IITER_IMPL

    protected:
        PIMPL_FAST
    private:

};
}
#endif // VECF_HPP
