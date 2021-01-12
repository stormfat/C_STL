#pragma once
//身份基类
#include <fstream>
#include <iostream>
#include <vector>
#include "globalFile.h"
using namespace std;
class Identity {
public:
  virtual void operMenu() = 0; //纯虚函数
  
protected:
  string m_Name;
  string m_Pwd;
};