#include "pch/wx_pch.h"
#include "UtilWx.hpp"

#include <Template/SafePtr.hpp>

#include <wx/stdpaths.h>
#include <wx/mimetype.h>

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

bool UtilWx::FindFileFillTxt(wxWindow * parent, wxTextCtrl * ctrl)
{
    const wxString & fil = ctrl->GetValue();

    wxFileDialog openFileDialog(parent, _("Find " + fil), "", fil,  "", wxFD_PREVIEW);
    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return false;     // the user changed idea...

    ctrl->SetValue(openFileDialog.GetPath());
    
    return true;
}

bool UtilWx::ExecuteDefaultEditorOnFile(const wxString & filePath, const wxString & extension)
{
    // 1) Get File Type
    EnjoLib::SafePtr<wxFileType> c_type(wxTheMimeTypesManager->GetFileTypeFromExtension(extension));
    if(!c_type.IsValid())
    {
        wxMessageBox("Could not find association");
        return false;
    }

    // 2) Get Open Message
    const wxString command = c_type->GetOpenCommand(filePath);
    if(!command)
    {
        wxMessageBox("No default program");
        return false; //No defoult program
    }
    // 3) Execute message
    wxExecute(command);
    return true;
}
