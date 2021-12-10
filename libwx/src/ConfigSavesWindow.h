#ifndef CONFIGSAVESWINDOW_H
#define CONFIGSAVESWINDOW_H

#include <wx/config.h>

class wxWindow;

class ConfigSavesWindow : public wxConfig
{
    public:
        ConfigSavesWindow(wxWindow * main, const wxString & appName);
        virtual ~ConfigSavesWindow();

        void RestoreSize() const;

    protected:
        wxWindow * m_main;
    private:
        unsigned m_widthApp;
        unsigned m_heightApp;
        unsigned m_appX;
        unsigned m_appY;

        const static wxString m_widthAppStr;
        const static wxString m_heightAppStr;
        const static wxString m_appXStr;
        const static wxString m_appYStr;
};

#endif // CONFIGSAVESWINDOW_H
