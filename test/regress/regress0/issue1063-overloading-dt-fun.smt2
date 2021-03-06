; COMMAND-LINE: --lang=smt2.5
; EXPECT: sat
(set-logic ALL)
(set-info :status sat)
(declare-datatypes () ((Enum (cons (val Int)) (On_Ground) (None))))
(declare-fun cons (Int Int) Int)
(declare-fun cons (Enum) Bool)
(declare-fun cons (Bool) Int)
(assert (cons (cons 0)))
(assert (= (cons (cons true) (cons false)) 4))
(check-sat)
