/*
 * file: dll_entity510.cpp
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

#include <api/dll_entity510.h>
#include <api/dll_iges.h>
#include <core/iges.h>
#include <core/entity510.h>


DLL_IGES_ENTITY_510::DLL_IGES_ENTITY_510( IGES* aParent, bool create ) : DLL_IGES_ENTITY( aParent )
{
    m_type = ENT_FACE;

    if( create )
    {
        if( NULL != aParent )
            aParent->NewEntity( ENT_FACE, &m_entity );
        else
            m_entity = new IGES_ENTITY_510( NULL );

        if( NULL != m_entity )
            m_entity->AttachValidFlag( &m_valid );
    }

    return;
}


DLL_IGES_ENTITY_510::DLL_IGES_ENTITY_510( DLL_IGES& aParent, bool create ) : DLL_IGES_ENTITY( aParent )
{
    m_type = ENT_FACE;
    IGES* ip = aParent.GetRawPtr();

    if( !create || NULL == ip )
        return;

    ip->NewEntity( ENT_FACE, &m_entity );

    if( NULL != m_entity )
        m_entity->AttachValidFlag( &m_valid );

    return;
}


DLL_IGES_ENTITY_510::~DLL_IGES_ENTITY_510()
{
    return;
}


bool DLL_IGES_ENTITY_510::NewEntity( void )
{
    if( m_valid && NULL != m_entity )
    {
        m_entity->DetachValidFlag( &m_valid );
        m_entity = NULL;
    }

    if( NULL != m_parent && m_hasParent )
        m_parent->NewEntity( ENT_FACE, &m_entity );
    else
        m_entity = new IGES_ENTITY_510( NULL );

    if( NULL != m_entity )
    {
        m_entity->AttachValidFlag(&m_valid);
        return true;
    }

    return false;
}

bool DLL_IGES_ENTITY_510::GetBounds( size_t& aListSize, IGES_ENTITY_508**& aBoundsList )
{
    if ( !m_valid || NULL == m_entity )
        return false;

    return ( (IGES_ENTITY_510*)m_entity )->GetBounds( aListSize, aBoundsList );
}

bool DLL_IGES_ENTITY_510::AddBound( IGES_ENTITY_508* aLoop )
{
    if ( !m_valid || NULL == m_entity )
        return false;

    return ( (IGES_ENTITY_510*)m_entity )->AddBound( aLoop );
}

bool DLL_IGES_ENTITY_510::SetSurface( IGES_ENTITY* aSurface )
{
    if ( !m_valid || NULL == m_entity )
        return false;

    return ( (IGES_ENTITY_510*)m_entity )->SetSurface( aSurface );
}

bool DLL_IGES_ENTITY_510::GetSurface( IGES_ENTITY const*& aSurface )
{
    if ( !m_valid || NULL == m_entity )
        return false;

    aSurface = ( (IGES_ENTITY_510*)m_entity )->GetSurface();
    return true;
}

bool DLL_IGES_ENTITY_510::SetOuterLoopFlag( bool aFlag )
{
    if ( !m_valid || NULL == m_entity )
        return false;

    ( (IGES_ENTITY_510*)m_entity )->SetOuterLoopFlag( aFlag );
    return true;
}

bool DLL_IGES_ENTITY_510::GetOuterLoopFlag( bool& aFlag )
{
    if ( !m_valid || NULL == m_entity )
        return false;

    aFlag = ( (IGES_ENTITY_510*)m_entity )->GetOuterLoopFlag();
    return true;
}