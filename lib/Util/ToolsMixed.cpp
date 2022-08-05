#include <Util/ToolsMixed.hpp>

#include "Tokenizer.hpp"
#include "CharManipulations.hpp"

#include <Math/GeneralMath.hpp>
#include <Ios/Cout.hpp>
#include <Ios/Osstream.hpp>
#include <Util/Except.hpp>
#include <Util/VecD.hpp>
#include <Util/CoutBuf.hpp>
#include <Util/StrColour.hpp>
#include <Statistical/Assertions.hpp>
#include <Statistical/Matrix.hpp>

#include <STD/Map.hpp>
#include <STD/Iomanip.hpp>
#include <STD/Ostream.hpp>
#include <mutex>

using namespace std;
using namespace EnjoLib;

EnjoLib::Str ToolsMixed::BinHex2Str(const unsigned char* data, int len) const
{
    EnjoLib::Osstream ss;
    ss.OStr() << std::hex;
    for(int i=0;i<len;++i)
        ss.OStr() << std::setw(2) << std::setfill('0') << (int)data[i];
    return ss.str();
}

std::map<EnjoLib::Str, EnjoLib::Str> ToolsMixed::FromPythonDict(const EnjoLib::Str & dictStr) const
{
    std::map<EnjoLib::Str, EnjoLib::Str> ret;
    if (dictStr.empty())
        return ret;
    if (dictStr.front() != '{')
        throw EnjoLib::ExceptInvalidArg("Doesn't start with {\n" + dictStr.str());
    if (dictStr.back() != '}')
        throw EnjoLib::ExceptInvalidArg("Doesn't start with }\n" + dictStr.str());

    const EnjoLib::Str & dict = dictStr.str().substr(1, dictStr.size() - 2);
    const Tokenizer tok;
    const CharManipulations cman;
    for (const auto & token : tok.Tokenize(dict, ','))
    {
        const auto & keyVal = tok.Tokenize(token, ':');
        const EnjoLib::Str key = cman.Replace(keyVal.at(0), " ", "");;
        const EnjoLib::Str keyNoQuotes = cman.Replace(key, "'", "");
        const EnjoLib::Str val = cman.Replace(keyVal.at(1), " ", "");;
        ret[keyNoQuotes] = val;
    }
    return ret;
}

void ToolsMixed::SystemCallWarn(const EnjoLib::Str & command, const EnjoLib::Str & functionName) const
{
    if (int err = system(command.c_str()))
    {
        Cout out;
        out << StrColour::GenWarn(SystemCallPrepareMessage(command, functionName, err)) << Nl;
    }
}

bool ToolsMixed::SystemCallWarnBool(const EnjoLib::Str & command, const EnjoLib::Str & functionName) const
{
    if (int err = system(command.c_str()))
    {
        Cout out;
        out << StrColour::GenWarn(SystemCallPrepareMessage(command, functionName, err)) << Nl;
        return false;
    }
    return true;
}

void ToolsMixed::SystemCallThrow(const EnjoLib::Str & command, const EnjoLib::Str & functionName) const
{
    if (int err = system(command.c_str()))
        throw EnjoLib::ExceptRuntimeError(SystemCallPrepareMessage(command, functionName, err).c_str());
}

EnjoLib::Str ToolsMixed::SystemCallPrepareMessage(const EnjoLib::Str & command, const EnjoLib::Str & functionName, int err) const
{
    EnjoLib::Osstream oss;
    oss << functionName << ":\nCouldn't call command = \n" << command << "\nerr = " << err;
    return oss.str();
}

EnjoLib::Str ToolsMixed::GenUniqueStringID() const
{
    static std::mutex mut;
    std::lock_guard<std::mutex> lock(mut);
    static int i = 0;
    const int tme = (int)time(NULL);

    EnjoLib::Osstream oss;
    oss << tme << '-' << ++i;

    return oss.str();
}

EnjoLib::Str ToolsMixed::GetTmpDir()
{
#ifdef WIN32
	return "./";
#else
	return "/tmp/";
#endif
}

