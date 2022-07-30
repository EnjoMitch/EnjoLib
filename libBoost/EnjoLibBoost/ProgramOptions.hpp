#ifndef PROGRAMOPTIONS_H
#define PROGRAMOPTIONS_H

#include <Util/Str.hpp>
#include <Util/VecStr.hpp>
#include <Template/VecT.hpp>
#include <Template/SafePtrFast.hpp>

namespace boost
{
namespace program_options
{
    class variables_map;
    class options_description;
}
}

namespace EnjoLib
{

class ProgramOptionsState
{
    public:
        ProgramOptionsState();
        virtual ~ProgramOptionsState();

        void ReadArgs(int argc, char ** argv);
        const boost::program_options::variables_map & GetVM() const;
        const boost::program_options::options_description & GetDescr() const;

        void AddInt     (const char * opt, const char * descr);
        void AddFloat   (const char * opt, const char * descr);
        void AddBool    (const char * opt, const char * descr);
        void AddStr     (const char * opt, const char * descr);

        static const char * OPT_HELP;

    protected:
        template <class T>
        void AddT       (const char * opt, const char * descr, T defaultVal);

    private:

        SafePtrFast<boost::program_options::variables_map> m_vm;
        SafePtrFast<boost::program_options::options_description> m_descr;

        //VecStr m_vStr;
        //VecT<int> m_vInt;
        //VecT<float> m_vFloat;
        //VecT<int> m_vBool;
};

class ProgramOptions
{
    public:
        ProgramOptions(const ProgramOptionsState & popst);
        virtual ~ProgramOptions();

        bool IsHelpRequested() const;
        Str GetHelp() const;
        const ProgramOptionsState & GetPos() const { return m_popst; }

        bool HasOpt                 (const char * opt) const;
        int GetIntFromMap           (const char * opt, int defaultVal = 0) const;
        float GetFloatFromMap       (const char * opt, float defaultVal = 0) const;
        bool GetBoolFromMap         (const char * opt) const;
        EnjoLib::Str GetStrFromMap  (const char * opt, const EnjoLib::Str & defaultVal = "") const;

    protected:
        template <class T>
        T GetTFromMap               (const char * opt, T defaultVal) const;

    private:
        const ProgramOptionsState & m_popst;
};

}
#endif // PROGRAMOPTIONS_H
