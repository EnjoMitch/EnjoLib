#ifndef MAPCHECKBOX_HPP
#define MAPCHECKBOX_HPP

#include "MapControlTpl.hpp"

class wxCheckBox;
class MapCheckbox : public MapControlTpl<bool, wxCheckBox>
{
    public:
        MapCheckbox();
        virtual ~MapCheckbox();

    protected:

    private:
};

#endif // MAPCHECKBOX_HPP
