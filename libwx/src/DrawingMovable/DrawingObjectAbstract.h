#ifndef DRAWINGOBJECTABS_H
#define DRAWINGOBJECTABS_H

#include <STD/Vector.hpp>
class wxDC;
class wxMouseEvent;

#include "MovableRect.h"

namespace EnjoLib
{
class Point;
class Canvas;

class DrawingObjectAbstract
{
    public:
        DrawingObjectAbstract(const Canvas & canvas, const Point & start);
        virtual ~DrawingObjectAbstract();
        void Draw( wxDC & dc, const DrawingObjectAbstract * selected ) const;

        bool Contains( wxMouseEvent & e );
        const MovableRect & GetStart() const;
        MovableRect & GetStartRW();
        virtual void Move( wxMouseEvent & e );

        virtual std::vector< MovableRect *> GetAllRectsRW() = 0;
        virtual std::vector< const MovableRect *> GetAllRects() const = 0;

    protected:
        virtual void DrawClient( wxDC & dc, bool isSelected ) const = 0;
        virtual std::vector<MovableRect *> ContainsClient( const Point & naturalClick ) = 0;

        Point GetPointNatural( wxMouseEvent & e ) const;
        std::vector<MovableRect *> m_chosenRects;
        const Point & m_ref;
        const double & m_zoom;
        const Canvas & m_canvas;

        MovableRect m_start;

    private:
        void StoreMouseClick( wxMouseEvent & e );


        int prevX, prevY;
};
}
#endif // DRAWINGOBJECTABS
