#ifndef MYWXSCROLLEDWINDOW_H
#define MYWXSCROLLEDWINDOW_H


#include <wx/scrolwin.h>
#include <Visual/CanvasMovableScallable.hpp>

namespace EnjoLib
{
class MyWxScrolledWindow : public wxScrolledWindow, public CanvasMovableScallable
{
    public:
        MyWxScrolledWindow(wxWindow * parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style , const wxString& name);
        virtual ~MyWxScrolledWindow();
        Point GetWindowSize() const;

    protected:

        void RefreshClient();
        Point ConvertMouseEvent2Point( wxMouseEvent & event );

        virtual void wxScaleMouseWheel( wxMouseEvent & event );
        virtual void wxOnRightDown(wxMouseEvent & event);
        virtual void wxOnRightUp(wxMouseEvent & event);
        virtual void wxOnMove(wxMouseEvent & event);
        virtual void MyDraw(wxDC & dc) = 0;

    private:
        void OnDraw (wxDC& dc);

        wxColor m_backgroundColor;
};
}

#endif // MYWXSCROLLEDWINDOW_H
