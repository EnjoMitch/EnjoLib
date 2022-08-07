#include "VecD.hpp"
#include "VecF.hpp"
#include "Str.hpp"

#include <Util/CoutBuf.hpp>
#include <Util/PimplDeleter.hpp>
#include <Statistical/VectorD.hpp>
#include <Statistical/VectorF.hpp>
#include <Statistical/Assertions.hpp>



using namespace EnjoLib;

struct VecD::Impl
{
    Impl() {}
    //Impl(const std::vector<VecD::value_type> & init) : dat(init) {}
    Impl(const std::vector<float> & init) : dat(init) {}
    Impl(const std::vector<double> & init) : dat(init) {}
    Impl( const std::vector<bool> & init ) : dat(init) {}
    Impl( const value_type * init, size_t szz ) : dat(std::vector<VecD::value_type>(init, init + szz)) {}
    Impl( int n ) : dat(n) {}
    Impl( int n, const value_type & val ) : dat(n, val) {}
    Impl( const STDFWD::string & data ) : dat(data) {}
    Impl( const Str & data ) : dat(data.c_str()) {}
    Impl( const IIterable<VecD::value_type> & init )
    {
        dat.reserve(init.size());
        for (const auto & val : init)
        {
            dat.push_back(val);
        }
    }
#ifdef EL_FLOATING_POINT_LOW_PRECISION
    VectorF dat;
#else
    VectorD dat;
#endif
};

PIMPL_DELETER(VecD)

const VecD::value_type * VecD::data() const
{
    return GetImpl().dat.data();
}

VecD::value_type * VecD::data()
{
    return GetImplRW().dat.data();
}

const std::vector<VecD::value_type> & VecD::Data() const
{
    return m_impl->dat;
}

std::vector<VecD::value_type> VecD::DataCopy() const
{
    return m_impl->dat;
}

std::vector<VecD::value_type> & VecD::DataRW()
{
    return m_impl->dat;
}

std::vector<bool> VecD::ToVecBool() const
{
    return m_impl->dat.ToVecBool();
}
std::vector<double> VecD::ToVecDouble() const
{
    std::vector<double> ret(this->size());
    for (size_t i = 0; i < this->size(); ++i)
    {
        const auto & thisVal = this->at(i);
        ret.at(i) = thisVal;
    }
    return ret;
}
VecF VecD::ToVecF() const
{
    VecF ret(this->size());
    for (size_t i = 0; i < this->size(); ++i)
    {
        const auto & thisVal = this->at(i);
        ret.at(i) = thisVal;
    }
    return ret;
}

VecD::VecD()
: m_impl(new Impl())
{
    //LOGL << "Vec Constr\n";
}

VecD::~VecD(){}

VecD::VecD( int n, const value_type & val )
: m_impl(new Impl(n, val))
{

}

VecD::VecD( const VecF & init )
: m_impl(new Impl(init.Data()))
{

}

VecD::VecD( const VecD & other )
: m_impl(new Impl(other.GetImpl().dat))
{

}
VecD & VecD::operator=(const VecD & other)
{   /// TODO: impl not initialized
     GetImplRW() = other.GetImpl();
     return *this;
}

VecD::VecD( const IIterable<VecD::value_type> & init ): m_impl(new Impl(init)){}
VecD::VecD( const std::initializer_list<VecD::value_type> & init ): m_impl(new Impl(init)){}
VecD::VecD( const std::vector<VecD::value_type> & init ): m_impl(new Impl(init)){}
#ifdef EL_FLOATING_POINT_LOW_PRECISION
VecD::VecD( const std::vector<double> & init ): m_impl(new Impl(init)){}
#else
VecD::VecD( const std::vector<float> & init ): m_impl(new Impl(init)){}
#endif
VecD::VecD( const STDFWD::vector<bool> & init ): m_impl(new Impl(init)){}
VecD::VecD( int n ): m_impl(new Impl(n)){}
VecD::VecD( const STDFWD::string & data ): m_impl(new Impl(data)){}
VecD::VecD( const Str & data )           : m_impl(new Impl(data)){}

EnjoLib::Str VecD::ToStr() const
{
    return GetImpl().dat.ToStr();
}
EnjoLib::Str VecD::Print(int precision) const
{
    return GetImpl().dat.Print(precision);
}
EnjoLib::Str VecD::PrintScilab( const char * varName ) const
{
    return GetImpl().dat.PrintScilab(varName);
}
EnjoLib::Str VecD::PrintPython( const char * varName ) const
{
    return GetImpl().dat.PrintPython(varName);
}

VecD::value_type VecD::Len() const
{
    return m_impl->dat.Len();
}
//! Normalised copy of vector
VecD VecD::Norm() const
{
    return m_impl->dat.Norm();
}
VecD::value_type VecD::SumSquares() const
{
    return m_impl->dat.SumSquares();
}
VecD::value_type VecD::SumAbs() const
{
    return m_impl->dat.SumAbs();
}
VecD::value_type VecD::Sum() const
{
    return m_impl->dat.Sum();
}
VecD::value_type VecD::Mean() const
{
    return m_impl->dat.Mean();
}
VecD::value_type VecD::MeanWeighted() const
{
    return m_impl->dat.MeanWeighted();
}
VecD::value_type VecD::Max() const
{
   return  m_impl->dat.Max();
}
VecD::value_type VecD::MaxAbs() const
{
    return m_impl->dat.MaxAbs();
}
VecD::value_type VecD::Min() const
{
    return m_impl->dat.Min();
}

void VecD::reserve(size_t siz)
{
    m_impl->dat.reserve(siz);
}

void VecD::Add(value_type val)
{
    m_impl->dat.Add(val);
}

VecD VecD::Abs() const
{
    return m_impl->dat.Abs();
}

VecD VecD::AdjustMean() const
{
    return m_impl->dat.AdjustMean();
}

VecD VecD::SliceTS(unsigned idx, unsigned len) const
{
    return m_impl->dat.SliceTS(idx, len);
}

VecD VecD::LogSigned() const
{
    return m_impl->dat.LogSigned();
}

VecD VecD::Slice(unsigned idx, unsigned len) const
{
    return m_impl->dat.Slice(idx, len);
}
VecD VecD::Diffs() const
{
    return m_impl->dat.Diffs();
}
VecD VecD::Smooth(unsigned numToSmooth) const
{
    return m_impl->dat.Smooth(numToSmooth);
}

const VecD::VecD::value_type & VecD::at(size_t idx) const
{
    return m_impl->dat.at(idx);
}
const VecD::VecD::value_type & VecD::operator[](size_t idx) const
{
    return m_impl->dat[idx];
}
size_t VecD::size() const
{
    return m_impl->dat.size();
}
VecD::VecD::value_type & VecD::atw(size_t idx)
{
    return m_impl->dat.at(idx);
}
VecD::VecD::value_type & VecD::at(size_t idx)
{
    return m_impl->dat.at(idx);
}
VecD::value_type &  VecD::operator[](size_t idx)
{
    return m_impl->dat.operator[](idx);
}
void  VecD::push_back(const value_type & val)
{
    return m_impl->dat.push_back(val);
}
void VecD::pop_back()
{
    if (empty())
    {
        return;
    }
    m_impl->dat.pop_back();
}

void VecD::pop_front()
{
    if (empty())
    {
        return;
    }
    m_impl->dat.pop_front();
}
void VecD::push_front(const value_type & val)
{
    m_impl->dat.push_front(val);
}
void VecD::emplace_front(const value_type & val)
{
    m_impl->dat.push_front(val);
}

bool  VecD::empty() const
{
    return m_impl->dat.empty();
}
void VecD::clear()
{
    m_impl->dat.clear();
}

void VecD::emplace_back(const value_type & val)
{
    m_impl->dat.emplace_back(val);
}

VecD & VecD::operator += (const VecD & par)
{
    m_impl->dat.operator +=(par.GetImpl().dat);
    return *this;
}
VecD & VecD::operator -= (const VecD & par)
{
    m_impl->dat.operator -=(par.GetImpl().dat);
    return *this;
}
VecD & VecD::operator *= (const VecD & par)
{
    m_impl->dat.operator *=(par.GetImpl().dat);
    return *this;
}
VecD & VecD::operator /= (const VecD & par)
{
    m_impl->dat.operator /=(par.GetImpl().dat);
    return *this;
}

VecD & VecD::operator /= (const value_type f)
{
    m_impl->dat.operator /=(f);
    return *this;
}
VecD & VecD::operator *= (const value_type f)
{
    m_impl->dat.operator *=(f);
    return *this;
}
VecD & VecD::operator += (const value_type f)
{
    m_impl->dat.operator +=(f);
    return *this;
}
VecD & VecD::operator -= (const value_type f)
{
    m_impl->dat.operator -=(f);
    return *this;
}

VecD VecD::operator + (const VecD & par) const
{
    return m_impl->dat.operator +(par.GetImpl().dat);
}
VecD VecD::operator - (const VecD & par) const
{
    return m_impl->dat.operator -(par.GetImpl().dat);
}
VecD VecD::operator * (const VecD & par) const
{
    return m_impl->dat.operator *(par.GetImpl().dat);
}
VecD VecD::operator / (const VecD & par) const
{
    return m_impl->dat.operator /(par.GetImpl().dat);
}
VecD VecD::operator - () const
{
    return m_impl->dat.operator -();
}
VecD VecD::operator + (const value_type f) const
{
    return VecD(*this) += (f);
}
VecD VecD::operator - (const value_type f) const
{
    return VecD(*this) -= (f);
}
VecD VecD::operator * (const value_type f) const
{
    return VecD(*this) *= (f);
}
VecD VecD::operator / (const value_type f) const
{
    return VecD(*this) /= (f);
}
bool VecD::operator > (const VecD & par) const
{
    return m_impl->dat.operator >(par.GetImpl().dat);
}
bool VecD::operator < (const VecD & par) const
{
    return m_impl->dat.operator <(par.GetImpl().dat);
}
bool VecD::operator != (const VecD & par) const
{
    return m_impl->dat  != par.GetImpl().dat;
}

bool VecD::operator == (const VecD & par) const
{
    return m_impl->dat  == par.GetImpl().dat;
}

const VecD::value_type & VecD::First() const
{
    Assertions::NonEmpty(m_impl->dat, "First");
    return GetImpl().dat.front();
}
const VecD::value_type & VecD::Last() const
{
    Assertions::NonEmpty(m_impl->dat, "Last");
    return GetImpl().dat.back();
}

VecD::value_type & VecD::First()
{
    Assertions::NonEmpty(m_impl->dat, "First");
    return GetImplRW().dat.front();
}
VecD::value_type & VecD::Last()
{
    Assertions::NonEmpty(m_impl->dat, "Last");
    return GetImplRW().dat.back();
}

VecD::value_type & VecD::front() {    return First();}
VecD::value_type & VecD::back() {     return Last();}
const VecD::value_type & VecD::front() const {return First();}
const VecD::value_type & VecD::back()  const {return Last();}

VecD::iterator VecD::begin()          {return iterator(&m_impl->dat[0]);}
VecD::iterator VecD::end()            {return iterator(&m_impl->dat[size()]);}
VecD::const_iterator VecD::begin() const    {return const_iterator(&m_impl->dat[0]);}
VecD::const_iterator VecD::end()   const    {return const_iterator(&m_impl->dat[size()]);}
VecD::const_iterator VecD::cbegin() const   {return begin();}
VecD::const_iterator VecD::cend()   const   {return end();}
static int a = 0;

/*
VecD::const_iterator                                       VecD::begin() const {return const_iterator(&m_impl->dat[0]);}
VecD::const_iterator                                       VecD::end() const {return const_iterator(&m_impl->dat[size()]);}

VecD::iterator                                       VecD::begin() {return iterator(&m_impl->dat[0]);}
VecD::iterator                                       VecD::end(){return iterator(&m_impl->dat[size()]);}

VecD::const_iterator                                 VecD::cbegin() const {return const_iterator(&m_impl->dat[0]);}
VecD::const_iterator                                 VecD::cend() const {return const_iterator(&m_impl->dat[size()]);}

VecD::reverse_iterator                               VecD::rbegin(){return reverse_iterator(&m_impl->dat[size() - 1]);}
VecD::reverse_iterator                               VecD::rend(){return reverse_iterator(&m_impl->dat[-1]);}

VecD::const_reverse_iterator                         VecD::crbegin() const {return const_reverse_iterator(&m_impl->dat[size() - 1]);}
VecD::const_reverse_iterator                         VecD::crend() const {return const_reverse_iterator(&m_impl->dat[-1]);}

*/

bool VecD::operator == (const IVecT<VecD::value_type> & par) const
{
    /// TODO: Repetition
    Assertions::Throw("Unimplemented", "VecD::operator == ");
    return false;
}

