#include "speaker.h"
using namespace std;

//������������
void Speaker::setName(string name) { this->m_Name = name; }

//�����ַ���
void Speaker::setScore(int i, double score = 0) { this->m_score[i] = score; }

//�������ֻ�ȡ����
string Speaker::getName() { return this->m_Name; }

//��ȡ��������
double Speaker::getScore(int i) { return this->m_score[i]; }