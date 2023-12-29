//****************************************************************
//* This file is part of the AsFem framework
//* Advanced Simulation kit based on Finite Element Method (AsFem)
//* All rights reserved, Yang Bai/MM-Lab@CopyRight 2020-present
//* https://github.com/MatMechLab/AsFem
//* Licensed under GNU GPLv3, please see LICENSE for details
//* https://www.gnu.org/licenses/gpl-3.0.en.html
//****************************************************************
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ Author : Yang Bai
//+++ Date   : 2022.08.10
//+++ Purpose: Implement the circle IC, the given dofs will be
//+++          assigned with two values(in and out circle)
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma once

#include "ICSystem/InitialConditionBase.h"

class CircleIC:public InitialConditionBase{
protected:
    /**
     * compute the initial condition value for each dof (of each node)
     * @param t_params parameters read from json input file
     * @param icvalue the initial condition value
     * @param dim the dimensions of current mesh
     * @param dofs the dofs number of current IC
     * @param nodecoords the current node's coordinates
     * @param localU the initial condition values of current IC
     */
    virtual void computeInitialValue(const nlohmann::json &t_params,
                                     const double &icvalue,
                                     const int &dim,
                                     const int &dofs,
                                     const Vector3d &nodecoords,
                                     VectorXd &localU) override;

private:
    double x0,y0,r,dist;/**< the position of center point and the radius */
    double innerval,outval;/**< for the inner and outside value */
    double value;/** value of current nodal point */

};