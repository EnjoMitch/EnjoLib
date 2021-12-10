#ifndef MAPSPIN_HPP
#define MAPSPIN_HPP

#include "MapControlTpl.hpp"

class wxSpinCtrl;
class MapSpin : public MapControlTpl<long int, wxSpinCtrl>
{
    public:
        MapSpin();
        virtual ~MapSpin();

    protected:

    private:
};

#endif // MAPSPIN_HPP
