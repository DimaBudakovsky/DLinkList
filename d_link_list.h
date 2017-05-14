#pragma once
#include <vector>

//вспомогательный класс для реализации списка
template <typename T> class Node
{
  public:
    Node();
    Node(T obj, Node<T>* prev_data = nullptr, Node<T>* next_data = nullptr);
    ~Node();

    T& data();

    bool setData(const T obj);
    T getData();

    bool setPrev(Node* prev_data);
    Node* getPrev();

    bool setNext(Node* next_data);
    Node* getNext();

  private:
    T m_data;
    Node* p_prev;
    Node* p_next;
};

//Шаблон класса ListIter для обхода двусвязного списка за линейное время
template <typename T> class ListIter
{
public:
  ListIter();

  ListIter(Node<T>* item);
  //проверка на нулевой итератор
  bool isListIterNull();

  ~ListIter();

  ListIter& operator++(int); // postfix A++

  ListIter& operator--(int);// postfix A--

  //перегрузка оператора разыменования указателя
  T& operator *();

private:
  Node<T>* p_item;
};

template <typename T> class DLinkList
{
public:
  DLinkList();
  ~DLinkList();

  //получить итератор на первый элемент списка
  ListIter<T> begin();

  //получить итератор на последний элемент списка
  ListIter<T> end();

  //получить длину списка
  unsigned int getLength() const;
  //добавить новый элемент с значением value в конец списка
  void push_back( const T& value );
  //добавить новый элемент с значением value в начало списка
  void push_front( const T& value );

  //удалить последний элемент списка
  void pop_back();
  //удалить первый элемент списка
  void pop_front();

  //отчистить список, удалить данные, освободить память
  void clear();

  //удалить элемент списка с индексом i
  bool eraseItem(unsigned int i);
  //добавить элемент списка с индексом i, предыдущий элемент с индексом i сдвигается вправо 
  /// как быть если i выходит за пределы длины списка??? на текущий момент возвращает false
  bool insertItem(const T& value, unsigned int i);

  //записать значение элемента списка под индексом i в переменную ret_val
  bool getItem(T& ret_val, unsigned int i) const;
  //записать значение value в i-ый элемент списка
  bool setItem(const T& value, unsigned int i);

  //сортировка списка по возрастанию значения
  void sort();
  //найти подмножество списка, возвращает индекс начала подмножества, либо -1 если не найдено
  int findSubList(const DLinkList& sub_list);
  //найти подмножество списка, возвращает итератор начала подмножества, если не найдено, то нулевой итератор
  ListIter<T> findSubListIter(const DLinkList& sub_list);
  //получить подмножество списка согласно заданным свойствам: 
  //[i_begin, i_end] диапазон элементов для обработки;
  //унарный предикат bool isCorespondValueFunc(const T& val); над значением
  //унарный предикат bool isCorespondInxFunc(const T& val); над индексом
  DLinkList getSubList(unsigned int i_begin, unsigned int i_end, bool (*isCorespondValueFunc)(const T& val) = nullptr, 
                                                                 bool (*isCorespondInxFunc)(const unsigned int& indx) = nullptr);
  //слияние списка other с текущим
  void merge(const DLinkList& other );
  //разделить список по условию, которое задаётся с помощью:
  //унарный предикат bool isCorespondValueFunc(const T& val); над значением элемента списка
  //унарный предикат bool isCorespondInxFunc(const T& val); над индексом элемента списка
  //возвращает массив списков, полученных из текущего с помощью заданного isCorespondValueFunc и isCorespondInxFunc условия
  //std::vector — последовательный контейнер, инкапсулирующий массивы переменного размера
  std::vector<DLinkList> divideListByCondition(bool (*isCorespondValueFunc)(const T& val), bool (*isCorespondInxFunc)(const unsigned int& indx) = nullptr);

  //перегрузка конструктора копирования
  DLinkList(const DLinkList & other);
  //перегрузка оператора присваивания
  DLinkList& operator = (const DLinkList& other );
  //перегрузка бинарного оператора + конкатенация списков
  DLinkList operator + (const DLinkList &v);
  //перегрузка оператора [] для доступа к элементу списка
  T & operator [] (unsigned int i);

private:
  //внутренние методы класса для удобства реализации
  //получить соседний элемент, следующий, если revert = false, иначе предыдущий
  Node<T>* getNeighborElement(Node<T>* item, bool revert = false) const;
  //получить элемент списка по индексу
  Node<T>* getElement(const unsigned int& i) const;

  //копировать элементы списка из заданного диапазона [first, last]
  DLinkList<T>* getCopyRangeList(Node<T>* first, Node<T>* last) const;
  //устанавливает, насколько соответствует подмножество текущего списка с элемента first образцу pattern_list,
  //на выходе функции число соответствующих элементов списка, при == pattern_list.getLength() соответствие полное
  unsigned int getScoreMatching(Node<T>* first, const DLinkList& pattern_list) const;

private:
  //указатель на первый элемент списка
  Node<T>* p_first;
  //указатель на последний элемент списка
  Node<T>* p_last;
  //кол-во элементов в списке
  unsigned int n_size_list;
};
