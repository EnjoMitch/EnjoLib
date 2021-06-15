#ifndef LINUXSYSTEMCALLS_HPP
#define LINUXSYSTEMCALLS_HPP

#include <Util/Str.hpp>

namespace EnjoLib
{
class LinuxSystemCalls
{
    public:
        LinuxSystemCalls();
        virtual ~LinuxSystemCalls();
        
        static void OptiPNG(const EnjoLib::Str & fullPath);
        static void Negate(const EnjoLib::Str & fullPath);

    protected:

    private:
};
}

#endif // LINUXSYSTEMCALLS_HPP
