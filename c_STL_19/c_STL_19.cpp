#include <algorithm>
#include <ctime>
#include <iostream>
#include <numeric> //accumulate()
#include <vector>
using namespace std;

// for_each()�����㷨
void forEach(int &v) { cout << v << " "; }
class ForEach {
public:
  void operator()(int &v) { cout << v << " "; }
};

void test01() {
  vector<int> v;
  for (int i = 0; i < 10; i++)
    v.push_back(i);
  cout << "������ͨ����for_each(v.begin(),v.end(),forEach)����:";
  for_each(v.begin(), v.end(), forEach);
  cout << endl;
  cout << "���÷º���for_each(v.begin(),v.end(),ForEach())����:";
  for_each(v.begin(), v.end(), ForEach());
  cout << endl;
}

// transform()�����㷨
class MyTransform {
public:
  int operator()(int v) { return v + 1; }
};
void test02() {
  vector<int> v;
  for (int i = 0; i < 10; i++)
    v.push_back(i);
  vector<int> v1;
  v1.resize(v.size()); //��v1��size��ʼ���ɺ�vһ��,�Ա��ڰ���
  transform(v.begin(), v.end(), v1.begin(), MyTransform());
  cout << "����transform(v.begin(),v.end(),v1.begin(),MyTransform())v1:";
  for_each(v1.begin(), v1.end(), forEach);
  cout << endl;
}

// find()�����㷨:�ҵ����ص�ǰλ�õĵ�����,û�ҵ��Ļ�����end().
void test03() {
  vector<int> v;
  for (int i = 0; i < 10; i++)
    v.push_back(i);
  auto it = find(v.begin(), v.end(), 9);
  if (it != v.end())
    cout << "�ҵ�" << *it << endl;
  else
    cout << "û�ҵ�!" << endl;
}

// find_if()��������.����Ϊ��ʼ,����λ�ü�������ν��.�ҵ����ص�ǰλ�õ�����,û�ҵ�����end()
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

  bool operator==(const Person &p) { // operator==����һ������
    if (this->m_Age == p.m_Age)
      return true;
    else
      return false;
  }

  bool operator==(int age) { // operator==����һ������
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
    cout << "����" << *it << "����15" << endl;
  else
    cout << "������" << endl;
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
    cout << "�ҵ�����" << (*it1).getAge() << "����30��" << endl;
  else
    cout << "û�ҵ�" << endl;
}

// adjacent_find()���������ظ�Ԫ��,���������ظ�Ԫ�ص�һ��λ�õĵ�����,���û�����ڵ��ظ�Ԫ��,����end();
void test05() {
  vector<int> v;
  for (int i = 0; i < 10; i++)
    v.push_back(i);
  v.push_back(9);
  auto it = adjacent_find(v.begin(), v.end());
  if (it != v.end())
    cout << "�ҵ��ظ���Ԫ��" << *it << endl;
  else
    cout << "û���ظ�Ԫ��" << endl;
}

// binary_search()����Ԫ���Ƿ����,���ڷ���true,���򷵻�false,�����������в�����.����vector��Ҫ����sort()��������.
void test06() {
  vector<int> v;
  for (int i = 0; i < 100; i++) {
    v.push_back(rand() % 100); //����0-99֮������������vector
  }
  /*for (auto it = v.begin(); it != v.end(); it++)
    cout << (*it) << " ";*/
  sort(v.begin(), v.end()); //�����������ٲ���
  if (binary_search(v.begin(), v.end(), 10))
    cout << "�ҵ�10" << endl;
  else
    cout << "û�ҵ�" << endl;
}

// count()ͳ��Ԫ�ظ���
void test07() {
  //ͳ��������������
  vector<int> v;
  v.push_back(10);
  v.push_back(40);
  v.push_back(30);
  v.push_back(40);
  v.push_back(20);
  v.push_back(40);
  cout << "�ҵ�" << (count(v.begin(), v.end(), 40)) << "��40" << endl;

  //ͳ���Զ�����������
  vector<Person> vPerson;
  Person p1("����", 35);
  Person p2("�ܲ�", 15);
  Person p3("��Ȩ", 40);
  Person p4("����", 35);
  Person p5("�ŷ�", 37);
  Person p6("����", 36);
  Person p7("�����", 40);
  vPerson.push_back(p1);
  vPerson.push_back(p2);
  vPerson.push_back(p3);
  vPerson.push_back(p4);
  vPerson.push_back(p5);
  vPerson.push_back(p6);
  cout << "����Ϊ35�����" << (count(vPerson.begin(), vPerson.end(), 35))
       << "��" << endl;
  cout << "�������ͬ�����" << (count(vPerson.begin(), vPerson.end(), p7))
       << "��" << endl;
}

// count_if()������ͳ��Ԫ�ظ���,����Ϊ:������βλ�ü�ν��
void test08() {
  vector<Person> vPerson;
  Person p1("����", 35);
  Person p2("�ܲ�", 45);
  Person p3("��Ȩ", 40);
  Person p4("����", 25);
  Person p5("�ŷ�", 5);
  Person p6("����", 6);
  Person p7("�����", 40);
  vPerson.push_back(p1);
  vPerson.push_back(p2);
  vPerson.push_back(p3);
  vPerson.push_back(p4);
  vPerson.push_back(p5);
  vPerson.push_back(p6);
  cout << "�������10�����:"
       << (count_if(vPerson.begin(), vPerson.end(), MyPersonCondition()))
       << "��" << endl;
}

// random_shuffle()ָ����Χ�ڵ�Ԫ�������������
void test09() {
  vector<int> v;
  for (int i = 0; i < 20; i++) {
    v.push_back(rand() % 150); //����0-149֮������������vector
  }
  sort(v.begin(), v.end());
  cout << "���������:";
  for_each(v.begin(), v.end(), forEach);
  cout << endl;
  random_shuffle(v.begin(), v.end());
  cout << "random_shuffle��:";
  for_each(v.begin(), v.end(), forEach);
  cout << endl;
}

// merge()�������������ϲ�,���洢����һ��������,���ҲΪ����.
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

// reverse()���������������з�ת.
void test11() {
  vector<int> v;
  for (int i = 0; i < 10; i++)
    v.push_back(i);
  reverse(v.begin(), v.end());
  for_each(v.begin(), v.end(), forEach);
  cout << endl;
}

// copy()������ָ����Χ��Ԫ�ؿ�������һ����,����Ϊ:Դ������βλ��,Ŀ��������ʼλ��
void test12() {
  vector<int> v, v1;
  for (int i = 0; i < 10; i++)
    v.push_back(i);
  v1.resize(v.size());
  copy(v.begin(), v.begin() + 4, v1.begin());
  for_each(v1.begin(), v1.end(), forEach);
  cout << endl;
}

// replace()������ָ����Χ�ľ�Ԫ�ظ�Ϊ��Ԫ��,����Ϊ:������β������,��Ԫ��,��Ԫ��
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

// replace_if()������������������Ԫ���滻��ָ��Ԫ��.����:��ֹ������,ν��,�滻����Ԫ��
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

// swap()ͬ������Ԫ�ػ���.
void test15() {
  vector<int> v, v1;
  for (int i = 0; i < 10; i++)
    v.push_back(i + 1);
  for (int i = 0; i < 8; i++)
    v1.push_back(i);
  cout << "����ǰ:";
  for_each(v.begin(), v.end(), forEach);
  cout << endl;
  for_each(v1.begin(), v1.end(), forEach);
  cout << endl;
  swap(v1, v);
  cout << "������:";
  for_each(v.begin(), v.end(), forEach);
  cout << endl;
  for_each(v1.begin(), v1.end(), forEach);
  cout << endl;
}

// accumulate()��������Ԫ���ۼ��ܺ�,����:��ֹ������,��ʼֵ
void test16() {
  vector<int> v;
  for (int i = 0; i <= 100; i++)
    v.push_back(i);
  int total = accumulate(v.begin(), v.end(), 0);
  cout << "�ܺ�:" << total << endl;
}

// fill()�����������ָ����Ԫ��,����:��ֹ������,����ֵ
void test17() {
  vector<int> v;
  v.resize(10);
  //�����������
  fill(v.begin(), v.end(), 100);
  cout << "��100����:";
  for_each(v.begin(), v.end(), forEach);
  cout << endl;
}

// set_intersection()����������Ԫ�صĽ���,Ҫ��������������������.����:beg1,end1,beg2,end2,destĿ��������ʼ������
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
      v2.size())); // vTarget���ٿռ�,���ܵ����Ԫ�ظ���Ϊ���������н�С��Ԫ�ظ���
  auto endIt = set_intersection(v.begin(), v.end(), v2.begin(), v2.end(),
                                vTarget.begin()); //���ؽ������һ��������λ��
  cout << "v,v2�Ľ���Ϊ:";
  for_each(vTarget.begin(), endIt, forEach);
  cout << endl;
}

// set_union()����������Ԫ�صĲ���,�������������в���Ϊ:beg1,end1,beg2,end2,vTarget.beg
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
  cout << "v,v2����Ϊ:";
  for_each(vTarget.begin(), endIt, forEach);

  cout << endl;
}

// set_differece()����������Ԫ�صĲ.��������������,����Ϊ:beg1,end1,beg2,end2,vTarget.beg
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
  cout << "v��v2�Ľ��Ϊ:" << endl;
  for_each(vTarget.begin(), endIt, forEach);
  cout << endl;
  endIt =
      set_difference(v2.begin(), v2.end(), v.begin(), v.end(), vTarget.begin());
  cout << "v2��v�Ľ��Ϊ:" << endl;
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