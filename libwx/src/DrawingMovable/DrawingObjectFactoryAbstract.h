#ifndef DRAWINGOBJECTFACTORYABSTRACT_H
#define DRAWINGOBJECTFACTORYABSTRACT_H

namespace EnjoLib
{
class DrawingObjectAbstract;
class Canvas;
class Point;

class DrawingObjectFactoryAbstract
{
    public:
        DrawingObjectFactoryAbstract();
        virtual ~DrawingObjectFactoryAbstract();
        virtual DrawingObjectAbstract * Create( int type, const Canvas & canvas, const Point & start) = 0;

    protected:
    private:
};
}
#endif // DRAWINGOBJECTFACTORY_H
