/*��������:
10��Ա��
Ա����Ϣ:����,����,����
����:�߻�,����,�з�
Ҫ��:�����Ա�����乤�ʺͲ���,ͨ��multimap������Ϣ���� key(���ű��),value(Ա��)
�ֲ�����ʾԱ����Ϣ*/

/*ʵ�ֲ���:
1.����Ա��,����vector
2.����vector,ȡ��ÿ��Ա��,�����������
3.�����,��Ա�����ű����Ϊkey,����Ա����Ϊvalue,�ŵ�multimap������
4.�ֲ�����ʾԱ����Ϣ.*/

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
    this->m_Name = "Ա��";
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

//����worker vector�Ƿ���
void printWorker(const vector<Worker> &worker) {
  for (auto it = worker.begin(); it != worker.end(); it++)
    cout << (*it).getName() << " " << (*it).getSalary() << endl;
}

void setGroup(vector<Worker> &v, multimap<int, Worker> &m) {
  for (auto it = v.begin(); it != v.end(); it++) {
    //����������ű��
    int deptId = rand() % 3; //����0,1,2
    //��Ա������map
    m.insert(make_pair(deptId, (*it)));
  }
}

void showWorker(const multimap<int, Worker> &m) {
  cout << "�߻�����:" << endl;
  auto pos = m.find(CHEHUA); //����key�ҵ�value
  int count = m.count(CHEHUA);
  int index = 0;
  for (; pos != m.end() && index < count; pos++, index++)
    cout << pos->second.getName() << ",����:" << (*pos).second.getSalary()
         << endl;
  cout << endl;
  cout << "��������:" << endl;
  pos = m.find(MEISHU); //����key�ҵ�value
  count = m.count(MEISHU);
  index = 0;
  for (; pos != m.end() && index < count; pos++, index++)
    cout << ((*pos).second).getName() << ",����:" << ((*pos).second).getSalary()
         << endl;
  cout << endl;
  cout << "�з�����:" << endl;
  pos = m.find(YANFA); //����key�ҵ�value
  count = m.count(YANFA);
  index = 0;
  for (; pos != m.end() && index < count; pos++, index++)
    cout << ((*pos).second).getName() << ",����:" << ((*pos).second).getSalary()
         << endl;
}

int main() {
  srand((unsigned int)time);
  // 1.����Ա����
  vector<Worker> vWorker;
  createWorker(vWorker);

  // 2.Ա������
  multimap<int, Worker> mWorker;
  setGroup(vWorker, mWorker);

  // 3.������ʾ
  showWorker(mWorker);
  // printWorker(vWorker);
  return 0;
}