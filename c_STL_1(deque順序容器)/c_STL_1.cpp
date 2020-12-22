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
//容器打印
template <typename T> void printDeque(const deque<T> &de) {
  for (auto it = de.begin(); it != de.end(); it++) {
    size_t num = distance(
        de.begin(),
        it); // distance算法返回值為參數2-參數1的值.本例中,返回是當前迭代器序號距離序號一的差值,也就是返回元素下標
    cout << "[" << num << "]=" << *it << "|";
  }
  cout << endl;
  cout << "-----------------------------------------" << endl;
}

// deque的插入和删除
void test01() {
  deque<char> a;     //聲明並定義一個deque.
  a.push_back('3');  //在隊尾加入
  a.push_front('5'); //在隊首加入
  a.push_back('a');
  a.push_front('b');
  a.push_front('c');
  cout << "test01()中容器a原始内容: " << endl;
  printDeque(a);
  cout << "test01()中容器a从尾部删除一个元素后打印结果: " << endl;
  a.pop_back();
  printDeque(a);
  cout << "test01()中容器a从头部删除一个元素后打印结果: " << endl;
  a.pop_front();
  printDeque(a);

  deque<char> b;
  b.push_back('e');
  b.push_back('f');
  b.push_back('g');
  cout << "test01()中容器b原始内容: " << endl;
  printDeque(b);
  cout << "test01()中目前a中的内容: " << endl;
  printDeque(a);
  a.insert(a.begin() + 1, b.begin(), b.end());
  cout << "test01()中执行\" a.insert(a.begin()+1, b.begin(), b.end()); "
          "\"后a中的内容: "
       << endl;
  printDeque(a);
}

// deque排序操作
void test02() {
  deque<int> d;
  d.push_back(20);
  d.push_back(10);
  d.push_back(40);
  d.push_back(50);
  d.push_back(100);
  d.push_back(103);
  d.push_back(120);
  d.push_back(70);
  cout << "test02()中容器d的原始内容: " << endl;
  printDeque(d);
  sort(d.begin(), d.end());//sort()适用于支持随机迭代器的容器,如vector和deque
  cout << "test02()中容器d经过排序后内容: " << endl;
  printDeque(d);
}

int main() {
  test01();
  cout << endl;
  cout << endl;
  test02();
  system("pause");

  return 0;
}