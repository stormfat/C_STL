#include <iostream>
#include <map>
#include <string>
using namespace std;

class Person {
public:
  Person(int id, string name, int age) : m_Name(name), m_Id(id), m_Age(age) {}
  string getName() const;
  int getId() const;
  int getAge() const;

private:
  string m_Name;
  int m_Id;
  int m_Age;
};

string Person::getName() const { return this->m_Name; }
int Person::getAge() const { return this->m_Age; }
int Person::getId() const { return this->m_Id; }

class MyClassSort {
public:
  bool operator()(const Person &p1, const Person &p2) const {
    /*   if (p1.getId() == p2.getId())
         return p1.getAge() > p2.getAge();*/
    return p1.getId() > p2.getId();
  }
};

template <typename T1, typename T2, typename T3>
void printMap(const map<T1, T2, T3> &m) {
  for (auto it = m.begin(); it != m.end(); it++)
    cout << "Key:" << (*it).first << ",value:" << (*it).second << "; ";
  cout << endl;
}

//���÷º���,��������ʽ
class MySort {
public:
  bool operator()(int v1, int v2) const { return v1 > v2; }
};

// map���� ����͸�ֵ
void test01() { //����map����
  map<int, int, MySort> m;
  m.insert(pair<int, int>(1, 10));
  m.insert(pair<int, int>(2, 20));
  m.insert(pair<int, int>(3, 30));
  m.insert(pair<int, int>(4, 40));
  m.insert(make_pair(5, 30)); // make_pair�Ĳ��뷽ʽ,����
  printMap(m);

  map<char, int> m1;
  m1.insert(pair<char, int>('a', 10));
  m1.insert(pair<char, int>('b', 20));
  m1.insert(pair<char, int>('d', 10));
  m1.insert(pair<char, int>('c', 10));
  printMap(m1);

  map<int, Person, MySort> m3;
  Person p1(2, "����", 35);
  Person p2(4, "�ܲ�", 45);
  Person p3(6, "��Ȩ", 40);
  Person p4(8, "����", 25);
  Person p5(8, "�ŷ�", 35);
  Person p6(9, "����", 36);
  pair<map<int, Person, MySort>::iterator, bool> ret;
  ret = m3.insert(make_pair(p1.getId(), p1));
  if (ret.second)
    cout << p1.getName() << "����ɹ�" << endl;
  else
    cout << "����ʧ��" << endl;
  ret = m3.insert(make_pair(p2.getId(), p2));
  if (ret.second)
    cout << p2.getName() << "����ɹ�" << endl;
  else
    cout << "����ʧ��" << endl;
  ret = m3.insert(make_pair(p3.getId(), p3));
  if (ret.second)
    cout << p3.getName() << "����ɹ�" << endl;
  else
    cout << "����ʧ��" << endl;
  ret = m3.insert(make_pair(p4.getId(), p4));
  if (ret.second)
    cout << p4.getName() << "����ɹ�" << endl;
  else
    cout << "����ʧ��" << endl;
  ret = m3.insert(make_pair(p5.getId(), p5));
  if (ret.second)
    cout << p5.getName() << "����ɹ�" << endl;
  else
    cout << "����ʧ��" << endl;
  ret = m3.insert(make_pair(p6.getId(), p6));
  if (ret.second)
    cout << p6.getName() << "����ɹ�" << endl;
  else
    cout << "����ʧ��" << endl;

  for (map<int, Person, MySort>::const_iterator it = m3.begin(); it != m3.end();
       it++)
    cout << "key:" << (*it).first << ",����:" << ((*it).second).getName()
         << ",ID:" << (*it).second.getId() << ",����:" << (*it).second.getAge()
         << endl;
}

int main() {
  test01();
  return 0;
}