#include "Manager.h"
//#include "Student.h"
//#include "Teacher.h"
//#include "ComputerRoom.h"

Manager::Manager() {}
Manager::Manager(string name, string pwd) {
  this->m_Name = name;
  this->m_Pwd = pwd;

  this->initVector();

  //获取机房信息
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

//选择菜单
void Manager::operMenu() {
  cout << "欢迎管理员: " << this->m_Name << "登录!" << endl;
  cout << "\t\t---------------------------------\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           1.添加账号           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           2.查看账号           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           3.查看机房           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           4.清空预约           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           0.注销登录           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t---------------------------------\n";
  cout << "请选择操作: " << endl;
}

//添加账号
void Manager::addPerson() {
  cout << "请输入添加账号的类型" << endl;
  cout << "1.添加学生" << endl;
  cout << "2.添加老师" << endl;

  string filename;
  string tip;
  string errorTip;
  ofstream ofs;

  int select = 0;
  cin >> select;
  if (select == 1) {
    filename = STUDENT_FILE;
    tip = "请输入学号:";
    errorTip = "学号重复,请重新输入";
  } else {
    filename = TEACHER_FILE;
    tip = "请输入职工号:";
    errorTip = "职工号重复,请重新输入";
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
  cout << "请输入姓名:" << endl;
  cin >> name;
  cout << "请输入密码:" << endl;
  cin >> pwd;
  ofs << id << " " << name << " " << pwd << " " ;
  cout << "添加成功" << endl;
  system("pause");
  system("cls");
  ofs.close();

  //更新新添加的账号到容器中
  this->initVector();
}

//显示账号
void printStudent(Student &s) {
  cout << "学号: " << s.getId() << ",姓名: " << s.getName()
       << ",密码: " << s.getPwd() << endl;
}

void printTeacher(Teacher &t) {
  cout << "职工号: " << t.getId() << ",姓名: " << t.getName()
       << ",密码: " << t.getPwd() << endl;
}

void Manager::showPerson() {
  cout << "请选择查看内容: " << endl;
  cout << "1.查看所有学生: " << endl;
  cout << "2.查看所有教师: " << endl;
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

//查看机房信息
void printComputer(ComputerRoom &c) {
  cout << "机房号: " << c.getComId() << " 容量:" << c.getMaxNum() << endl;
}
void Manager::showComputer() {
  for_each(vCom.begin(), vCom.end(), printComputer);
  system("pause");
  system("cls");
}

//清空预约记录
void Manager::cleanFile() {
  ofstream ofs(ORDER_FILE, ios::trunc);
  ofs.close();
  cout << "清空成功!" << endl;
  system("pause");
  system("cls");
}

//初始化容器
void Manager::initVector() {
  ifstream ifs;
  ifs.open(STUDENT_FILE, ios::in);
  if (!ifs.is_open()) {
    cout << "文件读取失败" << endl;
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
  cout << "当前学生数量为:" << vStudent.size() << endl;
  ifs.close();

  Teacher t;
  ifs.open(TEACHER_FILE, ios::in);
  if (!ifs.is_open()) {
    cout << "文件读取失败" << endl;
    return;
  }
  while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
    t.setId(fId);
    t.setName(fName);
    t.setPwd(fPwd);
    vTeacher.push_back(t);
  }
  cout << "当前教师数量为:" << vTeacher.size() << endl;
  ifs.close();
}

//查看是否有重复ID
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
