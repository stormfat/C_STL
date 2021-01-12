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
  
  //选择菜单
  virtual void operMenu();

  //添加账号
  void addPerson();

  //查看账号
  void showPerson();

  //查看机房信息
  void showComputer();

  //清空预约记录
  void cleanFile();

  //初始化容器
  void initVector();

  //ID重复验证方法
  bool checkRepeat(int, int);

  

  //建立学生和教师,机房容器
  vector<Student> vStudent;
  vector<Teacher> vTeacher;
  vector<ComputerRoom> vCom;

};