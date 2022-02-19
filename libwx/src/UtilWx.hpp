#ifndef UTILWX_H
#define UTILWX_H

class wxTextCtrl;
class wxWindow;
class wxString;

namespace EnjoLib {
    
class UtilWx
{
    public:
        UtilWx();
        virtual ~UtilWx();
        
        static wxString GetHomeDir();
        static bool IsLinux();
        
        static bool FindFileFillTxt(wxWindow * parent, wxTextCtrl * ctrl);
        static bool ExecuteDefaultEditorOnFile(const wxString & filePath, const wxString & extension);

    protected:

    private:
};

}
#endif // UTILWX_H
