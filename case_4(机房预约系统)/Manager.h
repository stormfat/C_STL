#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include <fstream>
#include <algorithm>
#include "Student.h"
#include "Teacher.h"
#include "ComputerRoom.h"

class Manager : public Identity {
public:
  Manager();
  Manager(string name, string pwd);
  
  //ѡ��˵�
  virtual void operMenu();

  //����˺�
  void addPerson();

  //�鿴�˺�
  void showPerson();

  //�鿴������Ϣ
  void showComputer();

  //���ԤԼ��¼
  void cleanFile();

  //��ʼ������
  void initVector();

  //ID�ظ���֤����
  bool checkRepeat(int, int);

  

  //����ѧ���ͽ�ʦ,��������
  vector<Student> vStudent;
  vector<Teacher> vTeacher;
  vector<ComputerRoom> vCom;

};