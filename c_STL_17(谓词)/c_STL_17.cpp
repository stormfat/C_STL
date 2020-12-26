/*谓词概念:返回bool类型的仿函数称为谓词
如果operator（)接受一个参数,称为一元谓词
如果operator（)接受两个参数,称为二元谓词*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//一元谓词
class GreaterFive {
public:
  bool operator()(int val) { return val > 5; }
};

//二元谓词
class MyCompare {
public:
  bool operator()(int v1, int v2) { return v1 > v2; }
};

void test01() {
  vector<int> v;
  vector<int> v1;
  v1.push_back(10);
  v1.push_back(40);
  v1.push_back(20);
  v1.push_back(30);
  v1.push_back(50);

  for (int i = 0; i < 10; i++)
    v.push_back(i);
  //查找容器中有没有大于5的数字
  auto it = find_if(v.begin(), v.end(), GreaterFive());
  if (it != v.end())
    cout << "找到" << (*it) << endl;
  else
    cout << "没找到" << endl;
  
  sort(v1.begin(), v1.end(), MyCompare());
  for (auto it = v1.begin(); it != v1.end(); it++)
    cout << (*it) << endl;
}



int main() {
  test01();
  return 0;
}