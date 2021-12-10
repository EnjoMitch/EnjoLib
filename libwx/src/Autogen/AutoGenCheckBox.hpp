#ifndef AUTOGENCHECKBOX_HPP
#define AUTOGENCHECKBOX_HPP

#include <Util/Str.hpp>
#include <Template/VecT.hpp>

class MapCheckbox;

namespace EnjoLib {
class AutoGenCheckBox
{
    public:
        AutoGenCheckBox();
        virtual ~AutoGenCheckBox();
        
        static void Gen(wxWindow * parent, 
                        const EnjoLib::VecT<bool*>          & bools, 
                        const EnjoLib::VecT<EnjoLib::Str>   & boolsDescr, 
                        const EnjoLib::VecT<EnjoLib::Str>   & boolsTooltips,
                        wxBoxSizer * sizer, MapCheckbox * mapCheckbox, wxObjectEventFunction fun);

    protected:

    private:
};

}
#endif // AUTOGENCHECKBOX_HPP
