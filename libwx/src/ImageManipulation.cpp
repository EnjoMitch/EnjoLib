#include "pch/wx_pch.h"

#include <cmath>
#include <wx/image.h>

#include "ImageManipulation.hpp"

ImageManipulation::ImageManipulation()
{
    //ctor
}

ImageManipulation::~ImageManipulation()
{
    //dtor
}

wxImage ImageManipulation::AutoCropWhiteSpace(const wxImage& InputImage)
{
     int nHeight=InputImage.GetHeight();
     int nWidth=InputImage.GetWidth();
     unsigned char nR=InputImage.GetRed(0,0);
     unsigned char nG=InputImage.GetGreen(0,0);
     unsigned char nB=InputImage.GetBlue(0,0);
     int nCloseness=15;

     wxRect ClipRect;
     //Calculate top clip
     for(int y=0;y<nHeight;y++)
     {
         for(int x=0;x<nWidth;x++)
         {
             if(std::abs(InputImage.GetRed(x,y)-nR)>nCloseness||std::abs(InputImage.GetGreen(x,y)-nG)>nCloseness||std::abs(InputImage.GetBlue(x,y)-nB)>nCloseness)
             {
                 ClipRect.y=std::max(y-1,0);
                 goto bottom;
             }
         }
     }
     bottom:
     //Calculate bottom clip
     for(int y=nHeight-1;y>=0; y--)
     {
         for(int x=0;x<nWidth;x++)
         {
             if(std::abs(InputImage.GetRed(x,y)-nR)>nCloseness||std::abs(InputImage.GetGreen(x,y)-nG)>nCloseness||std::abs(InputImage.GetBlue(x,y)-nB)>nCloseness)
             {
                 ClipRect.height=std::min(y+1,nHeight)-ClipRect.y;
                 goto left;
             }
         }
     }
     left:
     //Calculate left clip
     for(int x=0;x<nWidth; x++)
     {
         for(int y=ClipRect.y;y<ClipRect.y+ClipRect.height;y++)
         {
             if(std::abs(InputImage.GetRed(x,y)-nR)>nCloseness||std::abs(InputImage.GetGreen(x,y)-nG)>nCloseness||std::abs(InputImage.GetBlue(x,y)-nB)>nCloseness)
             {
                 ClipRect.x=std::max(x-1,0);
                 goto right;
             }
         }
     }
     right:
     //Calculate right clip
     for(int x=nWidth-1;x>=0; x--)
     {
         for(int y=ClipRect.y;y<ClipRect.y+ClipRect.height;y++)
         {
             if(std::abs(InputImage.GetRed(x,y)-nR)>nCloseness||std::abs(InputImage.GetGreen(x,y)-nG)>nCloseness||std::abs(InputImage.GetBlue(x,y)-nB)>nCloseness)
             {
                 ClipRect.width=std::min(x+1,nWidth)-ClipRect.x;
                 goto crop;
             }
         }
     }
     crop:
     //Create new cropped image
     return InputImage.GetSubImage(ClipRect);
 }
