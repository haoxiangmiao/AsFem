//****************************************************************
//* This file is part of the AsFem framework
//* A Simple Finite Element Method program (AsFem)
//* All rights reserved, Yang Bai @ CopyRight 2020
//* https://github.com/yangbai90/AsFem.git
//* Licensed under GNU GPLv3, please see LICENSE for details
//* https://www.gnu.org/licenses/gpl-3.0.en.html
//****************************************************************
//*** Author: Yang Bai
//*** Purpose: define the base class for both the bulk(include bc)
//***          and the interface mesh
//****************************************************************

#ifndef ASFEM_MESHBASE_H
#define ASFEM_MESHBASE_H

class MeshBase
{
public:
    MeshBase();
public:
    //*****************************************************
    //*** for mesh creation
    //*****************************************************
    virtual void CreateMesh();
public:
    //*****************************************************
    //*** for basic get function
    //*****************************************************
    virtual int GetElmtsNum()const;
    virtual int GetNodesNum()const;
};

#endif


