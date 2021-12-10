#include "MyListCtrlTempl.h"

template <class T>
MyListCtrlTempl<T>::MyListCtrlTempl(wxWindow *parent, wxWindowID id,
                                 const wxPoint &pos, const wxSize &size,
                                 long style, const wxValidator &validator, const wxString &name)
: wxListCtrl( parent, id, pos, size, style, validator, name)
{
    //ctor
}

template <class T>
MyListCtrlTempl<T>::~MyListCtrlTempl()
{
    //dtor
}

template <class T>
long MyListCtrlTempl<T>::FindItem( long start, T * data )
{
    return wxListCtrl::FindItem( start, (wxUIntPtr) data);
}

template <class T>
T *	MyListCtrlTempl<T>::GetItemData (long item) const
{
    return (T *) wxListCtrl::GetItemData( item );
}

template <class T>
bool MyListCtrlTempl<T>::SetItemPtrData (long item, T * data)
{
    return wxListCtrl::SetItemPtrData( item, (wxUIntPtr) data );
}
