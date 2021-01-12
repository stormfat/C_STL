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

  
  //菜单界面
  virtual void operMenu();

  //预约申请
  void applyOrder();

  //查看自己的预约
  void showMyOrder();

  //查看所有预约
  void showAllOrder();

  //取消预约
  void cancalOrder();

  vector<ComputerRoom> vCom;

private:
  int m_Id;
};