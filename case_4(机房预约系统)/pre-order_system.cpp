/*�������:
1.1�Ż�������20��;2�Ż�������50��;3�Ż�������100��
2.ѧ������:����ʹ�û���
  ��ʦ:���ѧ������
  ����Ա:��ѧ��,��ʦ�����˺�
3.����Ķ���ÿ���ɹ���Ա�������.
  ѧ������ԤԼδ��һ�ܵĻ���ʹ��,ԤԼ����Ϊ��һ������,ԤԼ����Ҫѡ��ԤԼʱ��(��,����)
  ��ʦ����ʵ��������ԤԼ�ɹ����*/

/*ϵͳ��������:
1.��¼�����ѡ���(ѧ��,��ʦ,����Ա,�˳�)
2.ÿ�������Ҫ�ṩ��֤����
3.ѧ��������ݹ���:����,�鿴�Լ���ԤԼ,�鿴����ԤԼ,ȡ��ԤԼ(��������ԤԼ,�Գɹ���ԤԼ������е�ԤԼ),ע��
4.��ʦ��ݹ���:�鿴����ԤԼ,���,ע��
5.����Ա��ݹ���:����˺�,�鿴�˺�,�鿴����,���ԤԼ,ע��*/

#include "Identity.h"
#include "Manager.h"
#include "Student.h"
#include "Teacher.h"
#include "globalFile.h"
#include <fstream> //ifstream
#include <iostream>
using namespace std;

//ѧ���˵� ȫ�ֺ���
void studentMenu(Identity *&student) {
  while (true) {
    //ѧ���˵�
    student->operMenu();
    Student *stu = (Student *)student;
    int select = 0;
    cin >> select;

    if (select == 1)
      stu->applyOrder();
    else if (select == 2)
      stu->showMyOrder();
    else if (select == 3)
      stu->showAllOrder();
    else if (select == 4)
      stu->cancalOrder();
    else {
      delete student;
      cout << "ע���ɹ�" << endl;
      system("pause");
      system("cls");
      return;
    }
  }
}

//����Ա�˵�,ȫ�ֺ���
void managerMenu(Identity *&manager) {
  while (true) {
    //���ù���Ա�Ӳ˵�
    manager->operMenu();
    //������ָ�� תΪ����ָ��,����������Ľӿ�
    Manager *man = (Manager *)manager;
    int select = 0;
    cin >> select;
    if (select == 1) {
      man->addPerson();
    } else if(select == 2) {
      man->showPerson();
    } else if (select == 3) {
      man->showComputer();
    } else if (select == 4) {
      man->cleanFile();
    } else {
      delete manager;
      cout << "ע���ɹ�" << endl;
      system("pause");
      system("cls");
      return;
    }
  }
}

//��ʦ�˵�
void teacherMenu(Identity *&teacher) {
  while (true) {
    teacher->operMenu();
    Teacher *tea = (Teacher *)teacher;
    int select = 0;
    cin >> select;
    if (select == 1)
      tea->showAllOrder();
    if (select == 2)
      tea->validOrder();
    else {
      delete teacher;
      cout << "ע���ɹ�" << endl;
      system("pause");
      system("cls");
      return;
    }
  }
}

//��¼����,ȫ�ֺ���,����1:��¼����������ļ���,����2:��¼���������
void loginIn(string fileName, int type) {
  //��������ָ��,����ָ���������,ʵ�ֶ�̬.
  Identity *person = NULL;

  //���ļ�
  ifstream ifs;
  ifs.open(fileName, ios::in);

  //�ж��ļ��Ƿ����
  if (!ifs.is_open()) {
    cout << "�ļ�������!" << endl;
    ifs.close();
    return;
  }

  //׼�������û���Ϣ
  int id = 0;
  string name;
  string pwd;

  //�ж����
  if (type == 1) //ѧ��
  {
    cout << "���������ѧ��:" << endl;
    cin >> id;
  } else if (type == 2) {
    cout << "������Ա����:" << endl;
    cin >> id;
  }
  cout << "�������û���:" << endl;
  cin >> name;
  cout << "����������:" << endl;
  cin >> pwd;

  if (type == 1) {
    //��֤ѧ����¼��Ϣ
    int fID; //���ļ��ж�ȡ����ID,NAME,PWD.
    string fName;
    string fPwd;
    while (ifs >> fID && ifs >> fName && ifs >> fPwd) {
      //���û��ṩ����Ϣ���Ա�
      if (fID == id && fName == name && fPwd == pwd) {
        cout << "ѧ����֤��¼�ɹ�!" << endl;
        system("pause");
        system("cls");
        person = new Student(id, name, pwd);
        studentMenu(person);
        return;
      }
    }
  } else if (type == 2) {
    //��֤��ʦ��¼��Ϣ
    int fID; //���ļ��ж�ȡ����ID,NAME,PWD.
    string fName;
    string fPwd;
    while (ifs >> fID && ifs >> fName && ifs >> fPwd) {
      //���û��ṩ����Ϣ���Ա�
      if (fID == id && fName == name && fPwd == pwd) {
        cout << "��ʦ��֤��¼�ɹ�!" << endl;
        system("pause");
        system("cls");
        person = new Teacher(id, name, pwd);
        teacherMenu(person);
        return;
      }
    }

  } else if (type == 3) {
    //��֤����Ա��¼��Ϣ
    string fName;
    string fPwd;
    while (ifs >> fName && ifs >> fPwd) {
      if (fName == name && fPwd == pwd) {
        cout << "����Ա��֤��¼�ɹ�" << endl;
        system("pause");
        system("cls");
        person = new Manager(name, pwd);
        managerMenu(person);
        return;
      }
    }
  }
  cout << "��֤��¼ʧ��!" << endl;
  system("pause");
  system("cls");
  return;
}

int main() {
  int select = 0;
  while (true) {
    cout << "================== ��ӭʹ�û���ԤԼϵͳ =================="
         << endl;
    cout << endl << "�������������" << endl;
    cout << "\t\t--------------------------\n";
    cout << "\t\t|                        |\n";
    cout << "\t\t|       1.ѧ������       |\n";
    cout << "\t\t|                        |\n";
    cout << "\t\t|       2.��    ʦ       |\n";
    cout << "\t\t|                        |\n";
    cout << "\t\t|       3.�� �� Ա       |\n";
    cout << "\t\t|                        |\n";
    cout << "\t\t|       0.��    ��       |\n";
    cout << "\t\t|                        |\n";
    cout << "\t\t--------------------------\n";
    cout << "�������ѡ��: ";
    cin >> select;
    switch (select) {
    case 1: //ѧ���������
      loginIn(STUDENT_FILE, 1);
      break;
    case 2: //��ʦ���
      loginIn(TEACHER_FILE, 2);
      break;
    case 3: //����Ա���
      loginIn(ADMIN_FILE, 3);
      break;
    case 0: //�˳�
      cout << "��ӭ�´�ʹ��!" << endl;
      system("pause");
      return 0;
      break;
    default:
      cout << "��������,������ѡ��!" << endl;
      system("pause");
      system("cls");
      break;
    }
  }
  system("pause");
  return 0;
}
