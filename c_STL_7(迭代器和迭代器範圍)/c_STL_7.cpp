#include <deque>
#include <iostream>
#include <list>
#include <vector>

using std::cout;
using std::deque;
using std::endl;
using std::list;
using std::vector;

//一個通過迭代器在向量中查找特定元素的方法1.
bool findInt(vector<int>::iterator beg, vector<int>::iterator end, int ival) {
  bool flag = false;
  while (beg != end) {
    if (*beg == ival) {
      flag = true;
      break;
    }
    beg++;
  }
  return flag;
}

//一個通過迭代器在向量中查找特定元素的方法2.
bool findInt2(vector<int>::iterator beg, vector<int>::iterator end, int ival) {

  while (beg != end) {
    if (*beg == ival) {
      break;
    }
    beg++;
  }
  if (beg == end)
    return false;
  else
    return true;
}

/*以上兩個方法,第一個引入了局部變量flag,第二個沒有引入新的變量,但增加了一個判斷結構.*/

int main() {
  vector<int> a;
  deque<int> b;
  list<int> c;

  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(4);
  a.push_back(5);

  vector<int>::iterator iter1 =
      a.end(); /*返回最後一個元素的下一個,為一個結束標記.不能用cout<<*iter1
               << endl;進行顯示*/
  //將迭代器指向中間位置,iterator+n(-n)只有vector和deque容器支持
  iter1--;
  vector<int>::iterator iter2 = a.begin() + a.size() / 2;
  cout << "中間元素為:" << *iter2 << endl;
  vector<int>::iterator iter3 = a.begin();
  cout << "findInt1查詢結果\t";
  if (findInt(iter3, iter1, 5)) {
    cout << "找到" << endl;
  } //此時iter1指向向量最後一個元素,但是不在查詢範圍内,所以5不能被找到
  else
    cout << "沒找到" << endl;

  cout << "findInt2查詢結果\t";
  if (findInt2(iter2, iter1, 2)) {
    cout << "找到" << endl;
  } else
    cout << "沒找到" << endl;
  return 0;
}