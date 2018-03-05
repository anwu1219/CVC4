; COMMAND-LINE: --rewrite-divk --no-check-proofs --no-check-unsat-cores
; EXPECT: sat
(set-logic ALL_SUPPORTED)
(set-info :status sat)
(declare-fun t () Int)
(assert (> t 0))
(assert (not (= t (bv2nat ((_ int2bv 16) t)))))
(check-sat)