#ifndef TOOLSMIXED_H
#define TOOLSMIXED_H

#include <Util/Str.hpp>
#include "../3rdParty/stdfwd.hh"

namespace EnjoLib
{
class ToolsMixed
{
    public:
        ToolsMixed(){}
        virtual ~ToolsMixed(){}

        EnjoLib::Str BinHex2Str(const unsigned char* data, int len) const;
        void AnimationPropeller(int * idx) const;
        void Animation09AZ(int * idx) const;
        void AnimationCustom(int * idx, const EnjoLib::Str & animSeries) const;
        stdfwd::map<EnjoLib::Str, EnjoLib::Str> FromPythonDict(const EnjoLib::Str & dictStr) const;
        void SystemCallWarn(const EnjoLib::Str & command, const EnjoLib::Str & functionName) const;
        bool SystemCallWarnBool(const EnjoLib::Str & command, const EnjoLib::Str & functionName) const;
        void SystemCallThrow(const EnjoLib::Str & command, const EnjoLib::Str & functionName) const;
        EnjoLib::Str GenUniqueStringID() const;

    protected:

    private:
        EnjoLib::Str SystemCallPrepareMessage(const EnjoLib::Str & command, const EnjoLib::Str & functionName, int err) const;
};
}
#endif // TOOLSMIXED_H
