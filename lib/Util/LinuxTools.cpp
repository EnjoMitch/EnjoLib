#include "LinuxTools.hpp"
#include "ToolsMixed.hpp"
#include <openssl/sha.h>

using namespace std;
using namespace EnjoLib;

LinuxTools::LinuxTools(){}
LinuxTools::~LinuxTools(){}

EnjoLib::Str LinuxTools::HashSHA256(const EnjoLib::Str & data) const
{
    const int digestLen = SHA256_DIGEST_LENGTH;
    unsigned char hash[digestLen];
    unsigned char input[data.size()];
    for (unsigned i = 0; i < data.size(); ++i)
        input[i] = data[i];
    SHA256(input, data.size(), hash);

    const EnjoLib::Str ret = ToolsMixed().BinHex2Str(hash, digestLen);
    return ret;
}



