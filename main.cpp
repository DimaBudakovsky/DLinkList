#include "d_link_list.h"
#include "d_link_list.cpp"//подключаем для избежания проблемы с линковкой (для шаблонов)
#include <iostream>
#include <string>
#include <vector>

bool isCorespondValueFunc(const int& val)
{
  bool ret(false);
  if ( val == 2)
    ret = true;
  return ret;
}

bool isCorespondIndxFunc(const unsigned int& indx)
{
  bool ret(false);
  if ( indx%2 == 0)
    ret = true;
  return ret;
}
typedef int (*func_src)(const char& a, std::string& str1, std::string& str2, std::string& str3);
typedef int (*func)(...);

int mergeStr2(const char& a, std::string& str1, std::string& str2)
{
  std::cout << "FUNCTION: mergeStr2" << std::endl;
  int ret(0);
  const char* p_a = &a;
  std::string str_add(p_a);

  str1 = str_add + str1 + str2;
  return ret;
}

int mergeStr3(const char& a, std::string& str1, std::string& str2, std::string& str3)
{
  std::cout << "FUNCTION: mergeStr3" << std::endl;
  int ret(0);
  const char* p_a = &a;
  std::string str_add(p_a);

  str1 = str_add + str1 + str2 + str3;
  return ret;
}

int ret88()
{
  std::cout << "FUNCTION: ret88" << std::endl;
  return  88;
}

int findSymbol(const char& a, std::string& str)
{
  std::cout << "FUNCTION: findSymbol" << std::endl;
  return  str.find (a);
}

int addSymbol(const char& a, std::string& str)
{
  std::cout << "FUNCTION: addSymbol" << std::endl;
  int ret(0);
  const char* p_a = &a;
  std::string str_add(p_a);

  str = "str:" + str + '+' + str_add;
  return ret;
}

int addSymbol2(const char& a, std::string& str)
{
  std::cout << "FUNCTION: addSymbol2" << std::endl;
  int ret(0);
  const char* p_a = &a;
  std::string str_add(p_a);

  str = str_add + str;
  return ret;
}

int eraseSymbol(const char& a, std::string& str)
{
  std::cout << "FUNCTION: eraseSymbol" << std::endl;
  int ret(0);
  const char* p_a = &a;
  std::string str_add(p_a);
  std::size_t found = str.find(a);
  if (found!=std::string::npos)
    str = str.erase(found);
  else
    ret = -1;

  return ret;
}



enum COMMANDS
{
  PushBack = 0,
  PushFront = 1,
  PopBack = 2,
  PopFront = 3,
  Clear = 4,
  EraseItem = 5,
  InsertItem = 6,
  GetItem = 7,
  SetItem = 8,
  Sort = 9,
  FindSubList = 10,
  GetSubList = 11,
  Merge = 12,
  DivideListByCondition = 13,
  Test = 14,
  End = 15
};

void CPushBack(DLinkList<std::string>* p_list)
{
  std::string str;
  std::cout << "PushBack: <string> params" << std::endl;
  std::cin >> str;
  p_list->push_back(str);
  std::cout << "List: ";
  for (ListIter<std::string> it = p_list->begin(); !it.isListIterNull(); it++)
    std::cout << "\"" << *it << "\"" << " ";

  std::cout << std::endl;
}

void CPushFront(DLinkList<std::string>* p_list)
{
  std::string str;
  std::cout << "PushFront: <string> params" << std::endl;
  std::cin >> str;
  p_list->push_front(str);
  std::cout << "List: ";
  for (ListIter<std::string> it = p_list->begin(); !it.isListIterNull(); it++)
    std::cout << "\"" << *it << "\"" << " ";

  std::cout << std::endl;
}

void CPopBack(DLinkList<std::string>* p_list)
{
  std::cout << "PopBack:" << std::endl;
  try
  {
    p_list->pop_back();
  }
  catch (ExseptionList& e)
  {
    std::cout << e.about_error() <<std::endl;
  }
  catch (...)
  {
    std::cout << "Unknown exseption" << std::endl;
  }

  std::cout << "List: ";
  for (ListIter<std::string> it = p_list->begin(); !it.isListIterNull(); it++)
    std::cout << "\"" << *it << "\"" << " ";

  std::cout << std::endl;
}

void CPopFront(DLinkList<std::string>* p_list)
{
  std::cout << "PopFront:" << std::endl;
  try
  {
    p_list->pop_front();
  }
  catch (ExseptionList& e)
  {
    std::cout << e.about_error() <<std::endl;
  }
  catch (...)
  {
    std::cout << "Unknown exseption" << std::endl;
  }

  std::cout << "List: ";
  for (ListIter<std::string> it = p_list->begin(); !it.isListIterNull(); it++)
    std::cout << "\"" << *it << "\"" << " ";

  std::cout << std::endl;
}

void CClear(DLinkList<std::string>* p_list)
{
  std::cout << "Clear:" << std::endl;
  p_list->clear();

  std::cout << "List: ";
  for (ListIter<std::string> it = p_list->begin(); !it.isListIterNull(); it++)
    std::cout << "\"" << *it << "\"" << " ";

  std::cout << std::endl;
}

void CEraseItem(DLinkList<std::string>* p_list)
{
  int inx(-1);
  std::cout << "EraseItem: <int> item's index param" << std::endl;
  std::cin >> inx;
  std::cout << "Result: ";
  if (p_list->eraseItem(inx))
    std::cout << "True\n";
  else
    std::cout << "False\n";

  std::cout << "List: ";
  for (ListIter<std::string> it = p_list->begin(); !it.isListIterNull(); it++)
    std::cout << "\"" << *it << "\"" << " ";

  std::cout << std::endl;
}

void CInsertItem(DLinkList<std::string>* p_list)
{
  int inx(-1);
  std::string str_value;
  std::cout << "InsertItem: <int> item's index and <string> value params" << std::endl;
  std::cin >> inx;
  std::cin >> str_value;
  std::cout << "Result: ";
  if (p_list->insertItem(str_value, inx))
    std::cout << "True\n";
  else
    std::cout << "False\n";

  std::cout << "List: ";
  for (ListIter<std::string> it = p_list->begin(); !it.isListIterNull(); it++)
    std::cout << "\"" << *it << "\"" << " ";

  std::cout << std::endl;
}

void CGetItem(DLinkList<std::string>* p_list)
{
  int inx(-1);
  std::string str_value("");
  std::cout << "GetItem: <int> item's index param" << std::endl;
  std::cin >> inx;
  std::cout << "Result: ";
  if (p_list->getItem(str_value, inx))
  {
    std::cout << "True, Value: \"" << str_value << "\"\n";
  }
  else
    std::cout << "False\n";
}

void CSetItem(DLinkList<std::string>* p_list)
{
  int inx(-1);
  std::string str_value("");
  std::cout << "SetItem: <int> item's index and <string> value params" << std::endl;
  std::cin >> inx;
  std::cin >> str_value;
  std::cout << "Result: ";
  if (p_list->setItem(str_value, inx))
  {
    std::cout << "True\n";
  }
  else
    std::cout << "False\n";

  std::cout << "List: ";
  for (ListIter<std::string> it = p_list->begin(); !it.isListIterNull(); it++)
    std::cout << "\"" << *it << "\"" << " ";

  std::cout << std::endl;
}

void CSort(DLinkList<std::string>* p_list)
{
  std::cout << "Sort:" << std::endl;
  p_list->sort();
  std::cout << "List: ";
  for (ListIter<std::string> it = p_list->begin(); !it.isListIterNull(); it++)
    std::cout << "\"" << *it << "\"" << " ";

  std::cout << std::endl;
}

void CFindSubList(DLinkList<std::string>* p_list)
{
  int lsize(-1);
  std::cout << "FindSubList: <int> is size of SubList elements, <string[size]> is strings of SubList" << std::endl;
  std::cin >> lsize;
  DLinkList<std::string> sub_list;
  for(int i(0); i < lsize; i++)
  {
    std::string str;
    std::cin >> str;
    sub_list.push_back(str);
  }
  int inx = p_list->findSubList(sub_list);
  std::cout << "Index of sub_list is: " << inx << std::endl;
}

void CGetSubList(DLinkList<std::string>* p_list)
{
  int inx_begin(-1), inx_end(-1);
  std::cout << "GetSubList: <int> is first index of sub_list, <int> is last index of sub_list" << std::endl;
  std::cin >> inx_begin;
  std::cin >> inx_end;
  DLinkList<std::string> sub_list = p_list->getSubList(inx_begin, inx_end);

  std::cout << "SubList: ";
  for (ListIter<std::string> it = sub_list.begin(); !it.isListIterNull(); it++)
    std::cout << "\"" << *it << "\"" << " ";

  std::cout << std::endl;
}

void CMerge(DLinkList<std::string>* p_list)
{
  int lsize(-1);
  std::cout << "Merge: <int> is size of list for added, <string[size]> it is strings of list for added" << std::endl;
  std::cin >> lsize;
  std::cout << "Merge: Enter " << lsize << " string's elements" << std::endl;
  DLinkList<std::string> add_list;
  for(int i(0); i < lsize; i++)
  {
    std::string str;
    std::cin >> str;
    add_list.push_back(str);
  }
  p_list->merge(add_list);

  std::cout << "List: ";
  for (ListIter<std::string> it = p_list->begin(); !it.isListIterNull(); it++)
    std::cout << "\"" << *it << "\"" << " ";

  std::cout << std::endl;
}

std::string global_value_threshold("");
unsigned int global_index_threshold(0);

bool isLessValThenThresh(const std::string& val)
{
  bool ret(false);
  if ( val < global_value_threshold)
    ret = true;
  return ret;
}

bool isMoreValThenThresh(const std::string& val)
{
  bool ret(false);
  if ( val > global_value_threshold)
    ret = true;
  return ret;
}

bool isEqualValThresh(const std::string& val)
{
  bool ret(false);
  if ( val == global_value_threshold)
    ret = true;
  return ret;
}

bool isLessInxThenThresh(const unsigned int& inx)
{
  bool ret(false);
  if ( inx < global_index_threshold)
    ret = true;
  return ret;
}

bool isMoreInxThenThresh(const unsigned int& inx)
{
  bool ret(false);
  if ( inx > global_index_threshold)
    ret = true;
  return ret;
}

bool isEqualInxThenThresh(const unsigned int& inx)
{
  bool ret(false);
  if ( inx == global_index_threshold)
    ret = true;
  return ret;
}

bool isEvenInx(const unsigned int& inx)
{
  bool ret(false);
  if ( inx % 2 == 0)
    ret = true;
  return ret;
}

bool isOddInx(const unsigned int& inx)
{
  bool ret(false);
  if ( inx % 2 != 0)
    ret = true;
  return ret;
}

std::vector<DLinkList<std::string>> controlSelection(DLinkList<std::string>* p_list, const int& condition_index_dividing, 
                                                     bool (*isCorespondValueFunc)(const std::string& val))
{
  std::vector<DLinkList<std::string>> deviding_vec;
  if (condition_index_dividing == 0)
    deviding_vec = p_list->divideListByCondition(isCorespondValueFunc, &isLessInxThenThresh);
  else if (condition_index_dividing == 1)
    deviding_vec = p_list->divideListByCondition(isCorespondValueFunc, &isMoreInxThenThresh);
  else if (condition_index_dividing == 2)
    deviding_vec = p_list->divideListByCondition(isCorespondValueFunc, &isEqualInxThenThresh);
  else if (condition_index_dividing == 3)
    deviding_vec = p_list->divideListByCondition(isCorespondValueFunc, &isEvenInx);
  else if (condition_index_dividing == 4)
    deviding_vec = p_list->divideListByCondition(isCorespondValueFunc, &isOddInx);
  else
    std::cout << "There is no such condition" << std::endl;

  return deviding_vec;
}

void CDivideListByCondition(DLinkList<std::string>* p_list)
{
  std::vector<DLinkList<std::string>> deviding_vec;
  int condition(-1);
  std::cout << "DivideListByCondition: Select the condition for dividing the list: " << std::endl 
            << "0 - Condition by the value of the elements\n" 
            << "1 - Condition by the index of the elements\n"
            << "2 - Both\n";

  std::cin >> condition;
  int condition_value_dividing(-1);
  int condition_index_dividing(-1);
  switch (condition)
  {
  case 0:
    std::cout << "Select the condition for dividing the list by the value of the elements: " << std::endl 
      << "0 - value of the element < threshold T\n" 
      << "1 - value of the element > threshold T\n"
      << "2 - value of the element == threshold T\n";

    std::cin >> condition_value_dividing;
    std::cout << "Enter threshold <string> value: " << std::endl;
    std::cin >> global_value_threshold;
    if (condition_value_dividing == 0)
      deviding_vec = p_list->divideListByCondition(&isLessValThenThresh);
    else if (condition_value_dividing == 1)
      deviding_vec = p_list->divideListByCondition(&isMoreValThenThresh);
    else if (condition_value_dividing == 2)
      deviding_vec = p_list->divideListByCondition(&isEqualValThresh);
    else
      std::cout << "There is no such condition" << std::endl;
    break;
  case 1:
    std::cout << "Select the condition for dividing the list by the index of the elements: " << std::endl 
      << "0 - index of the element < threshold T\n" 
      << "1 - index of the element > threshold T\n"
      << "2 - index of the element == threshold T\n"
      << "3 - index of the element is even number\n"
      << "4 - index of the element is odd number\n";


    std::cin >> condition_index_dividing;
    if (condition_index_dividing >= 0 && condition_index_dividing < 3)
    {
      std::cout << "Enter index threshold <int> value: " << std::endl;
      std::cin >> global_index_threshold;
    }
    deviding_vec = controlSelection(p_list, condition_index_dividing, nullptr);
    break;
  case 2:
    std::cout << "Select the condition for dividing the list by the value of the elements: " << std::endl 
      << "0 - value of the element < threshold T\n" 
      << "1 - value of the element > threshold T\n"
      << "2 - value of the element == threshold T\n";

    std::cin >> condition_value_dividing;
    std::cout << "Enter threshold <string> value: " << std::endl;
    std::cin >> global_value_threshold;

    std::cout << "Select the condition for dividing the list by the index of the elements: " << std::endl 
      << "0 - index of the element < threshold T\n" 
      << "1 - index of the element > threshold T\n"
      << "2 - index of the element == threshold T\n"
      << "3 - index of the element is even number\n"
      << "4 - index of the element is odd number\n";


    std::cin >> condition_index_dividing;
    if (condition_index_dividing >= 0 && condition_index_dividing < 3)
    {
      std::cout << "Enter index threshold <int> value: " << std::endl;
      std::cin >> global_index_threshold;
    }

    if (condition_value_dividing == 0)
      deviding_vec = controlSelection(p_list, condition_index_dividing, &isLessValThenThresh);
    else if (condition_value_dividing == 1)
      deviding_vec = controlSelection(p_list, condition_index_dividing, &isMoreValThenThresh);
    else if (condition_value_dividing == 2)
      deviding_vec = controlSelection(p_list, condition_index_dividing, &isEqualValThresh);
    else
      std::cout << "There is no such condition" << std::endl;
    break;

    break;
  default:
    std::cout << "There is no such condition" << std::endl;
    break;
  }

  std::cout << "Deviding List: \n";
  for (std::vector<DLinkList<std::string>>::iterator i = deviding_vec.begin(); i != deviding_vec.end(); i++)
  {
    for (ListIter<std::string> it = i->begin(); !it.isListIterNull(); it++)
      std::cout << "\"" << *it << "\"" << " ";

    std::cout << ";\n";
  }

  std::cout << std::endl;
}

void CHelp()
{
  std::string str_command[16] = 
  { 
    "PushBack",
    "PushFront",
    "PopBack",
    "PopFront",
    "Clear",
    "EraseItem",
    "InsertItem",
    "GetItem",
    "SetItem",
    "Sort",
    "FindSubList",
    "GetSubList",
    "Merge",
    "DivideListByCondition",
    "Test",
    "End"
  };
  for (int i(0); i < 16; i++)
    std::cout << "Command numer <" << i << "> is func " << str_command[i] << std::endl;
}

template <typename T> bool add_element_test(T* array, const int& array_len)
{
  bool rets(true);

  DLinkList<T> list;
  DLinkList<T> list_revert;
  for (int i(0); i < array_len; i++)
  {
    list.push_back(array[i]);
    list_revert.push_front(array[i]);
  }
  
  bool result_push_back(true);
  bool result_push_front(true);
  
  int inx(0);
  for (ListIter<T> it = list.begin(); !it.isListIterNull(); it++, inx++)
    if (*it != array[inx])
      result_push_back = false;

  if (!result_push_back || list.getLength() != array_len)
  {
    std::cout << "Error in PushBack!\n";
    result_push_back = false;
  }

  inx = 0;
  for (ListIter<T> it = list_revert.end(); !it.isListIterNull(); it--, inx++)
    if (*it != array[inx])
      result_push_front = false;


  if (!result_push_front || list_revert.getLength() != array_len)
  {
    std::cout << "Error in PushFront!\n";
    result_push_front = false;
  }
  rets = result_push_back && result_push_front;
  return rets;
}

template <typename T> bool reduce_number_elements_test(T* array, const int& array_len)
{
  bool rets(true);

  DLinkList<T> list;
  //pop_back
  try
  {
    list.pop_back();
  }
  catch(ExseptionList& e)
  {
    //условно корректная ситуация
    e.about_error();
  }
  catch(...)
  {
    rets = false;
    std::cout << "Unknown exseption pop_back" << std::endl;
  }
  //pop_front
  try
  {
    list.pop_front();
  }
  catch(ExseptionList& e)
  {
    //условно корректная ситуация
    e.about_error();
  }
  catch(...)
  {
    rets = false;
    std::cout << "Unknown exseption pop_front" << std::endl;
  }

  //Заполняем список элементами из массива
  for (int i(0); i < array_len; i++)
    list.push_back(array[i]);

  int step(0);
  bool result_pop(true);
  try
  {
    while(list.getLength() != 0)
    {
      step++;
      list.pop_back();
      if (list.getLength() != 0)
        list.pop_front();

      int inx(step);
      for(ListIter<T> it = list.begin(); !it.isListIterNull() || inx < array_len-step; it++, inx++)
        if (*it != array[inx])
          result_pop = false;
    }
  }
  catch (ExseptionList& e)
  {
    rets = false;
    std::cout << e.about_error() << std::endl;
  }
  catch (...)
  {
    rets = false;
    std::cout << "Unknown exseption pop_front" << std::endl;
  }

  if (!result_pop || list.getLength() != 0)
    std::cout << "Error in pop_back or pop_front function!\n";

  rets = rets && result_pop;

  ///Проверка push_back после удаления с помощью pop_back и pop_front
  try
  {
    //Снова заполняем список элементами из массива
    for (int i(0); i < array_len; i++)
      list.push_back(array[i]);
  }
  catch(...)
  {
    rets = false;
    std::cout << "Unknown exseption push_back" << std::endl;
  }

  try
  {
    list.clear();
  }
  catch(...)
  {
    rets = false;
    std::cout << "Unknown exseption clear" << std::endl;
  }
  

  int count(0);
  for (ListIter<T> it = list.begin(); !it.isListIterNull(); it++)
    count++;

  if (count != 0 || list.getLength() != 0)
  {
    rets = false;
    std::cout << "Error in clear function!\n";
  }

  ///Проверка push_back после удаления с помощью clear
  try
  {
    //Снова заполняем список элементами из массива
    for (int i(0); i < array_len; i++)
      list.push_back(array[i]);
  }
  catch(...)
  {
    rets = false;
    std::cout << "Unknown exseption push_back" << std::endl;
  }

  return rets;
}

template <typename T> bool add_reduce_element_by_inx_test(T* array, const int& array_len)
{
  bool rets(true);

  DLinkList<T> list;
  for (int i(0); i < array_len; i++)
    list.push_back(array[i]);

  for (int i(0); i < array_len; i++)
  {
    rets == rets && list.eraseItem(i) && list.insertItem(array[i], i);
    int inx(0);
    for (ListIter<T> it = list.begin(); !it.isListIterNull(); it++, inx++)
      if (*it != array[inx])
        rets = false;
  }
  //Тестирование на выход за пределы списка, eraseItem и insertItem должны возвращать значение false
  rets == rets && (!list.eraseItem(2 * array_len) && !list.insertItem(array[0], 3 * array_len));

  if(!rets)
    std::cout << "Error eraseItem or insertItem" << std::endl;

  return rets;
}

template <typename T> bool access_element_by_inx_test(T* array, const int& array_len)
{
  bool rets(true);

  DLinkList<T> list;
  for (int i(0); i < array_len; i++)
    list.push_back(array[i]);

  int inx(0);
  for (ListIter<T> it = list.begin(); !it.isListIterNull(); it++, inx++)
  {
    T ret_val;
    bool ret_get_item = list.getItem(ret_val, inx);
    if (*it != array[inx] || (ret_get_item && ret_val != array[inx]) || (list[inx] != array[inx]))
      rets = false;
  }

  if(!rets)
    std::cout << "Error get element's value by index" << std::endl;

  bool set_item_func(true);
  inx = 0;
  T val = array[0];
  for (ListIter<T> it = list.begin(); !it.isListIterNull(); it++, inx++)
  {
    T ret_val;
    if(!(list.setItem(val, inx) && list.getItem(ret_val, inx) && ret_val == val))
      set_item_func = false;
    else
      list.setItem(array[inx], inx);

    if (array[inx] != *it)
      set_item_func = false;
  }
  if(!set_item_func)
    std::cout << "Error func setItem value by index" << std::endl;

  bool set_item_by_iter(true);
  inx = 0;
  for (ListIter<T> it = list.begin(); !it.isListIterNull(); it++, inx++)
  {
    *it = val;

    if(list[inx] != val)
      set_item_by_iter = false;

    *it = array[inx];
    if (array[inx] != *it)
      set_item_by_iter = false;
  }
  if(!set_item_by_iter)
    std::cout << "Error set item throw iterator" << std::endl;

  bool set_item_by_operator(true);
  inx = 0;
  for (ListIter<T> it = list.begin(); !it.isListIterNull(); it++, inx++)
  {
    list[inx] = val;
    if (*it != val)
      set_item_by_operator = false;

    list[inx] = array[inx];
    if (array[inx] != *it)
      set_item_by_operator = false;
  }
  if(!set_item_by_operator)
    std::cout << "Error set item throw operator []" << std::endl;

  rets = rets && set_item_by_operator && set_item_by_iter && set_item_func;

  return rets;
}

template <typename T> bool sort_test(T* array, const int& array_len)
{
  bool rets(true);

  DLinkList<T> list;
  for (int i(0); i < array_len; i++)
    list.push_back(array[i]);

  try
  {
    list.sort();
  }
  catch(...)
  {
    rets = false;
    std::cout << "Unknown exseption sort" << std::endl;
  }

  bool started(true);
  ListIter<T> it = list.begin();
  T prev_val = *it;
  it++;
  for (; !it.isListIterNull(); it++)
  {
    if (prev_val > *it)
      started = false;
  }

  if (!started)
  {
    rets = false;
    std::cout << "List wasn't sorted by function sort()!" << std::endl;
  }

  return rets;
}

template <typename T> bool find_sub_list(T* array, const int& array_len)
{
  bool rets(true);

  DLinkList<T> list;
  DLinkList<T> sub_list;
  int a1 = array_len/2;
  int a2 = array_len - 1;
  for (int i(0); i < array_len; i++)
  {
    list.push_back(array[i]);
    if (i >= a1 && i < a2)
      sub_list.push_back(array[i]);
  }

  int res = list.findSubList(sub_list);
  if (res != a1)
  {
    rets = false;
    std::cout << "Error findSubList" << std::endl;
  }
  ListIter<T> it = list.findSubListIter(sub_list);
  if (*it != array[a1])
  {
    rets = false;
    std::cout << "Error findSubList" << std::endl;
  }

  sub_list.merge(list);
  //подмножество не найдено
  if (list.findSubList(sub_list) != -1 || !list.findSubListIter(sub_list).isListIterNull())
  {
    rets = false;
    std::cout << "Error findSubList" << std::endl;
  }
  return rets;
}

template <typename T> bool concatenation_and_merge_list(T* array, const int& array_len)
{
  bool rets(true);

  DLinkList<T> list;
  DLinkList<T> list_revert;
  for (int i(0); i < array_len; i++)
  {
    list.push_back(array[i]);
    list_revert.push_front(array[i]);
  }

  DLinkList<T> empty_list;
  empty_list.merge(list);
  empty_list.merge(list_revert);

  bool result_merge(true);

  int inx(0);
  ListIter<T> it = empty_list.begin();
  for ( ; !it.isListIterNull() && inx < array_len; it++, inx++)
    if (*it != array[inx])
      result_merge = false;

  inx--;
  for ( ; !it.isListIterNull() && inx >= 0; it++, inx--)
    if (*it != array[inx])
      result_merge = false;

  if (!result_merge || empty_list.getLength() != 2*array_len)
  {
    std::cout << "Error in merge!\n";
    rets = false;
  }

  DLinkList<T> empty_list2 = list + list_revert + list;
  bool result_concatenation(true);

  //Проверка конкатенации
  inx = 0;
  it = empty_list2.begin();
  for ( ; !it.isListIterNull() && inx < array_len; it++, inx++)
    if (*it != array[inx])
      result_concatenation = false;
  inx--;
  for ( ; !it.isListIterNull() && inx >= 0; it++, inx--)
    if (*it != array[inx])
      result_concatenation = false;
  inx++;
  for ( ; !it.isListIterNull() && inx < array_len; it++, inx++)
    if (*it != array[inx])
      result_concatenation = false;

  if (!result_concatenation || empty_list2.getLength() != 3*array_len)
  {
    std::cout << "Error in concatenation!\n";
    rets = false;
  }

  return rets;
}

bool CTest()
{
  bool res(true);
  const int strs_size = 18;
  std::string str_elements[strs_size] = 
  {
    "PushBack",
    "",
    "PushFront"
    " ",
    "PopBack",
    "PopFront",
    "Clear",
    "EraseItem",
    "InsertItem",
    "GetItem",
    "SetItem",
    "Sort",
    "FindSubList",
    "GetSubList",
    "Merge",
    "DivideListByCondition",
    "Test",
    "End"
  };

  const int func_size = 7;
  func func_elements[func_size] = 
  {
    reinterpret_cast<func>(&findSymbol),
    reinterpret_cast<func>(&ret88),
    reinterpret_cast<func>(&addSymbol),
    reinterpret_cast<func>(&mergeStr2),
    reinterpret_cast<func>(&addSymbol2),
    reinterpret_cast<func>(&mergeStr3),
    reinterpret_cast<func>(&eraseSymbol)
  };

  res = add_element_test(str_elements, strs_size) && add_element_test(func_elements, func_size) &&
        reduce_number_elements_test(str_elements, strs_size) && reduce_number_elements_test(func_elements, func_size) && 
        add_reduce_element_by_inx_test(str_elements, strs_size) && add_reduce_element_by_inx_test(func_elements, func_size) && 
        access_element_by_inx_test(str_elements, strs_size) && access_element_by_inx_test(func_elements, func_size) && 
        sort_test(str_elements, strs_size) && sort_test(func_elements, func_size) && 
        find_sub_list(str_elements, strs_size) && find_sub_list(func_elements, func_size) && 
        concatenation_and_merge_list(str_elements, strs_size) && concatenation_and_merge_list(func_elements, func_size);

  return res;
}

int main()
{
  DLinkList<std::string> str_list;
  bool isEnd(false);
  CHelp();
  bool res = CTest();
  while(!isEnd)
  {
    int inx_command(-1);
    std::cin >> inx_command;
    COMMANDS command = (COMMANDS)inx_command;
    switch (command)
    {
    case PushBack:
      CPushBack(&str_list);
      break;
    case PushFront:
      CPushFront(&str_list);
      break;
    case PopBack:
      CPopBack(&str_list);
      break;
    case PopFront:
      CPopFront(&str_list);
      break;
    case Clear:
      CClear(&str_list);
      break;
    case EraseItem:
      CEraseItem(&str_list);
      break;
    case InsertItem:
      CInsertItem(&str_list);
      break;
    case GetItem:
      CGetItem(&str_list);
      break;
    case SetItem:
      CSetItem(&str_list);
      break;
    case Sort:
      CSort(&str_list);
      break;
    case FindSubList:
      CFindSubList(&str_list);
      break;
    case GetSubList:
      CGetSubList(&str_list);
      break;
    case Merge:
      CMerge(&str_list);
      break;
    case DivideListByCondition:
      CDivideListByCondition(&str_list);
      break;
    case Test:
      if (CTest())
        std::cout << "Tests were passed successfully\n";
      else
        std::cout << "ERROR: Tests were passed unsuccessfully\n";
      break;
    case End:
      isEnd = true;
      break;
    default:
      isEnd = true;
      std::cout << "Unknown command! Delete brain\n";
      break;
    }
  }
//   str_list0.push_back("abcds");
//   //CPushBack(&str_list0);
//   CInsertItem(&str_list0);
//   int y = 0;
  /*

  DLinkList<int> list;
  if (true)
  {
    DLinkList<int> list1, list2, list3;
    for (int i (1); i <= 10; i++)
    {
      list1.push_back(i);
      list2.push_front(2*i);
      list3.push_back(3*i);
    }
    list =  list2 + list3 + list1;
  }
  
  int abs(0);
  try
  {
    abs = list[-1];
  }
  catch (ExseptionList& e)
  {
    std::cout << e.about_error() << std::endl;
  }
  catch (...)
  {
    std::cout << "Unknown exseption" << std::endl;
  }
  
  int t = list.getLength();
  for (unsigned int i (0); i < list.getLength(); i++)
  {
    std::cout << list[i] << ", ";
  }
  std::cout << std::endl << "!!!!!!!SORTED!!!!!!!!!!" << std::endl;

  list.sort();
  for (unsigned int i (0); i < list.getLength(); i++)
  {
    std::cout << list[i] << ", ";
  }
  std::cout << std::endl << "!!!!!!!!!!!!!!!!!" << std::endl;

  DLinkList<int> list_pattern;
  list_pattern.push_back(9);
  list_pattern.push_back(10);
  list_pattern.push_back(10);
  int Q = list.findSubList(list_pattern);
  std::vector<DLinkList<int>> seperates = list.divideListByCondition(&isCorespondValueFunc);
  for (std::vector<DLinkList<int>>::iterator i = seperates.begin(); i != seperates.end(); ++i)
  {
    for (unsigned int j (0); j < i->getLength(); j++)
    {
      std::cout << (*i)[j] << ", ";
    }
    std::cout << std::endl;
  }
  
  DLinkList<std::string> str_list;
  if (str_list.getLength() == 0)
    std::cout << "Good getLength()\n";

  try
  {
    str_list.pop_back();
  }
  catch (ExseptionList& e)
  {
    std::cout << e.about_error() <<std::endl;
  }

  str_list.push_back("abcdefg");

  try
  {
    str_list.pop_back();
  }
  catch (ExseptionList& e)
  {
    std::cout << e.about_error() <<std::endl;
  }

  std::cout << "Vvediti new element string list" << std::endl;
  std::string str;
  std::cin >> str;
  str_list.push_back(str);

  str_list.push_back("b");
  str_list.push_back("abcd");
  str_list.push_back("a");
  str_list.push_back("abcde");
  str_list.push_back("abc");
  str_list.push_back("ab");
  str_list.push_back("du");
  str_list.push_back("bu");
  str_list.sort();
  for (ListIter<std::string> it = str_list.begin(); !it.isListIterNull(); it++)
    std::cout << *it << ", ";

  std::cout << std::endl;
  

  DLinkList<func> f_list, f_list2;
  f_list.push_back(reinterpret_cast<func>(&findSymbol));//0
  f_list.push_back(reinterpret_cast<func>(&ret88));//1
  f_list.push_back(reinterpret_cast<func>(&addSymbol));//2
  f_list.push_back(reinterpret_cast<func>(&mergeStr2));//3
  f_list.push_back(reinterpret_cast<func>(&addSymbol2));//4
  f_list.push_back(reinterpret_cast<func>(&mergeStr3));//5
  f_list.push_back(reinterpret_cast<func>(&eraseSymbol));//6
  int ret0 = reinterpret_cast<func_src>(f_list[0])('a', std::string("eabcd"), std::string("str2"), std::string("str3"));
  int ret1 = reinterpret_cast<func_src>(f_list[1])('a', std::string("eabcd"), std::string("str2"), std::string("str3"));
  int ret2 = reinterpret_cast<func_src>(f_list[2])('a', std::string("eabcd"), std::string("str2"), std::string("str3"));
  int ret3 = reinterpret_cast<func_src>(f_list[3])('a', std::string("eabcd"), std::string("str2"), std::string("str3"));
  int ret4 = reinterpret_cast<func_src>(f_list[4])('a', std::string("eabcd"), std::string("str2"), std::string("str3"));
  int ret5 = reinterpret_cast<func_src>(f_list[5])('a', std::string("eabcd"), std::string("str2"), std::string("str3"));
  int ret6 = reinterpret_cast<func_src>(f_list[6])('a', std::string("eabcd"), std::string("str2"), std::string("str3"));
  f_list.sort();
  std::cout << "SORTED\n";
  int sret0 = reinterpret_cast<func_src>(f_list[0])('a', std::string("eabcd"), std::string("str2"), std::string("str3"));
  int sret1 = reinterpret_cast<func_src>(f_list[1])('a', std::string("eabcd"), std::string("str2"), std::string("str3"));
  int sret2 = reinterpret_cast<func_src>(f_list[2])('a', std::string("eabcd"), std::string("str2"), std::string("str3"));
  int sret3 = reinterpret_cast<func_src>(f_list[3])('a', std::string("eabcd"), std::string("str2"), std::string("str3"));
  int sret4 = reinterpret_cast<func_src>(f_list[4])('a', std::string("eabcd"), std::string("str2"), std::string("str3"));
  int sret5 = reinterpret_cast<func_src>(f_list[5])('a', std::string("eabcd"), std::string("str2"), std::string("str3"));
  int sret6 = reinterpret_cast<func_src>(f_list[6])('a', std::string("eabcd"), std::string("str2"), std::string("str3"));
  
  std::cout << "FIND\n";
  f_list2.push_back(reinterpret_cast<func>(&ret88));
  ListIter<func> it_f = f_list.findSubListIter(f_list2);
  if (!it_f.isListIterNull())
    reinterpret_cast<func_src>(*it_f)('a', std::string("eabcd"), std::string("str2"), std::string("str3"));

  bool res_erase = f_list.eraseItem(2);
  std::cout << "ERASED\n";
  int ssret0 = reinterpret_cast<func_src>(f_list[0])('a', std::string("eabcd"), std::string("str2"), std::string("str3"));
  int ssret1 = reinterpret_cast<func_src>(f_list[1])('a', std::string("eabcd"), std::string("str2"), std::string("str3"));
  int ssret2 = reinterpret_cast<func_src>(f_list[2])('a', std::string("eabcd"), std::string("str2"), std::string("str3"));
  int ssret3 = reinterpret_cast<func_src>(f_list[3])('a', std::string("eabcd"), std::string("str2"), std::string("str3"));
  int ssret4 = reinterpret_cast<func_src>(f_list[4])('a', std::string("eabcd"), std::string("str2"), std::string("str3"));
  int ssret5 = reinterpret_cast<func_src>(f_list[5])('a', std::string("eabcd"), std::string("str2"), std::string("str3"));

//  int abs = list[123]; 

//   int a(-1);
//   list[0] = 2;
//   list.getItem(a, 5);
*/
  return 0;
}