/*ν�ʸ���:����bool���͵ķº�����Ϊν��
���operator��)����һ������,��ΪһԪν��
���operator��)������������,��Ϊ��Ԫν��*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//һԪν��
class GreaterFive {
public:
  bool operator()(int val) { return val > 5; }
};

//��Ԫν��
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
  //������������û�д���5������
  auto it = find_if(v.begin(), v.end(), GreaterFive());
  if (it != v.end())
    cout << "�ҵ�" << (*it) << endl;
  else
    cout << "û�ҵ�" << endl;
  
  sort(v1.begin(), v1.end(), MyCompare());
  for (auto it = v1.begin(); it != v1.end(); it++)
    cout << (*it) << endl;
}



int main() {
  test01();
  return 0;
}