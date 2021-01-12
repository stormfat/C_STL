#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include "globalFile.h"
using namespace std;

class OrderFile {
public:
  OrderFile();
  
  //����ԤԼ��¼
  void updateOrder();
  
  //��¼������ key--��¼������ value--�����¼�ļ�ֵ����Ϣ
  map<int, map<string, string>> m_orderData;

  //ԤԼ��¼������
  int m_Size;
};