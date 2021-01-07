#pragma once
#include "speaker.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//设计演讲管理类
class SpeechManager {
public:
  SpeechManager();
  ~SpeechManager();

  //初始化容器和属性
  void initSpeech();

  //菜单功能
  void show_Menu();

  //退出程序
  void exitSystem();

  //创建选手
  void createSpeaker();

  //开始比赛
  void startSpeech();

  //抽签方法
  void speechDraw();

  //比赛方法
  void speechContes();

  //显示比赛分数
  void showScore();

  //保存记录方法
  void saveRecord();

  //查看记录
  void loadRecord();

  //显示往届得分
  void showRecord();

  //清空记录
  void clearRecord();

  //保存各轮比赛选手编号容器
  vector<int> v1;       //所有比赛选手 12人
  vector<int> v2;       //第一轮晋级者 6人
  vector<int> vVictory; //决赛前三名 3人

  //存放编号及选手名称,使用map容器.
  map<int, Speaker> m_Speaker;

  //存放比赛论数
  int m_Index;
  //标记文件是否为空
  bool fileIsEmpty;
  //往届记录
  map<int, vector<string>> m_Record;
};
