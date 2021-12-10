#include "pch/wx_pch.h"
#include "UtilWx.hpp"

#include <wx/stdpaths.h>

using namespace EnjoLib;

UtilWx::UtilWx(){}
UtilWx::~UtilWx(){}

wxString UtilWx::GetHomeDir()
{
    wxString homeDots = wxStandardPaths::Get().GetUserDataDir();
    homeDots = homeDots.substr(0, homeDots.rfind('/'));
    
    return homeDots;
}

bool UtilWx::IsLinux()
{
    return (wxGetOsVersion() == wxOS_UNIX_LINUX);
}
