/*�ַ���stringѧϰ:string��������
��������:
1.string()
2.string(const char* s)
3.string(const string& str)
4.string(int n,char c)
*/
#include <iostream>
#include <string>
using namespace std;

//�ַ�������
void test01() {
  string str1 = "abcdefgde";
  int pos = str1.find("de");
  if (pos == -1)
    cout << "δ�ҵ��ַ���" << endl;
  else
    cout << "������λ��Ϊ: " << pos << endl;
  // rfindΪ��right��ʼ��
  pos = str1.rfind("de");
  if (pos == -1)
    cout << "δ�ҵ��ַ���" << endl;
  else
    cout << "������λ��Ϊ: " << pos << endl;
}

//�ַ����滻
void test02() {
  string str1 = "abcdef";
  //�Ӳ���1�����2���ַ��滻Ϊ����3
  str1.replace(2, 2, "1111");
  cout << "str1: " << str1 << endl;
}

//�ַ����Ƚ�
void test03() {
  string str1 = "xello1";
  string str2 = "helloa";
  if (str1.compare(str2) == 0)
    cout << "str1����str2" << endl;
  else if (str1.compare(str2) > 0)
    cout << "str1����str2" << endl;
  else
    cout << "str1С��str2" << endl;
}

//�ַ�����ȡ
void test04() {
  string str = "hello";
  //ͨ��[]��ʽ���ʵ����ַ�
  for (size_t i = 0; i < str.length(); i++)
    cout << str[i] << " ";
  cout << endl;
  //ͨ��at��ʽ���ʵ����ַ�
  for (size_t i = 0; i < str.length(); i++)
    cout << str.at(i) << " ";
  cout << endl;
  //�޸ĵ����ַ�
  str.at(0) = 'c';
  str[2] = 'b';
  cout << str << endl;
}

//�ַ��������ɾ��
void test05() {
  string str = "hello";
  str.insert(1, "000");
  cout << str << endl; // h000ello
  str.erase(1, 2);
  cout << str << endl; // h0ello
}

//�ַ�����ȡ
void test06() {
  string str = "abcdef";
  string subStr = str.substr(1, 3); // bcd
  cout << subStr << endl;
}

//�ۺ�Ӧ��:����һ�������ʼ�,���л�ȡ�û���
void test07() {
  cout << "������ĵ����ʼ���ַ: " << endl;
  string email;
  cin >> email;
  int pos = email.find("@");
  if (pos == -1)
    cout << "��Ч�ĵ����ʼ���ʽ!" << endl;
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