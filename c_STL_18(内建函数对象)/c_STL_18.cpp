#include <algorithm>
#include <functional> //Ϊʹ���ڽ���STL�º���
#include <iostream>
#include <vector>
using namespace std;

/*�����º���:plus(��),minus(��),multiplies(��),divides(��),modulus(ȡģ)
negate(ȡ��)*/

void test01() {
  negate<int> n; //����һ������ʵ��
  cout << n(50) << endl;
}

void test02() {
  plus<double> p;
  cout << p(1.20, 2.0) << endl;
}

//��ϵ�º���:equal_to(����),not_equal_to(������),greater(����),
// greater_equal(���ڵ���),less(С��),less_equal(С�ڵ���)
//���� greater
void test03() {
  vector<int> v;
  v.push_back(20);
  v.push_back(49);
  v.push_back(32);
  v.push_back(23);
  v.push_back(15);
  v.push_back(43);
  cout << "����ǰ:" << endl;
  for (auto it = v.begin(); it != v.end(); it++)
    cout << *it << " ";
  cout << endl;
  cout << "Ĭ������:" << endl;
  sort(v.begin(), v.end());
  for (auto it = v.begin(); it != v.end(); it++)
    cout << *it << " ";
  cout << endl;
  cout << "��������:" << endl;
  sort(v.begin(), v.end(), greater<int>()); //ʹ����������
  for (auto it = v.begin(); it != v.end(); it++)
    cout << *it << " ";
  cout << endl;
}

//�߼��º���: logical_and,logical_or,logical_not
void test04() {
  vector<bool> v;
  v.push_back(true);
  v.push_back(false);
  v.push_back(true);
  v.push_back(false);
  for (auto it = v.begin(); it != v.end(); it++)
    cout << *it << " ";
  cout << endl;
  //����logical_notȡ���������һ������
  vector<bool> v1;
  v1.resize(v.size()); //��v1�Ŀռ���Ϊ��vһ����
  transform(v.begin(), v.end(), v1.begin(), logical_not<bool>());
  for (auto it = v1.begin(); it != v1.end(); it++)
    cout << *it << " ";
  cout << endl;
}

int main() {
  test01();
  test02();
  test03();
  cout << "test04()���н��:" << endl;
  test04();
  return 0;
}