/*程序功能:
1.开始演讲比赛:完成整届比赛的流程,每个比赛阶段需要给用户一个提示,用户按任意键后继续下一个阶段
2.查看往届记录:查看之前比赛的前三名信息,每次比赛都会记录到.csv文件中
3.清空比赛记录:将文件数据清空
4.退出比赛程序:可以退出当前程序*/

#include "speechmanager.h"
#include <algorithm> //greater
#include <deque>
#include <numeric> //accumulate

//定义构造函数
SpeechManager::SpeechManager() {
  //初始化容器和属性
  this->initSpeech();

  //创建选手
  this->createSpeaker();

  //读取记录
  this->loadRecord();
}

//定义析构函数
SpeechManager::~SpeechManager() {}

//定义菜单显示功能
void SpeechManager::show_Menu() {
  cout << "***************************************" << endl;
  cout << "*********** 欢迎参加演讲比赛 **********" << endl;
  cout << "*********** 1.开始演讲比赛 ************" << endl;
  cout << "*********** 2.查看往届记录 ************" << endl;
  cout << "*********** 3.清空比赛记录 ************" << endl;
  cout << "*********** 0.退出比赛程序 ************" << endl;
  cout << "***************************************" << endl;
  cout << endl;
}

//定义退出功能
void SpeechManager::exitSystem() {
  cout << "欢迎下次使用!" << endl;
  system("pause");
  exit(0);
}

//定义成员初始化方法
void SpeechManager::initSpeech() {
  //容器置空
  this->v1.clear();
  this->v2.clear();
  this->vVictory.clear();
  this->m_Speaker.clear();
  //初始化轮数
  this->m_Index = 1;
  //清空记录容器
  this->m_Record.clear();
}

//创建选手
void SpeechManager::createSpeaker() {
  string nameSeed = "ABCDEFGHIJKL";
  for (size_t i = 0; i < nameSeed.size(); i++) {
    string name = "姓名";
    name += nameSeed[i];
    Speaker spk;
    spk.setName(name);
    for (int i = 0; i < 2; i++)
      spk.setScore(i, 0);

    // 12名选手编号
    this->v1.push_back(i + 10001);

    //选手编号 以及对应的名字放入map中
    this->m_Speaker.insert(make_pair(v1[i], spk));
  }
}

//定义抽签方法
void SpeechManager::speechDraw() {
  cout << "第<<" << this->m_Index << ">>论比赛选手正在抽签" << endl;
  cout << "----------------------" << endl;
  cout << "抽签后演讲顺序如下:" << endl;
  if (this->m_Index == 1) {
    random_shuffle(v1.begin(), v1.end()); //将v1洗牌
    for (auto it = v1.begin(); it != v1.end(); it++)
      cout << *it << "  "; //输出洗牌后的v1
    cout << endl;
    // this->m_Index = 2; //将轮数设为第2轮.
  } else {
    random_shuffle(v2.begin(), v2.end());
    for (auto it = v2.begin(); it != v2.end(); it++)
      cout << *it << "  ";
    cout << endl;
  }
  cout << "----------------------" << endl;
  system("pause");
  cout << endl;
}

//定义比赛方法
void SpeechManager::speechContes() {
  cout << "--------第" << this->m_Index << "轮比赛开始:--------" << endl;

  //临时容器,保存key(分数),value(选手编号),降序排列
  multimap<double, int, greater<double>> groupScore;
  int num = 0; //记录人员数,6个为1组

  vector<int> v_Src; //比赛的人员容器
  //根据轮数,将v_Src指向相应的容器,第一轮指向v1,第二轮指向v2
  if (this->m_Index == 1)
    v_Src = v1;
  else
    v_Src = v2;

  for (auto it = v_Src.begin(); it != v_Src.end(); it++) {
    num++;
    //十个评委打分
    deque<double> dScore;
    for (int i = 0; i < 10; i++) {
      double score = (rand() % 401 + 600) / 10.f;
      dScore.push_back(score);
    }

    //将dScore降序排列
    sort(dScore.begin(), dScore.end(), greater<double>());
    dScore.pop_front(); //去掉最高分
    dScore.pop_back();  //去掉最低分

    //获取总分,保留一位小数
    double sum = accumulate(dScore.begin(), dScore.end(), 0.0f);
    double avg = sum / (double)dScore.size(); //求平均分

    //通过*it(选手编号)访问map中相应选手,并对当前选手的m_score赋值,因为m_score数组起始下标为0,m_Index起始下标为1,所以要将m_index-1
    this->m_Speaker[*it].setScore(this->m_Index - 1, avg);

    // 6人一组,用临时容器保存
    groupScore.insert(make_pair(avg, *it));
    // num累加到6和12时进入if语句
    if (num % 6 == 0) {
      cout << "第" << num / 6 << "小组比赛名次:" << endl;
      for (auto it = groupScore.begin(); it != groupScore.end(); it++)
        cout << "编号:" << it->second
             << " 姓名:" << this->m_Speaker[it->second].getName() << " 成绩:"
             << this->m_Speaker[it->second].getScore(this->m_Index - 1) << endl;
      int count = 0;
      //取前三名,如果是第一轮放入v2中,如果是决赛放入vVictory中
      for (auto it = groupScore.begin(); it != groupScore.end() && count < 3;
           count++, it++) {
        if (this->m_Index == 1)
          v2.push_back(it->second);
        else
          vVictory.push_back(it->second);
      }
      groupScore.clear(); //从第7人开始重新统计
    }
  }
  cout << "----------第" << this->m_Index << "轮比赛完毕!----------" << endl;
  system("pause");
}

//定义开始比赛方法
void SpeechManager::startSpeech() {
  //第一轮比赛
  // 1.抽签
  this->speechDraw();
  //比赛
  this->speechContes();
  //显示晋级结果
  this->showScore();
  //第二轮比赛
  this->m_Index++;
  //抽签
  this->speechDraw();
  //比赛
  this->speechContes();
  //显示晋级结果
  this->showScore();
  //保存最终三名选手分数到文件
  this->saveRecord();
  cout << "本届比赛完毕!" << endl;

  //比赛结束后重置所有数据,并获取记录
  this->initSpeech();
  this->createSpeaker();
  this->loadRecord();

  system("pause");
  system("cls");
}

//定义显示分数方法
void SpeechManager::showScore() {
  cout << "----------第" << this->m_Index << "轮晋级选手信息如下:----------"
       << endl;
  vector<int> v; //临时容器
  if (this->m_Index == 1)
    v = v2;
  else
    v = vVictory;
  for (auto it = v.begin(); it != v.end(); it++)
    cout << "选手编号:" << *it << " 姓名:" << m_Speaker[*it].getName()
         << " 成绩:" << m_Speaker[*it].getScore(this->m_Index - 1) << endl;
  cout << endl;
  system("pause");
  system("cls");
  this->show_Menu();
}

//定义保存记录方法
void SpeechManager::saveRecord() {
  ofstream ofs;
  //用追加(app)的方式写文件
  ofs.open("speech.csv", ios::out | ios::app);

  //将冠亚季军选手的数据写入文件
  for (auto it = vVictory.begin(); it != vVictory.end(); it++)
    ofs << *it << "," << m_Speaker[*it].getScore(1) << ",";
  ofs << endl;
  ofs.close();
  cout << "决赛前三名记录已保存" << endl;
  //更改文件不为空的状态
  this->fileIsEmpty = false;
}

//定义读入记录方法
void SpeechManager::loadRecord() {
  ifstream ifs("speech.csv", ios::in);
  if (!ifs.is_open()) {
    this->fileIsEmpty = true;
    cout << "文件不存在!" << endl;
    ifs.close();
    return;
  }

  char ch;
  ifs >> ch;
  if (ifs.eof()) {
    cout << "文件为空!" << endl;
    this->fileIsEmpty = true;
    ifs.close();
    return;
  }

  //文件存在且不为空时
  this->fileIsEmpty = false;
  ifs.putback(ch); //刚才读取的单个字符放回
  string data;
  int index = 0;
  //将ifs中的内容读到data中
  while (ifs >> data) {
    vector<string> v;
    int pos = -1;
    int start = 0;
    while (true) {
      pos = data.find(",", start); //在字符串中从0位开始查找","
      if (pos == -1)               //没找到返回-1
        break;
      //找到了,pos为当前","的位置.pos-start从start开始到","之间字符串的长度,用substr将两个","之间的字符串分割出来
      string tmp = data.substr(start, pos - start);
      v.push_back(tmp);
      //重定位find开始寻找的位置为当前","的下一个位置,并将它设置为substr分割的起始位置
      start = pos + 1;
    }
    this->m_Record.insert(make_pair(index, v));
    index++;
  }
  ifs.close();
}

//定义往届得分显示方法
void SpeechManager::showRecord() {
  if (this->fileIsEmpty)
    cout << "文件不存在,或记录为空" << endl;
  for (int i = 0; i < this->m_Record.size(); i++)
    cout << "第" << i + 1 << "届"
         << " 冠军编号:" << this->m_Record[i][0]
         << " 得分:" << this->m_Record[i][1] << " "
         << " 亚军编号:" << this->m_Record[i][2]
         << " 得分:" << this->m_Record[i][3] << " "
         << " 季军编号:" << this->m_Record[i][4]
         << " 得分:" << this->m_Record[i][5] << endl;
  system("pause");
  system("cls");
}

//定义清空记录方法
void SpeechManager::clearRecord() {
  cout << "确认清空?" << endl;
  cout << "1.确认" << endl;
  cout << "2.返回" << endl;
  int select = 0;
  cin >> select;
  if (select == 1) {
    // ios::trunc,如果文件存在则删除并重新创建
    ofstream ofs("speech.csv", ios::trunc);
    ofs.close();
    this->initSpeech();
    this->createSpeaker();
    this->loadRecord();
    cout << "清空成功!" << endl;
  }
  system("pause");
  system("cls");
}
