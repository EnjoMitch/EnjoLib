#include "../pch/wx_pch.h"

#include "DrawingObjectAbstract.h"
#include "Visual/Canvas.hpp"
#include <wx/event.h>
#include <wx/dcclient.h>

using namespace EnjoLib;

DrawingObjectAbstract::DrawingObjectAbstract(const Canvas & canvas, const Point & start)
: m_ref( canvas.GetRef() )
, m_zoom ( canvas.GetZoom() )
, m_canvas( canvas )
, m_start( canvas.GetPointNatural(start) )
{
    prevX = prevY = 0;
}

DrawingObjectAbstract::~DrawingObjectAbstract()
{
}

bool DrawingObjectAbstract::Contains( wxMouseEvent & e )
{
    Point clickNatural = GetPointNatural(e);
    m_chosenRects = ContainsClient( clickNatural );
    bool contains = ! m_chosenRects.empty();

    if ( contains )
        StoreMouseClick(e);

    return contains;
}

Point DrawingObjectAbstract::GetPointNatural( wxMouseEvent & e ) const
{
    Point natural = m_canvas.GetPointNatural( e.GetX(), e.GetY() );
    return natural;
}

void DrawingObjectAbstract::StoreMouseClick( wxMouseEvent & e )
{
   prevX = e.GetX();
   prevY = e.GetY();
}

void DrawingObjectAbstract::Move( wxMouseEvent & e )
{
    int dx = e.GetX() - prevX;
    int dy = e.GetY() - prevY;
    Point diff = Point( dx, dy ) / m_zoom;

    for ( MovableRect * mr : m_chosenRects )
            mr->Move( diff );

    StoreMouseClick(e);
}

void DrawingObjectAbstract::Draw( wxDC & dc, const DrawingObjectAbstract * selected ) const
{
    DrawClient(dc, selected == this );
}

const MovableRect & DrawingObjectAbstract::GetStart() const
{
    return m_start;
}

MovableRect & DrawingObjectAbstract::GetStartRW()
{
    return m_start;
}

