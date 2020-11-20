/*QUEUE隊列:
特點:先進先出(從隊尾插入,在隊首刪除)
自適應容器(容器適配器)
不能使用vector*/
#include <deque>
#include <iostream>
#include <list>
#include <queue>

using std::cout;
using std::deque;
using std::endl;
using std::queue;

int main() {
  queue<int, deque<int>> a;  //如這樣定義queue<int>a;默認第二參數為deque.
  a.push(10);
  a.push(5);
  a.push(-1);
  a.push(20);
  cout << "目前隊列中有" << a.size() << "個元素" << endl;
  cout << "隊首的元素是" << a.front() /*只看不刪除*/ << endl;
  cout << "隊尾的數據是" << a.back() /*只看不刪除*/ << endl;
  a.pop();  //刪除隊首元素
  cout << "目前隊列中有" << a.size() << "個元素" << endl;
  cout << "隊首的元素是" << a.front() /*只看不刪除*/ << endl;
  cout << "隊尾的數據是" << a.back() /*只看不刪除*/ << endl;
  return 0;
}