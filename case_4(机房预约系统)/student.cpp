#include "Student.h"
#include "orderFile.h"

Student::Student() {}
Student::Student(int id, string name, string pwd) {
  this->m_Id = id;
  this->m_Name = name;
  this->m_Pwd = pwd;

  //初始化机房信息
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
void Student::operMenu() {
  cout << "欢迎: " << this->m_Name << "登录!" << endl;
  cout << "\t\t---------------------------------\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           1.申请预约           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           2.查看预约           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           3.所有预约           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           4.取消预约           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           0.注销登录           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t---------------------------------\n";
  cout << "请选择操作: " << endl;
}

void Student::setId(int id) { this->m_Id = id; }
int Student ::getId() { return this->m_Id; }
void Student::setName(string name) { this->m_Name = name; }
void Student::setPwd(string pwd) { this->m_Pwd = pwd; }
string Student::getName() { return this->m_Name; }
string Student::getPwd() { return this->m_Pwd; }

//预约申请
void Student::applyOrder() {
  cout << "机房开放时间为周一至周五!" << endl;
  cout << "请输入申请预约的时间:" << endl;
  cout << "1.周一" << endl;
  cout << "2.周二" << endl;
  cout << "3.周三" << endl;
  cout << "4.周四" << endl;
  cout << "5.周五" << endl;
  int date = 0;
  int interval = 0;
  int room = 0;

  while (true) {
    cin >> date;
    if (date >= 1 && date <= 5)
      break;
    cout << "输入有误,请重新输入" << endl;
  }

  cout << "请输入申请预约的时间段:" << endl;
  cout << "1.上午" << endl;
  cout << "2.下午" << endl;
  while (true) {
    cin >> interval;
    if (interval == 1 || interval == 2)
      break;
    cout << "输入有误,请重新输入" << endl;
  }

  cout << "请选择机房:" << endl;
  for (size_t i = 0; i < vCom.size(); i++)
    cout << vCom[i].getComId() << "号机房容量为:" << vCom[i].getMaxNum()
         << endl;
  while (true) {
    cin >> room;
    if (room >= 1 && room <= 3)
      break;
    cout << "输入有误,请重新输入" << endl;
  }
  cout << "预约成功,审核中...." << endl;
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

//查看自己的预约
void Student::showMyOrder() {
  OrderFile of;
  int i;
  bool flag = false;
  if (of.m_Size == 0) {
    cout << "无预约记录" << endl;
    system("pause");
    system("cls");
    return;
  }
  for (i = 0; i < of.m_Size; i++) {

    //先用c_str()将string对象转为c格式常量字符指针(const
    // char*),再用atoi()将指针所指内容转为int类型
    if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->getId()) {
      cout << "预约日期:周" << of.m_orderData[i]["date"];
      cout << " 时段:"
           << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
      cout << " " << of.m_orderData[i]["roomId"] << "号机房";
      string status = " 状态:";
      if (of.m_orderData[i]["status"] == "1")
        status += "审核中...";
      else if (of.m_orderData[i]["status"] == "2")
        status += "已预约";
      else if (of.m_orderData[i]["status"] == "-1")
        status += "预约失败";
      else if (of.m_orderData[i]["status"] == "0")
        status += "已取消";
      cout << status << endl;
      flag = true;
    }
  }
  //当遍历完整个文件且没有发现同学号的记录
  if (i == of.m_Size && !flag)
    cout << "没有你的预约" << endl;
  system("pause");
  system("cls");
}

//查看所有预约
void Student::showAllOrder() {
  OrderFile of;
  if (of.m_Size == 0) {
    cout << "无预约记录" << endl;
    system("pause");
    system("cls");
    return;
  }
  for (int i = 0; i < of.m_Size; i++) {
    cout << "第" << i + 1 << "条记录:" << endl;
    cout << "学号:" << of.m_orderData[i]["stuId"] << " ";
    cout << "姓名:" << of.m_orderData[i]["stuName"] << " ";
    cout << "预约日期:周" << of.m_orderData[i]["date"] << " ";
    cout << "时段:" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午")
         << " ";
    cout << of.m_orderData[i]["roomId"] << "号机房"
         << " ";
    string status = "状态:";
    if (of.m_orderData[i]["status"] == "1")
      status += "审核中...";
    else if (of.m_orderData[i]["status"] == "2")
      status += "已预约";
    else if (of.m_orderData[i]["status"] == "-1")
      status += "预约失败";
    else if (of.m_orderData[i]["status"] == "0")
      status += "已取消";
    cout << status << endl;
  }
  system("pause");
  system("cls");
}

//取消预约
void Student::cancalOrder() {
  OrderFile of;
  if (of.m_Size == 0) {
    cout << "无预约记录" << endl;
    system("pause");
    system("cls");
    return;
  }
  cout << "审核中或预约成功的记录可以取消,请输入要取消的记录" << endl;
  vector<int> v;
  int index = 1;
  for (int i = 0; i < of.m_Size; i++) {
    if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {
      if (of.m_orderData[i]["status"] == "1" ||
          of.m_orderData[i]["status"] == "2") {
        //将符合条件的下标存入v中.方便取消预约时获取到Orderfile中的记录
        v.push_back(i);
        cout << index++ << ". ";
        cout << "预约日期:周" << of.m_orderData[i]["date"];
        cout << " 时段:"
             << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
        cout << " " << of.m_orderData[i]["roomId"] << "号机房";
        string status = " 状态:";
        if (of.m_orderData[i]["status"] == "1")
          status += "审核中...";
        else if (of.m_orderData[i]["status"] == "2")
          status += "已预约";
        cout << status << endl;
      }
    }
  }
  cout << "请输入要取消的记录号,输入0返回" << endl;
  size_t select = 0;
  while (true) {
    cin >> select;
    if (select >= 0 && select <= v.size()) {
      if (select == 0)
        break;
      else {
        of.m_orderData[v[select - 1]]["status"] = "0";
        of.updateOrder();
        cout << "已取消" << endl;
        break;
      }
    }
    cout << "输入有误,请重新输入" << endl;
  }
  system("pause");
  system("cls");
}
