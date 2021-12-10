#ifndef MYCHOICEENUM_H
#define MYCHOICEENUM_H

#include <wx/choice.h>
namespace EnjoLib
{
    class EnumStringMap;
}


class MyChoiceEnum : public wxChoice
{
    public:
        MyChoiceEnum(wxWindow *parent, wxWindowID id,
                     const wxPoint &pos=wxDefaultPosition, const wxSize &size=wxDefaultSize,
                     int n=0, const wxString choices[]=NULL, long style=0,
                     const wxValidator &validator=wxDefaultValidator,
                     const wxString &name=wxChoiceNameStr);
        virtual ~MyChoiceEnum();

        void Init( const EnjoLib::EnumStringMap & enumMap, int initialSelection = 0 );


    protected:
        virtual void OnSelection( wxCommandEvent& event );


    private:
};

#endif // MYCHOICEENUM_H
