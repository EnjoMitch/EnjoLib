#ifndef MAPCHOICEENUM_HPP
#define MAPCHOICEENUM_HPP

#include "IMapControl.hpp"
#include "MapControlBaseTpl.hpp"

#include <STD/Map.hpp>

class MyChoiceEnum;
class MapChoiceEnum : public IMapControl
{
    public:
        MapChoiceEnum();
        virtual ~MapChoiceEnum();

        void Register(long int * variable, MyChoiceEnum * checkbox);
        void FromCheckToVariable() override;
        void FromVariableToCheck() override;

    protected:

    private:

        std::map<long int *, MyChoiceEnum *> m_mapControl;
};

#endif // MAPCHOICEENUM_HPP
