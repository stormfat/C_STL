#pragma once
//��ݻ���
#include <fstream>
#include <iostream>
#include <vector>
#include "globalFile.h"
using namespace std;
class Identity {
public:
  virtual void operMenu() = 0; //���麯��
  
protected:
  string m_Name;
  string m_Pwd;
};