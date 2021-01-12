#include "Teacher.h"

Teacher::Teacher() {}

Teacher::Teacher(int empID, string name, string pwd) {
  this->m_EmpId = empID;
  this->m_Name = name;
  this->m_Pwd = pwd;
}

void Teacher::setId(int id) { this->m_EmpId = id; }
int Teacher::getId() { return this->m_EmpId; }
void Teacher::setName(string name) { this->m_Name = name; }
void Teacher::setPwd(string pwd) { this->m_Pwd = pwd; }
string Teacher::getName() { return this->m_Name; }
string Teacher::getPwd() { return this->m_Pwd; }

void Teacher::operMenu() {
  cout << "��ӭ: " << this->m_Name << "��¼!" << endl;
  cout << "\t\t---------------------------------\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           1.�鿴ԤԼ           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           2.���ԤԼ           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           0.ע����¼           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t---------------------------------\n";
  cout << "��ѡ�����: " << endl;
}

//�鿴����ԤԼ
void Teacher::showAllOrder() {
  OrderFile of;
  if (of.m_Size == 0) {
    cout << "��ԤԼ��¼" << endl;
    system("pause");
    system("cls");
    return;
  }
  for (int i = 0; i < of.m_Size; i++) {
    cout << "��" << i + 1 << "����¼:" << endl;
    cout << "ѧ��:" << of.m_orderData[i]["stuId"] << " ";
    cout << "����:" << of.m_orderData[i]["stuName"] << " ";
    cout << "ԤԼ����:��" << of.m_orderData[i]["date"] << " ";
    cout << "ʱ��:" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����")
         << " ";
    cout << of.m_orderData[i]["roomId"] << "�Ż���"
         << " ";
    string status = "״̬:";
    if (of.m_orderData[i]["status"] == "1")
      status += "�����...";
    else if (of.m_orderData[i]["status"] == "2")
      status += "��ԤԼ";
    else if (of.m_orderData[i]["status"] == "-1")
      status += "ԤԼʧ��";
    else if (of.m_orderData[i]["status"] == "0")
      status += "��ȡ��";
    cout << status << endl;
  }
  system("pause");
  system("cls");
}

//���ԤԼ
void Teacher::validOrder() {
  OrderFile of;
  if (of.m_Size == 0) {
    cout << "��ԤԼ��¼" << endl;
    system("pause");
    system("cls");
    return;
  }
  cout << "����˵�ԤԼ��¼����: " << endl;
  vector<int> v;
  int index = 1;
  for (int i = 0; i < of.m_Size; i++) {
    if (of.m_orderData[i]["status"] == "1") {
      //�������������±����v��.����ȡ��ԤԼʱ��ȡ��Orderfile�еļ�¼
      v.push_back(i);
      cout << index++ << ". ";
      cout << "ѧ��:" << of.m_orderData[i]["stuId"];
      cout << " ����:" << of.m_orderData[i]["stuName"];
      cout << " ԤԼ����:��" << of.m_orderData[i]["date"];
      cout << " ʱ��:"
           << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
      cout << " " << of.m_orderData[i]["roomId"] << "�Ż���";
      string status = " ״̬:";
      if (of.m_orderData[i]["status"] == "1")
        status += "�����...";
      cout << status << endl;
    }
  }
  cout << "������Ҫ��˵ļ�¼��,0������" << endl;
  size_t select = 0;
  int ret = 0;
  while (true) {
    cin >> select;
    if (select >= 0 && select <= v.size()) {
      if (select == 0)
        break;
      else {
        cout << "��������˽��" << endl;
        cout << "1.ͨ��" << endl;
        cout << "2.��ͨ��" << endl;
        cin >> ret;
        if (ret == 1)
          of.m_orderData[v[select - 1]]["status"] = "2";
        else
          of.m_orderData[v[select - 1]]["status"] = "-1";
        of.updateOrder();
        cout << "������" << endl;
        break;
      }
    }
    cout << "��������,����������" << endl;
  }
  system("pause");
  system("cls");
}