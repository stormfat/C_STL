#include "Student.h"
#include "orderFile.h"

Student::Student() {}
Student::Student(int id, string name, string pwd) {
  this->m_Id = id;
  this->m_Name = name;
  this->m_Pwd = pwd;

  //��ʼ��������Ϣ
  ifstream ifs;
  ifs.open(COMPUTER_FILE, ios::in);
  ComputerRoom c;
  int fid;
  int fnum;
  while (ifs >> fid && ifs >> fnum) {
    c.setComId(fid);
    c.setMaxnum(fnum);
    vCom.push_back(c);
  }
  ifs.close();
}

//ѡ��˵�
void Student::operMenu() {
  cout << "��ӭ: " << this->m_Name << "��¼!" << endl;
  cout << "\t\t---------------------------------\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           1.����ԤԼ           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           2.�鿴ԤԼ           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           3.����ԤԼ           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           4.ȡ��ԤԼ           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           0.ע����¼           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t---------------------------------\n";
  cout << "��ѡ�����: " << endl;
}

void Student::setId(int id) { this->m_Id = id; }
int Student ::getId() { return this->m_Id; }
void Student::setName(string name) { this->m_Name = name; }
void Student::setPwd(string pwd) { this->m_Pwd = pwd; }
string Student::getName() { return this->m_Name; }
string Student::getPwd() { return this->m_Pwd; }

//ԤԼ����
void Student::applyOrder() {
  cout << "��������ʱ��Ϊ��һ������!" << endl;
  cout << "����������ԤԼ��ʱ��:" << endl;
  cout << "1.��һ" << endl;
  cout << "2.�ܶ�" << endl;
  cout << "3.����" << endl;
  cout << "4.����" << endl;
  cout << "5.����" << endl;
  int date = 0;
  int interval = 0;
  int room = 0;

  while (true) {
    cin >> date;
    if (date >= 1 && date <= 5)
      break;
    cout << "��������,����������" << endl;
  }

  cout << "����������ԤԼ��ʱ���:" << endl;
  cout << "1.����" << endl;
  cout << "2.����" << endl;
  while (true) {
    cin >> interval;
    if (interval == 1 || interval == 2)
      break;
    cout << "��������,����������" << endl;
  }

  cout << "��ѡ�����:" << endl;
  for (size_t i = 0; i < vCom.size(); i++)
    cout << vCom[i].getComId() << "�Ż�������Ϊ:" << vCom[i].getMaxNum()
         << endl;
  while (true) {
    cin >> room;
    if (room >= 1 && room <= 3)
      break;
    cout << "��������,����������" << endl;
  }
  cout << "ԤԼ�ɹ�,�����...." << endl;
  ofstream ofs;
  ofs.open(ORDER_FILE, ios::app);
  ofs << "date:" << date << " ";
  ofs << "interval:" << interval << " ";
  ofs << "stuId:" << this->getId() << " ";
  ofs << "stuName:" << this->getName() << " ";
  ofs << "roomId:" << room << " ";
  ofs << "status:" << 1 << endl;
  ofs.close();
  system("pause");
  system("cls");
}

//�鿴�Լ���ԤԼ
void Student::showMyOrder() {
  OrderFile of;
  int i;
  bool flag = false;
  if (of.m_Size == 0) {
    cout << "��ԤԼ��¼" << endl;
    system("pause");
    system("cls");
    return;
  }
  for (i = 0; i < of.m_Size; i++) {

    //����c_str()��string����תΪc��ʽ�����ַ�ָ��(const
    // char*),����atoi()��ָ����ָ����תΪint����
    if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->getId()) {
      cout << "ԤԼ����:��" << of.m_orderData[i]["date"];
      cout << " ʱ��:"
           << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
      cout << " " << of.m_orderData[i]["roomId"] << "�Ż���";
      string status = " ״̬:";
      if (of.m_orderData[i]["status"] == "1")
        status += "�����...";
      else if (of.m_orderData[i]["status"] == "2")
        status += "��ԤԼ";
      else if (of.m_orderData[i]["status"] == "-1")
        status += "ԤԼʧ��";
      else if (of.m_orderData[i]["status"] == "0")
        status += "��ȡ��";
      cout << status << endl;
      flag = true;
    }
  }
  //�������������ļ���û�з���ͬѧ�ŵļ�¼
  if (i == of.m_Size && !flag)
    cout << "û�����ԤԼ" << endl;
  system("pause");
  system("cls");
}

//�鿴����ԤԼ
void Student::showAllOrder() {
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

//ȡ��ԤԼ
void Student::cancalOrder() {
  OrderFile of;
  if (of.m_Size == 0) {
    cout << "��ԤԼ��¼" << endl;
    system("pause");
    system("cls");
    return;
  }
  cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ��,������Ҫȡ���ļ�¼" << endl;
  vector<int> v;
  int index = 1;
  for (int i = 0; i < of.m_Size; i++) {
    if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {
      if (of.m_orderData[i]["status"] == "1" ||
          of.m_orderData[i]["status"] == "2") {
        //�������������±����v��.����ȡ��ԤԼʱ��ȡ��Orderfile�еļ�¼
        v.push_back(i);
        cout << index++ << ". ";
        cout << "ԤԼ����:��" << of.m_orderData[i]["date"];
        cout << " ʱ��:"
             << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
        cout << " " << of.m_orderData[i]["roomId"] << "�Ż���";
        string status = " ״̬:";
        if (of.m_orderData[i]["status"] == "1")
          status += "�����...";
        else if (of.m_orderData[i]["status"] == "2")
          status += "��ԤԼ";
        cout << status << endl;
      }
    }
  }
  cout << "������Ҫȡ���ļ�¼��,����0����" << endl;
  size_t select = 0;
  while (true) {
    cin >> select;
    if (select >= 0 && select <= v.size()) {
      if (select == 0)
        break;
      else {
        of.m_orderData[v[select - 1]]["status"] = "0";
        of.updateOrder();
        cout << "��ȡ��" << endl;
        break;
      }
    }
    cout << "��������,����������" << endl;
  }
  system("pause");
  system("cls");
}
