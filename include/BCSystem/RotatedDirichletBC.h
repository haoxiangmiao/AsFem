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
//+++ Date   : 2022.11.05
//+++ Purpose: implement the rotated dirichlet boundary condition
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma once

#include "BCSystem/DirichletBCBase.h"

/**
 * This class implement the rotated dirichelt boundary condition calculation
 */
class RotatedDirichletBC:public DirichletBCBase{
public:
    RotatedDirichletBC();
    /**
     * execute the boundary condition value for different (dirichlet type) boundary conditions.
     * \f$u=u_{g}\f$ is the final output
     * @param t_calctype the calculation type for either residual or jacbobian
     * @param t_penalty the penalty for dirichlet boundary conditions
     * @param t_bcvalue the boundary value defined in the input file
     * @param t_json the boundary condition related parameters(json file content)
     * @param t_elmtinfo the basic information for current element
     * @param t_elmtsoln the element solution of current element
     * @param dofids the global id of the applied dof(start from 1, the global one)
     * @param U the system solution
     * @param K the system sparse matrix
     * @param RHS the system residual vector
     */
    virtual void computeBCValue(const FECalcType &t_calctype,const double &t_penalty,const double &t_bcvalue,const nlohmann::json &t_json,
                                const LocalElmtInfo &t_elmtinfo,
                                const LocalElmtSolution &t_elmtsoln,
                                const vector<int> &dofids,
                                Vector &U,
                                SparseMatrix &K,
                                Vector &RHS) override;

private:
    /**
     * calculate the 'displacement' value of current dofs
     * @param t_bcvalue the boundary value defined in the input file
     * @param t_json the boundary condition related parameters(json file content)
     * @param dofids the global id of the applied dof(start from 1, the global one)
     * @param t_elmtinfo the basic information for current element
     * @param t_elmtsoln the solution of current element
     * @param localU the solution vector of current node
     */
    virtual void computeU(const double &t_bcvalue,const nlohmann::json &t_json,const vector<int> &dofids,
                          const LocalElmtInfo &t_elmtinfo,
                          const LocalElmtSolution &t_elmtsoln,
                          VectorXd &localU) override; 
private:
    double m_theta0;/**< angle of current nodal point*/
    double m_theta;/**< the rotation angle*/
    const double PI=3.14159265359;/**< the PI value */
    double m_rotation_speed;/**< the rotation speed */
    double m_x0,m_y0,m_z0;/**< the coordinate of rotation center */
    double m_radius;/**< radius of center to current position */
};
