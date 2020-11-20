/*STACK:LIFO後進先出
自適應容器(容器適配器)*/
#include <iostream>
#include <stack>
#include <vector>
using std::cout;
using std::deque;
using std::endl;
using std::stack;
using std::vector;

int main() {
  stack<int, deque<int>> a;
  stack<int> d;
  d.push(1);
  d.push(2);
  d.push(3);
  int x = d.top();  //查看棧頂元素
  cout << "目前棧頂元素是:" << x << endl;
  d.pop();  //刪除棧頂元素(出棧)
  x = d.top();
  cout << "目前棧頂元素是:" << x << endl;
  while (d.empty() == false) {
    x = d.top();
    d.pop();
    cout << x << endl;
  }

  return 0;
}