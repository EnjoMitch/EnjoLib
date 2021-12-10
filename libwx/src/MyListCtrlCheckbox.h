#ifndef MYLISTCTRL_H
#define MYLISTCTRL_H

#include <wx/listctrl.h>
#include <wx/imaglist.h>
#include <STD/Vector.hpp>

class Record;

class MyListCtrlCheckbox : public wxListCtrl
{
    public:
        MyListCtrlCheckbox(wxWindow *parent, wxWindowID id, const wxPoint &pos=wxDefaultPosition, const wxSize &size=wxDefaultSize,
                    long style=wxLC_ICON, const wxValidator &validator=wxDefaultValidator, const wxString &name=wxListCtrlNameStr);
        virtual ~MyListCtrlCheckbox();

        std::vector<long> GetCheckedIds() const;
        std::vector<long> GetUncheckedIds() const;
        std::vector<wxUIntPtr> GetCheckedData() const;
        std::vector<wxUIntPtr> GetUncheckedData() const;
        bool IsChecked(long item) const;
        void SetChecked(long item, bool checked);

    protected:
        std::vector<long> GetAllItems() const;
        void OnMouseEvent(wxMouseEvent& event);
        bool CreateIcons();
        virtual void OnClickedCheckbox( long item );

    private:

        const wxSize m_imageSize;
        wxImageList m_imageList;

};

#endif // MYLISTCTRL_H
