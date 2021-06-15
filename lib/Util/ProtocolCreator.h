#ifndef PROTOCOLCREATOR_H
#define PROTOCOLCREATOR_H

#include "Util/Str.hpp"
#include "Util/PimplThin.hpp"
#include <3rdParty/stdfwd.hh>
#include <cstdint>

namespace EnjoLib {
class ProtocolCreatorImpl;
class ProtocolCreator
{
    public:
        static const char SEP = ';';
        
        ProtocolCreator(const Str & sep = SEP);
        virtual ~ProtocolCreator();

        void AddSeparator(const Str & sep);
        void AddNL();
        void AddStr(float var);
        void AddStr(int var);
        void AddInt64(uint64_t var);
        void AddDouble(double var);
        void AddStr(const Str & str);

        Str Get() const;
        
    protected:

    private:
        PIMPL_THIN
        
        const Str m_sep = ";";
};
}

#endif // PROTOCOLCREATOR_H
