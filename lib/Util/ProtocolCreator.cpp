#include <Util/ProtocolCreator.h>
#include <Util/PimplDeleter.hpp>

#include <Util/Osstream.hpp>

using namespace std;
using namespace EnjoLib;

struct ProtocolCreator::Impl
{
    const EnjoLib::Osstream & Get() const
    {
        return m_oss;
    }
    EnjoLib::Osstream & Get()
    {
        return m_oss;
    }
    EnjoLib::Osstream m_oss;
};
PIMPL_DELETER(ProtocolCreator)

ProtocolCreator::~ProtocolCreator(){}
ProtocolCreator::ProtocolCreator(const Str & sep)
: m_impl(new Impl())
, m_sep(sep)
{}

void ProtocolCreator::AddStr(float var)
{
    m_impl->Get() << var << m_sep;
}

void ProtocolCreator::AddStr(int var)
{
    m_impl->Get() << var << m_sep;
}

void ProtocolCreator::AddInt64(uint64_t var)
{
    m_impl->Get() << var << m_sep;
}

void ProtocolCreator::AddDouble(double var)
{
    m_impl->Get() << var << m_sep;
}

void ProtocolCreator::AddStr(const Str & str)
{
    m_impl->Get() << str << m_sep;
}

void ProtocolCreator::AddSeparator(const Str & sep)
{
    m_impl->Get() << sep;
}

void ProtocolCreator::AddNL()
{
    AddSeparator('\n');
}

Str ProtocolCreator::Get() const
{
    EnjoLib::Str ret = m_impl->Get().str();
    if (not ret.empty())
        ret.pop_back();
    return ret;
}
