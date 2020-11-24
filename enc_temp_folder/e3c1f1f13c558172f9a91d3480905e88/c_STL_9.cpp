#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
const long VALUE = 1000000;

string get_a_target_string() {
  long target = 0;
  char buf[10];
  cout << "輸入要檢索的值(0," << RAND_MAX << "):";
  cin >> target;
  snprintf(buf, 10, "%d", target);
  return string(buf);
}

long get_a_target_long() {
  long target = 0;
  cout << "輸入要檢索的索引值:";
  cin >> target;
  return target;
}

void test_multiset(const long &value) {
  cout << "\ntest_multiset()......\n";
  multiset<string> c;
  char buf[10];
  clock_t timeStart = clock();
  for (long i = 0; i < value; ++i) {
    try {
      snprintf(buf, 10, "%d", rand());
      c.insert(string(buf));
    } catch (exception &p) {
      cout << "i=" << i << " " << p.what() << endl;
      abort();
    }
  }

  cout << "multiset構建時間:" << (clock() - timeStart) << endl;
  cout << "multiset.size()" << c.size() << endl;
  cout << "multiset.max_size()" << c.max_size() << endl;

  string target = get_a_target_string();
  {
    timeStart = clock();
    auto pItem =
        ::find(c.begin(), c.end(), target); //比multiset自帶的find函數慢很多
    cout << "::find()函數檢索時間:" << (clock() - timeStart) << endl;
    if (pItem != c.end())
      cout << "找到" << *pItem << endl;
    else
      cout << "沒找到" << endl;
  }

  {
    timeStart = clock();
    auto pItem = c.find(target);
    cout << "multiset.find()函數檢索時間:" << (clock() - timeStart) << endl;
    if (pItem != c.end())
      cout << "找到" << *pItem << endl;
    else
      cout << "沒找到" << endl;
  }
}

void test_multimap(const long &value) {
  cout << "\ntest_multimap()......\n";
  multimap<long, string> c;
  char buf[10];
  clock_t timeStart = clock();
  for (long i = 0; i < value; ++i) {
    try {
      snprintf(buf, 10, "%d", rand());
      c.insert(pair<long, string>(
          i, buf)); // multimap每一個元素包括一個索引(key)及value(buf)
    } catch (exception &p) {
      cout << "i=" << i << " " << p.what() << endl;
      abort();
    }
  }

  cout << "multimap構建時間:" << (clock() - timeStart) << endl;
  cout << "multimap.size()" << c.size() << endl;
  cout << "multimap.max_size()" << c.max_size() << endl;

  long target = get_a_target_long();
  {
    timeStart = clock();

    auto pItem = c.find(target); //通過key進行檢索
    cout << "multimap.find()函數檢索時間:" << (clock() - timeStart) << endl;
    if (pItem != c.end())
      cout << "找到" << (*pItem).second
           << endl; //從找到的pItem中獲取第二個參數,也就是value.
    else
      cout << "沒找到" << endl;
  }
}

void test_unordered_multiset(const long &value) {
  cout << "\ntest_unordered_multiset().......\n";
  unordered_multiset<string> c;
  char buf[10];
  clock_t timeStart = clock();
  for (long i = 0; i < value; ++i) {
    try {
      snprintf(buf, 10, "%d", rand());
      c.insert(string(buf));
    } catch (exception &p) {
      cout << "i=" << i << " " << p.what() << endl;
      abort();
    }
  }
  cout << "unordered_multiset構建時間:" << (clock() - timeStart) << endl;
  cout << "unordered_multiset.size()" << c.size() << endl;
  cout << "unordered_multiset.max_size()" << c.max_size() << endl;
  cout << "unordered_multiset.bucket_count()" << c.bucket_count() << endl;
  cout << "unordered_multiset.load_factor()" << c.load_factor() << endl;
  cout << "unordered_multiset.max_load_factor()=" << c.max_load_factor()
       << endl;
  cout << "unordered_multiset.max_bucket_count()=" << c.max_bucket_count()
       << endl;
  for (unsigned i = 0; i < 20; ++i)
    cout << "bucket #" << i << " has " << c.bucket_size(i) << " elements.\n";

  string target = get_a_target_string();
  {
    timeStart = clock();
    auto pItem =
        ::find(c.begin(), c.end(), target); //比multiset自帶的find函數慢很多
    cout << "::find()函數檢索時間:" << (clock() - timeStart) << endl;
    if (pItem != c.end())
      cout << "找到" << *pItem << endl;
    else
      cout << "沒找到" << endl;
  }

  {
    timeStart = clock();
    auto pItem = c.find(target);
    cout << "unordered_multiset.find()函數檢索時間:" << (clock() - timeStart)
         << endl;
    if (pItem != c.end())
      cout << "找到" << *pItem << endl;
    else
      cout << "沒找到" << endl;
  }
}

void test_map(const long &value) {
  cout << "\ntest_map()......\n";
  map<long, string> c;
  char buf[10];

  clock_t timeStart = clock();
  for (long i = 0; i < value; ++i) {
    try {
      snprintf(buf, 10, "%d", rand());
      c[i] = string(buf); // map可以用下标将key和value关联,而multimap不行
                          //,因为map的value不可重复
    } catch (exception &p) {
      cout << "i=" << i << " " << p.what() << endl;
      abort();
    }
  }

  cout << "map構建時間:" << (clock() - timeStart) << endl;
  cout << "map.size()" << c.size() << endl;
  cout << "map.max_size()" << c.max_size() << endl;

  long target = get_a_target_long();
  {
    timeStart = clock();

    auto pItem = c.find(target); //通過key進行檢索
    cout << "map.find()函數檢索時間:" << (clock() - timeStart) << endl;
    if (pItem != c.end())
      cout << "找到" << (*pItem).first << "索引对应的value:" << (*pItem).second
           << endl; //從找到的pItem中獲取第二個參數,也就是value.
    else
      cout << "沒找到" << endl;
  }
}

int main() {
  int n = 1;
  while (n != 0) {
    cout << "\n輸入1測試multiset,輸入2測試multimap,輸入3測試unordered_multiset,"
            "輸入4測試map,輸入0退出!";
    cin >> n;
    switch (n) {
    case 1:
      test_multiset(VALUE);
      continue;
    case 2:
      test_multimap(VALUE);
      continue;
    case 3:
      test_unordered_multiset(VALUE);
      continue;
    case 4:
      test_map(VALUE);
      continue;
    case 0:
      break;
    default:
      break;
    }
  }
}