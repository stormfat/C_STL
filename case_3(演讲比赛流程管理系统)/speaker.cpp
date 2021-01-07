#include "speaker.h"
using namespace std;

//定义命名方法
void Speaker::setName(string name) { this->m_Name = name; }

//定义打分方法
void Speaker::setScore(int i, double score = 0) { this->m_score[i] = score; }

//定义名字获取方法
string Speaker::getName() { return this->m_Name; }

//获取分数方法
double Speaker::getScore(int i) { return this->m_score[i]; }