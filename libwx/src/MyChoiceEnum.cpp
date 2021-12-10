#include "pch/wx_pch.h"

#include "MyChoiceEnum.h"
#include <Util/EnumStringMap.hpp>
#include <STD/Map.hpp>

MyChoiceEnum::MyChoiceEnum(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size,
                           int n, const wxString choices[], long style, const wxValidator &validator,
                           const wxString &name)
: wxChoice( parent, id, pos, size, n, choices, style, validator, name )
{
    Connect(wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MyChoiceEnum::OnSelection,0,this);
    //Init( enumMap );
}

MyChoiceEnum::~MyChoiceEnum(){}

void MyChoiceEnum::Init( const EnjoLib::EnumStringMap & enumMap, int initialSelection )
{
    Clear();
    for (unsigned i = 0; i < enumMap.size(); ++i)
       Append("");
    for ( EnjoLib::EnumStringMap::value_type::const_iterator it = enumMap.Data().begin(); it != enumMap.Data().end(); ++it)
        SetString(it->first, it->second.str());
    SetSelection(initialSelection);
}

void MyChoiceEnum::OnSelection( wxCommandEvent& event )
{
    event.Skip();
}
