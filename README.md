### Лабораторная работа №4 по дисциплине: «Алгоритмы и структуры данных»
Изучение методов построения таблиц с постоянным временем доступа к элементам. Освоение технологии реализации таблиц на примере АТД «Хеш-таблица».
#### Вариант
Тип ключа k – строка текста произвольной длины (символы – заглавные буквы латинского алфавита).
- Преобразование k’ методом конкатенации битовых образов символов.
- Метод хеширования – мультипликативный.
- Метод разрешения коллизий – квадратичный.
#### Задание
Спроектировать, реализовать и провести тестовые испытания АТД «Хеш-таблица» для коллекции, содержащей данные произвольного типа. Тип ключей и данных задаётся клиентской программой. Хеш-таблица может быть представлена в одной из двух форм:
- хеш-таблица с цепочками коллизий,
- хеш-таблица с открытой адресацией. Интерфейс АТД «Хеш-таблица» включает следующие операции:
- опрос размера таблицы,
- опрос количества элементов в таблице,
- опрос пустоты таблицы,
- очистка таблицы,
- поиск элемента по ключу k,
- вставка элемента по ключу k,
- удаление элемента по ключу k,
- задание формы представления – хеш-таблица с цепочками коллизий,
- задание формы представления – хеш-таблица с открытой адресацией,
- опрос формы представления,
- запрос прямого итератора begin(),
- запрос «неустановленного» прямого итератора end(),
прямой итератор для доступа к значениям в хеш-таблице с основными операциями:
- доступ по чтению и записи к значению текущего элемента,
- переход к следующему элементу в хеш-таблице,
- проверка равенства итераторов ==,
- проверка неравенства итераторов !=. 