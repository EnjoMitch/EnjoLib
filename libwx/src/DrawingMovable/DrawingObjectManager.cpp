#include "../pch/wx_pch.h"

#include <wx/event.h>
#include <wx/dcclient.h>

#include "DrawingObjectManager.h"
#include "DrawingObjectAbstract.h"
#include "DrawingObjectFactoryAbstract.h"

using namespace EnjoLib;

DrawingObjectManager::DrawingObjectManager(const Canvas & canvas, DrawingObjectFactoryAbstract & factory)
    : m_canvas( canvas ), m_factory( factory )
{
}

DrawingObjectManager::~DrawingObjectManager()
{
    for ( DrawingObjectAbstract * dobj : m_objectsToDelete )
        delete dobj;
    for ( DrawingObjectAbstract * dobj : m_objects )
        delete dobj;
}

void DrawingObjectManager::Draw( wxDC & dc, const DrawingObjectAbstract * selected ) const
{
    for ( DrawingObjectAbstract * dobj : m_objects )
        dobj->Draw(dc, selected);

    DrawClient( dc, selected );
}

void DrawingObjectManager::Delete( DrawingObjectAbstract * selected )
{
    DeleteClient( selected );
    for ( std::vector<DrawingObjectAbstract *>::iterator it = m_objects.begin();
            it != m_objects.end(); ++it )
    {
        if (*it == selected)
        {
            AddToDeleted(*it);
            m_objects.erase(it);
            break;
        }
    }
}

DrawingObjectAbstract * DrawingObjectManager::DeleteLast()
{
    if (m_objects.empty())
        return NULL;
    Delete( m_objects.back() );
    if (m_objects.empty())
        return NULL;
    else
        return m_objects.back();
}

void DrawingObjectManager::Clear()
{
    for ( DrawingObjectAbstract * dobj : m_objects )
    {
        DeleteClient( dobj );
        AddToDeleted( dobj );
    }
    m_objects.clear();
}

void DrawingObjectManager::AddToDeleted(DrawingObjectAbstract * toDelete )
{
    bool alreadyToDelete = false;
    for ( unsigned i = 0; ! alreadyToDelete && i < m_objectsToDelete.size(); ++i )
    {
        DrawingObjectAbstract * dobj = m_objectsToDelete[i];
        if ( dobj == toDelete )
            alreadyToDelete = true;
    }
    if ( ! alreadyToDelete )
        m_objectsToDelete.push_back(toDelete);
}

DrawingObjectAbstract * DrawingObjectManager::Contains( wxMouseEvent & e )
{
    DrawingObjectAbstract * selected = NULL;
    for ( DrawingObjectAbstract * dobj : m_objects )
        if ( dobj->Contains(e) )
            selected = dobj;

    return selected;
}

DrawingObjectAbstract * DrawingObjectManager::Add( int type, wxMouseEvent & event )
{
    Point pos( event.GetX(), event.GetY() );
    DrawingObjectAbstract * obj = m_factory.Create( type, m_canvas, pos);
    m_objects.push_back( obj );

    return obj;
}

const Canvas & DrawingObjectManager::GetCanvas() const
{
    return m_canvas;
}


