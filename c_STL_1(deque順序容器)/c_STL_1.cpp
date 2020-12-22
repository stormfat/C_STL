/*�������deque�
1.deque��һ���ӑB���M
2.deque�cvector�ǳ����
3.deque�����ڔ��M�_�^��ĩβ����̈́h������*/

#include <algorithm>
#include <deque>
#include <iostream>
using std::cout;
using std::deque;
using std::endl;
//������ӡ
template <typename T> void printDeque(const deque<T> &de) {
  for (auto it = de.begin(); it != de.end(); it++) {
    size_t num = distance(
        de.begin(),
        it); // distance�㷨����ֵ�酢��2-����1��ֵ.������,�����Ǯ�ǰ��������̖���x��̖һ�Ĳ�ֵ,Ҳ���Ƿ���Ԫ����
    cout << "[" << num << "]=" << *it << "|";
  }
  cout << endl;
  cout << "-----------------------------------------" << endl;
}

// deque�Ĳ����ɾ��
void test01() {
  deque<char> a;     //���K���xһ��deque.
  a.push_back('3');  //���β����
  a.push_front('5'); //����׼���
  a.push_back('a');
  a.push_front('b');
  a.push_front('c');
  cout << "test01()������aԭʼ����: " << endl;
  printDeque(a);
  cout << "test01()������a��β��ɾ��һ��Ԫ�غ��ӡ���: " << endl;
  a.pop_back();
  printDeque(a);
  cout << "test01()������a��ͷ��ɾ��һ��Ԫ�غ��ӡ���: " << endl;
  a.pop_front();
  printDeque(a);

  deque<char> b;
  b.push_back('e');
  b.push_back('f');
  b.push_back('g');
  cout << "test01()������bԭʼ����: " << endl;
  printDeque(b);
  cout << "test01()��Ŀǰa�е�����: " << endl;
  printDeque(a);
  a.insert(a.begin() + 1, b.begin(), b.end());
  cout << "test01()��ִ��\" a.insert(a.begin()+1, b.begin(), b.end()); "
          "\"��a�е�����: "
       << endl;
  printDeque(a);
}

// deque�������
void test02() {
  deque<int> d;
  d.push_back(20);
  d.push_back(10);
  d.push_back(40);
  d.push_back(50);
  d.push_back(100);
  d.push_back(103);
  d.push_back(120);
  d.push_back(70);
  cout << "test02()������d��ԭʼ����: " << endl;
  printDeque(d);
  sort(d.begin(), d.end());//sort()������֧�����������������,��vector��deque
  cout << "test02()������d�������������: " << endl;
  printDeque(d);
}

int main() {
  test01();
  cout << endl;
  cout << endl;
  test02();
  system("pause");

  return 0;
}