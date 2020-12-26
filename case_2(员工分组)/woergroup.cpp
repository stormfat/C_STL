/*案列描述:
10个员工
员工信息:姓名,工资,部门
部分:策划,美术,研发
要求:随机给员工分配工资和部门,通过multimap进行信息插入 key(部门编号),value(员工)
分部门显示员工信息*/

/*实现步骤:
1.创建员工,放入vector
2.遍历vector,取出每个员工,进行随机分组
3.分组后,将员工部门编号作为key,具体员工作为value,放到multimap容器中
4.分部门显示员工信息.*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

#define CHEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker {
public:
  Worker(char name, double salary = 0) {
    this->m_Name = "员工";
    this->m_Name += name;
    this->m_Salary = salary;
  }
  string getName() const { return m_Name; }
  double getSalary() const { return m_Salary; }
  void setSalary(double salary) { this->m_Salary = salary; }

private:
  string m_Name;
  double m_Salary;
};

void createWorker(vector<Worker> &vwoker) {
  string nameSeed = "ABCDEFGHIJ";
  for (int i = 0; i < 10; i++) {
    Worker worker(nameSeed[i], rand() % 10000 + 10000.0);
    vwoker.push_back(worker);
  }
}

//测试worker vector是否建立
void printWorker(const vector<Worker> &worker) {
  for (auto it = worker.begin(); it != worker.end(); it++)
    cout << (*it).getName() << " " << (*it).getSalary() << endl;
}

void setGroup(vector<Worker> &v, multimap<int, Worker> &m) {
  for (auto it = v.begin(); it != v.end(); it++) {
    //产生随机部门编号
    int deptId = rand() % 3; //产生0,1,2
    //将员工插入map
    m.insert(make_pair(deptId, (*it)));
  }
}

void showWorker(const multimap<int, Worker> &m) {
  cout << "策划部门:" << endl;
  auto pos = m.find(CHEHUA); //按照key找到value
  int count = m.count(CHEHUA);
  int index = 0;
  for (; pos != m.end() && index < count; pos++, index++)
    cout << pos->second.getName() << ",工资:" << (*pos).second.getSalary()
         << endl;
  cout << endl;
  cout << "美术部门:" << endl;
  pos = m.find(MEISHU); //按照key找到value
  count = m.count(MEISHU);
  index = 0;
  for (; pos != m.end() && index < count; pos++, index++)
    cout << ((*pos).second).getName() << ",工资:" << ((*pos).second).getSalary()
         << endl;
  cout << endl;
  cout << "研发部门:" << endl;
  pos = m.find(YANFA); //按照key找到value
  count = m.count(YANFA);
  index = 0;
  for (; pos != m.end() && index < count; pos++, index++)
    cout << ((*pos).second).getName() << ",工资:" << ((*pos).second).getSalary()
         << endl;
}

int main() {
  srand((unsigned int)time);
  // 1.创建员工组
  vector<Worker> vWorker;
  createWorker(vWorker);

  // 2.员工分组
  multimap<int, Worker> mWorker;
  setGroup(vWorker, mWorker);

  // 3.分组显示
  showWorker(mWorker);
  // printWorker(vWorker);
  return 0;
}