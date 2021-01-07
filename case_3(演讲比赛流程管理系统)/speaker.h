#pragma once
#include <iostream>
using namespace std;

class Speaker {
public:
  void setName(string);
  void setScore(int,double);
  string getName();
  double getScore(int);

private:
  string m_Name;
  double m_score[2];
};