#ifndef MOVABLERECT_H
#define MOVABLERECT_H

#include "Systems/RectangleMy.hpp"
class wxDC;

namespace EnjoLib
{
class MovableRect : public EnjoLib::RectangleMy
{
    public:
        MovableRect( const RectangleMy & rect );
        MovableRect( const Point & bottomLeft, const Point & topRight );
        MovableRect( const Point & pos);
        virtual ~MovableRect();
        bool Contains( const Point & clickNatural ) const;
        void Move( const Point & diff );
        void Draw( wxDC & dc, double zoom, const Point & ref ) const;


    protected:
    private:
};
}
#endif // MOVABLERECT_H
