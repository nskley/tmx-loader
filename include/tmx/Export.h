/*********************************************************************
Matt Marchant 2013 - 2016
SFML Tiled Map Loader - https://github.com/bjorn/tiled/wiki/TMX-Map-Format
http://trederia.blogspot.com/2013/05/tiled-map-loader-for-sfml.html

Zlib License:

This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented;
you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment
in the product documentation would be appreciated but
is not required.

2. Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any
source distribution.
*********************************************************************/

#ifndef TMX_EXPORT_H_
#define TMX_EXPORT_H_

//check which platform we're on and create export macros as necessary
#if !defined(TMX_STATIC)

#if defined(_WIN32)

//windows compilers need specific (and different) keywords for export
#define TMX_EXPORT_API __declspec(dllexport)

//for vc compilers we also need to turn off this annoying C4251 warning
#ifdef _MSC_VER
#pragma warning(disable: 4251)
#endif //_MSC_VER

#else //linux, FreeBSD, Mac OS X

#if __GNUC__ >= 4

//gcc 4 has special keywords for showing/hiding symbols,
//the same keyword is used for both importing and exporting
#define TMX_EXPORT_API __attribute__ ((__visibility__ ("default")))

#else

//gcc < 4 has no mechanism to explicitly hide symbols, everything's exported
#define TMX_EXPORT_API
#endif //__GNUC__

#endif //_WIN32

#else

//static build doesn't need import/export macros
#define TMX_EXPORT_API

#endif //TMX_STATIC

//TODO if linking the source directly to a project in visual studio
//use this to supress a warning about export symbols no a non-exported project
//#ifdef _MSC_VER
//#pragma warning(disable: 4275)
//#endif //_MSC_VER

#endif //TMX_EXPORT_H_
