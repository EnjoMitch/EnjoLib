#include <EnjoLibBoost/ProgramOptions.hpp>

#include <Ios/Osstream.hpp>
#include <boost/program_options.hpp>

using namespace EnjoLib;
using namespace std;
namespace po = boost::program_options;

ProgramOptions:: ProgramOptions(const ProgramOptionsState & popst)
: m_popst(popst)
{
}
ProgramOptions::~ProgramOptions(){}

bool ProgramOptions::IsHelpRequested() const
{
    return GetBoolFromMap(ProgramOptionsState::OPT_HELP);
}

Str ProgramOptions::GetHelp() const
{
    Osstream oss;
    oss.OStr() << m_popst.GetDescr();
    return oss.str();
}

bool ProgramOptions::HasOpt                 (const char * opt) const
{
    return GetPos().GetVM().count(opt);
}

template <class T>
T ProgramOptions::GetTFromMap(const char * opt, T defaultVal) const
{
    const po::variables_map & vm = GetPos().GetVM();
    if (HasOpt(opt))
    {
        const T var = vm[opt].as<T>();
        //cout << opt << " was set to " << var << ".\n";
        return var;
    }
    return defaultVal;
}

int ProgramOptions::GetIntFromMap(const char * opt, int defaultVal) const
{
    return GetTFromMap(opt, defaultVal);
}

float ProgramOptions::GetFloatFromMap(const char * opt, float defaultVal) const
{
    return GetTFromMap(opt, defaultVal);
}

EnjoLib::Str ProgramOptions::GetStrFromMap(const char * opt, const EnjoLib::Str & defaultVal) const
{
    return GetTFromMap(opt, defaultVal);
}

bool ProgramOptions::GetBoolFromMap(const char * opt) const
{
    return HasOpt(opt);
}

/// TODO: ?
/*
void GetFloatFromMap(const po::variables_map & vm, OptionsNumeric * optsNum, const char * opt)
{
    if (vm.count(opt)) (*optsNum).Add(opt, GetTFromMap(vm, opt, float(0)));
}
*/

const char * ProgramOptionsState::OPT_HELP = "help";
ProgramOptionsState::ProgramOptionsState()
: m_vm(new po::variables_map)
, m_descr(new po::options_description("Allowed options"))
{
    m_descr->add_options()(OPT_HELP, "produce help message");
}
ProgramOptionsState::~ProgramOptionsState()
{
    AddBool(OPT_HELP, "produce help message");
}

void ProgramOptionsState::ReadArgs(int argc, char ** argv)
{
    po::store(po::parse_command_line(argc, argv, *m_descr), *m_vm);
    po::notify(*m_vm);
}

const po::variables_map & ProgramOptionsState::GetVM() const
{
    return *m_vm;
}

const po::options_description & ProgramOptionsState::GetDescr() const
{
    return *m_descr;
}

void ProgramOptionsState::AddInt     (const char * opt, const char * descr)
{
    AddT(opt, descr, int(0));
}
void ProgramOptionsState::AddFloat   (const char * opt, const char * descr)
{
    AddT(opt, descr, float(0));
}
void ProgramOptionsState::AddBool    (const char * opt, const char * descr)
{
    m_descr->add_options()(opt, descr);
}
void ProgramOptionsState::AddStr     (const char * opt, const char * descr)
{
    AddT(opt, descr, EnjoLib::Str());
}

template <class T>
void ProgramOptionsState::AddT       (const char * opt, const char * descr, T defaultVal)
{
    m_descr->add_options()(opt, po::value<T>(), descr);
}
