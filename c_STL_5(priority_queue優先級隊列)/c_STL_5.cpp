/*優先級隊列是自適應容器(容器適配器):不能用list
常用函數:empty(),size(),top(),pop(),push(item)
queue不能進行遍歷操作.*/

#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::priority_queue;
using std::deque;

int main() {
  priority_queue<int> pq;//默認使用vector
  priority_queue<int, deque<int>, std::greater<int>> pq2;//最小值優先級隊列
  pq.push(10);
  pq.push(3);
  pq.push(20);
  pq.push(30);
  pq.push(-1);
  while (pq.empty() == false) {
    cout << "將從隊列中刪除:" << pq.top() << endl;
    pq.pop();
  }
  pq2.push(10);
  pq2.push(3);
  pq2.push(20);
  pq2.push(30);
  pq2.push(-1);
  while (!pq2.empty()) {
    cout << "將從隊列中刪除:" << pq2.top() << endl;
    pq2.pop();
  }
  return 0;
}