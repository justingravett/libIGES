/*
 * file: entity502.h
 *
 * Copyright 2015, Dr. Cirilo Bernardo (cirilo.bernardo@gmail.com)
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

/*
 * Description: IGES Entity 502: Vertex List, Section 4.147, p.586+ (614+)
 */

#ifndef ENTITY_502_H
#define ENTITY_502_H

#include <libigesconf.h>
#include <core/iges_entity.h>
#include <geom/mcad_elements.h>

// NOTE:
// The associated parameter data are:
// + N: Int: number of vertices in the list
// + P(n): Real[3]: X, Y, Z of points in real space
//
// Forms:
//  1: Vertex List
//
// Unused DE items:
// + Structure
// + Line Font Pattern
// + View
// + Transformation Matrix
// + Line weight
// + Color number
//


/**
 * Class IGES_ENTITY_502
 * represents the Vertex List entity
 */
class IGES_ENTITY_502 : public IGES_ENTITY
{
protected:

    friend class IGES;
    virtual bool format( int &index );
    virtual bool rescale( double sf );

public:
    std::vector<MCAD_POINT> vertices;   //< list of vertices comprising this entity

    // public functions for libIGES only
    virtual bool associate(std::vector<IGES_ENTITY *> *entities);
    virtual bool unlink(IGES_ENTITY *aChild);
    virtual bool isOrphaned( void );
    virtual bool addReference(IGES_ENTITY *aParentEntity, bool &isDuplicate);
    virtual bool delReference(IGES_ENTITY *aParentEntity);
    virtual bool readDE(IGES_RECORD *aRecord, std::ifstream &aFile, int &aSequenceVar);
    virtual bool readPD(std::ifstream &aFile, int &aSequenceVar);

public:
    IGES_ENTITY_502( IGES* aParent );
    virtual ~IGES_ENTITY_502();

    // Inherited virtual functions
    virtual bool SetTransform( IGES_ENTITY* aTransform );
    virtual bool SetEntityForm( int aForm );
    virtual bool SetDependency( IGES_STAT_DEPENDS aDependency );
    virtual bool SetHierarchy( IGES_STAT_HIER aHierarchy );
    // parameters not supported by the specification:
    virtual bool SetLineFontPattern( IGES_LINEFONT_PATTERN aPattern );
    virtual bool SetLineFontPattern( IGES_ENTITY* aPattern );
    virtual bool SetView( IGES_ENTITY* aView );
    virtual bool SetColor( IGES_COLOR aColor );
    virtual bool SetColor( IGES_ENTITY* aColor );
    virtual bool SetLineWeightNum( int aLineWeight );

    // functions unique to E502

    /**
     * Function GetVertices
     * returns a pointer to the group of vertices comprising this Vertex List entity
     */
    const bool GetVertices( size_t& aListSize, MCAD_POINT const*& aPointList );


    /**
     * Function GetNVertices
     * returns the number of vertices comprising this Vertex List entity
     */
    size_t GetNVertices( void );


    /**
     * Function AddVertex
     * adds a Model Space vertex to this Vertex List entity
     */
    void AddVertex( MCAD_POINT aPoint );
};

#endif  // ENTITY_502_H
