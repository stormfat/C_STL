/*vector主要接口:
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

//几种构造方式
void test01() {
  vector<int> v; //向容器中插入数据
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);
  cout << "开始打印V: " << endl;
  ;
  printVector(v);

  //用某个vector容器的范围进行构造
  vector<int> v2(v.begin(), v.end());
  v2.push_back(40);
  cout << "开始打印V2: " << endl;
  ;
  printVector(v2);

  // n个elem方式进行构造
  vector<char> v3(10, 'a');
  cout << "开始打印V3: " << endl;
  ;
  printVector(v3);

  //拷贝构造方式
  vector<int> v4(v2);
  cout << "开始打印V4: " << endl;
  printVector(v4);
}

//容器嵌套
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
  //将小容器插入大容器中
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

// vector赋值
void test03() {
  vector<int> v1;
  for (int i = 10; i < 20; i++)
    v1.push_back(i);
  vector<int> v2;
  //用operator=赋值重载方式对v2赋值
  v2 = v1;
  cout << "V2:" << endl;
  printVector(v2);

  //用assign方法赋值
  vector<int> v3;
  v3.assign(v1.begin(), v1.end());
  cout << "v3:" << endl;
  printVector(v3);

  // n个elem方式赋值
  vector<int> v4;
  v4.assign(10, 10);
  cout << "v4: " << endl;
  printVector(v4);
}

// vector的删除和插入
void test04() {
  vector<int> v;
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);
  v.push_back(40);
  v.push_back(50);

  cout << "正在打印test04()v: " << endl;
  printVector(v);

  v.pop_back();
  cout << "正在打印pop后的test04()v: " << endl;
  printVector(v);

  v.insert(v.begin(), 3, 1000);
  cout << "正在打印insert后的test04()v: " << endl;
  printVector(v);

  v.erase(v.begin(), v.begin() + 1);
  cout << "正在打印erase后的test04()v: " << endl;
  printVector(v);

  v.clear();
  cout << "正在打印clear后的test04()v: " << endl;
}

// vector数据存取
void test05() {
  vector<int> v;
  for (int i = 0; i < 10; i++)
    v.push_back(i);
  //用at方式遍历
  cout << "用at方式遍历test05()v: " << endl;
  for (int i = 0; i < v.size(); i++)
    cout << v.at(i) << " ";
  cout << endl;
  //获取第一个元素
  cout << "第一个元素:" << v.front() << endl;
  //获取最后一个元素
  cout << "最后一个元素:" << v.back() << endl;
}

// vector swap实现元素互换,swap()互换的是其引用地址.
void test06() {
  vector<int> v1, v2;
  for (int i = 0; i < 10; i++)
    v1.push_back(i);
  for (int i = 9; i >= 0; i--)
    v2.push_back(i);
  cout << "正在打印互换前的test06() v1: " << endl;
  printVector(v1);
  cout << "正在打印互换前test06() v2: " << endl;
  printVector(v2);
  v1.swap(v2);
  cout << "正在打印互换后的test06() v1: " << endl;
  printVector(v1);
  cout << "正在打印互换后test06() v2: " << endl;
  printVector(v2);
}

//巧用swap收缩内存空间
void test07() {
  vector<int> v;
  for (int i = 0; i < 100000; i++)
    v.push_back(i);
  cout << "test07() v的容量: " << v.capacity() << endl;
  cout << "test07() v的大小: " << v.size() << endl;

  v.resize(10);
  cout << "resize后的test07() v的容量: " << v.capacity() << endl;
  cout << "resize后的test07() v的大小: " << v.size() << endl;

  vector<int>(v).swap(v);
  cout << "使用匿名对象进行互换后的test07() v的容量: " << v.capacity()
       << endl; // vector<int>(v)表示用拷贝构造声明了一个匿名对象,再用匿名对象的
                // swap方法,和原v进行互换
  cout << "使用匿名对象进行互换后的test07() v的大小: " << v.size() << endl;
}

// vector预留空间:减少vector在动态扩展容量时的扩展次数,只预分配内存空间,
//不置初始值和resize()不同
void test08() {
  int num = 0; //统计v开辟内存的次数
  int *p = NULL;
  vector<int> v;
  for (int i = 0; i < 100000; i++) {
    v.push_back(i);
    if (p != &v[0]) {
      p = &v[0];
      num++;
    }
  }
  cout << "用了" << num << "次,v开辟了100000个元素所需的内存空间" << endl;
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
  cout << "使用reserve()后用了" << num << "次,v1开辟了100000个元素所需的内存空间" << endl;
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