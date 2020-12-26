/*函数对象特点:
1.函数对象在使用时,可以像函数那样调用,可以有参数,可以有返回值
2.函数对象超出普通函数概念,函数对象是一个类,可以有自己的类成员
3.函数对象可以作为参数传递*/

#include <iostream>
using namespace std;

//函数对象在使用时,可以像函数那样调用,可以有参数,可以有返回值
class Myadd {
public:
  int operator()(int v1, int v2) { return v1 + v2; }
};

void test01() {
  Myadd myadd;
  cout << myadd(10, 10) << endl;
}

//函数对象超出普通函数概念, 函数对象是一个类, 可以有自己的类成员
class MyPrint {
public:
  MyPrint() { this->count = 0; }
  void operator()(string test) {
    cout << test << endl;
    this->count++;
  }
  int count; //保存被调用次数
};

void test02() {
  MyPrint myprint;
  myprint("hello world!");
  myprint("hello world!");
  myprint("hello world!");
  myprint("hello world!");
  cout << "myprint被调用:" << myprint.count << endl;
}

//函数对象可以作为参数传递
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