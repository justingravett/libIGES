/*
 * file: dll_entity502.h
 *
 * Copyright 2020, Justin Gravett (ESAero)
 *
 * This file is part of libIGES.
 *
 * libIGES is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * libIGES is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, If not, see
 * <http://www.gnu.org/licenses/> or write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


#ifndef DLL_ENTITY_502_H
#define DLL_ENTITY_502_H

#include <libigesconf.h>
#include <api/dll_iges_entity.h>
#include <geom/mcad_elements.h>

class MCAD_API DLL_IGES_ENTITY_502 : public DLL_IGES_ENTITY
{
public:
    DLL_IGES_ENTITY_502( IGES* aParent, bool create );
    DLL_IGES_ENTITY_502( DLL_IGES& aParent, bool create );
    virtual ~DLL_IGES_ENTITY_502();

    virtual bool NewEntity( void );

    bool GetNVertices( size_t& numVertices );

    bool GetVertices( size_t& aListSize, MCAD_POINT const*& aPointList );

    bool AddVertex( const MCAD_POINT& aPoint );
};

#endif  // DLL_ENTITY_502_H
