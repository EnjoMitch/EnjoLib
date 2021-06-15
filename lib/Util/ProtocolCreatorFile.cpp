#include "ProtocolCreatorFile.hpp"

#include <Util/Ofstream.hpp>

using namespace EnjoLib;

ProtocolCreatorFile::ProtocolCreatorFile(const Str & fileName, const Str & sep, bool mustSucceed)
: ProtocolCreator(sep)
, m_fileName(fileName)
, m_mustSucceed(mustSucceed)
{
}

ProtocolCreatorFile::~ProtocolCreatorFile()
{
    ToFile();
}

bool ProtocolCreatorFile::ToFile() const
{
    Ofstream ofs(m_fileName, m_mustSucceed);
    if (ofs.is_open())
    {
        ofs << Get() << NL;
        return true;
    }
    return false;
}

Str ProtocolCreatorFile::GetFileName() const
{
    return m_fileName;
}