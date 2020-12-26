/*���������ص�:
1.����������ʹ��ʱ,����������������,�����в���,�����з���ֵ
2.�������󳬳���ͨ��������,����������һ����,�������Լ������Ա
3.�������������Ϊ��������*/

#include <iostream>
using namespace std;

//����������ʹ��ʱ,����������������,�����в���,�����з���ֵ
class Myadd {
public:
  int operator()(int v1, int v2) { return v1 + v2; }
};

void test01() {
  Myadd myadd;
  cout << myadd(10, 10) << endl;
}

//�������󳬳���ͨ��������, ����������һ����, �������Լ������Ա
class MyPrint {
public:
  MyPrint() { this->count = 0; }
  void operator()(string test) {
    cout << test << endl;
    this->count++;
  }
  int count; //���汻���ô���
};

void test02() {
  MyPrint myprint;
  myprint("hello world!");
  myprint("hello world!");
  myprint("hello world!");
  myprint("hello world!");
  cout << "myprint������:" << myprint.count << endl;
}

//�������������Ϊ��������
void doPrint(MyPrint &mp, string test) { mp(test); }

void test03() {
  MyPrint myprint;
  doPrint(myprint, "hello c++");
}

int main() {
  test01();
  test02();
  test03();
  return 0;
}