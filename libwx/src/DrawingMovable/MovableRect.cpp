#include "../pch/wx_pch.h"
#include <wx/dcclient.h>

#include "MovableRect.h"

using namespace EnjoLib;

MovableRect::MovableRect( const Point & bottomLeft, const Point & topRight )
: RectangleMy(bottomLeft, topRight)
{
}

MovableRect::MovableRect( const RectangleMy & rect )
: RectangleMy(rect)
{

}

MovableRect::MovableRect( const Point & pos )
: RectangleMy(pos, 100)
{
}

MovableRect::~MovableRect()
{
}

bool MovableRect::Contains( const Point & click ) const
{
    bool inX = click.x > m_topLeft.x && click.x < m_bottomRight.x;
    bool inY = click.y > m_topLeft.y && click.y < m_bottomRight.y;
    return inX && inY;
}

void MovableRect::Move( const Point & diff )
{
    m_topLeft += diff;
    m_bottomRight += diff;
}

void MovableRect::Draw( wxDC & dc, double zoom, const Point & ref ) const
{
    const Point & p1 = m_topLeft;
    const Point & p2 = m_bottomRight;

    int x1 = p1.x * zoom - ref.x;
    int y1 = p1.y * zoom - ref.y;
    int x2 = p2.x * zoom - ref.x;
    int y2 = p2.y * zoom - ref.y;

    dc.DrawLine( x1, y1, x1, y2 );
    dc.DrawLine( x2, y1, x2, y2 );
    dc.DrawLine( x1, y1, x2, y1 );
    dc.DrawLine( x1, y2, x2, y2 );
}
