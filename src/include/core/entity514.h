/*
 * file: entity514.h
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
 * Description: IGES Entity 514: Shell, Section 4.151, p.595+ (623+)
 */

#ifndef ENTITY_514_H
#define ENTITY_514_H

#include <libigesconf.h>
#include <core/iges_entity.h>

// NOTE:
// The associated parameter data are:
// + N: Int: number of edge tuples
// + CURV(n): Int: DE to curve entity (100, 102, 104, 106/(11,12,63), 110, 112, 126, 130)
// + SVP(n): Int: DE of Vertex Entity (E502-1) for start vertex
// + SV(n): Int: List Index of Vertex in SVP(n) for start vertex
// + TVP(n): Int: DE of Vertex Entity (E502-1) for terminate vertex
// + TV(n): Int: List Index of Vertex in TVP(n) for terminate vertex
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

class IGES_ENTITY_510;


/**
 * Class IGES_ENTITY_514
 * represents the Shell Entity
 */
class IGES_ENTITY_514 : public IGES_ENTITY
{
protected:

    friend class IGES;
    virtual bool format( int &index );
    virtual bool rescale( double sf );

    std::list< std::pair<int, bool> > ifaces;                   //< DE and OFlag for faces
    std::vector< std::pair<IGES_ENTITY_510*, bool> > mfaces;    //< faces of the shell


public:

    // public functions for libIGES only
    virtual bool associate(std::vector<IGES_ENTITY *> *entities);
    virtual bool unlink(IGES_ENTITY *aChild);
    virtual bool isOrphaned( void );
    virtual bool addReference(IGES_ENTITY *aParentEntity, bool &isDuplicate);
    virtual bool delReference(IGES_ENTITY *aParentEntity);
    virtual bool readDE(IGES_RECORD *aRecord, std::ifstream &aFile, int &aSequenceVar);
    virtual bool readPD(std::ifstream &aFile, int &aSequenceVar);

public:
    IGES_ENTITY_514( IGES* aParent );
    virtual ~IGES_ENTITY_514();

    // Inherited virtual functions
    virtual bool SetTransform( IGES_ENTITY* aTransform );
    virtual bool SetEntityForm( int aForm );
    // parameters not supported by the specification:
    virtual bool SetLineFontPattern( IGES_LINEFONT_PATTERN aPattern );
    virtual bool SetLineFontPattern( IGES_ENTITY* aPattern );
    virtual bool SetView( IGES_ENTITY* aView );
    virtual bool SetColor( IGES_COLOR aColor );
    virtual bool SetColor( IGES_ENTITY* aColor );
    virtual bool SetLineWeightNum( int aLineWeight );

    // functions unique to E514

    bool AddFace( IGES_ENTITY_510* aFace, bool oFlag );

    bool GetFaces( size_t& aListSize, std::pair<IGES_ENTITY_510*, bool>* aFaceList );

    /**
     * Function GetNFaces
     * returns the number of faces in mfaces
     */
    size_t GetNFaces( void );
};

#endif  // ENTITY_514_H
