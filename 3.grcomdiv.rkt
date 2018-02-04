#lang racket

; Q3. Define a function grcomdiv that takes two integers and returns
; their greatest common divisor.
; ref: https://stackoverflow.com/questions/17261441/scheme-my-gcd-always-returns-zero
(define (grcomdiv a b)
  (cond [(= b 0) a]
        [else (grcomdiv b (modulo a b))]))
;modulo 取余
(grcomdiv 10 15)
(grcomdiv 64 30)