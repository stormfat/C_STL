#include <algorithm> //sort()
#include <cstdio>    //abort()
#include <cstdio>    //snprintf()
#include <ctime>     //clock()
#include <deque>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;
const long VALUE = 1000000;

int compareStrings(const void *a, const void *b) {
  if (*(string *)a > *(string *)b)
    return 1;
  else if (*(string *)a < *(string *)b)
    return -1;
  else
    return 0;
}

string get_a_target_string() {
  long target = 0;
  char buf[10];
  cout << "輸入要檢索的值(0," << RAND_MAX << "):";
  cin >> target;
  snprintf(buf, 10, "%d", target);
  return string(buf);
}

void test_vector(const long &value) {
  cout << "\nTest_vector()........\n";
  vector<string> c;
  char buf[10];
  clock_t timeStart = clock();
  for (long i = 0; i < value; ++i) {
    try {
      snprintf(
          buf, 10, "%d",
          rand()); //將rand()獲取的隨機數(0-32767),轉換成%d格式,在不大于10個字符的情況下放入buf字符數組中.
      c.push_back(string(buf));
    } catch (exception &p) {
      cout << "i=" << i << " " << p.what() << endl;
      abort();
    }
  }
  cout << "建立vector的時間:" << (clock() - timeStart) << "毫秒" << endl;
  cout << "vector的大小:" << c.size() << endl;
  cout << "vector的第一個元素:" << c.front() << endl;
  cout << "vector的最後一個元素:" << c.back() << endl;
  cout << "vector的内存起始地址:" << c.data() << endl;
  cout << "vector的實際大小:" << c.capacity() << endl;
  string target = get_a_target_string();
  timeStart = clock();
  auto pItem = ::find(c.begin(), c.end(), target);
  cout << "檢索了" << (clock() - timeStart) << "毫秒,";
  if (pItem != c.end())
    cout << "找到了" << *pItem << endl;
  else
    cout << "沒找到!" << endl;
  cout << "vector排序中.....\n";
  timeStart = clock();
  sort(c.begin(), c.end());
  cout << "排序時間:" << (clock() - timeStart) << "毫秒" << endl;
  cout << "bsearch()檢索中.....\n";
  string *pItem1 = (string *)bsearch(&target, (c.data()), c.size(),
                                     sizeof(string), compareStrings);
  if (pItem1 != NULL)
    cout << "找到" << *pItem1 << ",用時" << (clock() - timeStart) << "毫秒"
         << endl;
  else
    cout << "沒有找到,用時" << (clock() - timeStart) << endl;
}

void test_deque(const long &value) {
  cout << "\nTest_deque()........\n";
  deque<string> c;
  char buf[10];
  clock_t timeStart = clock();
  for (long i = 0; i < value; ++i) {
    try {
      snprintf(
          buf, 10, "%d",
          rand()); //將rand()獲取的隨機數(0-32767),轉換成%d格式,在不大于10個字符的情況下放入buf字符數組中.
      c.push_back(string(buf));
    } catch (exception &p) {
      cout << "i=" << i << " " << p.what() << endl;
      abort();
    }
  }
  cout << "建立deque的時間:" << (clock() - timeStart) << "毫秒" << endl;
  cout << "deque的大小:" << c.size() << endl;
  cout << "deque的第一個元素:" << c.front() << endl;
  cout << "deque的最後一個元素:" << c.back() << endl;
  cout << "deque的最大容量:" << c.max_size() << endl;

  string target = get_a_target_string();
  timeStart = clock();
  auto pItem = ::find(c.begin(), c.end(), target);
  cout << "檢索了" << (clock() - timeStart) << "毫秒,";
  if (pItem != c.end())
    cout << "找到了" << *pItem << endl;
  else
    cout << "沒找到!" << endl;
  cout << "deque排序中.....\n";
  timeStart = clock();
  ::sort(c.begin(), c.end());
  cout << "排序時間:" << (clock() - timeStart) << "毫秒" << endl;
}

void test_list(const long &value) {
  cout << "\nTest_list()........\n";
  list<string> c;
  char buf[10];
  clock_t timeStart = clock();
  for (long i = 0; i < value; ++i) {
    try {
      snprintf(
          buf, 10, "%d",
          rand()); //將rand()獲取的隨機數(0-32767),轉換成%d格式,在不大于10個字符的情況下放入buf字符數組中.
      c.push_back(string(buf));
    } catch (exception &p) {
      cout << "i=" << i << " " << p.what() << endl;
      abort();
    }
  }
  cout << "建立list的時間:" << (clock() - timeStart) << "毫秒" << endl;
  cout << "list的大小:" << c.size() << endl;
  cout << "list的第一個元素:" << c.front() << endl;
  cout << "list的最後一個元素:" << c.back() << endl;
  cout << "list的最大容量:" << c.max_size() << endl;

  string target = get_a_target_string();
  timeStart = clock();
  auto pItem = ::find(c.begin(), c.end(), target);
  cout << "檢索了" << (clock() - timeStart) << "毫秒,";
  if (pItem != c.end())
    cout << "找到了" << *pItem << endl;
  else
    cout << "沒找到!" << endl;
  cout << "list排序中.....\n";
  timeStart = clock();
  c.sort();
  cout << "排序時間:" << (clock() - timeStart) << "毫秒" << endl;
}

void test_stack(const long &value) {
  cout << "\nTest_stack()........\n";
  stack<string> c;
  char buf[10];
  clock_t timeStart = clock();
  for (long i = 0; i < value; ++i) {
    try {
      snprintf(
          buf, 10, "%d",
          rand()); //將rand()獲取的隨機數(0-32767),轉換成%d格式,在不大于10個字符的情況下放入buf字符數組中.
      c.push(string(buf));
    } catch (exception &p) {
      cout << "i=" << i << " " << p.what() << endl;
      abort();
    }
  }
  cout << "建立stack的時間:" << (clock() - timeStart) << "毫秒" << endl;
  cout << "stack的大小:" << c.size() << endl;
  cout << "stack的棧頂元素:" << c.top() << endl;
  c.pop();
  cout << "棧頂元素出棧后stack的大小:" << c.size() << endl;
  cout << "目前的棧頂元素:" << c.top() << endl;
}

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
  int n = 1;

  while (n != 0) {
    cout << "\n輸入1測試vector,輸入2測試list,輸入3測試deque,輸入4測試stack,"
            "輸入0退出!";
    cin >> n;
    switch (n) {
    case 1:
      test_vector(VALUE);
      continue;
    case 2:
      test_list(VALUE);
      continue;
    case 3:
      test_deque(VALUE);
      continue;
    case 4:
      test_stack(VALUE);
      continue;
    case 0:
      break;
    default:
      break;
    }
  }
}
