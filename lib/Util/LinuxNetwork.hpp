#ifndef LINUXNETWORK_H
#define LINUXNETWORK_H

#include <Util/Str.hpp>

namespace EnjoLib
{
class LinuxNetwork
{
    public:
        LinuxNetwork();
        virtual ~LinuxNetwork();
        EnjoLib::Str GetMacAddress(const EnjoLib::Str & interface) const;
        bool HasMacAddress(const EnjoLib::Str & interface) const;
        bool IsPortOpen(const EnjoLib::Str & host, int port) const;

    protected:

    private:
        EnjoLib::Str InterfaceToFilename(const EnjoLib::Str & interface) const;
};
}


#endif // LINUXNETWORK_H
