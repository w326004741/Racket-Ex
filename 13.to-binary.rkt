#lang racket
; Write a procedure to-binary that takes a decimal interger and converts it into 
; a list of 0’s and 1’s representing the number in binary form. 
; The least significant bit should be on the right of the list.

; > (to-binary 9)
; '(1 0 0 1)
; > (to-binary 23)
; '(1 0 1 1 1)

; 19 = (1 x 10^1) + (9 x 10^0)
; 10011 = (1 x 2^4) + (0 x 2^3) + (0 x 2^2) + (1 x 2^1) + (1 x 2^0)

(define (to-binary n)
    (if (= n 0)
    null
    (cons (modulo n 2) (to-binary (/ (- n (modulo  n 2)) 2)))
    ))
(to-binary 19) ; => '(1 1 0 0 1) = (1 x 2^0) + (1 x 2^1) + (1 x 2^4)
               ;                 = 1 + 2 + 16 =19
(to-binary 9)
(to-binary 23)
;设 a = (modulo n 2) => n modulo 2(n 对 2 取余) => remainder(取余) = 0 or 1 = binary
; if a = 0; then n - 0 = n;     n/2     
; if a = 1; then n - 1 = n -1; (n-1)/2
; if n = 19 => a = 1 => (- n (modulo n 2)) = 19 - 1 = 18 => 18/2 = 9 = to-binary