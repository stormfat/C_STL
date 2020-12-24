/*�W������
1.��list�_�^����Ԫ��
2.��listĩβ����Ԫ��
3.��list���g����Ԫ��
4.�h��list�е�Ԫ��
5.��list��Ԫ���M�з��D������
6.List������֧��������ʵ�����,������Ծʽ����*/

#include <algorithm> //Ϊ��ʹ��distance()�㷨
#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std::list;
using std::string;

class Person {
public:
  Person(string name, int age, int height)
      : m_Name(name), m_Age(age), m_Height(height) {}
  string getName() { return this->m_Name; }
  int getAge() { return m_Age; }
  int getHeight() { return m_Height; }

private:
  string m_Name;
  int m_Age;
  int m_Height;
};

// Person�����ӡ����
void PrintListPerson(list<Person> &lperson) {
  for (auto it = lperson.begin(); it != lperson.end(); it++)
    cout << "����:" << (*it).getName() << ", ����:" << (*it).getAge()
         << ", ���:" << (*it).getHeight() << endl;
}

//��������
bool comparePerson(Person &p1, Person &p2) { //��������������,���������ͬ����߽���
  if (p1.getAge() == p2.getAge())
    return p1.getHeight() > p2.getHeight();
  else
    return p1.getAge() < p2.getAge();
}

//������,���Զ������ͽ�������
void test02() {
  list<Person> lPerson; // ��������

  Person p1("����", 35, 175);
  Person p2("�ܲ�", 45, 165);
  Person p3("��Ȩ", 40, 170);
  Person p4("����", 25, 190);
  Person p5("�ŷ�", 35, 175);
  Person p6("����", 35, 195);

  lPerson.push_back(p1);
  lPerson.push_back(p2);
  lPerson.push_back(p3);
  lPerson.push_back(p4);
  lPerson.push_back(p5);
  lPerson.push_back(p6);
  cout << "-----------����ǰ:-----------" << endl;
  PrintListPerson(lPerson);
  cout << endl;
  cout << "---------- �����------------" << endl;
  lPerson.sort(comparePerson);
  PrintListPerson(lPerson);
}

template <typename T> void PrintListContent(list<T> &listInput) {
  cout << endl;
  for (auto iter = listInput.begin(); iter != listInput.end(); iter++) {
    size_t num = distance(listInput.begin(), iter);
    cout << "[" << num << "]=" << *iter << endl;
  }
}
void test01() {
  list<int>::iterator iter;
  list<int> a;
  list<int> b;
  b.push_back(100);
  b.push_back(200);
  b.push_back(300);
  b.push_back(400);
  b.push_back(500);

  a.push_back(10);
  a.push_front(2001);
  a.push_front(-1);
  a.push_front(9999);
  a.push_back(8989);
  iter = a.begin();
  iter++;
  a.insert(iter, 3, 7); //�ڵ�����λ��ǰ����3��7;
  PrintListContent(a);
  iter++;
  a.erase(a.begin(),
          iter); //�h����begin()����ǰ������λ��(��������ǰλ��)������Ԫ��
  PrintListContent(a);

  /* for (iter = a.begin(); iter != a.end(); iter++) {
     size_t num = distance(a.begin(), iter);
     cout << "a[" << num << "]=" << *iter << endl;
   }*/
  PrintListContent(b);
  list<int>::iterator iter2;
  iter2 = b.begin();
  iter2++;

  b.erase(iter2);
  PrintListContent(b);
  cout << endl;
  a.insert(a.begin(), ++b.begin(), --b.end());
  PrintListContent(a);
  a.sort();    //���򺯔�
  a.reverse(); //���D����
  cout << "�������ٷ��D��";
  PrintListContent(a);
}

int main() {
  // test01();
  test02();

  return 0;
}
