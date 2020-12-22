#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
/*设计5名选手,10个评委分别对每个选手打分,去除最高分,最低分,取平均分输出*/

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
    string name = "选手";
    name += nameSeed[i];
    int score = 0;
    Person p(name, score);
    v.push_back(p);
  }
}

//打分
void setScore(vector<Person> &v) {
  for (auto it = v.begin(); it != v.end(); it++) {
    deque<int> dScore;
    for (int i = 0; i < 10; i++) {
      int score = rand() % 41 + 60; //取60~100的随机数
      dScore.push_back(score);
    }
    cout << (*it).getName() << "评委评分分别为: " << endl;
    for (auto it = dScore.begin(); it != dScore.end(); it++) {
      cout << *it << "  ";
    }
    cout << endl;
    sort(dScore.begin(), dScore.end());
    cout << "去掉一个最高分: " << *(dScore.end() - 1) << endl;

    dScore.pop_back(); //去掉最高分
    cout << "去掉一个最低分: " << *dScore.begin() << endl;
    dScore.pop_front(); //去掉最低分
    int sumScore = 0;
    for (auto it = dScore.begin(); it != dScore.end(); it++) {
      sumScore += *it; //求总分
    }
    int avgScore = sumScore / dScore.size(); //求平均分
    //cout << (*it).getName() << "的平均分是: " << avgScore << endl;
    cout << endl;
    (*it).setScore(avgScore);
  }
  
}

//显示选手得分
void showScore(vector<Person> &v) {
  for (auto it = v.begin(); it != v.end(); it++)
    cout << (*it).getName() << "最后得分为: " << (*it).getScore() << endl;
}

void test(vector<Person> &v) { //测试
  for (auto it = v.begin(); it != v.end(); it++)
    cout << "姓名: " << (*it).getName() << ",分数: " << (*it).getScore()
         << endl;
}

int main() {
  srand((unsigned int)time(NULL));
  // 1.创建5名选手
  vector<Person> vPerson;
  createPerson(vPerson);
  setScore(vPerson);
  showScore(vPerson);
  //测试选手vector是否建立成功
  // test(vPerson);

  return 0;
}