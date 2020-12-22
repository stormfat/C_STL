/*vector��Ҫ�ӿ�:
push_back()
pop_back()
front()
back()
swap()
resize()
reserve()*/

#include <iostream>
#include <vector>
using namespace std;

template <typename T> void printVector(const T &vec) {
  for (auto iter = vec.begin(); iter != vec.end(); iter++) {
    cout << *iter << " ";
  }
  cout << endl;
}

//���ֹ��췽ʽ
void test01() {
  vector<int> v; //�������в�������
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);
  cout << "��ʼ��ӡV: " << endl;
  ;
  printVector(v);

  //��ĳ��vector�����ķ�Χ���й���
  vector<int> v2(v.begin(), v.end());
  v2.push_back(40);
  cout << "��ʼ��ӡV2: " << endl;
  ;
  printVector(v2);

  // n��elem��ʽ���й���
  vector<char> v3(10, 'a');
  cout << "��ʼ��ӡV3: " << endl;
  ;
  printVector(v3);

  //�������췽ʽ
  vector<int> v4(v2);
  cout << "��ʼ��ӡV4: " << endl;
  printVector(v4);
}

//����Ƕ��
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
  //��С���������������
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

// vector��ֵ
void test03() {
  vector<int> v1;
  for (int i = 10; i < 20; i++)
    v1.push_back(i);
  vector<int> v2;
  //��operator=��ֵ���ط�ʽ��v2��ֵ
  v2 = v1;
  cout << "V2:" << endl;
  printVector(v2);

  //��assign������ֵ
  vector<int> v3;
  v3.assign(v1.begin(), v1.end());
  cout << "v3:" << endl;
  printVector(v3);

  // n��elem��ʽ��ֵ
  vector<int> v4;
  v4.assign(10, 10);
  cout << "v4: " << endl;
  printVector(v4);
}

// vector��ɾ���Ͳ���
void test04() {
  vector<int> v;
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);
  v.push_back(40);
  v.push_back(50);

  cout << "���ڴ�ӡtest04()v: " << endl;
  printVector(v);

  v.pop_back();
  cout << "���ڴ�ӡpop���test04()v: " << endl;
  printVector(v);

  v.insert(v.begin(), 3, 1000);
  cout << "���ڴ�ӡinsert���test04()v: " << endl;
  printVector(v);

  v.erase(v.begin(), v.begin() + 1);
  cout << "���ڴ�ӡerase���test04()v: " << endl;
  printVector(v);

  v.clear();
  cout << "���ڴ�ӡclear���test04()v: " << endl;
}

// vector���ݴ�ȡ
void test05() {
  vector<int> v;
  for (int i = 0; i < 10; i++)
    v.push_back(i);
  //��at��ʽ����
  cout << "��at��ʽ����test05()v: " << endl;
  for (int i = 0; i < v.size(); i++)
    cout << v.at(i) << " ";
  cout << endl;
  //��ȡ��һ��Ԫ��
  cout << "��һ��Ԫ��:" << v.front() << endl;
  //��ȡ���һ��Ԫ��
  cout << "���һ��Ԫ��:" << v.back() << endl;
}

// vector swapʵ��Ԫ�ػ���,swap()�������������õ�ַ.
void test06() {
  vector<int> v1, v2;
  for (int i = 0; i < 10; i++)
    v1.push_back(i);
  for (int i = 9; i >= 0; i--)
    v2.push_back(i);
  cout << "���ڴ�ӡ����ǰ��test06() v1: " << endl;
  printVector(v1);
  cout << "���ڴ�ӡ����ǰtest06() v2: " << endl;
  printVector(v2);
  v1.swap(v2);
  cout << "���ڴ�ӡ�������test06() v1: " << endl;
  printVector(v1);
  cout << "���ڴ�ӡ������test06() v2: " << endl;
  printVector(v2);
}

//����swap�����ڴ�ռ�
void test07() {
  vector<int> v;
  for (int i = 0; i < 100000; i++)
    v.push_back(i);
  cout << "test07() v������: " << v.capacity() << endl;
  cout << "test07() v�Ĵ�С: " << v.size() << endl;

  v.resize(10);
  cout << "resize���test07() v������: " << v.capacity() << endl;
  cout << "resize���test07() v�Ĵ�С: " << v.size() << endl;

  vector<int>(v).swap(v);
  cout << "ʹ������������л������test07() v������: " << v.capacity()
       << endl; // vector<int>(v)��ʾ�ÿ�������������һ����������,�������������
                // swap����,��ԭv���л���
  cout << "ʹ������������л������test07() v�Ĵ�С: " << v.size() << endl;
}

// vectorԤ���ռ�:����vector�ڶ�̬��չ����ʱ����չ����,ֻԤ�����ڴ�ռ�,
//���ó�ʼֵ��resize()��ͬ
void test08() {
  int num = 0; //ͳ��v�����ڴ�Ĵ���
  int *p = NULL;
  vector<int> v;
  for (int i = 0; i < 100000; i++) {
    v.push_back(i);
    if (p != &v[0]) {
      p = &v[0];
      num++;
    }
  }
  cout << "����" << num << "��,v������100000��Ԫ��������ڴ�ռ�" << endl;
  num = 0;
  p = NULL;
  vector<int> v1;
  v1.reserve(100000);
  for (int i = 0; i < 100000; i++) {
    v1.push_back(i);
    if (p != &v[0]) {
      p = &v[0];
      num++;
    }
  }
  cout << "ʹ��reserve()������" << num << "��,v1������100000��Ԫ��������ڴ�ռ�" << endl;
}


int main() {
  test01();
  cout << "----------------------------------" << endl;
  test02();
  cout << "----------------------------------" << endl;
  test03();
  cout << "----------------------------------" << endl;
  test04();
  cout << "----------------------------------" << endl;
  test05();
  cout << "----------------------------------" << endl;
  test06();
  cout << "----------------------------------" << endl;
  test07();
  cout << "----------------------------------" << endl;
  test08();
  system("pause");
  return 0;
}