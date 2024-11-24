#lang racket
;basic comparison of 2 strings
(define (longer-string str1 str2)
(if (> (string-length str1) (string-length str2))
str1
str2))

;longest in a list of strings using a helper function to
(define (longest-in-list ls)
(if (null? (cdr ls))
(car ls)
(longer-string (car ls)
(longest-in-list (cdr ls)))))

;2: Explain each of the recursive calls for the list ("red" "white" "and" "blue") and how the function produces its result.
; The `longest-in-list` function finds the longest string in a list by comparing the first string (car) with the longest string found in the rest of the list(cdr). It keeps doing this until it has compared all the strings and returns the longest one.

#|
3. Find out what happens if longest-in-list is applied to an empty list.
a. Explain what happens.
b. How can this be fixed
|#

#|
The function longest-in-list will fail when applied to an empty list because it tries to compare the car 
(first element) with the cdr (rest of the list). There is no car or cdr in an empty list, as there's nothing 
to compare. We can add a base case that checks if the list is null to fix this. If the list is empty, the 
function will return an empty string (or a default value), ensuring that it handles the empty list correctly.

  How error handling may look: 
  (cond
    ((null? ls) "")  ; Return an empty string for an empty list
    ((null? (cdr lst)) (car lst)) ; Looking to find the empty car or cdr
            rest)
|#

#|
4. Write a recursive function, mult5, that will return how many numbers in the list are
 multiples of 5.
 examples:
 (mult5 ‘(60 22 13 25)) ===> 2
 (mult5 ‘(5)) ===> 1
 (mult5 ‘()) ===> 0
|#

(define (mult5 lst)
  (if (null? lst) ; setting a base case to avoid errors of 5
      0
      (if (= (remainder (car lst) 5) 0) ;if the remainder is 0, it means the car in the list is a multiple f5
          (+ 1 (mult5 (cdr lst))) ; will add 1 of mult of 5, will recursively check the rest of the list
          (mult5 (cdr lst))))) ; recursively check the rest of the list without adding 1

; 5. Write a recursive function, sumAdj, that will return the sum of all adjacent pairs in a list.
; example:
; (sumAdj '(6 2 3 4)) ===> 20 ; 8 + 5 + 7

(define (sumAdj lst)
  (cond
    [(or (null? lst) 
    (null? (cdr lst))) 0]
    [else (+ (+ (car lst) (cadr lst))
              (sumAdj (cdr lst)))]))

#|
6. Write a recursive function, getlast, that will return the last element in a list.
   If the list is empty, return the string "empty list".
|#

(define (getlast lst)
  (cond
    [(null? (cdr lst))  ;setting base case: if the cdr of the list is empty, check if the list itself is empty
     (if (null? lst) ;if the list is empty, return "empty list"
         "empty list"
         (car lst))] ;otherwise, return the last element (car lst)
    [else (getlast (cdr lst))])) ;  Recursive case: continue searching in the rest of the list(cdr lst)

#|
7. Write a recursive function, removeLast, that will remove the last element from a list of numbers.
   If the list is empty, return an empty list. Do NOT use any built-in list functions.
|#

(define (removeLast lst)
  (cond 
    [(null? (cdr lst)) '()]  ;setting base case: if the list has only one element, return an empty list
    [else (cons (car lst) ;Recursive case: construct a new list without the last element. this line also keeps the first element
                (removeLast (cdr lst)))])) ;Recursively process the rest of the list to remove the last element

#|
8. Write a recursive function, series, that will return a list of the first n values in the series.
   The series begins with a1 and has a change of delta between terms.
   For example:
   (series 2 3 5) ===> (2 5 8 11 14)
   (series 5 8 1) ===> (5)
   (series 0 10 10) ===> (0 10 20 30 40 50 60 70 80 90)
   (series -2 0 3) ===> (-2 -2 -2)
|#

(define (series a1 delta n)
  (if (= n 0) ;if n is 0, return an empty list
      '()
      (cons a1 ;add the current value to the list
            (series (+ a1 delta) delta (- n 1))))) ;recursively generate the rest of the series

#|
8. Write a recursive function, remove-large, that takes a list of numbers and returns a list
   where any value larger than the second parameter has been removed from the original list:
   For example:
   (remove-large '(1 3 5 7 9 11) 5) ===> (1 3 5)
   (remove-large '(10.5 3 8 12.7 6.2) 10) ===> (3 8 6.2)
   (remove-large '(1 3 5 7 9 11) 0) ===> ()
   (remove-large '() 0) ===> ()
|#

(define (remove-large lst threshold)
  (cond
    [(null? lst) '()] ; If the list is empty, return an empty list
    [(<= (car lst) threshold) ; If the first element is less than or equal to threshold
     (cons (car lst) ; Keep the first element
           (remove-large (cdr lst) threshold))]) ; Recursively process the rest of the list

#|
10. Write a function, sqr-each, that takes a list of numbers and returns a list where each value has been squared:
   For example:
   (sqr-each '(3 -62 41.4 17/4)) ===> (9 3844 1713.96 289/16)
   (sqr-each '(0)) ===> (0)
   (sqr-each '()) ===> ()
|#

(define (sqr-each lst)
  (define (sqr-each-helper lst result)
    (cond
      [(null? lst) result] ;done if list is empty
      [else (sqr-each-helper (cdr lst) ;process rest of the list
                             (cons (* (car lst) (car lst)) result))])) ;square and add to result
  (reverse (sqr-each-helper lst '()))) ;reverse the result to correct order

#|
11. Write a function, repeat, that takes two arguments, size and item, and returns a list
   of size elements, each of which is item:
   For example:
   (repeat 6 'foo) ===> (foo foo foo foo foo foo)
   (repeat 2 '()) ===> (() ())
   (repeat 1 15) ===> (15)
   (repeat 3 '(alpha beta)) ===> ((alpha beta) (alpha beta) (alpha beta))
   (repeat 0 'help) ===> ()
|#

(define (repeat size item) 
  (if (= size 0) ; If size is 0, return an empty list
      '() ; Return empty list
      (cons item ; Add item to the list
            (repeat (- size 1) item))))) ; Repeat with size minus 1