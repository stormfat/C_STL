#pragma once
#include "Identity.h"
#include "orderFile.h"
#include "ComputerRoom.h"

using namespace std;
#include <iostream>

class Teacher : public Identity {
public:
  Teacher();
  Teacher(int empID, string name, string pwd);
  int getId();
  void setId(int);
  string getName();
  string getPwd();
  void setName(string);
  void setPwd(string);
  virtual void operMenu();
 
  
  //查看所有预约
  void showAllOrder();

  //审核预约
  void validOrder();

private:
  int m_EmpId; //教师编号
};