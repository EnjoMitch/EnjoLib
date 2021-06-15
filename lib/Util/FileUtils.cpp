/*
Modified BSD License

This file originates from:
http://sf.net/projects/enjomitchsorbit

Copyright (c) 2012, Szymon "Enjo" Ender
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "FileUtils.hpp"
#include "CharManipulations.hpp"
#include <Util/CoutBuf.hpp>
#include <Util/Ofstream.hpp>
#include <Util/Ifstream.hpp>

#include <STD/VectorCpp.hpp>
#include <STD/Istream.hpp>
#include <sys/types.h>
#include <sys/stat.h>

using namespace EnjoLib;

std::vector<VecStr > FileUtils::GetConfigSections( const EnjoLib::Str & fileName,
        const EnjoLib::Str & startMarker,
        const EnjoLib::Str & endMarker ) const
{
    std::vector<VecStr > sections;
    Ifstream file(fileName.c_str(), false);
    if ( !file.is_open() )
        return sections;

    EnjoLib::Str line;
    while ( GetLine(file, line) )
    {
        if (CharManipulations().Trim(line) == startMarker)
        {
            VecStr section = GetOneSection( file.IStr(), endMarker );
            sections.push_back(section);
        }
    }
    return sections;
}

VecStr FileUtils::GetOneSection( std::istream & file, const EnjoLib::Str & endMarker ) const
{
    VecStr section;
    EnjoLib::Str line;
    while ( std::getline(file, line.strRW()) && CharManipulations().Trim(line) != endMarker )
        section.push_back(line);
    return section;
}

bool FileUtils::FileExists( const EnjoLib::Str & fileName ) const
{
    Ifstream f(fileName.c_str(), false);
    return f.is_open();
}

bool FileUtils::DirExists( const EnjoLib::Str & dirName ) const
{
    struct stat info;

    if( stat( dirName.c_str(), &info ) != 0 )
        //printf( "cannot access %s\n", pathname );
        return false;
    else if( info.st_mode & S_IFDIR )  // S_ISDIR() doesn't exist on my windows
        //printf( "%s is a directory\n", pathname );
        return true;
    else
        //printf( "%s is no directory\n", pathname );
        return false;
}

void FileUtils::CreateDirIfNotExistsLinux(const EnjoLib::Str & dirName) const
{
    if (DirExists(dirName))
        return;
    const EnjoLib::Str command = "mkdir -p " + dirName;
    if (int err = system(command.c_str()))
    {
        ELO
        LOG << "FileUtils::CreateDirIfNotExistsLinux(): err = " << err << NL3;
    }
}

EnjoLib::Str FileUtils::GetBaseDir(const EnjoLib::Str & fullPath) const
{
    std::size_t found = fullPath.str().find_last_of("/\\");
    if (found == std::string::npos)
    {
        return "";
    }
    const EnjoLib::Str & baseDir = fullPath.str().substr(0,found);
    return baseDir;
}

size_t FileUtils::GetNumLinesFile( const EnjoLib::Str & fileName, bool skipHeader ) const
{
    Ifstream is(fileName);
    return GetNumLinesFile(is.IStr(), skipHeader);
}

size_t FileUtils::GetNumLinesFile( std::istream & is, bool skipHeader ) const
{
    size_t size = 0;
    EnjoLib::Str line;
    if (skipHeader)
        std::getline(is, line.strRW());
    while ( std::getline(is, line.strRW()) )
        ++size;
    return size;
}

void FileUtils::Remove(const EnjoLib::Str & fileName)
{
    std::remove(fileName.c_str());
}
