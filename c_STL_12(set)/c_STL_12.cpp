#include <iostream>
#include <set>
using namespace std;

// set��������͸�ֵ
void printSet(set<int> &s) {
  for (auto it = s.begin(); it != s.end(); it++)
    cout << *it << endl;
}

void test01() {
  set<int> s1;
  //Ԫ�ز���ʱ�Զ�����,����������ظ�ֵ.
  s1.insert(10);
  s1.insert(20);
  s1.insert(30);
  s1.insert(50);
  s1.insert(40);
  cout << "��ӡs1:" << endl;
  printSet(s1);
  cout << endl;

  //��������
  set<int> s2(s1);
  cout << "��ӡs2:" << endl;
  printSet(s2);

  //���Һ�ͳ��,find()����һ��������,���û���ҵ�����set.end()
  set<int>::iterator it = s1.find(60);
  if (it != s1.end())
    cout << "�ҵ�:" << *it << endl;
  else
    cout << "δ�ҵ�!" << endl;
  cout << "s1��10�ĸ���Ϊ:" << s1.count(10) << endl;
}

// set��multiset������
void test02() {
  set<int> s;
  pair<set<int>::iterator, bool> ret = s.insert(10);//insert()����һ��pair����
  if (ret.second)
    cout << "��һ�β���ɹ�" << endl;
  else
    cout << "��һ�β���ʧ��" << endl;
  ret=s.insert(10);
  if (ret.second)
    cout << "�ڶ��β���ɹ�" << endl;
  else
    cout << "�ڶ��β���ʧ��" << endl;
  multiset<int> ms;
  ms.insert(10);
  ms.insert(10);
  cout<<"ʹ��set,�ҵ�" << s.count(10) << "��" << *(s.find(10)) << endl;
  cout << "multiset,�ҵ�" << ms.count(10) << "��" << *(ms.find(10)) << endl;
  
}

int main() {
  cout << "������test01()ִ�н��:" << endl;
  test01();
  cout << endl;
  cout << "������test02()ִ�н��:" << endl;
  test02();
  return 0;
}