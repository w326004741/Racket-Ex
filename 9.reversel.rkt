#lang racket 

; Q9. Write a function called reversel that takes a list and returns it reversed.
; rev '(1 2 3 4 5) ===> '(5 4 3 2 1)

(define (rev l)
    (if (null? l)
    null
    (append (rev (cdr l)) (list (car l))
    )))
; Test out rev with the list (1 2 3 4 5)
(define m (list 1 2 3 4 5))
(rev m)