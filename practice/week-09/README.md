# Задачи за двуични дървета

### Зад 1.
Дадено е представяне на дърво във вид на масив, където:\
коерена е на позиция 0,\
наследниците на елемент `i` от масива са на позиции `2*i+1` и `2*i+2`\
Да се построи дървото от подадент такъв масив.\
За целите на задачата ще допуснем, че масива се състои от цели неотрицателни числа а елементите които трябва да пропускаме ще имат стойост `-1`.

### Зад 2.
От дадено двуично дърво да се построи масив като в предходната задача.

### Зад 3.
Дадено е произволно двуично дърво. Да се провери дали елементите на k-то ниво в дървото обрзуват палиндром.\
Note: нивото на корена на дървото е 0.

### Зад 4.
Дадено е произволно двуично дърво. Да се провери дали лявото и дясното подърво са огледални.

 ### Зад 5.
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
Да се намери сумата `Si = Ni Opi Ti` за и от 0 до n, където:\
`Ni` e число от дървото с числа,\
`Opi` е съответната операция от дървото с операции,\
`Ti` е броя на елементите в поддървото на `Ni`.