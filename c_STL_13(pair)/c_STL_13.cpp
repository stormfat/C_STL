#include <iostream>
#include <string>
using namespace std;

// pair对组的创建
void test01() {
  //第一种方式
  pair<string, int> p("TOM", 20);
  cout << "姓名:" << p.first << ",年龄:" << p.second;
  //第二种方式
  cout << endl;
  pair<string, int> p2 = make_pair("jerry", 25);
  cout << "姓名:" << p2.first << ",年龄:" << p2.second;
}

int main() {
  test01();
  return 0;
}