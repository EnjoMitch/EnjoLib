#include "VecD.hpp"
#include "VecF.hpp"
#include "Str.hpp"
#include <Util/PimplDeleter.hpp>
#include <Statistical/VectorD.hpp>
#include <Statistical/Assertions.hpp>



using namespace EnjoLib;

struct VecD::Impl
{
    Impl() {}
    Impl(const std::vector<double> & init) : dat(init) {}
    Impl(const std::vector<float> & init) : dat(init) {}
    Impl( const std::vector<bool> & init ) : dat(init) {}
    Impl( const double * init, size_t szz ) : dat(std::vector<double>(init, init + szz)) {}
    Impl( int n ) : dat(n) {}
    Impl( int n, const double & val ) : dat(n, val) {}
    Impl( const stdfwd::string & data ) : dat(data) {}
    Impl( const Str & data ) : dat(data.c_str()) {}
    VectorD dat;
};

PIMPL_DELETER(VecD)

const double * VecD::data() const
{
    return GetImpl().dat.data();
}

double * VecD::data()
{
    return GetImplRW().dat.data();
}

const std::vector<double> & VecD::Data() const
{
    return m_impl->dat;
}

std::vector<double> VecD::DataCopy() const
{
    return m_impl->dat;
}

std::vector<double> & VecD::DataRW()
{
    return m_impl->dat;
}

std::vector<bool> VecD::ToVecBool() const
{
    return m_impl->dat.ToVecBool();
}

VecD::VecD()
: m_impl(new Impl())
{
}

VecD::~VecD(){}

VecD::VecD( int n, const double & val )
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
{
     GetImplRW() = other.GetImpl();
     return *this;
}

VecD::VecD( const std::initializer_list<double> & init ): m_impl(new Impl(init)){}
VecD::VecD( const std::vector<double> & init ): m_impl(new Impl(init)){}
VecD::VecD( const std::vector<float> & init ): m_impl(new Impl(init)){}
VecD::VecD( const stdfwd::vector<bool> & init ): m_impl(new Impl(init)){}
VecD::VecD( int n ): m_impl(new Impl(n)){}
VecD::VecD( const stdfwd::string & data ): m_impl(new Impl(data)){}
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

double VecD::Len() const
{
    return m_impl->dat.Len();
}
//! Normalised copy of vector
VecD VecD::Norm() const
{
    return m_impl->dat.Norm();
}
double VecD::SumSquares() const
{
    return m_impl->dat.SumSquares();
}
double VecD::SumAbs() const
{
    return m_impl->dat.SumAbs();
}
double VecD::Sum() const
{
    return m_impl->dat.Sum();
}
double VecD::Mean() const
{
    return m_impl->dat.Mean();
}
double VecD::MeanWeighted() const
{
    return m_impl->dat.MeanWeighted();
}
double VecD::Max() const
{
   return  m_impl->dat.Max();
}
double VecD::MaxAbs() const
{
    return m_impl->dat.MaxAbs();
}
double VecD::Min() const
{
    return m_impl->dat.Min();
}

void VecD::reserve(size_t siz)
{
    m_impl->dat.reserve(siz);
}

void VecD::Add(double val)
{
    m_impl->dat.Add(val);
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

const double & VecD::at(size_t idx) const
{
    return m_impl->dat.at(idx);
}
const double & VecD::operator[](size_t idx) const
{
    return m_impl->dat[idx];
}
size_t VecD::size() const
{
    return m_impl->dat.size();
}
double &  VecD::atw(size_t idx)
{
    return m_impl->dat.at(idx);
}
double & VecD::at(size_t idx)
{
    return m_impl->dat.at(idx);
}
double &  VecD::operator[](size_t idx)
{
    return m_impl->dat.operator[](idx);
}
void  VecD::push_back(const double & val)
{
    return m_impl->dat.push_back(val);
}
bool  VecD::empty() const
{
    return m_impl->dat.empty();
}
void VecD::clear()
{
    m_impl->dat.clear();
}

void VecD::emplace_back(const double & val)
{
    return m_impl->dat.emplace_back(val);
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
VecD & VecD::operator /= (const double f)
{
    m_impl->dat.operator /=(f);
    return *this;
}
VecD & VecD::operator *= (const double f)
{
    m_impl->dat.operator *=(f);
    return *this;
}
VecD & VecD::operator += (const double f)
{
    m_impl->dat.operator +=(f);
    return *this;
}
VecD & VecD::operator -= (const double f)
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
VecD VecD::operator - () const
{
    return m_impl->dat.operator -();
}
VecD VecD::operator + (const double f) const
{
    return VecD(*this) += (f);
}
VecD VecD::operator - (const double f) const
{
    return VecD(*this) -= (f);
}
VecD VecD::operator * (const double f) const
{
    return VecD(*this) *= (f);
}
VecD VecD::operator / (const double f) const
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

const double & VecD::First() const
{
    Assertions::NonEmpty(m_impl->dat, "First");
    return GetImpl().dat.front();
}
const double & VecD::Last() const
{
    Assertions::NonEmpty(m_impl->dat, "Last");
    return GetImpl().dat.back();
}

double & VecD::First()
{
    Assertions::NonEmpty(m_impl->dat, "First");
    return GetImplRW().dat.front();
}
double & VecD::Last()
{
    Assertions::NonEmpty(m_impl->dat, "Last");
    return GetImplRW().dat.back();
}

double & VecD::front() {    return First();}
double & VecD::back() {     return Last();}
const double & VecD::front() const {return First();}
const double & VecD::back()  const {return Last();}

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