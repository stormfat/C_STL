/*順序容器deque類
1.deque是一個動態數組
2.deque與vector非常類似
3.deque可以在數組開頭和末尾插入和刪除數據*/

#include <algorithm>
#include <deque>
#include <iostream>
using std::cout;
using std::deque;
using std::endl;

int main() {
  deque<int> a;     //聲明並定義一個deque.
  a.push_back(3);   //在隊尾加入
  a.push_front(5);  //在隊首加入
  a.push_back(4);
  a.push_front(6);
  for (int i = 0; i < a.size(); ++i) {
    cout << a[i] << endl;
  }
  a.push_front(7);
  deque<int>::iterator it;
  int i = 1;
  for (it = a.begin(); it != a.end(); it++) {
    size_t num = distance(
        a.begin(),
        it);  // distance算法返回值為參數2-參數1的值.本例中,返回是當前迭代器序號距離序號一的差值,也就是返回元素下標
    cout << "a[" << num << "]=" << *it << endl;
  }
  return 0;
}