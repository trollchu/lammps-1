/* ----------------------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   http://lammps.sandia.gov, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under 
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */
#ifdef FIX_CLASS

FixStyle(wall/piston,FixWallPiston)

#else

#ifndef LMP_FIX_WALL_PISTON_H
#define LMP_FIX_WALL_PISTON_H

#include "fix.h"

namespace LAMMPS_NS {

class FixWallPiston : public Fix {
 public:
  FixWallPiston(class LAMMPS *, int, char **);
  int setmask();
  void post_integrate();
  void initial_integrate(int);

 private:
  int xloflag,xhiflag,yloflag,yhiflag,zloflag,zhiflag;
  int scaleflag, roughflag, rampflag, rampNL1flag, rampNL2flag, rampNL3flag, rampNL4flag, rampNL5flag;
  double roughdist,roughoff,x0,y0,z0,vx,vy,vz,maxvx,maxvy,maxvz,paccelx,paccely,paccelz, angfreq;
  int tempflag, tseed;
  double t_target, t_period, t_extent;
  class RanMars *randomt;
  double *gfactor1,*gfactor2;
};

}

#endif
#endif
