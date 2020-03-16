/*
 * file: dll_entity502.cpp
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

#include <api/dll_entity502.h>
#include <api/dll_iges.h>
#include <core/iges.h>
#include <core/entity502.h>


DLL_IGES_ENTITY_502::DLL_IGES_ENTITY_502( IGES* aParent, bool create ) : DLL_IGES_ENTITY( aParent )
{
    m_type = ENT_VERTEX;

    if( create )
    {
        if( NULL != aParent )
            aParent->NewEntity( ENT_VERTEX, &m_entity );
        else
            m_entity = new IGES_ENTITY_502( NULL );

        if( NULL != m_entity )
            m_entity->AttachValidFlag( &m_valid );
    }

    return;
}


DLL_IGES_ENTITY_502::DLL_IGES_ENTITY_502( DLL_IGES& aParent, bool create ) : DLL_IGES_ENTITY( aParent )
{
    m_type = ENT_VERTEX;
    IGES* ip = aParent.GetRawPtr();

    if( !create || NULL == ip )
        return;

    ip->NewEntity( ENT_VERTEX, &m_entity );

    if( NULL != m_entity )
        m_entity->AttachValidFlag( &m_valid );

    return;
}


DLL_IGES_ENTITY_502::~DLL_IGES_ENTITY_502()
{
    return;
}


bool DLL_IGES_ENTITY_502::NewEntity( void )
{
    if( m_valid && NULL != m_entity )
    {
        m_entity->DetachValidFlag( &m_valid );
        m_entity = NULL;
    }

    if( NULL != m_parent && m_hasParent )
        m_parent->NewEntity( ENT_VERTEX, &m_entity );
    else
        m_entity = new IGES_ENTITY_502( NULL );

    if( NULL != m_entity )
    {
        m_entity->AttachValidFlag(&m_valid);
        return true;
    }

    return false;
}

bool DLL_IGES_ENTITY_502::GetVertices( size_t& aListSize, MCAD_POINT const*& aPointList )
{
    if( !m_valid || NULL == m_entity )
        return false;

    ((IGES_ENTITY_502*)m_entity)->GetVertices( aListSize, aPointList );
    return true;
}

bool DLL_IGES_ENTITY_502::GetNVertices( size_t& numVertices )
{
    if( !m_valid || NULL == m_entity )
        return false;

    numVertices = ((IGES_ENTITY_502*)m_entity)->GetNVertices();
    return true;
}

bool DLL_IGES_ENTITY_502::AddVertex( const MCAD_POINT& aPoint )
{
    if( !m_valid || NULL == m_entity )
        return false;
    
    ((IGES_ENTITY_502*)m_entity)->AddVertex( aPoint );
    return true;
}