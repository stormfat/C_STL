/*需求分析:
1.赛制分两轮,第一轮淘汰赛,第二轮决赛
2.12名选手编号从10001-10012
3.分2组,每组6人,第一轮每组选手按抽签顺序演讲
4.十个评委给每个选手打分,去掉最高,最低分后求平均分为选手最后得分
5.淘汰组内排名最后的三名选手
6.第二轮前三名胜出
7.每轮比赛过后需要显示晋级选手的信息*/
#include "speechmanager.h"
#include <iostream>
#include <ctime>
using namespace std;

int main() {
  SpeechManager sp;
  //***********测试选手创建代码块********
  /*for (auto it = sp.m_Speaker.begin(); it != sp.m_Speaker.end(); it++)
    cout << "ID:" << (*it).first << ",name:" << (*it).second.getName()
         << ",分数:" << (*it).second.getScore(0) << endl;*/
  //**********************************
  //随机数种子
  srand((unsigned int)time(0));
  while (true) {
    sp.show_Menu();
    int choice = 0; //存储用户的选择项
    cout << "请输入选项:" << endl;
    cin >> choice;
    switch (choice) {
    case 1: //开始
      sp.startSpeech();
      break;
    case 2: //查看
      sp.showRecord();
      break;
    case 3: //清空
      sp.clearRecord();
      break;
    case 0: //退出
      sp.exitSystem();
      break;
    default:
      system("cls");
      break;
    }
  }
  return 0;
}