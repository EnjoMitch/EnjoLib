#ifndef TOOLSMIXED_H
#define TOOLSMIXED_H

#include <Util/Str.hpp>
#include <Util/VecD.hpp>
#include "../3rdParty/stdfwd.hh"

namespace EnjoLib
{
class ToolsMixed
{
    public:
        ToolsMixed(){}
        virtual ~ToolsMixed(){}

        Str BinHex2Str(const unsigned char* data, int len) const;
        void AnimationPropeller(int * idx) const;
        void Animation09AZ(int * idx) const;
        void AnimationCustom(int * idx, const Str & animSeries) const;
        struct ConfigPercentToAscii
        {
            ConfigPercentToAscii(){}
            bool decoration = false;
            bool blocks = true;
        };
        EnjoLib::Str GetPercentToAscii(double val, double minimum = 0, double maximum = 1, bool blocks = false);
        EnjoLib::Str GetPercentToAscii(const EnjoLib::VecD & val, double minimum = 0, double maximum = 1, const ConfigPercentToAscii & conf = ConfigPercentToAscii{});
        Str GenBars10(double percentage0_100, const char barFull = '=', const char barEmpty = ' ') const;
        Str GenChars(const Str & pattern, int numberOfRepetitions) const;
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
