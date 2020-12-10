# STL: map, set, unordered_map, onordered_set

Документация на структурите:
[map](https://en.cppreference.com/w/cpp/container/map),
[set](https://en.cppreference.com/w/cpp/container/set),
[unordered_map](https://en.cppreference.com/w/cpp/container/unordered_map),
[onordered_set](https://en.cppreference.com/w/cpp/container/unordered_set)

STL hash [тук](https://en.cppreference.com/w/cpp/utility/hash)\
комбинираща хеш функция [тук](https://www.boost.org/doc/libs/1_35_0/doc/html/boost/hash_combine_id241013.html)

## Зад. 1 Command Pattern

Напишете интерфейс Command с една функция string execute (string arguments, int count). После си направете Map от низове към команди. Направете програмата, която постоянно чете команди от потребителя и ги изпълнява.
Реализирайте следните команди:
* echo text
  * Принтира в конзолата текста text
* exit
  * Спира програмата

**Бонус:**
Направете командата cat, която принтира съдържание на тексов файл.

## Зад. 2 Криптиране
Напишете програма, която криптира и декриптирана файлове. Криптирането става чрез еднократно размешване(shuffling) и неговото многократно прилагане върху всеки байт. Тоест генерира се веднъж пермутация всички числа от 0 до 255 и се запазва в някакъв двупосочен Map<byte,byte>. После всеки байт от файла го заменяме с този от Map-a. По възможност направете encrypt и decrypt като команди към предната задача. 
Направете двоичен запис на самото размешване Map<byte,byte> в **друг файл**, който да се генерира при криптиране и да се използва при декриптиране.

**Бележкa:**
За криптирането използвайте [rand()](http://www.cplusplus.com/reference/cstdlib/rand/) за да генерирате произволна подредба чрез алгоритъма на [Fisher-Yates](https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle)

* encrypt source destination mapFile
  * Взима съдържанието на *source* и го записва криптирано в *destination* използвайки нов ключ, който се запазва в *mapFile*.
* decrypt source destination mapFile
  * Взима криптирано съдържание от *source* и го запазва в *destination* като го декриптирана използвайки *mapFile*.

