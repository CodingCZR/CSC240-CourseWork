#lang racket

;; Problem 1: Write a functio, c-> f, that will convert celcius to fahrenheit
;; F = (9/5) * c + 12
(define (c-to-f degreeCelcius)
  (+ (* (/ 9.0 5.0) degreeCelcius) 32)) ;; 9/5 to divide itself before multiplying by Celcius + 32

#|
Problem 2: Write 3 functions, discrim, quad+ and quad-. Each function will have 3 parameters
a,b, and c that represent coeffeicents of a quadratic equation:  x = (-b ± √ (b2 - 4ac) )/2a
discrim will be the part of the formula: b^2-4ac. both quad+and quad- will use the discrim function
|#

(define (discrim a b c)
  (- (* b b) - (* 4 a c)))

 ;; function for the positive quad
(define (quad+ a b c)
  (/ (+ b (sqrt (discrim a b c))) (* 2 a)))

 ;; function for the positive quad
(define (quad- a b c)
  (/ (- b (sqrt (discrim a b c))) (* 2 a)))

#|
Write a function, quadrant, with 2 parameters: x and y that represent coordinates of a point in a
Cartesian coordinate system (x, y). Determine which quadrant the point is located in and return
one of the following: I, II, III, IV, x-axis, y-axis, or origin.
|#

(define (quadrant1 x y)
  (cond ;;  setting up condition
    [(and (= x 0) (= y 0)) 'origin]        ;; Point is located the origin
    [(and (= x 0)) 'y-axis]                ;; Point is located on the y-axis
    [(and (= y 0) 'x-axis)]                ;; Point is located on the x-axis
    [(and (> x 0) (> y 0)) 'I]             ;; Point is located in Quadrant I
    [(and (< x 0) (> y 0)) 'II]            ;; Point is located in Quadrant II
    [(and (< x 0) (< y 0)) 'III]           ;; Point is locaed in Quadrant III
    [(and (> x 0) (< y 0)) 'IV]))          ;; Point is located in Quadrant IV

;; Function to compute the difference between the square of the sum and the sum of the squares
  (define sum (/ (* n (+ n 1)) 2)) ;; the sum of the first N natural numbers using the formula: N * (N + 1) / 2
  (define square-sum (* sum sum)) ;; the square of the sum
  (define sum-squares (/ (* n (+ n 1) (+ (* 2 n) 1)) 6)) ;; the sum of the squares of the first N natural numbers using the formula: N * (N + 1) * (2N + 1) / 6
  (- square-sum sum-squares)) ;; the difference between the square of the sum and the sum of the squares




       