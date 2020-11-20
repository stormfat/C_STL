/*學習内容
1.在list開頭插入元素
2.在list末尾插入元素
3.在list中間插入元素
4.刪除list中的元素
5.對list中元素進行反轉和排序*/

#include <algorithm>
#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std::list;

void PrintListContent(const list<int>& listInput) {
  cout << endl;
  list<int>::const_iterator iter;
  for (iter = listInput.begin(); iter != listInput.end(); iter++) {
    size_t num = distance(listInput.begin(), iter);
    cout << "[" << num << "]=" << *iter << endl;
  }
}

int main() {
  list<int>::iterator iter;
  list<int> a;
  list<int> b;
  b.push_back(100);
  b.push_back(200);
  b.push_back(300);
  b.push_back(400);
  b.push_back(500);

  a.push_back(10);
  a.push_front(2001);
  a.push_front(-1);
  a.push_front(9999);
  a.push_back(8989);
  iter = a.begin();
  iter++;
  a.insert(iter, 3, 7);  //在迭代器位置前插入3個7;
  PrintListContent(a);
  iter++;
  a.erase(a.begin(),
          iter);  //刪除從begin()到當前迭代器位置(不包括當前位置)的所有元素
  PrintListContent(a);

  /* for (iter = a.begin(); iter != a.end(); iter++) {
     size_t num = distance(a.begin(), iter);
     cout << "a[" << num << "]=" << *iter << endl;
   }*/
  PrintListContent(b);
  list<int>::iterator iter2;
  iter2 = b.begin();
  iter2++;

  b.erase(iter2);
  PrintListContent(b);
  cout << endl;
  a.insert(a.begin(), ++b.begin(), --b.end());
  PrintListContent(a);
  a.sort();     //排序函數
  a.reverse();  //反轉函數
  cout << "先排序再反轉后";
  PrintListContent(a);
  return 0;
}
