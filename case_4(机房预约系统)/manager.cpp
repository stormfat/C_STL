#include "Manager.h"
//#include "Student.h"
//#include "Teacher.h"
//#include "ComputerRoom.h"

Manager::Manager() {}
Manager::Manager(string name, string pwd) {
  this->m_Name = name;
  this->m_Pwd = pwd;

  this->initVector();

  //��ȡ������Ϣ
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
void Manager::operMenu() {
  cout << "��ӭ����Ա: " << this->m_Name << "��¼!" << endl;
  cout << "\t\t---------------------------------\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           1.����˺�           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           2.�鿴�˺�           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           3.�鿴����           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           4.���ԤԼ           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           0.ע����¼           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t---------------------------------\n";
  cout << "��ѡ�����: " << endl;
}

//����˺�
void Manager::addPerson() {
  cout << "����������˺ŵ�����" << endl;
  cout << "1.���ѧ��" << endl;
  cout << "2.�����ʦ" << endl;

  string filename;
  string tip;
  string errorTip;
  ofstream ofs;

  int select = 0;
  cin >> select;
  if (select == 1) {
    filename = STUDENT_FILE;
    tip = "������ѧ��:";
    errorTip = "ѧ���ظ�,����������";
  } else {
    filename = TEACHER_FILE;
    tip = "������ְ����:";
    errorTip = "ְ�����ظ�,����������";
  }
  ofs.open(filename, ios::out | ios::app);
  int id;
  string name;
  string pwd;
  cout << tip << endl;
  while (true) {
    cin >> id;
    if (this->checkRepeat(id, select))
      cout << errorTip << endl;
    else
      break;
  }
  cout << "����������:" << endl;
  cin >> name;
  cout << "����������:" << endl;
  cin >> pwd;
  ofs << id << " " << name << " " << pwd << " " ;
  cout << "��ӳɹ�" << endl;
  system("pause");
  system("cls");
  ofs.close();

  //��������ӵ��˺ŵ�������
  this->initVector();
}

//��ʾ�˺�
void printStudent(Student &s) {
  cout << "ѧ��: " << s.getId() << ",����: " << s.getName()
       << ",����: " << s.getPwd() << endl;
}

void printTeacher(Teacher &t) {
  cout << "ְ����: " << t.getId() << ",����: " << t.getName()
       << ",����: " << t.getPwd() << endl;
}

void Manager::showPerson() {
  cout << "��ѡ��鿴����: " << endl;
  cout << "1.�鿴����ѧ��: " << endl;
  cout << "2.�鿴���н�ʦ: " << endl;
  int select = 0;
  cin >> select;
  if (select == 1) {

    for_each(vStudent.begin(), vStudent.end(), printStudent);
  } else {
    for_each(vTeacher.begin(), vTeacher.end(), printTeacher);
  }
  system("pause");
  system("cls");
}

//�鿴������Ϣ
void printComputer(ComputerRoom &c) {
  cout << "������: " << c.getComId() << " ����:" << c.getMaxNum() << endl;
}
void Manager::showComputer() {
  for_each(vCom.begin(), vCom.end(), printComputer);
  system("pause");
  system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile() {
  ofstream ofs(ORDER_FILE, ios::trunc);
  ofs.close();
  cout << "��ճɹ�!" << endl;
  system("pause");
  system("cls");
}

//��ʼ������
void Manager::initVector() {
  ifstream ifs;
  ifs.open(STUDENT_FILE, ios::in);
  if (!ifs.is_open()) {
    cout << "�ļ���ȡʧ��" << endl;
    return;
  }
  vStudent.clear();
  vTeacher.clear();

  Student s;
  int fId;
  string fName;
  string fPwd;
  while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
    s.setId(fId);
    s.setName(fName);
    s.setPwd(fPwd);
    vStudent.push_back(s);
  }
  cout << "��ǰѧ������Ϊ:" << vStudent.size() << endl;
  ifs.close();

  Teacher t;
  ifs.open(TEACHER_FILE, ios::in);
  if (!ifs.is_open()) {
    cout << "�ļ���ȡʧ��" << endl;
    return;
  }
  while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
    t.setId(fId);
    t.setName(fName);
    t.setPwd(fPwd);
    vTeacher.push_back(t);
  }
  cout << "��ǰ��ʦ����Ϊ:" << vTeacher.size() << endl;
  ifs.close();
}

//�鿴�Ƿ����ظ�ID
bool Manager::checkRepeat(int id, int type) {
  if (type == 1) {
    for (auto it = vStudent.begin(); it != vStudent.end(); it++) {
      if (id == (*it).getId())
        return true;
    }
  } else {
    for (auto it = vTeacher.begin(); it != vTeacher.end(); it++) {
      if (id == (*it).getId())
        return true;
    }
  }
  return false;
}
