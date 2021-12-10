#ifndef DRAWINGOBJECT_H
#define DRAWINGOBJECT_H

#include <STD/Vector.hpp>
class wxClientDC;
class wxMouseEvent;

#include "MovableRect.h"

namespace EnjoLib
{
class Point;
class Canvas;
class DrawingObject
{
    public:
        DrawingObject(const Canvas & canvas, const Point & start);
        virtual ~DrawingObject();
        void Draw( wxClientDC & dc, const DrawingObject * selected ) const;

        bool Contains( wxMouseEvent & e );
        virtual void Move( wxMouseEvent & e );


    protected:
        virtual void DrawClient( wxClientDC & dc, bool isSelected ) const = 0;
        virtual std::vector<MovableRect *> ContainsClient( const Point & naturalClick ) = 0;
        Point GetPointNatural( wxMouseEvent & e ) const;

        std::vector<MovableRect> m_rects;
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
#endif // DRAWINGOBJECT_H
