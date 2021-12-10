#ifndef DRAWINGOBJECTMANAGER_H
#define DRAWINGOBJECTMANAGER_H

#include <STD/Vector.hpp>
class wxMouseEvent;

namespace EnjoLib
{

class DrawingObjectAbstract;
class Canvas;
class DrawableObjectTypeAbstract;
class DrawingObjectFactoryAbstract;


class DrawingObjectManager
{
    public:
        DrawingObjectManager(const Canvas & canvas, DrawingObjectFactoryAbstract & factory);
        virtual ~DrawingObjectManager();
        DrawingObjectAbstract * Add( int type, wxMouseEvent & event );
        DrawingObjectAbstract * Contains( wxMouseEvent & e );
        void Draw( wxDC & dc, const DrawingObjectAbstract * selected ) const;
        void Delete( DrawingObjectAbstract * selected );
        DrawingObjectAbstract * DeleteLast();
        void Clear();

    protected:
        const Canvas & GetCanvas() const;
        virtual void DrawClient( wxDC & dc, const DrawingObjectAbstract * selected ) const = 0;
        virtual void DeleteClient( DrawingObjectAbstract * selected ) = 0;

        std::vector<DrawingObjectAbstract *> m_objects;

    private:
        void AddToDeleted(DrawingObjectAbstract * toDelete );

        const Canvas & m_canvas;
        DrawingObjectFactoryAbstract & m_factory;
        std::vector<DrawingObjectAbstract *> m_objectsToDelete;
};
}
#endif // DRAWINGOBJECTMANAGER_H
