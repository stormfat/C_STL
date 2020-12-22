/*QUEUE���:
���c:���M�ȳ�(���β����,����ׄh��)
���m������(�����m����)
����ʹ��vector*/
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
  queue<int, deque<int>> a; //���@�Ӷ��xqueue<int>a;Ĭ�J�ڶ�������deque.
  a.push(10);
  a.push(5);
  a.push(-1);
  a.push(20);
  cout << "Ŀǰ�������" << a.size() << "��Ԫ��" << endl;
  cout << "��׵�Ԫ����" << a.front() /*ֻ�����h��*/ << endl;
  cout << "�β�Ĕ�����" << a.back() /*ֻ�����h��*/ << endl;
  a.pop(); //�h�����Ԫ��
  cout << "Ŀǰ�������" << a.size() << "��Ԫ��" << endl;
  cout << "��׵�Ԫ����" << a.front() /*ֻ�����h��*/ << endl;
  cout << "�β�Ĕ�����" << a.back() /*ֻ�����h��*/ << endl;
}

void test02() {
  queue<Person> pQueue;
  Person p1("��ɮ", 30);
  Person p2("�����", 30000);
  Person p3("��˽�", 20000);
  Person p4("ɳ����", 25000);
  pQueue.push(p1);
  pQueue.push(p2);
  pQueue.push(p3);
  pQueue.push(p4);
  while (!pQueue.empty()) {
    cout << "������������:" << pQueue.front().m_Name
         << ",����:" << pQueue.front().m_Age << endl;
    cout << "��β��������:" << pQueue.back().m_Name
         << ",����:" << pQueue.back().m_Age << endl;
    pQueue.pop();
  }
}

int main() {
  cout << "test01()���н������:" << endl;
  test01();
  cout << endl;
  cout << "test02()���н������:" << endl;
  test02();
  return 0;
}