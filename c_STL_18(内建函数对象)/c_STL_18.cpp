#include <algorithm>
#include <functional> //为使用内建的STL仿函数
#include <iostream>
#include <vector>
using namespace std;

/*算术仿函数:plus(加),minus(减),multiplies(乘),divides(除),modulus(取模)
negate(取反)*/

void test01() {
  negate<int> n; //构建一个对象实例
  cout << n(50) << endl;
}

void test02() {
  plus<double> p;
  cout << p(1.20, 2.0) << endl;
}

//关系仿函数:equal_to(等于),not_equal_to(不等于),greater(大于),
// greater_equal(大于等于),less(小于),less_equal(小于等于)
//大于 greater
void test03() {
  vector<int> v;
  v.push_back(20);
  v.push_back(49);
  v.push_back(32);
  v.push_back(23);
  v.push_back(15);
  v.push_back(43);
  cout << "排序前:" << endl;
  for (auto it = v.begin(); it != v.end(); it++)
    cout << *it << " ";
  cout << endl;
  cout << "默认排序:" << endl;
  sort(v.begin(), v.end());
  for (auto it = v.begin(); it != v.end(); it++)
    cout << *it << " ";
  cout << endl;
  cout << "升序排序:" << endl;
  sort(v.begin(), v.end(), greater<int>()); //使用匿名对象
  for (auto it = v.begin(); it != v.end(); it++)
    cout << *it << " ";
  cout << endl;
}

//逻辑仿函数: logical_and,logical_or,logical_not
void test04() {
  vector<bool> v;
  v.push_back(true);
  v.push_back(false);
  v.push_back(true);
  v.push_back(false);
  for (auto it = v.begin(); it != v.end(); it++)
    cout << *it << " ";
  cout << endl;
  //利用logical_not取反后放入另一个容器
  vector<bool> v1;
  v1.resize(v.size()); //将v1的空间置为和v一样大
  transform(v.begin(), v.end(), v1.begin(), logical_not<bool>());
  for (auto it = v1.begin(); it != v1.end(); it++)
    cout << *it << " ";
  cout << endl;
}

int main() {
  test01();
  test02();
  test03();
  cout << "test04()运行结果:" << endl;
  test04();
  return 0;
}