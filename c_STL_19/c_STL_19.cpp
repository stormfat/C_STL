#include <algorithm>
#include <ctime>
#include <iostream>
#include <numeric> //accumulate()
#include <vector>
using namespace std;

// for_each()遍历算法
void forEach(int &v) { cout << v << " "; }
class ForEach {
public:
  void operator()(int &v) { cout << v << " "; }
};

void test01() {
  vector<int> v;
  for (int i = 0; i < 10; i++)
    v.push_back(i);
  cout << "利用普通函数for_each(v.begin(),v.end(),forEach)遍历:";
  for_each(v.begin(), v.end(), forEach);
  cout << endl;
  cout << "利用仿函数for_each(v.begin(),v.end(),ForEach())遍历:";
  for_each(v.begin(), v.end(), ForEach());
  cout << endl;
}

// transform()搬运算法
class MyTransform {
public:
  int operator()(int v) { return v + 1; }
};
void test02() {
  vector<int> v;
  for (int i = 0; i < 10; i++)
    v.push_back(i);
  vector<int> v1;
  v1.resize(v.size()); //将v1的size初始化成和v一样,以便于搬运
  transform(v.begin(), v.end(), v1.begin(), MyTransform());
  cout << "利用transform(v.begin(),v.end(),v1.begin(),MyTransform())v1:";
  for_each(v1.begin(), v1.end(), forEach);
  cout << endl;
}

// find()查找算法:找到返回当前位置的迭代器,没找到的话返回end().
void test03() {
  vector<int> v;
  for (int i = 0; i < 10; i++)
    v.push_back(i);
  auto it = find(v.begin(), v.end(), 9);
  if (it != v.end())
    cout << "找到" << *it << endl;
  else
    cout << "没找到!" << endl;
}

// find_if()条件查找.参数为起始,结束位置及函数或谓词.找到返回当前位置迭代器,没找到返回end()
class MyCondition {
public:
  bool operator()(int const &v) { return v > 15; }
};

class Person {
public:
  Person(int age) : m_Age(age) {}
  Person(string name, int age) : m_Name(name), m_Age(age) {}
  int getAge() { return this->m_Age; }
  string getName() { return this->m_Name; }

  bool operator==(const Person &p) { // operator==传入一个对象
    if (this->m_Age == p.m_Age)
      return true;
    else
      return false;
  }

  bool operator==(int age) { // operator==传入一个整型
    if (this->m_Age == age)
      return true;
    else
      return false;
  }

private:
  int m_Age;
  string m_Name;
};

class MyPersonCondition {
public:
  bool operator()(Person &vp) { return vp.getAge() > 10; }
};

void test04() {
  vector<int> v;
  for (int i = 0; i < 10; i++)
    v.push_back(i);
  auto it = find_if(v.begin(), v.end(), MyCondition());
  if (it != v.end())
    cout << "存在" << *it << "大于15" << endl;
  else
    cout << "不存在" << endl;
  vector<Person> vPerson;
  Person p1(12);
  Person p2(13);
  Person p3(14);
  Person p4(20);
  vPerson.push_back(p1);
  vPerson.push_back(p2);
  vPerson.push_back(p3);
  vPerson.push_back(p4);
  auto it1 = find_if(vPerson.begin(), vPerson.end(), MyPersonCondition());
  if (it1 != vPerson.end())
    cout << "找到年龄" << (*it1).getAge() << "大于30岁" << endl;
  else
    cout << "没找到" << endl;
}

// adjacent_find()查找相邻重复元素,返回相邻重复元素第一个位置的迭代器,如果没有相邻的重复元素,返回end();
void test05() {
  vector<int> v;
  for (int i = 0; i < 10; i++)
    v.push_back(i);
  v.push_back(9);
  auto it = adjacent_find(v.begin(), v.end());
  if (it != v.end())
    cout << "找到重复的元素" << *it << endl;
  else
    cout << "没有重复元素" << endl;
}

// binary_search()查找元素是否存在,存在返回true,否则返回false,在无序序列中不可用.所以vector需要先用sort()进行排序.
void test06() {
  vector<int> v;
  for (int i = 0; i < 100; i++) {
    v.push_back(rand() % 100); //产生0-99之间的随机数插入vector
  }
  /*for (auto it = v.begin(); it != v.end(); it++)
    cout << (*it) << " ";*/
  sort(v.begin(), v.end()); //必须先排序再查找
  if (binary_search(v.begin(), v.end(), 10))
    cout << "找到10" << endl;
  else
    cout << "没找到" << endl;
}

// count()统计元素个数
void test07() {
  //统计内置数据类型
  vector<int> v;
  v.push_back(10);
  v.push_back(40);
  v.push_back(30);
  v.push_back(40);
  v.push_back(20);
  v.push_back(40);
  cout << "找到" << (count(v.begin(), v.end(), 40)) << "个40" << endl;

  //统计自定义数据类型
  vector<Person> vPerson;
  Person p1("刘备", 35);
  Person p2("曹操", 15);
  Person p3("孙权", 40);
  Person p4("赵云", 35);
  Person p5("张飞", 37);
  Person p6("关羽", 36);
  Person p7("诸葛亮", 40);
  vPerson.push_back(p1);
  vPerson.push_back(p2);
  vPerson.push_back(p3);
  vPerson.push_back(p4);
  vPerson.push_back(p5);
  vPerson.push_back(p6);
  cout << "年龄为35岁的有" << (count(vPerson.begin(), vPerson.end(), 35))
       << "人" << endl;
  cout << "和诸葛亮同岁的有" << (count(vPerson.begin(), vPerson.end(), p7))
       << "人" << endl;
}

// count_if()按条件统计元素个数,参数为:容器首尾位置及谓词
void test08() {
  vector<Person> vPerson;
  Person p1("刘备", 35);
  Person p2("曹操", 45);
  Person p3("孙权", 40);
  Person p4("赵云", 25);
  Person p5("张飞", 5);
  Person p6("关羽", 6);
  Person p7("诸葛亮", 40);
  vPerson.push_back(p1);
  vPerson.push_back(p2);
  vPerson.push_back(p3);
  vPerson.push_back(p4);
  vPerson.push_back(p5);
  vPerson.push_back(p6);
  cout << "年龄大于10岁的有:"
       << (count_if(vPerson.begin(), vPerson.end(), MyPersonCondition()))
       << "人" << endl;
}

// random_shuffle()指定范围内的元素随机调整次序
void test09() {
  vector<int> v;
  for (int i = 0; i < 20; i++) {
    v.push_back(rand() % 150); //产生0-149之间的随机数插入vector
  }
  sort(v.begin(), v.end());
  cout << "经过排序后:";
  for_each(v.begin(), v.end(), forEach);
  cout << endl;
  random_shuffle(v.begin(), v.end());
  cout << "random_shuffle后:";
  for_each(v.begin(), v.end(), forEach);
  cout << endl;
}

// merge()两个有序容器合并,并存储到另一个容器中,结果也为有序.
void test10() {
  vector<int> v, v1, v2;
  for (int i = 0; i < 10; i++) {
    v.push_back(i);
    v1.push_back(i + 1);
  }
  v2.resize(v.size() + v1.size());
  merge(v.begin(), v.end(), v1.begin(), v1.end(), v2.begin());
  for_each(v2.begin(), v2.end(), forEach);
  cout << endl;
}

// reverse()将容器内容器进行反转.
void test11() {
  vector<int> v;
  for (int i = 0; i < 10; i++)
    v.push_back(i);
  reverse(v.begin(), v.end());
  for_each(v.begin(), v.end(), forEach);
  cout << endl;
}

// copy()容器类指定范围的元素拷贝至另一容器,参数为:源容器首尾位置,目的容器起始位置
void test12() {
  vector<int> v, v1;
  for (int i = 0; i < 10; i++)
    v.push_back(i);
  v1.resize(v.size());
  copy(v.begin(), v.begin() + 4, v1.begin());
  for_each(v1.begin(), v1.end(), forEach);
  cout << endl;
}

// replace()将容器指定范围的旧元素改为新元素,参数为:容器首尾迭代器,旧元素,新元素
void test13() {
  vector<int> v;
  for (int i = 0; i < 10; i++) {
    v.push_back(i);
    v.push_back(i);
  }
  replace(v.begin(), v.end(), 8, 18);
  for_each(v.begin(), v.end(), forEach);
  cout << endl;
}

// replace_if()将区间内满足条件的元素替换成指定元素.参数:起止迭代器,谓词,替换的新元素
class MyReplace {
public:
  bool operator()(int &v) { return v >= 30; }
};
void test14() {
  vector<int> v;
  v.push_back(120);
  v.push_back(20);
  v.push_back(10);
  v.push_back(220);
  v.push_back(320);
  v.push_back(140);
  v.push_back(1120);
  v.push_back(130);
  replace_if(v.begin(), v.end(), MyReplace(), 1000);
  for_each(v.begin(), v.end(), forEach);
  cout << endl;
}

// swap()同类容器元素互换.
void test15() {
  vector<int> v, v1;
  for (int i = 0; i < 10; i++)
    v.push_back(i + 1);
  for (int i = 0; i < 8; i++)
    v1.push_back(i);
  cout << "交换前:";
  for_each(v.begin(), v.end(), forEach);
  cout << endl;
  for_each(v1.begin(), v1.end(), forEach);
  cout << endl;
  swap(v1, v);
  cout << "交换后:";
  for_each(v.begin(), v.end(), forEach);
  cout << endl;
  for_each(v1.begin(), v1.end(), forEach);
  cout << endl;
}

// accumulate()计算容器元素累计总和,参数:起止迭代器,初始值
void test16() {
  vector<int> v;
  for (int i = 0; i <= 100; i++)
    v.push_back(i);
  int total = accumulate(v.begin(), v.end(), 0);
  cout << "总和:" << total << endl;
}

// fill()向容器中填充指定的元素,参数:起止迭代器,填充的值
void test17() {
  vector<int> v;
  v.resize(10);
  //后期重新填充
  fill(v.begin(), v.end(), 100);
  cout << "用100填充后:";
  for_each(v.begin(), v.end(), forEach);
  cout << endl;
}

// set_intersection()求两个容器元素的交集,要求容器必须是有序序列.参数:beg1,end1,beg2,end2,dest目标容器开始迭代器
void test18() {
  vector<int> v, v2, vTarget;
  v.push_back(120);
  v.push_back(20);
  v.push_back(10);
  v.push_back(220);
  v.push_back(320);
  v.push_back(140);
  v.push_back(1120);
  v.push_back(130);
  v2.push_back(100);
  v2.push_back(140);
  v2.push_back(90);
  v2.push_back(200);
  v2.push_back(130);
  v2.push_back(190);
  sort(v.begin(), v.end());
  sort(v2.begin(), v2.end());
  vTarget.resize(min(
      v.size(),
      v2.size())); // vTarget开辟空间,可能的最大元素个数为两个容器中较小的元素个数
  auto endIt = set_intersection(v.begin(), v.end(), v2.begin(), v2.end(),
                                vTarget.begin()); //返回交集最后一个迭代器位置
  cout << "v,v2的交集为:";
  for_each(vTarget.begin(), endIt, forEach);
  cout << endl;
}

// set_union()求两个容器元素的并集,必须是有序序列参数为:beg1,end1,beg2,end2,vTarget.beg
void test19() {
  vector<int> v, v2, vTarget;
  v.push_back(120);
  v.push_back(20);
  v.push_back(10);
  v.push_back(220);
  v.push_back(320);
  v.push_back(140);
  v.push_back(1120);
  v.push_back(130);
  v2.push_back(100);
  v2.push_back(140);
  v2.push_back(90);
  v2.push_back(200);
  v2.push_back(130);
  v2.push_back(190);
  sort(v.begin(), v.end());
  sort(v2.begin(), v2.end());
  vTarget.resize(v.size() + v2.size());
  auto endIt =
      set_union(v.begin(), v.end(), v2.begin(), v2.end(), vTarget.begin());
  cout << "v,v2并集为:";
  for_each(vTarget.begin(), endIt, forEach);

  cout << endl;
}

// set_differece()求两个容器元素的差集.必须是有序序列,参数为:beg1,end1,beg2,end2,vTarget.beg
void test20() {
  vector<int> v, v2, vTarget;
  v.push_back(120);
  v.push_back(20);
  v.push_back(10);
  v.push_back(220);
  v.push_back(320);
  v.push_back(140);
  v.push_back(1120);
  v.push_back(130);
  v2.push_back(100);
  v2.push_back(140);
  v2.push_back(90);
  v2.push_back(200);
  v2.push_back(130);
  v2.push_back(190);
  sort(v.begin(), v.end());
  sort(v2.begin(), v2.end());
  vTarget.resize(max(v.size(), v2.size()));
  auto endIt =
      set_difference(v.begin(), v.end(), v2.begin(), v2.end(), vTarget.begin());
  cout << "v差v2的结果为:" << endl;
  for_each(vTarget.begin(), endIt, forEach);
  cout << endl;
  endIt =
      set_difference(v2.begin(), v2.end(), v.begin(), v.end(), vTarget.begin());
  cout << "v2差v的结果为:" << endl;
  for_each(vTarget.begin(), endIt, forEach);
  cout << endl;
}

int main() {
  test01();
  test02();
  test03();
  test04();
  test05();
  srand((int)time(0));
  test06();
  test07();
  test08();
  test09();
  test10();
  test11();
  test12();
  test13();
  test14();
  test15();
  test16();
  test17();
  test18();
  test19();
  test20();
  return 0;
}