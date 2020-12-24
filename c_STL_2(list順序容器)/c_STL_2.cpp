/*學習内容
1.在list開頭插入元素
2.在list末尾插入元素
3.在list中間插入元素
4.刪除list中的元素
5.對list中元素進行反轉和排序
6.List容器不支持随机访问迭代器,不能跳跃式访问*/

#include <algorithm> //为了使用distance()算法
#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std::list;
using std::string;

class Person {
public:
  Person(string name, int age, int height)
      : m_Name(name), m_Age(age), m_Height(height) {}
  string getName() { return this->m_Name; }
  int getAge() { return m_Age; }
  int getHeight() { return m_Height; }

private:
  string m_Name;
  int m_Age;
  int m_Height;
};

// Person对象打印方法
void PrintListPerson(list<Person> &lperson) {
  for (auto it = lperson.begin(); it != lperson.end(); it++)
    cout << "姓名:" << (*it).getName() << ", 年龄:" << (*it).getAge()
         << ", 身高:" << (*it).getHeight() << endl;
}

//排序条件
bool comparePerson(Person &p1, Person &p2) { //按年龄升序排列,如果年龄相同按身高降序
  if (p1.getAge() == p2.getAge())
    return p1.getHeight() > p2.getHeight();
  else
    return p1.getAge() < p2.getAge();
}

//排序案例,把自定义类型进行排序
void test02() {
  list<Person> lPerson; // 创建容器

  Person p1("刘备", 35, 175);
  Person p2("曹操", 45, 165);
  Person p3("孙权", 40, 170);
  Person p4("赵云", 25, 190);
  Person p5("张飞", 35, 175);
  Person p6("关羽", 35, 195);

  lPerson.push_back(p1);
  lPerson.push_back(p2);
  lPerson.push_back(p3);
  lPerson.push_back(p4);
  lPerson.push_back(p5);
  lPerson.push_back(p6);
  cout << "-----------排序前:-----------" << endl;
  PrintListPerson(lPerson);
  cout << endl;
  cout << "---------- 排序后------------" << endl;
  lPerson.sort(comparePerson);
  PrintListPerson(lPerson);
}

template <typename T> void PrintListContent(list<T> &listInput) {
  cout << endl;
  for (auto iter = listInput.begin(); iter != listInput.end(); iter++) {
    size_t num = distance(listInput.begin(), iter);
    cout << "[" << num << "]=" << *iter << endl;
  }
}
void test01() {
  list<int>::iterator iter;
  list<int> a;
  list<int> b;
  b.push_back(100);
  b.push_back(200);
  b.push_back(300);
  b.push_back(400);
  b.push_back(500);

  a.push_back(10);
  a.push_front(2001);
  a.push_front(-1);
  a.push_front(9999);
  a.push_back(8989);
  iter = a.begin();
  iter++;
  a.insert(iter, 3, 7); //在迭代器位置前插入3個7;
  PrintListContent(a);
  iter++;
  a.erase(a.begin(),
          iter); //刪除從begin()到當前迭代器位置(不包括當前位置)的所有元素
  PrintListContent(a);

  /* for (iter = a.begin(); iter != a.end(); iter++) {
     size_t num = distance(a.begin(), iter);
     cout << "a[" << num << "]=" << *iter << endl;
   }*/
  PrintListContent(b);
  list<int>::iterator iter2;
  iter2 = b.begin();
  iter2++;

  b.erase(iter2);
  PrintListContent(b);
  cout << endl;
  a.insert(a.begin(), ++b.begin(), --b.end());
  PrintListContent(a);
  a.sort();    //排序函數
  a.reverse(); //反轉函數
  cout << "先排序再反轉后";
  PrintListContent(a);
}

int main() {
  // test01();
  test02();

  return 0;
}
