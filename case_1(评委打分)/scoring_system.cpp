#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
/*���5��ѡ��,10����ί�ֱ��ÿ��ѡ�ִ��,ȥ����߷�,��ͷ�,ȡƽ�������*/

class Person {
public:
  Person(string name, int score) : m_Name(name), m_Score(score) {}
  string getName() { return m_Name; }
  int getScore() { return m_Score; }
  void setScore(int score) { m_Score = score; }

private:
  string m_Name;
  int m_Score;
};

void createPerson(vector<Person> &v) {
  string nameSeed = "ABCDE";
  for (size_t i = 0; i < 5; i++) {
    string name = "ѡ��";
    name += nameSeed[i];
    int score = 0;
    Person p(name, score);
    v.push_back(p);
  }
}

//���
void setScore(vector<Person> &v) {
  for (auto it = v.begin(); it != v.end(); it++) {
    deque<int> dScore;
    for (int i = 0; i < 10; i++) {
      int score = rand() % 41 + 60; //ȡ60~100�������
      dScore.push_back(score);
    }
    cout << (*it).getName() << "��ί���ֱַ�Ϊ: " << endl;
    for (auto it = dScore.begin(); it != dScore.end(); it++) {
      cout << *it << "  ";
    }
    cout << endl;
    sort(dScore.begin(), dScore.end());
    cout << "ȥ��һ����߷�: " << *(dScore.end() - 1) << endl;

    dScore.pop_back(); //ȥ����߷�
    cout << "ȥ��һ����ͷ�: " << *dScore.begin() << endl;
    dScore.pop_front(); //ȥ����ͷ�
    int sumScore = 0;
    for (auto it = dScore.begin(); it != dScore.end(); it++) {
      sumScore += *it; //���ܷ�
    }
    int avgScore = sumScore / dScore.size(); //��ƽ����
    //cout << (*it).getName() << "��ƽ������: " << avgScore << endl;
    cout << endl;
    (*it).setScore(avgScore);
  }
  
}

//��ʾѡ�ֵ÷�
void showScore(vector<Person> &v) {
  for (auto it = v.begin(); it != v.end(); it++)
    cout << (*it).getName() << "���÷�Ϊ: " << (*it).getScore() << endl;
}

void test(vector<Person> &v) { //����
  for (auto it = v.begin(); it != v.end(); it++)
    cout << "����: " << (*it).getName() << ",����: " << (*it).getScore()
         << endl;
}

int main() {
  srand((unsigned int)time(NULL));
  // 1.����5��ѡ��
  vector<Person> vPerson;
  createPerson(vPerson);
  setScore(vPerson);
  showScore(vPerson);
  //����ѡ��vector�Ƿ����ɹ�
  // test(vPerson);

  return 0;
}