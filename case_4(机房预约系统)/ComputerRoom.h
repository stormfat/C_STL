#pragma once
#include <iostream>
using namespace std;

class ComputerRoom {
public:
  ComputerRoom() {}
  int getComId() { return this->m_ComId; }
  int getMaxNum() { return this->m_MaxNum; }
  void setComId(int fid) { this->m_ComId = fid; }
  void setMaxnum(int fnum) { this->m_MaxNum = fnum; }

private:
  int m_ComId;  //机房ID
  int m_MaxNum; //机房最大容量
};