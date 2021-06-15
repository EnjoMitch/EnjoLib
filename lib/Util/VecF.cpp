#include "VecF.hpp"
#include <Util/PimplDeleter.hpp>
#include <Statistical/VectorF.hpp>
#include <Statistical/Assertions.hpp>



using namespace EnjoLib;

struct VecF::Impl
{
    Impl(){}
    Impl(const std::vector<float> & init) : dat(init) {}
    Impl(const std::vector<double> & init) : dat(init) {}
    Impl(const IVecT<float> & init) : dat(init.Data()) {}
    Impl( int n ) : dat(n) {}
    //Impl( int n, float val ) : dat(n, val) {} // TODO
    Impl( int n, float val ) : dat(n) {}
    VectorF dat;
};

PIMPL_DELETER(VecF)

VecF::VecF()
: m_impl(new Impl())
{
}

VecF::~VecF(){}

VecF::VecF( int n )
: m_impl(new Impl(n))
{

}

VecF::VecF( int n, float val )
: m_impl(new Impl(n, val))
{

}

VecF::VecF( const std::initializer_list<double> & init ) : m_impl(new Impl(init)){    }
VecF::VecF( const std::vector<float> & init ) : m_impl(new Impl(init)){    }
VecF::VecF( const std::vector<double> & init ): m_impl(new Impl(init)) {   }
VecF::VecF( const IVecT<float> & init ): m_impl(new Impl(init)) {   }

VecF::VecF( const VecF & other )
: m_impl(new Impl(other.GetImpl().dat))
{

}
VecF & VecF::operator=(const VecF & other)
{
     GetImplRW() = other.GetImpl();
     return *this;
}

EnjoLib::Str VecF::ToStr() const
{
    return GetImpl().dat.ToStr();
}
EnjoLib::Str VecF::Print(int precision) const
{
    return GetImpl().dat.Print(precision);
}
EnjoLib::Str VecF::PrintScilab( const char * varName ) const
{
    return GetImpl().dat.PrintScilab(varName);
}
EnjoLib::Str VecF::PrintPython( const char * varName ) const
{
    return GetImpl().dat.PrintPython(varName);
}

const float * VecF::data() const
{
    return GetImpl().dat.data();
}

float * VecF::data()
{
    return GetImplRW().dat.data();
}

const std::vector<float> & VecF::Data() const
{
    return m_impl->dat;
}

std::vector<float> VecF::DataCopy() const
{
    return m_impl->dat;
}

std::vector<float> & VecF::DataRW()
{
    return m_impl->dat;
}

std::vector<bool> VecF::ToVecBool() const
{
    return m_impl->dat.ToVecBool();
}

float VecF::Len() const
{
    return m_impl->dat.Len();
}
//! Normalised copy of vector
VecF VecF::Norm() const
{
    return m_impl->dat.Norm();
}
float VecF::SumSquares() const
{
    return m_impl->dat.SumSquares();
}
float VecF::SumAbs() const
{
    return m_impl->dat.SumAbs();
}
float VecF::Sum() const
{
    return m_impl->dat.Sum();
}
float VecF::Mean() const
{
    return m_impl->dat.Mean();
}
float VecF::MeanWeighted() const
{
    return m_impl->dat.MeanWeighted();
}
float VecF::Max() const
{
   return  m_impl->dat.Max();
}
float VecF::MaxAbs() const
{
    return m_impl->dat.MaxAbs();
}
float VecF::Min() const
{
    return m_impl->dat.Min();
}

void VecF::reserve(size_t siz)
{
    m_impl->dat.reserve(siz);
}

void VecF::Add(float val)
{
    m_impl->dat.Add(val);
}

VecF VecF::AdjustMean() const
{
    return m_impl->dat.AdjustMean();
}

VecF VecF::SliceTS(unsigned idx, unsigned len) const
{
    return m_impl->dat.SliceTS(idx, len);
}

VecF VecF::LogSigned() const
{
    return m_impl->dat.LogSigned();
}

VecF VecF::Slice(unsigned idx, unsigned len) const
{
    return m_impl->dat.Slice(idx, len);
}
VecF VecF::Diffs() const
{
    return m_impl->dat.Diffs();
}
float & VecF::at(size_t idx)
{
    return m_impl->dat.at(idx);
}

const float & VecF::at(size_t idx) const
{
    return m_impl->dat.at(idx);
}
const float & VecF::operator[](size_t idx) const
{
    return m_impl->dat[idx];
}
size_t VecF::size() const
{
    return m_impl->dat.size();
}
float &  VecF::atw(size_t idx)
{
    return m_impl->dat.at(idx);
}
float &  VecF::operator[](size_t idx)
{
    return m_impl->dat.operator[](idx);
}
void  VecF::push_back(const float & val)
{
    return m_impl->dat.push_back(val);
}
void  VecF::pop_back()
{
    return m_impl->dat.pop_back();
}
bool  VecF::empty() const
{
    return m_impl->dat.empty();
}
void VecF::clear()
{
    m_impl->dat.clear();
}

void VecF::emplace_back(const float & val)
{
    return m_impl->dat.emplace_back(val);
}


VecF & VecF::operator += (const VecF & par)
{
    m_impl->dat.operator +=(par.GetImpl().dat);
    return *this;
}
VecF & VecF::operator -= (const VecF & par)
{
    m_impl->dat.operator -=(par.GetImpl().dat);
    return *this;
}
VecF & VecF::operator /= (const float f)
{
    m_impl->dat.operator /=(f);
    return *this;
}
VecF & VecF::operator *= (const float f)
{
    m_impl->dat.operator *=(f);
    return *this;
}
VecF & VecF::operator += (const float f)
{
    m_impl->dat.operator +=(f);
    return *this;
}
VecF & VecF::operator -= (const float f)
{
    m_impl->dat.operator -=(f);
    return *this;
}

VecF VecF::operator + (const VecF & par) const
{
    return m_impl->dat.operator +(par.GetImpl().dat);
}
VecF VecF::operator - (const VecF & par) const
{
    return m_impl->dat.operator -(par.GetImpl().dat);
}
VecF VecF::operator - () const
{
    return m_impl->dat.operator -();
}
VecF VecF::operator + (const float f) const
{
    return VecF(*this) += (f);
}
VecF VecF::operator - (const float f) const
{
    return VecF(*this) -= (f);
}
VecF VecF::operator * (const float f) const
{
    return VecF(*this) *= (f);
}
VecF VecF::operator / (const float f) const
{
    return VecF(*this) /= (f);
}
bool VecF::operator > (const VecF & par) const
{
    return m_impl->dat.operator >(par.GetImpl().dat);
}
bool VecF::operator < (const VecF & par) const
{
    return m_impl->dat.operator <(par.GetImpl().dat);
}
bool VecF::operator != (const VecF & par) const
{
    return m_impl->dat  != par.GetImpl().dat;
}

const float & VecF::First() const
{
    Assertions::NonEmpty(m_impl->dat, "First");
    return GetImpl().dat.front();
}
const float & VecF::Last() const
{
    Assertions::NonEmpty(m_impl->dat, "Last");
    return GetImpl().dat.back();
}

float & VecF::First()
{
    Assertions::NonEmpty(m_impl->dat, "First");
    return GetImplRW().dat.front();
}
float & VecF::Last()
{
    Assertions::NonEmpty(m_impl->dat, "Last");
    return GetImplRW().dat.back();
}

float & VecF::front() {    return First();}
float & VecF::back() {     return Last();}
const float & VecF::front() const {return First();}
const float & VecF::back()  const {return Last();}

VecF::iterator VecF::begin()          {return iterator(&m_impl->dat[0]);}
VecF::iterator VecF::end()            {return iterator(&m_impl->dat[size()]);}
VecF::const_iterator VecF::begin() const    {return const_iterator(&m_impl->dat[0]);}
VecF::const_iterator VecF::end()   const    {return const_iterator(&m_impl->dat[size()]);}
VecF::const_iterator VecF::cbegin() const   {return begin();}
VecF::const_iterator VecF::cend()   const   {return end();}
