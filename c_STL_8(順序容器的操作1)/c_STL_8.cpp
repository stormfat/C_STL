#include <deque>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
  vector<int> a;
  list<int> b;
  deque<int> c;
  a.push_back(10);
  a.push_back(20);
  a.push_back(30);

  b.push_back(100);
  b.push_back(200);
  b.push_back(300);

  c.push_back(1);
  c.push_back(2);
  c.push_back(3);

  cout << "使用auto輸出vector a:\t";
  for (auto iter = a.begin(); iter != a.end(); iter++)
    cout << *iter << " "; //用auto甜點自動獲取變量類型,此處為迭代器
  cout << endl;

  vector<int>::size_type a1;
  vector<int>::iterator a2;
  vector<int>::const_iterator a3;
  vector<int>::reverse_iterator a4; //逆序迭代器
  vector<int>::const_reverse_iterator a5;
  // vector<int>::difference_type a6;
  // vector<int>::value_type a7;
  // vector<int>::reference a8;
  // vector<int>::const_reference a9;
  cout << "使用迭代器輸出vector a:\t";
  for (a2 = a.begin(); a2 != a.end(); a2++)
    cout << *a2 << " ";
 
  list<int>::size_type b1;
  list<int>::iterator b2;
  list<int>::const_iterator b3;
  list<int>::reverse_iterator b4; //逆序迭代器
  list<int>::const_reverse_iterator b5;
  // list<int>::difference_type b6;
  // list<int>::value_type b7;
  // list<int>::reference b8;
  // list<int>::const_reference b9;

  deque<int>::size_type c1;
  deque<int>::iterator c2;
  deque<int>::const_iterator c3;
  deque<int>::reverse_iterator c4; //逆序迭代器
  deque<int>::const_reverse_iterator c5;
  // deque<int>::difference_type c6;
  // deque<int>::value_type c7;
  // deque<int>::reference c8;
  // deque<int>::const_reference c9;


  return 0;
}