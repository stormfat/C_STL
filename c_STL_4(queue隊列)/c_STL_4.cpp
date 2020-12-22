/*QUEUE隊列:
特點:先進先出(從隊尾插入,在隊首刪除)
自適應容器(容器適配器)
不能使用vector*/
#include <deque>
#include <iostream>
#include <list>
#include <queue>

using std::string;
using std::cout;
using std::deque;
using std::endl;
using std::queue;

class Person {
public:
  Person(string name,int age):m_Name(name),m_Age(age) {}
  string m_Name;
  int m_Age;
};

void test01() {
  queue<int, deque<int>> a; //如這樣定義queue<int>a;默認第二參數為deque.
  a.push(10);
  a.push(5);
  a.push(-1);
  a.push(20);
  cout << "目前隊列中有" << a.size() << "個元素" << endl;
  cout << "隊首的元素是" << a.front() /*只看不刪除*/ << endl;
  cout << "隊尾的數據是" << a.back() /*只看不刪除*/ << endl;
  a.pop(); //刪除隊首元素
  cout << "目前隊列中有" << a.size() << "個元素" << endl;
  cout << "隊首的元素是" << a.front() /*只看不刪除*/ << endl;
  cout << "隊尾的數據是" << a.back() /*只看不刪除*/ << endl;
}

void test02() {
  queue<Person> pQueue;
  Person p1("唐僧", 30);
  Person p2("孙悟空", 30000);
  Person p3("猪八戒", 20000);
  Person p4("沙和尚", 25000);
  pQueue.push(p1);
  pQueue.push(p2);
  pQueue.push(p3);
  pQueue.push(p4);
  while (!pQueue.empty()) {
    cout << "队首人物姓名:" << pQueue.front().m_Name
         << ",年龄:" << pQueue.front().m_Age << endl;
    cout << "队尾人物姓名:" << pQueue.back().m_Name
         << ",年龄:" << pQueue.back().m_Age << endl;
    pQueue.pop();
  }
}

int main() {
  cout << "test01()运行结果如下:" << endl;
  test01();
  cout << endl;
  cout << "test02()运行结果如下:" << endl;
  test02();
  return 0;
}