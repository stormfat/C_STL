#include "orderFile.h"

void strSubstr(string data, map<string, string> &m) {
  string key;
  string value;
  int pos = data.find(":");
  if (pos != -1) {
    key = data.substr(0, pos);
    value = data.substr(pos + 1, data.size() - pos - 1);
    m.insert(make_pair(key, value));
  }
}

OrderFile::OrderFile() {
  ifstream ifs;
  ifs.open(ORDER_FILE, ios::in);
  string date;
  string interval;
  string stuId;
  string stuName;
  string roomId;
  string status;

  this->m_Size = 0;
  while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName &&
         ifs >> roomId && ifs >> status) {
    map<string, string> m;
    strSubstr(date, m);
    strSubstr(interval, m);
    strSubstr(stuId, m);
    strSubstr(stuName, m);
    strSubstr(roomId, m);
    strSubstr(status, m);

    this->m_orderData.insert(make_pair(this->m_Size, m));
    this->m_Size++;
  }
  ifs.close();
  //测试代码
  //for (auto it = m_orderData.begin(); it != m_orderData.end(); it++) {
  //  cout << "第" << (*it).first +1<< "条记录:";
  //  for (auto subit = (*it).second.begin(); subit != (*it).second.end();
  //       subit++)
  //    cout << (*subit).first << ":" << (*subit).second << " ";
  //}
  //cout << endl;
}

void OrderFile::updateOrder() {
  if (this->m_Size == 0)
    return;
  ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
  for (int i = 0; i < m_Size; i++) {
    ofs << "date:" << this->m_orderData[i]["date"] << " ";
    ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
    ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
    ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
    ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
    ofs << "status:" << this->m_orderData[i]["status"] << endl;
  }
  ofs.close();
}