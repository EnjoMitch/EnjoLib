#include "LinuxNetwork.hpp"
#include <Util/Ifstream.hpp>
#include <Util/Ofstream.hpp>
#include <Util/CharManipulations.hpp>
#include <Util/ToolsMixed.hpp>
//#include <Util/Except.hpp>

using namespace std;
using namespace EnjoLib;

LinuxNetwork::LinuxNetwork(){}
LinuxNetwork::~LinuxNetwork(){}

EnjoLib::Str LinuxNetwork::GetMacAddress(const EnjoLib::Str & interface) const
{
    // cat /sys/class/net/eth0/address
    const EnjoLib::Str fileName = InterfaceToFilename(interface);
    Ifstream addr(fileName);
    EnjoLib::Str line;
    GetLine(addr, line);
    return line;
}

bool LinuxNetwork::HasMacAddress(const EnjoLib::Str & interface) const
{
    // cat /sys/class/net/eth0/address
    const EnjoLib::Str fileName = InterfaceToFilename(interface);
    const Ifstream addr(fileName.c_str(), false);
    return addr.is_open();
}

EnjoLib::Str LinuxNetwork::InterfaceToFilename(const EnjoLib::Str & interface) const
{
    return "/sys/class/net/" + interface + "/address";
}

bool LinuxNetwork::IsPortOpen(const EnjoLib::Str & host, int port) const
{
    const EnjoLib::Str & cmd = "timeout 0.5 nc -z " + host + " " + CharManipulations().ToStr(port);
    const bool ret = ToolsMixed().SystemCallWarnBool(cmd, "IsPortOpen");
    return ret;
}

    /*
    bool port_in_use(unsigned short port) {
    using namespace boost::asio;
    using ip::tcp;

    io_service svc;
    tcp::acceptor a(svc);

    boost::system::error_code ec;
    a.open(tcp::v4(), ec) || a.bind({ tcp::v4(), port }, ec);

    return ec == error::address_in_use;
}
*/
