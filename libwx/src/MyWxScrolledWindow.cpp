#include "pch/wx_pch.h"

#include "MyWxScrolledWindow.h"
#include <wx/dcbuffer.h>
using namespace EnjoLib;

MyWxScrolledWindow::MyWxScrolledWindow(wxWindow * parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style , const wxString& name)
: wxScrolledWindow((wxWindow*)parent, id, pos, size, style, name)
, m_backgroundColor(230,240,255)
{
    Connect(wxEVT_RIGHT_DOWN,(wxObjectEventFunction)&MyWxScrolledWindow::wxOnRightDown,0,this);
    Connect(wxEVT_RIGHT_UP,(wxObjectEventFunction)&MyWxScrolledWindow::wxOnRightUp,0,this);
    Connect(wxEVT_MOTION,(wxObjectEventFunction)&MyWxScrolledWindow::wxOnMove,0,this);
    Connect(wxEVT_MOUSEWHEEL,(wxObjectEventFunction)&MyWxScrolledWindow::wxScaleMouseWheel);

    SetBackgroundColour (m_backgroundColor);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
}

MyWxScrolledWindow::~MyWxScrolledWindow()
{
}

Point MyWxScrolledWindow::GetWindowSize() const
{
    return Point( GetClientSize().GetWidth(), GetClientSize().GetHeight() );
}

Point MyWxScrolledWindow::ConvertMouseEvent2Point( wxMouseEvent & event )
{
    return Point(event.GetX(), event.GetY());
}

void MyWxScrolledWindow::wxOnRightDown(wxMouseEvent & event)
{
    OnRightDown(ConvertMouseEvent2Point(event));
}

void MyWxScrolledWindow::wxOnRightUp(wxMouseEvent & event)
{
    OnRightUp();
}

void MyWxScrolledWindow::wxOnMove(wxMouseEvent & event)
{
    SetFocus(); // After auto zoom, the client looses focus on Windows. Here we recapture it
    OnMove(ConvertMouseEvent2Point(event));
}

void MyWxScrolledWindow::RefreshClient()
{
    Refresh();
}
void MyWxScrolledWindow::wxScaleMouseWheel( wxMouseEvent & event )
{
    ScaleMouseWheel(ConvertMouseEvent2Point(event), event.GetWheelRotation() );
}

void MyWxScrolledWindow::OnDraw (wxDC& dc)
{
    wxAutoBufferedPaintDC dcBuffered(this);
    dcBuffered.SetBrush(m_backgroundColor);
    dcBuffered.DrawRectangle(GetClientSize());
    MyDraw(dcBuffered);
}

