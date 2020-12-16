#include <iostream>
#include <vector>
using namespace std;
// vector存放内置数据类型

void test01() {
  vector<int> v; //向容器中插入数据
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);
  auto iter1 = v.begin();
  for (iter1; iter1 != v.end(); iter1++)
    cout << *iter1 << endl;
}

//容器嵌套
void test02() {
  vector<vector<int>> v;
  vector<int> v1;
  vector<int> v2;
  vector<int> v3;
  vector<int> v4;
  for (int i = 0; i < 4; i++) {
    v1.push_back(i + 1);
    v2.push_back(i + 2);
    v3.push_back(i + 3);
    v4.push_back(i + 4);
  }
  //将小容器插入大容器中
  v.push_back(v1);
  v.push_back(v2);
  v.push_back(v3);
  v.push_back(v4);
  auto iter = v.begin();
  for (iter; iter != v.end(); iter++) {

    for (auto itersub = (*iter).begin(); itersub != (*iter).end(); itersub++) {
      cout << *itersub << " ";
    }
    cout << endl;
  }
}

int main() {
  // test01();
  test02();
  system("pause");
  return 0;
}