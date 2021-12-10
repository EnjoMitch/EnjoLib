#ifndef MYLISTCTRLTEMPL_H
#define MYLISTCTRLTEMPL_H

#include <wx/listctrl.h>

template <class T>
class MyListCtrlTempl : public wxListCtrl
{
    public:
        MyListCtrlTempl(wxWindow *parent, wxWindowID id, const wxPoint &pos=wxDefaultPosition,
                        const wxSize &size=wxDefaultSize, long style=wxLC_ICON,
                        const wxValidator &validator=wxDefaultValidator, const wxString &name=wxListCtrlNameStr);
        virtual ~MyListCtrlTempl();

        long FindItem( long start, T * data );
        T *	GetItemData (long item) const;
        bool SetItemPtrData (long item, T * data);
    protected:
    private:
};

#endif // MYLISTCTRLTEMPL_H
