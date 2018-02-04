#lang racket

; Q14 Write a function select that takes two elements, 
; a list and a position in the list, and return the element of the list in that position
; (select (list 1 2 3 4 5) 1)  ===> 2
;         (     0 1 2 3 4) ===> position

(define (select l i)  ; l should be list, i should be number
    (if (= i 0)
    (car l)  ; this is true, if i = 0, and then = (car l) = 1
    (select (cdr l) (- i 1)))) ; this is false
    ; set select function, have two element, first is list, second is i
    
(select (list 1 2 3 4 5) 1)