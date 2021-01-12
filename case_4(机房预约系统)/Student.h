#pragma once
#include "Identity.h"
#include <iostream>
using namespace std;
#include "ComputerRoom.h"

class Student : public Identity {
public:
  Student();
  Student(int id, string name, string pwd);
  void setId(int);
  int getId();
  void setName(string);
  void setPwd(string);
  string getName();
  string getPwd();

  
  //�˵�����
  virtual void operMenu();

  //ԤԼ����
  void applyOrder();

  //�鿴�Լ���ԤԼ
  void showMyOrder();

  //�鿴����ԤԼ
  void showAllOrder();

  //ȡ��ԤԼ
  void cancalOrder();

  vector<ComputerRoom> vCom;

private:
  int m_Id;
};