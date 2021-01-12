/*需求分析:
1.1号机房容量20人;2号机房容量50人;3号机房容量100人
2.学生代表:申请使用机房
  教师:审核学生申请
  管理员:给学生,教师创建账号
3.申请的订单每周由管理员负责清空.
  学生可以预约未来一周的机房使用,预约日期为周一至周五,预约是需要选择预约时段(上,下午)
  教师依据实际情况审核预约成功与否*/

/*系统具体需求:
1.登录界面可选身份(学生,教师,管理员,退出)
2.每种身份需要提供验证机制
3.学生代表身份功能:申请,查看自己的预约,查看所有预约,取消预约(包括自身预约,以成功的预约及审核中的预约),注销
4.教师身份功能:查看所有预约,审核,注销
5.管理员身份功能:添加账号,查看账号,查看机房,清空预约,注销*/

#include "Identity.h"
#include "Manager.h"
#include "Student.h"
#include "Teacher.h"
#include "globalFile.h"
#include <fstream> //ifstream
#include <iostream>
using namespace std;

//学生菜单 全局函数
void studentMenu(Identity *&student) {
  while (true) {
    //学生菜单
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
      cout << "注销成功" << endl;
      system("pause");
      system("cls");
      return;
    }
  }
}

//管理员菜单,全局函数
void managerMenu(Identity *&manager) {
  while (true) {
    //调用管理员子菜单
    manager->operMenu();
    //将父类指针 转为子类指针,调用子类里的接口
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
      cout << "注销成功" << endl;
      system("pause");
      system("cls");
      return;
    }
  }
}

//教师菜单
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
      cout << "注销成功" << endl;
      system("pause");
      system("cls");
      return;
    }
  }
}

//登录功能,全局函数,参数1:登录者所需操作文件名,参数2:登录者身份类型
void loginIn(string fileName, int type) {
  //创建基类指针,用于指向子类对象,实现多态.
  Identity *person = NULL;

  //读文件
  ifstream ifs;
  ifs.open(fileName, ios::in);

  //判断文件是否存在
  if (!ifs.is_open()) {
    cout << "文件不存在!" << endl;
    ifs.close();
    return;
  }

  //准备接受用户信息
  int id = 0;
  string name;
  string pwd;

  //判断身份
  if (type == 1) //学生
  {
    cout << "请输入你的学号:" << endl;
    cin >> id;
  } else if (type == 2) {
    cout << "请输入员工号:" << endl;
    cin >> id;
  }
  cout << "请输入用户名:" << endl;
  cin >> name;
  cout << "请输入密码:" << endl;
  cin >> pwd;

  if (type == 1) {
    //验证学生登录信息
    int fID; //从文件中读取到的ID,NAME,PWD.
    string fName;
    string fPwd;
    while (ifs >> fID && ifs >> fName && ifs >> fPwd) {
      //与用户提供的信息做对比
      if (fID == id && fName == name && fPwd == pwd) {
        cout << "学生验证登录成功!" << endl;
        system("pause");
        system("cls");
        person = new Student(id, name, pwd);
        studentMenu(person);
        return;
      }
    }
  } else if (type == 2) {
    //验证教师登录信息
    int fID; //从文件中读取到的ID,NAME,PWD.
    string fName;
    string fPwd;
    while (ifs >> fID && ifs >> fName && ifs >> fPwd) {
      //与用户提供的信息做对比
      if (fID == id && fName == name && fPwd == pwd) {
        cout << "老师验证登录成功!" << endl;
        system("pause");
        system("cls");
        person = new Teacher(id, name, pwd);
        teacherMenu(person);
        return;
      }
    }

  } else if (type == 3) {
    //验证管理员登录信息
    string fName;
    string fPwd;
    while (ifs >> fName && ifs >> fPwd) {
      if (fName == name && fPwd == pwd) {
        cout << "管理员验证登录成功" << endl;
        system("pause");
        system("cls");
        person = new Manager(name, pwd);
        managerMenu(person);
        return;
      }
    }
  }
  cout << "验证登录失败!" << endl;
  system("pause");
  system("cls");
  return;
}

int main() {
  int select = 0;
  while (true) {
    cout << "================== 欢迎使用机房预约系统 =================="
         << endl;
    cout << endl << "请输入您的身份" << endl;
    cout << "\t\t--------------------------\n";
    cout << "\t\t|                        |\n";
    cout << "\t\t|       1.学生代表       |\n";
    cout << "\t\t|                        |\n";
    cout << "\t\t|       2.老    师       |\n";
    cout << "\t\t|                        |\n";
    cout << "\t\t|       3.管 理 员       |\n";
    cout << "\t\t|                        |\n";
    cout << "\t\t|       0.退    出       |\n";
    cout << "\t\t|                        |\n";
    cout << "\t\t--------------------------\n";
    cout << "输入你的选择: ";
    cin >> select;
    switch (select) {
    case 1: //学生代表身份
      loginIn(STUDENT_FILE, 1);
      break;
    case 2: //老师身份
      loginIn(TEACHER_FILE, 2);
      break;
    case 3: //管理员身份
      loginIn(ADMIN_FILE, 3);
      break;
    case 0: //退出
      cout << "欢迎下次使用!" << endl;
      system("pause");
      return 0;
      break;
    default:
      cout << "输入有误,请重新选择!" << endl;
      system("pause");
      system("cls");
      break;
    }
  }
  system("pause");
  return 0;
}
