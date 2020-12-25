#include <iostream>
#include <set>
#include <string>
using namespace std;
//�Զ�����������
class Person {
public:
  Person(string name, int age) {
    this->m_Name = name;
    this->m_Age = age;
  }
  string getName() const { return this->m_Name; }
  int getAge() const { return this->m_Age; }

  ////Ҫ��ȡset�������ĳ�Ա����,��Ҫ��дoperator<������
  // bool operator<(const Person &p) const {
  //  return this->getAge() < p.getAge();
  //  return this->getName() < p.getName();
  //}

private:
  string m_Name;
  int m_Age;
};

// set������ṹ,�����Զ�������ʱ,Ҫָ���������.
class Compare {
public:
  bool operator()(const Person &p1, const Person &p2) const {
    if (p1.getAge() == p2.getAge())       //������ͬʱ
      return p1.getName() > p2.getName(); //�����ֽ�������
    else
      return p1.getAge() > p2.getAge(); //���併������
  }
};

void test01() {
  set<Person, Compare> sPerson; //ָ���������
  Person p1("����", 35);
  Person p2("�ܲ�", 45);
  Person p3("��Ȩ", 40);
  Person p4("����", 25);
  Person p5("�ŷ�", 35);
  Person p6("����", 36);
  sPerson.insert(p1);
  sPerson.insert(p2);
  sPerson.insert(p3);
  sPerson.insert(p4);
  sPerson.insert(p5);
  sPerson.insert(p6);

  for (set<Person, Compare>::iterator it = sPerson.begin(); it != sPerson.end();
       it++) {
    cout << "����:" << (*it).getName() << ",����:" << (*it).getAge() << endl;
  }
}

int main() {
  test01();
  return 0;
}