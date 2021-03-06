# Двуични дървета

За решаването на задачите може да ползвате и разширявате примерната имплементация на дърво от лекциите, които съм качил в тази папка.

### Зад. 1
Дадено е произволно двуично дърво от цели числа. Да се намери минималния/максималния елемент.

### Зад 2.
Дадено е произволно двуично дърво от цели числа. Да се провери дали всички елементи в дървото са четни.

### Зад 3.
Дадено е двоично дърво и последователност от символи (дума). Напишете програма, която проверява дали думата се среща в дървото, като последният символ от думата трябва да бъде листо в дървото.

Пояснение:
Ако имаме следното дърво:
```
              a
	        /   \
           c     b
         /  \     \
        f     d    e
```
и думата “acd” (без кавичките), то програмата трябва да върне true.\
Ако имаме думата “cd” (без кавичките), то програмата трябва да върне отново true.\
Ако имаме думата “ac” (без кавичките), то програмата трябва да върне false.\
Ако имаме думата “b” (без кавичките), то програмата трябва да върне false.

### Зад 4.
 Дадено е двоично дърво, вътрешните върхове на което съдържат една от следните операции: '+', '-', и '*', а листата на дървото съдържат цели числа. Операция съдържаща се в даден връх се прилага върху двата наследника на този връх. Да се пресметне стойността получена от прилагането на операциите към числата в дървото.

 ### Зад 5.
 Дадено е дърво със същата структура като от задача х. Да се изведе обратния полски запис на израза.

### Зад 6.
Дадено е произволно двуично дърво. Да се провери дали в дървото има 2 повтарящи се елемента.
Бонус: да се направи за време от порядък O(n.logn).

### Зад 7.
Дадено е произволно двуично дърво. Да се провери дали елементите на k-то ниво в дървото обрзуват палиндром.\
Note: нивото на корена на дървото е 0.

### Зад 8.
Дадено е произволно двуично дърво. Да се провери дали лявото и дясното подърво са огледални.

 ### Зад 9.
 Дадени са две двоични дървета с еднаква структура – дърво от числа и дърво от операции, представени със символите +, - и *. По-долу са дадени примери за такива дървета.
 ```
              *
	        /   \
           +     -
         /  \     
        *     *    
```
 ```
              4
	        /   \
           2     7
         /  \     
        0     7    
```
Да се намери сумата Si = Ni Opi Ti за и от 0 до n, където:
Ni e число от дървото с числа,
Opi е съответната операция от дървото с операции,
Ti е броя на елементите в поддървото на Ni.