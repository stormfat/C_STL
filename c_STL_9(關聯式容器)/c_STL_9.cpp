#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
const long VALUE = 1000000;

string get_a_target_string() {
  long target = 0;
  char buf[10];
  cout << "ݔ��Ҫ�z����ֵ(0," << RAND_MAX << "):";
  cin >> target;
  snprintf(buf, 10, "%d", target);
  return string(buf);
}

long get_a_target_long() {
  long target = 0;
  cout << "ݔ��Ҫ�z��������ֵ:";
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

  cout << "multiset�����r�g:" << (clock() - timeStart) << endl;
  cout << "multiset.size()" << c.size() << endl;
  cout << "multiset.max_size()" << c.max_size() << endl;

  string target = get_a_target_string();
  {
    timeStart = clock();
    auto pItem =
        ::find(c.begin(), c.end(), target); //��multiset�Ԏ���find�������ܶ�
    cout << "::find()�����z���r�g:" << (clock() - timeStart) << endl;
    if (pItem != c.end())
      cout << "�ҵ�" << *pItem << endl;
    else
      cout << "�]�ҵ�" << endl;
  }

  {
    timeStart = clock();
    auto pItem = c.find(target);
    cout << "multiset.find()�����z���r�g:" << (clock() - timeStart) << endl;
    if (pItem != c.end())
      cout << "�ҵ�" << *pItem << endl;
    else
      cout << "�]�ҵ�" << endl;
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
          i, buf)); // multimapÿһ��Ԫ�ذ���һ������(key)��value(buf)
    } catch (exception &p) {
      cout << "i=" << i << " " << p.what() << endl;
      abort();
    }
  }

  cout << "multimap�����r�g:" << (clock() - timeStart) << endl;
  cout << "multimap.size()" << c.size() << endl;
  cout << "multimap.max_size()" << c.max_size() << endl;

  long target = get_a_target_long();
  {
    timeStart = clock();

    auto pItem = c.find(target); //ͨ�^key�M�Йz��
    cout << "multimap.find()�����z���r�g:" << (clock() - timeStart) << endl;
    if (pItem != c.end())
      cout << "�ҵ�" << (*pItem).second
           << endl; //���ҵ���pItem�Ы@ȡ�ڶ�������,Ҳ����value.
    else
      cout << "�]�ҵ�" << endl;
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
  cout << "unordered_multiset�����r�g:" << (clock() - timeStart) << endl;
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
        ::find(c.begin(), c.end(), target); //��multiset�Ԏ���find�������ܶ�
    cout << "::find()�����z���r�g:" << (clock() - timeStart) << endl;
    if (pItem != c.end())
      cout << "�ҵ�" << *pItem << endl;
    else
      cout << "�]�ҵ�" << endl;
  }

  {
    timeStart = clock();
    auto pItem = c.find(target);
    cout << "unordered_multiset.find()�����z���r�g:" << (clock() - timeStart)
         << endl;
    if (pItem != c.end())
      cout << "�ҵ�" << *pItem << endl;
    else
      cout << "�]�ҵ�" << endl;
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
      c[i] = string(buf); // map�������±꽫key��value����,��multimap����
    } catch (exception &p) {
      cout << "i=" << i << " " << p.what() << endl;
      abort();
    }
  }

  cout << "map�����r�g:" << (clock() - timeStart) << endl;
  cout << "map.size()" << c.size() << endl;
  cout << "map.max_size()" << c.max_size() << endl;

  long target = get_a_target_long();
  {
    timeStart = clock();

    auto pItem = c.find(target); //ͨ�^key�M�Йz��
    cout << "map.find()�����z���r�g:" << (clock() - timeStart) << endl;
    if (pItem != c.end())
      cout << "�ҵ�" << (*pItem).first << "������Ӧ��value:" << (*pItem).second
           << endl; //���ҵ���pItem�Ы@ȡ�ڶ�������,Ҳ����value.
    else
      cout << "�]�ҵ�" << endl;
  }
}

int main() {
  int n = 1;
  while (n != 0) {
    cout << "\nݔ��1�yԇmultiset,ݔ��2�yԇmultimap,ݔ��3�yԇunordered_multiset,"
            "ݔ��4�yԇmap,ݔ��0�˳�!";
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