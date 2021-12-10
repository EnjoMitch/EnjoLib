#include "../pch/wx_pch.h"

#include <wx/event.h>
#include <wx/dcclient.h>

#include "DrawingObject.h"
#include "Visual/Canvas.hpp"

using namespace EnjoLib;

DrawingObject::DrawingObject(const Canvas & canvas, const Point & start)
: m_ref( canvas.GetRef() )
, m_zoom ( canvas.GetZoom() )
, m_canvas( canvas )
, m_start( canvas.GetPointNatural(start) )
{
    prevX = prevY = 0;
}

DrawingObject::~DrawingObject()
{
}

bool DrawingObject::Contains( wxMouseEvent & e )
{
    Point clickNatural = GetPointNatural(e);
    m_chosenRects = ContainsClient( clickNatural );
    bool contains = ! m_chosenRects.empty();

    if ( contains )
        StoreMouseClick(e);

    return contains;
}

Point DrawingObject::GetPointNatural( wxMouseEvent & e ) const
{
    Point natural = m_canvas.GetPointNatural( e.GetX(), e.GetY() );
    return natural;
}

void DrawingObject::StoreMouseClick( wxMouseEvent & e )
{
   prevX = e.GetX();
   prevY = e.GetY();
}

void DrawingObject::Move( wxMouseEvent & e )
{
    int dx = e.GetX() - prevX;
    int dy = e.GetY() - prevY;
    Point diff = Point( dx, dy ) / m_zoom;

    for ( MovableRect * mr : m_chosenRects )
        mr->Move( diff );

    StoreMouseClick(e);
}

void DrawingObject::Draw( wxClientDC & dc, const DrawingObject * selected ) const
{
    DrawClient(dc, selected == this );
}
