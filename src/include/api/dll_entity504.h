/*
 * file: dll_entity504.h
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


#ifndef DLL_ENTITY_504_H
#define DLL_ENTITY_504_H

#include <libigesconf.h>
#include <api/dll_iges_entity.h>

class IGES_ENTITY_502;

class MCAD_API DLL_IGES_ENTITY_504 : public DLL_IGES_ENTITY
{
public:
    DLL_IGES_ENTITY_504( IGES* aParent, bool create );
    DLL_IGES_ENTITY_504( DLL_IGES& aParent, bool create );
    virtual ~DLL_IGES_ENTITY_504();

    virtual bool NewEntity( void );

    bool GetEdges( size_t aListSize, EDGE_DATA const*& aEdgeList );

    bool AddEdge( IGES_ENTITY* aCurve, IGES_ENTITY_502* aSVP, int aSV,
                  IGES_ENTITY_502* aTVP, int aTV );
};

#endif  // DLL_ENTITY_504_H
