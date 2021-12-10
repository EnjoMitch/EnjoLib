#ifndef IMAGEMANIPULATION_H
#define IMAGEMANIPULATION_H


class wxImage;
class ImageManipulation
{
    public:
        ImageManipulation();
        virtual ~ImageManipulation();

        static wxImage AutoCropWhiteSpace(const wxImage& InputImage);

    protected:
    private:
};

#endif // IMAGEMANIPULATION_H
