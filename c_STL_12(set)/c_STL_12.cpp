#include <iostream>
#include <set>
#include <string>
using namespace std;

// set容器构造和赋值
void printSet(set<int> &s) {
  for (auto it = s.begin(); it != s.end(); it++)
    cout << *it << endl;
}

void test01() {
  set<int> s1;
  //元素插入时自动排序,不允许插入重复值.
  s1.insert(10);
  s1.insert(20);
  s1.insert(30);
  s1.insert(50);
  s1.insert(40);
  cout << "打印s1:" << endl;
  printSet(s1);
  cout << endl;

  //拷贝构造
  set<int> s2(s1);
  cout << "打印s2:" << endl;
  printSet(s2);

  //查找和统计,find()返回一个迭代器,如果没有找到返回set.end()
  set<int>::iterator it = s1.find(60);
  if (it != s1.end())
    cout << "找到:" << *it << endl;
  else
    cout << "未找到!" << endl;
  cout << "s1中10的个数为:" << s1.count(10) << endl;
}

// set和multiset的区别
void test02() {
  set<int> s;
  pair<set<int>::iterator, bool> ret = s.insert(10); // insert()返回一个pair类型
  if (ret.second)
    cout << "第一次插入成功" << endl;
  else
    cout << "第一次插入失败" << endl;
  ret = s.insert(10);
  if (ret.second)
    cout << "第二次插入成功" << endl;
  else
    cout << "第二次插入失败" << endl;
  multiset<int> ms;
  ms.insert(10);
  ms.insert(10);
  cout << "使用set,找到" << s.count(10) << "个" << *(s.find(10)) << endl;
  cout << "multiset,找到" << ms.count(10) << "个" << *(ms.find(10)) << endl;
}

/*利用仿函数改变set默认排序规则*/
class MyCompare {
public:
  bool operator()(const int &v1, const int &v2) const { return v1 > v2; }
};
void test03() {
  set<int> s1;
  s1.insert(10);
  s1.insert(40);
  s1.insert(30);
  s1.insert(20);
  s1.insert(50);
  printSet(s1);
  cout << endl;
  //指定排序规则从大到小,排序规则在set创建对象时要给出
  set<int, MyCompare> s2;
  s2.insert(10);
  s2.insert(29);

  for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++)
    cout << *it << endl;
  cout << endl;
}





int main() {
  cout << "以下是test01()执行结果:" << endl;
  test01();
  cout << endl;
  cout << "以下是test02()执行结果:" << endl;
  test02();
  cout << "以下是test03()执行结果:" << endl;
  test03();
  return 0;
}