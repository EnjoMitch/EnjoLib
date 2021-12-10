#include "pch/wx_pch.h"

#include "ConfigSavesWindow.h"

const wxString ConfigSavesWindow::m_widthAppStr = "AppWidth";
const wxString ConfigSavesWindow::m_heightAppStr = "AppHeight";
const wxString ConfigSavesWindow::m_appXStr = "AppX";
const wxString ConfigSavesWindow::m_appYStr = "AppY";

ConfigSavesWindow::ConfigSavesWindow(wxWindow * main, const wxString & appName)
: wxConfig(appName)
, m_main(main)
{
    m_widthApp = ReadLong(m_widthAppStr, 800);
    m_heightApp = ReadLong(m_heightAppStr, 600);
    m_appX = ReadLong(m_appXStr, 0);
    m_appY = ReadLong(m_appYStr, 0);
}

ConfigSavesWindow::~ConfigSavesWindow()
{
    wxSize sz = m_main->GetSize();
    Write(m_widthAppStr, sz.x);
    Write(m_heightAppStr, sz.y);
    wxPoint pos = m_main->GetPosition();
    Write(m_appXStr, pos.x);
    Write(m_appYStr, pos.y);
}

void ConfigSavesWindow::RestoreSize() const
{
    m_main->SetSize(m_widthApp, m_heightApp);
    m_main->SetPosition(wxPoint(m_appX, m_appY));
}
