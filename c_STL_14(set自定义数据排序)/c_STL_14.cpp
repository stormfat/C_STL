#include <iostream>
#include <set>
#include <string>
using namespace std;
//自定义数据排序
class Person {
public:
  Person(string name, int age) {
    this->m_Name = name;
    this->m_Age = age;
  }
  string getName() const { return this->m_Name; }
  int getAge() const { return this->m_Age; }

  ////要获取set的类对象的成员函数,需要重写operator<操作符
  // bool operator<(const Person &p) const {
  //  return this->getAge() < p.getAge();
  //  return this->getName() < p.getName();
  //}

private:
  string m_Name;
  int m_Age;
};

// set是有序结构,插入自定义数据时,要指定排序规则.
class Compare {
public:
  bool operator()(const Person &p1, const Person &p2) const {
    if (p1.getAge() == p2.getAge())       //年龄相同时
      return p1.getName() > p2.getName(); //按名字降序排序
    else
      return p1.getAge() > p2.getAge(); //年龄降序排序
  }
};

void test01() {
  set<Person, Compare> sPerson; //指定排序规则
  Person p1("刘备", 35);
  Person p2("曹操", 45);
  Person p3("孙权", 40);
  Person p4("赵云", 25);
  Person p5("张飞", 35);
  Person p6("关羽", 36);
  sPerson.insert(p1);
  sPerson.insert(p2);
  sPerson.insert(p3);
  sPerson.insert(p4);
  sPerson.insert(p5);
  sPerson.insert(p6);

  for (set<Person, Compare>::iterator it = sPerson.begin(); it != sPerson.end();
       it++) {
    cout << "姓名:" << (*it).getName() << ",年龄:" << (*it).getAge() << endl;
  }
}

int main() {
  test01();
  return 0;
}