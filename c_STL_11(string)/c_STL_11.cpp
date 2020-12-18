/*字符串string学习:string本质是类
构建方法:
1.string()
2.string(const char* s)
3.string(const string& str)
4.string(int n,char c)
*/
#include <iostream>
#include <string>
using namespace std;

//字符串查找
void test01() {
  string str1 = "abcdefgde";
  int pos = str1.find("de");
  if (pos == -1)
    cout << "未找到字符串" << endl;
  else
    cout << "从左起位置为: " << pos << endl;
  // rfind为从right开始找
  pos = str1.rfind("de");
  if (pos == -1)
    cout << "未找到字符串" << endl;
  else
    cout << "从右起位置为: " << pos << endl;
}

//字符串替换
void test02() {
  string str1 = "abcdef";
  //从参数1起参数2个字符替换为参数3
  str1.replace(2, 2, "1111");
  cout << "str1: " << str1 << endl;
}

//字符串比较
void test03() {
  string str1 = "xello1";
  string str2 = "helloa";
  if (str1.compare(str2) == 0)
    cout << "str1等于str2" << endl;
  else if (str1.compare(str2) > 0)
    cout << "str1大于str2" << endl;
  else
    cout << "str1小于str2" << endl;
}

//字符串存取
void test04() {
  string str = "hello";
  //通过[]方式访问单个字符
  for (size_t i = 0; i < str.length(); i++)
    cout << str[i] << " ";
  cout << endl;
  //通过at方式访问单个字符
  for (size_t i = 0; i < str.length(); i++)
    cout << str.at(i) << " ";
  cout << endl;
  //修改单个字符
  str.at(0) = 'c';
  str[2] = 'b';
  cout << str << endl;
}

//字符串插入和删除
void test05() {
  string str = "hello";
  str.insert(1, "000");
  cout << str << endl; // h000ello
  str.erase(1, 2);
  cout << str << endl; // h0ello
}

//字符串截取
void test06() {
  string str = "abcdef";
  string subStr = str.substr(1, 3); // bcd
  cout << subStr << endl;
}

//综合应用:输入一个电子邮件,从中获取用户名
void test07() {
  cout << "输入你的电子邮件地址: " << endl;
  string email;
  cin >> email;
  int pos = email.find("@");
  if (pos == -1)
    cout << "无效的电子邮件格式!" << endl;
  else {
    string subStr = email.substr(0, pos);
    cout << subStr << endl;
  }
}

int main() {
  test02();
  test01();
  test03();
  test04();
  test05();
  test06();
  test07();
  system("pause");
  return 0;
}