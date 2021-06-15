#include "LinuxSystemCalls.hpp"
#include "ToolsMixed.hpp"



using namespace EnjoLib;

LinuxSystemCalls::LinuxSystemCalls(){}
LinuxSystemCalls::~LinuxSystemCalls(){}

void LinuxSystemCalls::OptiPNG(const EnjoLib::Str & fullPath)
{
    const EnjoLib::Str cmd = "optipng " + fullPath;
    ToolsMixed().SystemCallWarn(cmd, "LinuxSystemCalls::OptiPNG()");
}

void LinuxSystemCalls::Negate(const EnjoLib::Str & fullPath)
{
    const EnjoLib::Str commandNegate = "gm convert " + fullPath + " -negate " +  fullPath;
    ToolsMixed().SystemCallWarn(commandNegate, "LinuxSystemCalls::Negate()");
}

