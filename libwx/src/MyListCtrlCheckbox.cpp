#include "pch/wx_pch.h"

#include <wx/wxprec.h>
#include <wx/renderer.h>

#include "MyListCtrlCheckbox.h"
//#include "Record.h"

MyListCtrlCheckbox::MyListCtrlCheckbox(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size,
                    long style, const wxValidator &validator, const wxString &name)
: wxListCtrl(parent, id, pos, size, style, validator, name )
, m_imageSize(wxRendererNative::Get().GetCheckBoxSize(parent))
//, m_imageSize(15, 15)
, m_imageList(m_imageSize.x, m_imageSize.y, true)
{
    //ctor
    CreateIcons();
    Connect(wxID_ANY,wxEVT_LEFT_DOWN,(wxObjectEventFunction)&MyListCtrlCheckbox::OnMouseEvent);
}

MyListCtrlCheckbox::~MyListCtrlCheckbox()
{
    //dtor
}

bool MyListCtrlCheckbox::CreateIcons()
{
    SetImageList(&m_imageList, wxIMAGE_LIST_SMALL);

    // TODO: Using the native size would be better
    wxBitmap unchecked_bmp(m_imageSize.x, m_imageSize.y),
             checked_bmp(m_imageSize.x, m_imageSize.y),
             unchecked_disabled_bmp(m_imageSize.x, m_imageSize.y),
             checked_disabled_bmp(m_imageSize.x, m_imageSize.y);

    // Bitmaps must not be selected by a DC for addition to the image list but I don't see
    // a way of diselecting them in wxMemoryDC so let's just use a code block to end the scope
    {
        wxMemoryDC renderer_dc;

        // Unchecked
        renderer_dc.SelectObject(unchecked_bmp);
        renderer_dc.SetBackground(*wxTheBrushList->FindOrCreateBrush(GetBackgroundColour(), wxSOLID));
        renderer_dc.Clear();
        wxRendererNative::Get().DrawCheckBox(this, renderer_dc, wxRect(0, 0, m_imageSize.x, m_imageSize.y), 0);

        // Checked
        renderer_dc.SelectObject(checked_bmp);
        renderer_dc.SetBackground(*wxTheBrushList->FindOrCreateBrush(GetBackgroundColour(), wxSOLID));
        renderer_dc.Clear();
        wxRendererNative::Get().DrawCheckBox(this, renderer_dc, wxRect(0, 0, m_imageSize.x, m_imageSize.y), wxCONTROL_CHECKED);

        // Unchecked and Disabled
        renderer_dc.SelectObject(unchecked_disabled_bmp);
        renderer_dc.SetBackground(*wxTheBrushList->FindOrCreateBrush(GetBackgroundColour(), wxSOLID));
        renderer_dc.Clear();
        wxRendererNative::Get().DrawCheckBox(this, renderer_dc, wxRect(0, 0, m_imageSize.x, m_imageSize.y), 0 | wxCONTROL_DISABLED);

        // Checked and Disabled
        renderer_dc.SelectObject(checked_disabled_bmp);
        renderer_dc.SetBackground(*wxTheBrushList->FindOrCreateBrush(GetBackgroundColour(), wxSOLID));
        renderer_dc.Clear();
        wxRendererNative::Get().DrawCheckBox(this, renderer_dc, wxRect(0, 0, m_imageSize.x, m_imageSize.y), wxCONTROL_CHECKED | wxCONTROL_DISABLED);
    }

    // the add order must respect the wxCLC_XXX_IMGIDX defines in the headers !
    m_imageList.Add(unchecked_bmp);
    m_imageList.Add(checked_bmp);
    m_imageList.Add(unchecked_disabled_bmp);
    m_imageList.Add(checked_disabled_bmp);

    return true;
}

std::vector<long> MyListCtrlCheckbox::GetCheckedIds() const
{
    std::vector<long> itemsChecked, items = GetAllItems();
    for ( std::vector<long>::const_iterator it = items.begin(); it != items.end(); ++it )
        if ( IsChecked(*it) )
            itemsChecked.push_back(*it);
    return itemsChecked;
}

std::vector<long> MyListCtrlCheckbox::GetUncheckedIds() const
{
    std::vector<long> itemsUnchecked, items = GetAllItems();
    for ( std::vector<long>::const_iterator it = items.begin(); it != items.end(); ++it )
        if ( ! IsChecked(*it) )
            itemsUnchecked.push_back(*it);
    return itemsUnchecked;
}

std::vector<wxUIntPtr> MyListCtrlCheckbox::GetCheckedData() const
{
    std::vector<wxUIntPtr> itemsChecked;
    std::vector<long> items = GetCheckedIds();
    for ( std::vector<long>::const_iterator it = items.begin(); it != items.end(); ++it )
        itemsChecked.push_back(GetItemData(*it));
    return itemsChecked;
}

std::vector<wxUIntPtr> MyListCtrlCheckbox::GetUncheckedData() const
{
    std::vector<wxUIntPtr> itemsUnchecked;
    std::vector<long> items = GetUncheckedIds();
    for ( std::vector<long>::const_iterator it = items.begin(); it != items.end(); ++it )
        itemsUnchecked.push_back(GetItemData(*it));
    return itemsUnchecked;
}

std::vector<long> MyListCtrlCheckbox::GetAllItems() const
{
    std::vector<long> items;
    long itemIndex = -1;
    for ( ;; )
    {
        itemIndex = GetNextItem(itemIndex);
        if ( itemIndex == -1 )
            break;
        items.push_back(itemIndex);
    }
    return items;
}

void MyListCtrlCheckbox::SetChecked(long item, bool checked)
{
   SetItemImage(item, (checked ? 1 : 0), -1);
}

bool MyListCtrlCheckbox::IsChecked(long item) const
{
   wxListItem info;
   info.m_mask = wxLIST_MASK_IMAGE;
   info.m_itemId = item;

   if (GetItem(info))
      return (info.m_image == 1);
   else
      return false;
}

void MyListCtrlCheckbox::OnClickedCheckbox( long item )
{
    // Simply invert unselected item
    if ( ! GetItemState(item, wxLIST_STATE_SELECTED) )
        SetChecked( item, ! IsChecked(item) );
    else // All selected items will be inverted relatively to the item
    {
        bool itemWasChecked = IsChecked(item);
        std::vector<long> items = GetAllItems();
        for ( std::vector<long>::const_iterator it = items.begin(); it != items.end(); ++it )
           if ( GetItemState(*it, wxLIST_STATE_SELECTED) )
               SetChecked(*it, ! itemWasChecked);
    }
}

void MyListCtrlCheckbox::OnMouseEvent(wxMouseEvent& event)
{
  if (event.LeftDown())
  {
     int flags;
     long item = HitTest(event.GetPosition(), flags);
     if (item > -1 && (flags & wxLIST_HITTEST_ONITEMICON))
        OnClickedCheckbox( item );
     else
        event.Skip();
  }
  else
     event.Skip();
}
