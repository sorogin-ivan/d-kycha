﻿# Реализация приоритетной очереди на основе d-кучи, упорядоченной таблицы и бинарного дерева и её применение для построения остовного дерева графа с помощью алгоритма Краскала

## Содержание

* [Постановка задачи](#Постановка-задачи)
* [Руководство пользователя](#Руководство-пользователя)
	* [Использование реализации пирамидальной сортировки](#Использование-реализации-пирамидальной-сортировки)
	* [Использование реализации алгоритма Дейкстры](#Использование-реализации-алгоритма-Дейкстры)
	* [Использование реализации алгоритма Крускала](#Использование-реализации-алгоритма-Крускала)
* [Руководство программиста](#Руководство-программиста)
	* [Используемые технологии](#Используемые-технологии)
	* [Общая структура репозитория](#Общая-структура-репозитория)
	* [Описание структуры решения](#Описание-структуры-решения)
	* [Описание структур данных](#Описание-структур-данных)
		* [D-куча](#d-куча)
		* [Бинарное дерево](#Бинарное-дерево)
			* [Бинарное поисковое дерево](#Бинарное-поисковое-дерево)
		* [Таблицы](#Таблицы)
			* [Просматриваемые таблицы](#Просматриваемые-таблицы)
			* [Упорядоченные таблицы](#Упорядоченные-таблицы)
		* [Приоритетные очереди](#Приоритетные-очереди)
		* [Графы](#Графы)
		* [Разделенные множества](#Разделенные-множества)
	* [Описание алгоритмов](#Описание-алгоритмов)
		* [Пирамидальная сортировка](#Пирамидальная-сортировка)
		* [Алгоритм Дейкстры](#Алгоритм-Дейкстры)
		* [Алгоритм Крускала](#Алгоритм-Крускала)
	* [Программная реализация структур данных](#Программная-реализация-структур-данных)
		* [Схема наследования классов](#Схема-наследования-классов) 
		* [Программная реализация d-кучи](#Программная-реализация-d-кучи)
		* [Программная реализация бинарного поискового дерева](#Программная-реализация-бинарного-поискового-дерева)
		* [Программная реализация просматриваемых таблиц](#Программная-реализация-просматриваемых-таблиц)
		* [Программная реализация упорядоченных таблиц](#Программная-реализация-упорядоченных-таблиц)
		* [Программная реализация приоритетных очередей](#Программная-реализация-приоритетных-очередей)
		* [Программная реализация разделенных множеств](#Программная-реализация-разделенных-множеств)
		* [Программная реализация графа](#Программная-реализация-графа)
* [Заключение](#Заключение)
* [Литература](#Литература)


##Постановка задачи

1. Разработать статические библиотеки, реализующие следующие структуры данных:
	- D-кучу;
	- Бинарное поисковое дерево;
	- Графы;
	- Разделенные множества;
	- Таблицу;
	- Просматриваемую таблицу;
	- Упорядоченную таблицу;
	- Приоритетные очереди, реализованные на основе D-кучи, бинарном дереве и упорядоченной таблице.
2. Написать тестирующую программу для каждого метода каждой структуры данных с помощью Google C++ Testing Framework.
3. Написать приложение для демонстрации работы d-кучи (пирамидальная сортировка).
4. Написать приложение для демонстрации работы приоритетной очереди, основанной на d-куче (алгоритм Дейкстры):
	- входные данные - связный неориентированный взвешенный граф без петель со стартовой вершиной;
	- выходные данные:
	    - список вершин;
	    - список кратчайших путей до каждой вершины графа;
	    - список предшествующий вершин.
5. Написать приложение для демонстрации работы приоритетных очередей (на базе D-кучи, бинарного поискового дерева и упорядоченной таблицы) и разделенных множеств (алгоритм Крускала):
	* входные данные - связный неориентированный взвешенный граф без петель;
	* выходные данные - граф, представляющий минимальное остовное дерево для исходного графа.

##Руководство пользователя

###Использование реализации пирамидальной сортировки

####Запуск приложения и ввод данных

Программа предназначена для сортировки D-кучи.
Для запуска приложения нужно открыть исполняемый файл `sample_sort.exe`.
Программа запросит арность кучи, затем количество элементов. Программа автоматически заполнит дерево, с учетом ваших данных, и на экран выведется сначала исходная куча, затем отсортированная.

####Пример:

Вводим необходимые данные:

![1](/kartinki/1.png)

После ввода, на ваш экран будет выведен результат сортировки:

![2](/kartinki/2.png)


###Использование реализации алгоритма Дейкстры

####Запуск приложения и ввод данных

Программа предназначена для поиска кратчийших путей во взвешенном неориентированном графе от любой вершины до всех остальных вершин графа.
Для запуска приложения нужно открыть исполняемый файл `sample_deykstra.exe`.
Программа попросит ввести количество вершин графа и количество ребер. Затем необходимо ввести минимальное и максимальное значения весов ребер. Также будет запрошен номер стартовой вершины. Результатом будет вывод номеров всех вершин, кратчайших путей от стартовой вершины и номеров предшествующих вершин.

####Пример:

1) Вводим количество вершин графа

![3](/kartinki/3.png)

2) Теперь количество ребер графа

![4](/kartinki/4.png)

3) Ну и минимальное и максимальное значения весов рёбер графа

![5](/kartinki/5.png)

4) Граф готов. Теперь необходимо выбрать стартовую вершину

![6](/kartinki/6.png)

Программа выведет результат алгоритма

![7](/kartinki/7.png)


###Использование реализации алгоритма Крускала

####Запуск приложения и ввод данных

Программа предназначена для построения минимального остовного дерева для взвешенного неориентированного графа. 
Для запуска приложения нужно открыть исполняемый файл `sample_kruskal.exe`.
Программа потребует ввести тип данных, с помощью которого будет использоваться приоритетная очередь и количество вершин графа. Затем запросит каким образом заполнять граф. Результатом работы программы будет вывод списка ребер, составляющих минимальное остовное дерево.

####Пример

1) Вводим тип данных для приоритетной очереди

![8](/kartinki/8.png)

2) Теперь вводим количество вершин графа и количество рёбер

![9](/kartinki/9.png)

3) Введём способ заполнения графа. В данном случае выбрано ручное заполнение графа. Введем рёбра и их веса

![10](/kartinki/10.png)

Если выбрать автоматическое заполнение графа, программа запросит минимальное и максимальное значение графа.
Для ввода графа из файла, надо создать файл "file.txt" с необходимыми данными и поместить его в корне диска C.

4) Программа завершила работу и вывела результат на экран

![11](/kartinki/11.png)


##Руководство программиста

###Используемые технологии

В ходе выполнения работы использованы следующие технологии:
- Среда разработки Microsoft Visual Studio 2012.
- Фреймворк для написания автоматических тестов Google Test.
- Система контроля версий Git.

###Общая структура репозитория

Репозиторий содержит следующие директории и файлы:

* [`gtest`](https://github.com/AleksandrLykov/d-kycha/tree/master/gtest) - библиотека GoogleTest.
* [`include`](https://github.com/AleksandrLykov/d-kycha/tree/master/include) - директория для размещения заголовочных файлов и реализаций структур данных.
* [`sample`](https://github.com/AleksandrLykov/d-kycha/tree/master/samples) - директория для размещения исходных кодов приложений.
* [`test`](https://github.com/AleksandrLykov/d-kycha/tree/master/test) - директория для размещения тестов.
* [`sln`](https://github.com/AleksandrLykov/d-kycha/tree/master/sln) - директория с файлими решений (на данный момент Visual Studio 2012).
* [`kartinki`](https://github.com/AleksandrLykov/d-kycha/tree/master/kartinki) - директория с картинками для отчета;
* [`src`](https://github.com/AleksandrLykov/d-kycha/tree/master/src) - директория для размещения реализаций алгоритмов.

###Описание структуры решения

Решение состоит из 12 проектов:

* `algoritms` - статическая библиотека, содержащая объявление и реализацию алгоритмов для примеров.
* `bintree` - статическая библиотка, содержащая объявление и реализацию шаблонного класса `bintree`.
* `d_heap` - статическая библиотека, содержащая объявление и реализацию шаблонного класса `DHeap`.
* `graph` - статическая библиотека, содержащая объявление и реализацию шаблонного классов `graph`.
* `gtest` - фреймворк Google Test.
* `priority_queue` - статическая библиотека, содержащая объявление и реализацию приоритетных очередей, основанных на разных структурах данных.
* `sample_deykstra` - консольное приложение для демонстрации работы алгоритма Дейкстры.
* `sample_kruskal` - консольное приложение для демонстрации работы алгоритма Крускала.
* `sample_sort` - консольное приложение для демонстрации работы пирамидальной сортировки.
* `sets` - статическая библиотека, содержащая объявление и реализацию шаблонного класса `sets`.
* `table` - статическая библиотека, содержащая объявление и реализацию шаблонных классов `Table`, `ScanTable`, `SortTable`.
* `tests` - консольное приложение для проверки правильности реализации классов `bintree`, `DHeap`, `graph`, `BQueue`, `HQueue`, `TQueue`, `sets`, `ScanTable`, `SortTable`.


###Описание структур данных

####D-куча
D-куча - завершенное d-арное дерево, содержащее набор однотипных элементов, со следующими свойствами:
- каждый узел, не являющийся листом, за исключением, быть может, одного имеет ровно d потомков. Один узел, являющийся исключением, может иметь от 1 до d-1 потомка;
- если h - глубина дерева, то для любого i = 1, ..., k-1 такое дерево имеет ровно d^i узлов глубины i;
- количество узлов глубины k в дереве глубины k может варьироваться от 1 до d^k;
- каждый узел имеет вес. Иначе говоря, каждому узлу дерева присвоен ключ такого типа данных, на котором определен порядок сравнения;
- ключ элемента, приписанного узлу i, не превосходит ключа любого из своих потомков.

######Основные операции
* Транспонирование `trans` (трудоемкость = O(1)):
```
ТРАНСПОНИРОВАНИЕ(i, j)
{
	tmp = key[i];
	key[i] = key[j];
	key[j] = tmp;
}
```
* Индекс минимального ребенка `minchild` (трудоемкость = O(1)):
```
MINCHILD(i)
{
	minCh = a*d+1;
	if (a*d+d < kolvo - 1)
		maxCh = a*d + d;
	else maxCh = kolvo - 1;

    for (int i = minCh; i <= maxCh; i++)
    {
        if (keys[i] < keys[minCh]) 
        {
            minCh = i;
        }
    }
}
```
* Всплытие `vsplyt` (трудоемкость = log(n)):
```
ВСПЛЫТИЕ(i)
{
	p = (i - 1) / d;
	while (i != 0 && key[p] > key[i])
	{	
		ТРАНСПОНИРОВАНИЕ(i, p);
		i = p;
		p = (i - 1) / d;
	}
}
```
* Погружение `pogryzh` (трудоемкость = О(d*log(n)):
```
ПОГРУЖЕНИЕ(i)
{
	с = minchild(i); 
	while (i != 0 && key[c] < key[i]){
		ТРАНСПОНИРОВАНИЕ(i, c);
		i = c;
		c = minchild(c);
	}
}
```
* Вставка элемента `push` (трудоемкость = О(log(n)):
```
ВСТАВКА(x)
{
	key[size] = x;
	ВСПЛЫТИЕ(size);
	size++;
}
```
* Удаление элемента c минимальным ключом `delet` (трудоемкость = О(log(n)):
```
УДАЛЕНИЕ_С_МИНИМАЛЬНЫМ_КЛЮЧОМ()
{
	key[0] = key[size - 1];
	size--;
	ПОГРУЖЕНИЕ(0);
}
```
* Удаление элемента с заданным ключом `deletzadan` (трудоемкость = О(log(n)):
```
УДАЛЕНИЕ(i)
{
	key[i] = key[size - 1];
	size--;
	ПОГРУЖЕНИЕ(i);
}
```
* Окучивание `okych` (трудоемкость = О(log(n)):
```
ОКУЧИВАНИЕ()
{
	for(int i = size - 1; i >= 0; i--)
	ПОГРУЖЕНИЕ(i);
}
```

####Бинарное дерево

#####Бинарное поисковое дерево
Бинарное поисковое дерево - это двоичное дерево, обладающее следующими свойствами:
* каждый узел имеет не больше двух потомков;
* любое поддерево является бинарным поисковым деревом;
* значение ключа любого узла левого поддерева меньше значения ключа корневого узла;
* значение ключа любого узла правого поддерева больше значения ключа корневого узла.
 
######Основные операции
* Вставка элемента `insert` (трудоемкость = log(n)):
```
ВСТАВКА(Node)
{
	y = 0;
	x = root;
	while(x != 0)
	{
		y = x;
		if (node->key < x->key) x = x->left;
		else x = x->right;
	}
	node->parent = y;
	if (y == 0) 
		root = node;
	else if (node->key < y->key) 
		y->left = node;
	else y->right = node;
}
```
* Удаление элемента `Delete` (трудоемкость = log(n)):
```
УДАЛЕНИЕ(key)
{
	node = МИНИМУМ();
	if (node->parent == 0) 
	{
		if (node->right_ == 0)
		{
			root = 0;
			delete node;
		}
		root = node->right;
		root->parent = 0;
		node->right = 0;
		delete node;
	}
	node->parent->left = node->right;
	node->right = node->parent = NULL;
	delete node;
}
```
* Поиск элемента `FindKey` (трудоемкость = n):
```
ПОИСК(key)
{
	node = root;
	while(node != 0 && node->key != key)
	{
		if (node->key > key) 
			node = node->left;
		else 
			node = node->right;
	}
	return node;
}
```
* Обход в прямом порядке `workAroundForward`:
```
ОБХОД_В_ПРЯМОМ_ПОРЯДКЕ(Node *tr)
{
	cout << key;
	ОБХОД_В_ПРЯМОМ_ПОРЯДКЕ(tr->left);
	ОБХОД_В_ПРЯМОМ_ПОРЯДКЕ(tr->right);
}
```
* Обход в обратном порядке `workAroundReverse`:
```
ОБХОД_В_ОБРАТНОМ_ПОРЯДКЕ(Node *tr)
{
	ОБХОД_В_ОБРАТНОМ_ПОРЯДКЕ(tr->left);
	ОБХОД_В_ОБРАТНОМ_ПОРЯДКЕ(tr->right);
	cout << key;
}
```
* Симметричный обход `workAroundSymmetr`:
```
СИММЕТРИЧНЫЙ_ОБХОД(Node *tr)
{
    	СИММЕТРИЧНЫЙ_ОБХОД(tr->left);
	cout << key;
	СИММЕТРИЧНЫЙ_ОБХОД(tr->right);
}
```
* Обход в ширину `workAroundAcross`:
```
ОБХОД_В_ШИРИНУ()
{
	queue <Node*> q;
	q.ВСТАВКА(tr);	
	while (q.empty() == 0)
	{
		Node tmp = q.front();
		cout << key;
		q.pop();		
		if (tmp->left != NULL)
			ВСТАВКА (tmp->left);
		if (tmp->right != NULL)
			ВСТАВКА (tmp->right);		
	}
}
```
* Обход в глубину `workAroundDepth`:
```
ОБХОД_В_ГЛУБИНУ
{
	stack<Node<TType>*> s;
	s.push(tr);
	while (!s.empty() )
	{
		Node<TType>* tmp = s.top();
		cout << key;
		s.pop();
		if (tmp->right != NULL)
			ВСТАВКА(tmp->right);
		if (tmp->left != NULL)
			ВСТАВКА(tmp->left);
	}
}
```

####Таблицы

#####Просматриваемые таблицы
Таблица - динамическая структура данных, хранящая однотипные элементы. Записи хранятся в векторе памяти в порядке добавления (добавление производится в конец таблицы). При удалении записи просиходит перепаковка (сдвиг всех записей ниже текущей на одну позицию вверх).

######Основные операции
Основные операции:
* Вставка `insert`:
```
ВСТАВИТЬ(record)
{
	recs[ТЕКУЩЕЕ_КОЛИЧЕСТВО_ЗАПИСЕЙ] = record;
	ТЕКУЩЕЕ_КОЛИЧЕСТВО_ЗАПИСЕЙ++;
}
```
* Удаление `erase`:
```
УДАЛЕНИЕ(key)
{
	record = recs[0];
	tmp = 0;
	while ((recs[tmp]->getKey() != key) && (tmp <= ТЕКУЩЕЕ_КОЛИЧЕСТВО_ЗАПИСЕЙ))
		tmp++;
	if (tmp > ТЕКУЩЕЕ_КОЛИЧЕСТВО_ЗАПИСЕЙ)
		return;
	recs[tmp] = recs[ТЕКУЩЕЕ_КОЛИЧЕСТВО_ЗАПИСЕЙ - 1];
	recs[ТЕКУЩЕЕ_КОЛИЧЕСТВО_ЗАПИСЕЙ - 1] = 0;
	ТЕКУЩЕЕ_КОЛИЧЕСТВО_ЗАПИСЕЙ--;
}
```
* Поиск `search`:
```
НАЙТИ(key)
{
	tmp = 0;
	while(КЛЮЧ(recs[tmp]) != key && tmp <= ТЕКУЩЕЕ_КОЛИЧЕСТВО_ЗАПИСЕЙ)
		tmp += 1;
	if (tmp > ТЕКУЩЕЕ_КОЛИЧЕСТВО_ЗАПИСЕЙ) 
		return 0;
	return recs[tmp];
}
```

#####Упорядоченные таблицы
Упорядоченная таблица - это просматриваемая таблица, данные в которой отсортированы по невозрастанию/неубыванию ключей. Причем при вставке и удалении происходят перепаковки.

######Основная операция
* Сортировка элементов `sort` (трудоемкость = log(n)):
```
СОРТИРОВКА()
{
	TabRecord *tmp;
	for (int i=0; i<ТЕКУЩЕЕ_КОЛИЧЕСТВО_ЗАПИСЕЙ; i++)
		for (int j = i+1; j<ТЕКУЩЕЕ_КОЛИЧЕСТВО_ЗАПИСЕЙ; j++)
			if (recs[i]->getKey() > recs[j]->getKey() )
			{
				tmp = recs[i];
				recs[i] = recs[j];
				recs[j] = tmp;
			}
}
```
####Приоритетные очереди
Приоритетная очередь — это динамическая структура данных, содержащая элементы, каждый из которых имеет определенный приоритет. Элемент с более высоким приоритетом находится перед элементом с более низким приоритетом. Если у элементов одинаковые приоритеты, они располагаются в зависимости от своей позиции в очереди. 

######Основные операции:
* Вставка элемента `push`:
* Удаление элемента с максимальным приоритетом `pop`;
* Получение элемента с максимальным приоритетом `top`;
* Проверка очереди на пустоту `isEmpty`.

####Разделенные множества
Разледенные множества - абстрактный тип данных, предназначенный для представления коллекции k попарно непересекающихся можеств.

######Основные операции
* Создание множества `makesets` (трудоемкость = О(1)):
```
СОЗДАНИЕ_МНОЖЕСТВА(а)
{
	if (parent[a] != -1)
		return;

	parent[a] = a;
	height[a] = 0;
}
```
* Объединение множеств `unionsets` (трудоемкость = О(n)):
```
ОБЪЕДИНЕНИЕ_МНОЖЕСТВ(a,b)
{
	a = ПОИСК_МНОЖЕСТВА (a);
	b = ПОИСК_МНОЖЕСТВА (b);
	if (height[a] > height[b])
		parent[b] = a;
	else if (height[a] < height[b])
		parent[a] = b;
	else
	{
		parent[b] = a;
		height[a]++;
	}
}
```
* Поиск множества `findsets` (трудоемкость = О(1)):
```
ПОИСК_МНОЖЕСТВА(a)
{
	if (parent[a] == -1)
		return -1;

	while (parent[a] != a)
		a = parent[a];
	return a;
}
```

###Описание алгоритмов

####Пирамидальная сортировка

######Входные данные:

На вход поступает 2 значения: арность D-кучи и количество элементов.

######Выходные данные:

На выходе получаем массив значений, отсортированных по убыванию.

######Алгоритм

1. Просматривается минимальный элемент кучи и кладется в результирующую кучу.
2. Минимальный элемент D-кучи меняется с последним.
3. Размер D-кучи уменьшаем на 1.
4. Погружаем нулевой элемент.
5. Если размер кучи положителен, переход к п.1, иначе алгоритм завершается.

####Алгоритм Дейкстры

######Входные данные

На вход поступает:
* Количество вершин `n`
* Количество рёбер `m`
* Минимальное и максимальное значение веса ребра
* Стартовая вершина `s`.

######Выходные данные

На выходе получим 2 массива: 
* Массив `dist`, содержащий кратчайшие расстояния до каждой вершины графа `graph`.
* Массив `vis`, содержащий предшествующие вершины.
    
######Алгоритм

1. Создается массив для отметки посещения вершины `vis`. Всем элементам (кроме `vis[s] = s`) присваивается -1.
2. Создается результирующий массив расстояний `dist` (все элементы равны `MAX`, `dist[s] = 0`).
3. Создается приоритетная очередь, в которую кладется расстояние от текущей вершины до неё же.
4. Вынимается минимальный элемент.
5. Если метка вынутого элемента больше метки, хранящейся в массиве `dist`, переходим к следующему шагу.
6. Проходим по всем ребрам от текущей вершины. Если результирующее расстояние от смежной вершины больше, чем результирующее расстояние до вынутой в пункте 4 вершины в сумме с меткой ребра, вынутого в пункте 6, то:
	* В `vis`  по номеру смежной вершины кладется значение вершины, вынутой на этапе 4.
	* В `dist` по номету смежной вершины пишется новое значение расстояния, равное сумме результирующего расстояния до вынутой в пункте 4 вершины и меткои ребра, вынутогов пункте 6.
	* Обработанное ребро кладется в очередь.
7. Выполняем пункты 4-6 до тех пор, пока очередь не опустеет.

####Алгоритм Крускала

######Входные данные

На вход поступает:
* Количество вершин
* Количество рёбер
* Тип приоритетной очереди
* Минимальное и максимальное значение веса ребра(если выбрано автоматическое заполнение)
* Если выбрано ручное заполнение, то:
	* Стартовая вершина
	* Конечная вершина
	* Вес ребра

######Выходные данные

Набор рёбер `tree`, составляющих минимальное остовное дерево для данного графа.

######Алгоритм

1. Создается приоритетная очередь из ребер графа `queue` (приоритет по весу ребра).
2. Создается разделенное множество из всех вершин `set`.
3. Вынимается ребро из приоритетной очереди.
4. Если вершины, вынутые из очереди не принадлежат одному множеству, то 2 множества (под номерами вершин) объдиняются, а данное ребро добавляется в результирующий граф `tree`.
5. Если количество вершин `tree` не превышает количество `n-1` и если очередь не пуста, то переходим к п.3, иначе алгоритм завершается.

###Программная реализация структур данных

####Схема наследования классов

![12](/kartinki/12.png)

####Программная реализация D-кучи
В работе D-куча представлена классом `DHeap`, содержащим изложенные ниже:

* Поля:
	* `int d` - арность D-кучи 
	* `HType *keys` - массив, состоящий из элементов D-кучи
	* `int kolvo` - количество элементов кучи.

* Методы:
	* `getidx (int)` -  возвращает индекс родителя.
	* `trans (const int, const int)` - транспонирование 2-х елементов
	* `vsplyt (int)` - операция всплытие.
	* `pogryzh (int)` - операция погружения.
	* `minchild (int)` - минимальный "ребенок".
	* `delet ()` - операция удаления минимального элемента.
	* `deletzadan (int)` - операция удаления элемента с заданным индексом.
	* `push (HType)` - вставка элемента.
	* `okych ()` - операция окучивания.
	* `vyvod ()` - вывод кучи на экран.
	* `operator == (const DHeap<HType>&)const` - проверка на равенство.
	* `operator=(const DHeap<HType>&)` - перегрузка оператора `=`.
	* `getKolvo()` - возвращает количество элементов в куче
	* `getKey(int)` - возвращает ключ заданного элемента.

####Программная реализация бинарного поискового дерева
Узел дерева представляется классом `Node`, содержащим следующие поля:
* `HType data` - данные.
* `Node<HType>* left` - указатель на левого потомка.
* `Node<HType>* right` - указатель на правого потомка.
* `Node<HType>* parent` - укаазатель на родителя.
* `int balance` - баланс поддерева.

Бинарное поисковое дерево представлено классом `bintree`, содержащим следующие методы:
* `CopyTree (Node<TType> *)` - копирование дерева.
* `insert (Node<TType>*&, const Node<TType> *)` - вставка элемента.
* `Delete (Node<TType>*&, const TType &)` - удаление элемента.
* `Findkey (Node<TType>*, const TType &)` - поиск элемента по ключу.
* `FindMax (Node<TType>*)` - поиск максимального элемента.
* `FindMin (Node<TType>*)` - поиск минимального элемента.
* `FindNext (Node<TType>*, Node<TType>*)` - поиск элемента, следующего за заданным.
* `FindPrevious (Node<TType>*, Node<TType>*)` - поиск элемента, предыдущего за заданным.
* `workAroundAcross (Node<TType>*)` - обход в ширину.
* `workAroundForward (Node<TType>*)` - прямой обход.
* `workAroundReverse (Node<TType>*)` - обратный обход.
* `workAroundSymmetr (Node<TType>*)` - симметричный обход.
* `workAroundDepth (Node<TType>*)` - обход в глубину.
* `operator== (const bintree<TType>&)const` - проверка на равенство.
* `getSize()` - возвращает количество элементов.
* `getHeight(Node<TType>*)` - высота поддерева

####Программная реализация просматриваемых таблиц
Запись в таблице представлена классом `TabRecord`, содержащим следующие поля:
* `typ key` - идентификатор.
* `TType data` - ключ.

База для всех таблиц представлена классом `Table`, содержащим чисто виртуальные методы:
* `search (typ)` - поиск элемента по идентификатору.
* `insert (typ, TType)` - вставка элемента.
* `erase (typ)` - удаление элемента
* `isEmpty ()` - проверка на пустоту.
* `GetCount ()` - возвращает текущее количество записей.
* `reset ()` - сбрасывает указатель на `0`.
* `goNext ()` - переход к следующей записи.
* `isTabEnded ()` - возвращает `1`, если таблица закончилась, и `0` если нет.

Просматриваемые таблицы представлены классом `ScanTable`, содержащим следующие методы:
* `search (typ k)` - поиск элемента.
* `insert (typ k, TType Data)` - вставка элемента.
* `erase(typ k)` - удаление элемента.
* `print()` - вывод таблицы на экран.

####Программная реализация упорядоченных таблиц
Упорядоченные таблицы наследуются от класса `ScanTable` и представлены классом `SortTable`, содержащим нижеизложенные методы:
* `sort()` - сортировка данных.
* `search (typ key)` - поиск элемента.
* `insert(typ k, TType Data)` - вставка элемента.
* `erase(typ k)` - удаление элемента.
* `min ()` - возвращает минимальный элемент.


####Программная реализация приоритетных очередей
База для всех очередей представлена классом `PQueue`, содержащим чисто виртуальные методы:
* `push(const HType)` - вставка элемента.
* `pop()` - удаление элемента с максимальным приоритетом.
* `isEmpty()` - проверка на пустоту.
* `top()` - возвращает элемент с максимальным приоритетом.
* `GetSize ()` - возвращает количество элементов в очереди.

Приоритетная очередь на основе D-кучи наследуется от класса `PQueue` и представлена классом `DQueue`, содержащим следующие методы:
* `push(const HType)` - вставка элемента.
* `pop()` - удаление элемента с максимальным приоритетом.
* `isEmpty()` - проверка на пустоту.
* `top()` - возвращает элемент с максимальным приоритетом.
* `GetSize ()` - возвращает количество элементов в очереди.

Приоритетная очередь на основе бинарного поискового дерева наследуется от класса `PQueue` и представлена классом `BQueue`, содержащим следующие методы:
* `push(const HType)` - вставка элемента.
* `pop()` - удаление элемента с максимальным приоритетом.
* `isEmpty()` - проверка на пустоту.
* `top()` - возвращает элемент с максимальным приоритетом.
* `GetSize ()` - возвращает количество элементов в очереди.

Приоритетная очередь на основе упорядоченной таблицы наследуется от класса `PQueue` и представлена классом `TQueue`, содержащим следующие методы:
* `push(const TType);` - вставка элемента.
* `pop()` - удаление элемента с максимальным приоритетом.
* `isEmpty()` - проверка на пустоту.
* `top()` - возвращает элемент с максимальным приоритетом.
* `GetSize ()` - возвращает количество элементов в очереди.

####Программая реализация разделенных множеств
Разделенные множества представлены классом `sets`, содержащим следующие методы:
* `makesets (int)` - создает одноэлементное множество.
* `findsets (int)` - возвращает главный элемент множества
* `unionsets (int, int)` - объединяет множества.
* `vyvod()` - выводит множества на экран.
* `getsets(int)` - возвращает массив, в котором: 1-элемент - количество элементов в данном множестве, последующие элементы - данное множество.

####Программная реализация графа
Каждое ребро графа представлены классом `edge`, содержащим:
* `int o` - стартовая вершина
* `int k` - конечная вершина
* `HType weight` - вес ребра

Граф представлен классом `Graph`, содержащим следующие методы:
* `createGraph (HType, HType)` - создает граф (на вход принимается минимальное и максимальное значение веса ребра).
* `addEdge(int, int, HType)` - добавляет ребро с заданными условиями (откуда, куда, вес).
* `delEdge(int, int)` - удаляет заданное ребро
* `getKolvo()` - возвращает количество вершин
* `getEdgeSize()` - возвращает максимальное количество рёбер.
* `getRealSize()` - возвращает реальное количество рёбер.
* `getEdge(int)` - возвращает ребро.
* `getWeight(int, int)` - возвращает вес ребра
* `print()` - вывод граф на экран

##Заключение
В ходе лабораторной работы:
* Были реализованы структуры данных:
 - "D-куча"
 - "Бинарное поисковое дерево"
 - "Таблица"
 - "Просматриваемая таблица"
 - "Упорядоченная таблица"
 - "Приоритетная очередь на основе D-кучи"
 - "Приоритетная очередь на основе бинарного поискового дерева"
 - "Приоритетная очередь на основе упорядоченой таблицы"
 - "Графы"
 - "Разделенные множества"
с использованием шаблонных классов. 
* Написано тестирующее приложение, которое покрывает все методы, используемые в указанных классах. Все тесты успешно пройдены. 
* Написаны консольные приложения:
- Пирамидальная сортировка массива.
- алгоритм Дейкстры для поиска кратчайших путей от любой стартовой вершины связного неориентированного взвешенного графа без петель, реализованного на основе приоритетной очереди на базe D-кучи.
- алгоритм Крускала для построения минимального остовного дерева неориентированного взвешенного графа без петель, реализованного на основе приоритетных очередях на базе D-кучи, бинарного поискового дерева и упорядоченной таблицы.

##Литература
1. Кормен Т., Лейзерсон Ч., Риверст Р., Штайн К. Алгоритмы. Построение и анализ. - М.: Издательский дом "Вильямс". - 2005. - 1290с.
2. Алексеев В.Е., Таланов В.А. Графы. Модели вычислений. Структуры данных: Учебник. – Нижний Новгород: Изд-во ННГУ, 2005. 307 с.
