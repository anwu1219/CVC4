; COMMAND-LINE: --incremental
; EXPECT: unsat
; EXPECT: sat

; x not in A U B => x not in A
(set-logic ALL_SUPPORTED)
(define-sort SetInt () (Set Int))
(declare-fun A () (Set Int))
(declare-fun B () (Set Int))
(declare-fun x () Int)
(assert (member x A))
(push 1)
(assert (not (member x (union A B))))
(check-sat)
(pop 1)
(check-sat)
