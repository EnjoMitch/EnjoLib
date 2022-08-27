#ifndef TOOLSMIXED_H
#define TOOLSMIXED_H

#include <Util/StrFwd.hpp>
#include "../3rdParty/stdfwd.hh"

namespace EnjoLib
{

class VecD;

class ToolsMixed
{
    public:
        ToolsMixed(){}
        virtual ~ToolsMixed(){}

        Str BinHex2Str(const unsigned char* data, int len) const;
        STDFWD::map<Str, Str> FromPythonDict(const Str & dictStr) const;
        void SystemCallWarn(const Str & command, const Str & functionName) const;
        bool SystemCallWarnBool(const Str & command, const Str & functionName) const;
        void SystemCallThrow(const Str & command, const Str & functionName) const;
        Str GenUniqueStringID() const;
        static Str GetTmpDir();

    protected:

    private:
        Str SystemCallPrepareMessage(const Str & command, const Str & functionName, int err) const;
};
}
#endif // TOOLSMIXED_H
