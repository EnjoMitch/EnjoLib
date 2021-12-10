/***************************************************************
 * Name:      wx_pch.h
 * Purpose:   Header to create Pre-Compiled Header (PCH)
 * Author:     ()
 * Created:   2012-04-14
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef WX_PCH_H_INCLUDED
#define WX_PCH_H_INCLUDED

// basic wxWidgets headers
#include <wx/wxprec.h>

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#ifdef WX_PRECOMP
    // put here all your rarely-changing header files
 //   #include <wx/databaselayer/DatabaseLayer.h>
 //   #include <wx/databaselayer/DatabaseLayerException.h>
 //   #include <wx/databaselayer/SqliteDatabaseLayer.h>
    #include <cmath>
    #include <wx/string.h>
    #include <wx/event.h>
    #include <wx/dcclient.h>
    #include <wx/image.h>
#endif // WX_PRECOMP

#endif // WX_PCH_H_INCLUDED
