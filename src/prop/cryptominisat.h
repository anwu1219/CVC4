/*********************                                                        */
/*! \file cryptominisat.h
 ** \verbatim
 ** Top contributors (to current version):
 **   Liana Hadarean, Mathias Preiner
 ** This file is part of the CVC4 project.
 ** Copyright (c) 2009-2018 by the authors listed in the file AUTHORS
 ** in the top-level source directory) and their institutional affiliations.
 ** All rights reserved.  See the file COPYING in the top-level source
 ** directory for licensing information.\endverbatim
 **
 ** \brief SAT Solver.
 **
 ** Implementation of the cryptominisat sat solver for cvc4 (bitvectors).
 **/

#include "cvc4_private.h"

#ifndef __CVC4__PROP__CRYPTOMINISAT_H
#define __CVC4__PROP__CRYPTOMINISAT_H

#ifdef CVC4_USE_CRYPTOMINISAT

#include "prop/sat_solver.h"

// Cryptominisat has name clashes with the other Minisat implementations since
// the Minisat implementations export var_Undef, l_True, ... as macro whereas
// Cryptominisat uses static const. In order to avoid these conflicts we
// forward declare CMSat::SATSolver and include the cryptominisat header only
// in cryptominisat.cpp.
namespace CMSat {
  class SATSolver;
}

namespace CVC4 {
namespace prop {

class CryptoMinisatSolver : public SatSolver {

private:
  std::unique_ptr<CMSat::SATSolver> d_solver;
  unsigned d_numVariables;
  bool d_okay;
  SatVariable d_true;
  SatVariable d_false;
public:
  CryptoMinisatSolver(StatisticsRegistry* registry,
                      const std::string& name = "");
  ~CryptoMinisatSolver() override;

  ClauseId addClause(SatClause& clause, bool removable) override;
  ClauseId addXorClause(SatClause& clause, bool rhs, bool removable) override;

  bool nativeXor() override { return true; }

  SatVariable newVar(bool isTheoryAtom = false, bool preRegister = false, bool canErase = true) override;

  SatVariable trueVar() override;
  SatVariable falseVar() override;

  void markUnremovable(SatLiteral lit);

  void interrupt() override;
  
  SatValue solve() override;
  SatValue solve(long unsigned int&) override;
  SatValue solve(const std::vector<SatLiteral>& assumptions) override;

  bool ok() const override;
  SatValue value(SatLiteral l) override;
  SatValue modelValue(SatLiteral l) override;

  unsigned getAssertionLevel() const override;

  std::vector<SatLiteral> getTopLevelUnits() override;

  SatValue simplify() override;

  class Statistics {
  public:
    StatisticsRegistry* d_registry;
    IntStat d_statCallsToSolve;
    IntStat d_xorClausesAdded;
    IntStat d_clausesAdded;
    TimerStat d_solveTime;
    bool d_registerStats;
    Statistics(StatisticsRegistry* registry,
               const std::string& prefix);
    ~Statistics();
  };

  Statistics d_statistics;
};

}  // namespace prop
}  // namespace CVC4

#endif  // CVC4_USE_CRYPTOMINISAT
#endif  // __CVC4__PROP__CRYPTOMINISAT_H
