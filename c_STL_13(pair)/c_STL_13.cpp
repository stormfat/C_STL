#include <iostream>
#include <string>
using namespace std;

// pair����Ĵ���
void test01() {
  //��һ�ַ�ʽ
  pair<string, int> p("TOM", 20);
  cout << "����:" << p.first << ",����:" << p.second;
  //�ڶ��ַ�ʽ
  cout << endl;
  pair<string, int> p2 = make_pair("jerry", 25);
  cout << "����:" << p2.first << ",����:" << p2.second;
}

int main() {
  test01();
  return 0;
}