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
  cout << "欢迎: " << this->m_Name << "登录!" << endl;
  cout << "\t\t---------------------------------\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           1.查看预约           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           2.审核预约           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t|           0.注销登录           |\n";
  cout << "\t\t|                                |\n";
  cout << "\t\t---------------------------------\n";
  cout << "请选择操作: " << endl;
}

//查看所有预约
void Teacher::showAllOrder() {
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

//审核预约
void Teacher::validOrder() {
  OrderFile of;
  if (of.m_Size == 0) {
    cout << "无预约记录" << endl;
    system("pause");
    system("cls");
    return;
  }
  cout << "待审核的预约记录如下: " << endl;
  vector<int> v;
  int index = 1;
  for (int i = 0; i < of.m_Size; i++) {
    if (of.m_orderData[i]["status"] == "1") {
      //将符合条件的下标存入v中.方便取消预约时获取到Orderfile中的记录
      v.push_back(i);
      cout << index++ << ". ";
      cout << "学号:" << of.m_orderData[i]["stuId"];
      cout << " 姓名:" << of.m_orderData[i]["stuName"];
      cout << " 预约日期:周" << of.m_orderData[i]["date"];
      cout << " 时段:"
           << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
      cout << " " << of.m_orderData[i]["roomId"] << "号机房";
      string status = " 状态:";
      if (of.m_orderData[i]["status"] == "1")
        status += "审核中...";
      cout << status << endl;
    }
  }
  cout << "输入需要审核的记录号,0代表返回" << endl;
  size_t select = 0;
  int ret = 0;
  while (true) {
    cin >> select;
    if (select >= 0 && select <= v.size()) {
      if (select == 0)
        break;
      else {
        cout << "请输入审核结果" << endl;
        cout << "1.通过" << endl;
        cout << "2.不通过" << endl;
        cin >> ret;
        if (ret == 1)
          of.m_orderData[v[select - 1]]["status"] = "2";
        else
          of.m_orderData[v[select - 1]]["status"] = "-1";
        of.updateOrder();
        cout << "审核完毕" << endl;
        break;
      }
    }
    cout << "输入有误,请重新输入" << endl;
  }
  system("pause");
  system("cls");
}