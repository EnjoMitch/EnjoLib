#ifndef LINUXTOOLS_H
#define LINUXTOOLS_H

#include <Util/Str.hpp>

namespace EnjoLib
{
// echo -n `cat /sys/class/net/eth0/address` | openssl sha256
class LinuxTools
{
    public:
        LinuxTools();
        virtual ~LinuxTools();
        EnjoLib::Str HashSHA256(const EnjoLib::Str & data) const;

    protected:

    private:
};
}

#endif // LINUXTOOLS_H
