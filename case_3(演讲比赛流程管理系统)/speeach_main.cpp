/*�������:
1.���Ʒ�����,��һ����̭��,�ڶ��־���
2.12��ѡ�ֱ�Ŵ�10001-10012
3.��2��,ÿ��6��,��һ��ÿ��ѡ�ְ���ǩ˳���ݽ�
4.ʮ����ί��ÿ��ѡ�ִ��,ȥ�����,��ͷֺ���ƽ����Ϊѡ�����÷�
5.��̭����������������ѡ��
6.�ڶ���ǰ����ʤ��
7.ÿ�ֱ���������Ҫ��ʾ����ѡ�ֵ���Ϣ*/
#include "speechmanager.h"
#include <iostream>
#include <ctime>
using namespace std;

int main() {
  SpeechManager sp;
  //***********����ѡ�ִ��������********
  /*for (auto it = sp.m_Speaker.begin(); it != sp.m_Speaker.end(); it++)
    cout << "ID:" << (*it).first << ",name:" << (*it).second.getName()
         << ",����:" << (*it).second.getScore(0) << endl;*/
  //**********************************
  //���������
  srand((unsigned int)time(0));
  while (true) {
    sp.show_Menu();
    int choice = 0; //�洢�û���ѡ����
    cout << "������ѡ��:" << endl;
    cin >> choice;
    switch (choice) {
    case 1: //��ʼ
      sp.startSpeech();
      break;
    case 2: //�鿴
      sp.showRecord();
      break;
    case 3: //���
      sp.clearRecord();
      break;
    case 0: //�˳�
      sp.exitSystem();
      break;
    default:
      system("cls");
      break;
    }
  }
  return 0;
}