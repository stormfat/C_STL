#pragma once
#include "speaker.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//����ݽ�������
class SpeechManager {
public:
  SpeechManager();
  ~SpeechManager();

  //��ʼ������������
  void initSpeech();

  //�˵�����
  void show_Menu();

  //�˳�����
  void exitSystem();

  //����ѡ��
  void createSpeaker();

  //��ʼ����
  void startSpeech();

  //��ǩ����
  void speechDraw();

  //��������
  void speechContes();

  //��ʾ��������
  void showScore();

  //�����¼����
  void saveRecord();

  //�鿴��¼
  void loadRecord();

  //��ʾ����÷�
  void showRecord();

  //��ռ�¼
  void clearRecord();

  //������ֱ���ѡ�ֱ������
  vector<int> v1;       //���б���ѡ�� 12��
  vector<int> v2;       //��һ�ֽ����� 6��
  vector<int> vVictory; //����ǰ���� 3��

  //��ű�ż�ѡ������,ʹ��map����.
  map<int, Speaker> m_Speaker;

  //��ű�������
  int m_Index;
  //����ļ��Ƿ�Ϊ��
  bool fileIsEmpty;
  //�����¼
  map<int, vector<string>> m_Record;
};
