#ifndef PROTOCOLCREATORFILE_HPP
#define PROTOCOLCREATORFILE_HPP

#include <Util/ProtocolCreator.h>

namespace EnjoLib {
class ProtocolCreatorFile : public ProtocolCreator
{
    public:
        ProtocolCreatorFile(const Str & fileName, const Str & sep = "", bool mustSucceed = true);
        virtual ~ProtocolCreatorFile();
        
        bool ToFile() const;
        Str GetFileName() const;

    protected:

    private:
        
        Str m_fileName;
        bool m_mustSucceed = true;
};
}
#endif // PROTOCOLCREATORFILE_HPP
