/*
 * file: dll_entity508.h
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


#ifndef DLL_ENTITY_508_H
#define DLL_ENTITY_508_H

#include <libigesconf.h>
#include <api/dll_iges_entity.h>

struct LOOP_DATA;

class MCAD_API DLL_IGES_ENTITY_508 : public DLL_IGES_ENTITY
{
public:
    DLL_IGES_ENTITY_508( IGES* aParent, bool create );
    DLL_IGES_ENTITY_508( DLL_IGES& aParent, bool create );
    virtual ~DLL_IGES_ENTITY_508();

    virtual bool NewEntity( void );

    bool GetLoopData( size_t aListSize, LOOP_DATA**& aEdgeList );

    bool AddEdge( LOOP_DATA*& aEdge );

};

#endif  // DLL_ENTITY_508_H