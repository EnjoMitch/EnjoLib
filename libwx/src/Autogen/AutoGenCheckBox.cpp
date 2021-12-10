#include "../pch/wx_pch.h"

#include "AutoGenCheckBox.hpp"
#include "Maps/MapCheckbox.hpp"

#include <Util/Str.hpp>
#include <Util/CharManipulations.hpp>
#include <Template/VecT.hpp>
#include <Statistical/Assertions.hpp>

using namespace EnjoLib;

AutoGenCheckBox::AutoGenCheckBox()
{
    //ctor
}

AutoGenCheckBox::~AutoGenCheckBox()
{
    //dtor
}

void AutoGenCheckBox::Gen(wxWindow * parent, 
                        const EnjoLib::VecT<bool*>          & bools, 
                        const EnjoLib::VecT<EnjoLib::Str>   & boolsDescr, 
                        const EnjoLib::VecT<EnjoLib::Str>   & boolsTooltips, 
                        wxBoxSizer * sizer, MapCheckbox * mapCheckbox, wxObjectEventFunction fun)
{
    EnjoLib::Assertions::SizesEqual(bools.size(), boolsDescr.size(), "AutoGenCheckBox::Gen(): Bools descr");
    const CharManipulations cman;
    //std::cout << "PreTFImpl size = " << bools.size() <<  " " << boolsDescr.size() << std::endl;
    for (int i = 0; i < int(bools.size()); ++i)
    {
        const long idCheckbox = wxNewId();
        const EnjoLib::Str & toolTip = boolsTooltips.at(i);
        EnjoLib::Str descr = boolsDescr.at(i);
        
        if (descr.empty())
        {
            descr = "Unknown";
        }
        descr = cman.UpperCase2Sentence(descr);
        const char * name = descr.c_str();
        //std::cout << "i = " << i << " name = " << name << std::endl;
        wxCheckBox * check = new wxCheckBox(parent, idCheckbox, name, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, name);
        check->SetValue(false);
        check->SetToolTip(toolTip.c_str());

        sizer->Add(check, 0, wxEXPAND, 5);
        mapCheckbox->Register(bools.at(i),   check);
        parent->Connect(idCheckbox,wxEVT_COMMAND_CHECKBOX_CLICKED, fun);
        //Connect(idCheckbox,wxEVT_COMMAND_CHECKBOX_CLICKED, (wxObjectEventFunction)&DialogTF::OnTF);
    }
    sizer->Fit(parent);
	sizer->SetSizeHints(parent);
}
