/*
 * file: dll_entity504.cpp
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

#include <api/dll_entity504.h>
#include <api/dll_iges.h>
#include <core/iges.h>
#include <core/entity504.h>


DLL_IGES_ENTITY_504::DLL_IGES_ENTITY_504( IGES* aParent, bool create ) : DLL_IGES_ENTITY( aParent )
{
    m_type = ENT_EDGE;

    if( create )
    {
        if( NULL != aParent )
            aParent->NewEntity( ENT_EDGE, &m_entity );
        else
            m_entity = new IGES_ENTITY_504( NULL );

        if( NULL != m_entity )
            m_entity->AttachValidFlag( &m_valid );
    }

    return;
}


DLL_IGES_ENTITY_504::DLL_IGES_ENTITY_504( DLL_IGES& aParent, bool create ) : DLL_IGES_ENTITY( aParent )
{
    m_type = ENT_EDGE;
    IGES* ip = aParent.GetRawPtr();

    if( !create || NULL == ip )
        return;

    ip->NewEntity( ENT_EDGE, &m_entity );

    if( NULL != m_entity )
        m_entity->AttachValidFlag( &m_valid );

    return;
}


DLL_IGES_ENTITY_504::~DLL_IGES_ENTITY_504()
{
    return;
}


bool DLL_IGES_ENTITY_504::NewEntity( void )
{
    if( m_valid && NULL != m_entity )
    {
        m_entity->DetachValidFlag( &m_valid );
        m_entity = NULL;
    }

    if( NULL != m_parent && m_hasParent )
        m_parent->NewEntity( ENT_EDGE, &m_entity );
    else
        m_entity = new IGES_ENTITY_504( NULL );

    if( NULL != m_entity )
    {
        m_entity->AttachValidFlag(&m_valid);
        return true;
    }

    return false;
}

bool DLL_IGES_ENTITY_504::GetEdges( size_t aListSize, EDGE_DATA const*& aEdgeList )
{
    if ( !m_valid || NULL == m_entity )
        return false;

    return ( (IGES_ENTITY_504*)m_entity )->GetEdges( aListSize, aEdgeList );
}

bool DLL_IGES_ENTITY_504::AddEdge( IGES_ENTITY* aCurve, IGES_ENTITY_502* aSVP, int aSV,
                                   IGES_ENTITY_502* aTVP, int aTV )
{
    if ( !m_valid || NULL == m_entity )
        return false;

    return ( (IGES_ENTITY_504*)m_entity )->AddEdge( aCurve, aSVP, aSV, aTVP, aTV );
}
