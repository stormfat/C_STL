/*������:
1.��ʼ�ݽ�����:����������������,ÿ�������׶���Ҫ���û�һ����ʾ,�û���������������һ���׶�
2.�鿴�����¼:�鿴֮ǰ������ǰ������Ϣ,ÿ�α��������¼��.csv�ļ���
3.��ձ�����¼:���ļ��������
4.�˳���������:�����˳���ǰ����*/

#include "speechmanager.h"
#include <algorithm> //greater
#include <deque>
#include <numeric> //accumulate

//���幹�캯��
SpeechManager::SpeechManager() {
  //��ʼ������������
  this->initSpeech();

  //����ѡ��
  this->createSpeaker();

  //��ȡ��¼
  this->loadRecord();
}

//������������
SpeechManager::~SpeechManager() {}

//����˵���ʾ����
void SpeechManager::show_Menu() {
  cout << "***************************************" << endl;
  cout << "*********** ��ӭ�μ��ݽ����� **********" << endl;
  cout << "*********** 1.��ʼ�ݽ����� ************" << endl;
  cout << "*********** 2.�鿴�����¼ ************" << endl;
  cout << "*********** 3.��ձ�����¼ ************" << endl;
  cout << "*********** 0.�˳��������� ************" << endl;
  cout << "***************************************" << endl;
  cout << endl;
}

//�����˳�����
void SpeechManager::exitSystem() {
  cout << "��ӭ�´�ʹ��!" << endl;
  system("pause");
  exit(0);
}

//�����Ա��ʼ������
void SpeechManager::initSpeech() {
  //�����ÿ�
  this->v1.clear();
  this->v2.clear();
  this->vVictory.clear();
  this->m_Speaker.clear();
  //��ʼ������
  this->m_Index = 1;
  //��ռ�¼����
  this->m_Record.clear();
}

//����ѡ��
void SpeechManager::createSpeaker() {
  string nameSeed = "ABCDEFGHIJKL";
  for (size_t i = 0; i < nameSeed.size(); i++) {
    string name = "����";
    name += nameSeed[i];
    Speaker spk;
    spk.setName(name);
    for (int i = 0; i < 2; i++)
      spk.setScore(i, 0);

    // 12��ѡ�ֱ��
    this->v1.push_back(i + 10001);

    //ѡ�ֱ�� �Լ���Ӧ�����ַ���map��
    this->m_Speaker.insert(make_pair(v1[i], spk));
  }
}

//�����ǩ����
void SpeechManager::speechDraw() {
  cout << "��<<" << this->m_Index << ">>�۱���ѡ�����ڳ�ǩ" << endl;
  cout << "----------------------" << endl;
  cout << "��ǩ���ݽ�˳������:" << endl;
  if (this->m_Index == 1) {
    random_shuffle(v1.begin(), v1.end()); //��v1ϴ��
    for (auto it = v1.begin(); it != v1.end(); it++)
      cout << *it << "  "; //���ϴ�ƺ��v1
    cout << endl;
    // this->m_Index = 2; //��������Ϊ��2��.
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

//�����������
void SpeechManager::speechContes() {
  cout << "--------��" << this->m_Index << "�ֱ�����ʼ:--------" << endl;

  //��ʱ����,����key(����),value(ѡ�ֱ��),��������
  multimap<double, int, greater<double>> groupScore;
  int num = 0; //��¼��Ա��,6��Ϊ1��

  vector<int> v_Src; //��������Ա����
  //��������,��v_Srcָ����Ӧ������,��һ��ָ��v1,�ڶ���ָ��v2
  if (this->m_Index == 1)
    v_Src = v1;
  else
    v_Src = v2;

  for (auto it = v_Src.begin(); it != v_Src.end(); it++) {
    num++;
    //ʮ����ί���
    deque<double> dScore;
    for (int i = 0; i < 10; i++) {
      double score = (rand() % 401 + 600) / 10.f;
      dScore.push_back(score);
    }

    //��dScore��������
    sort(dScore.begin(), dScore.end(), greater<double>());
    dScore.pop_front(); //ȥ����߷�
    dScore.pop_back();  //ȥ����ͷ�

    //��ȡ�ܷ�,����һλС��
    double sum = accumulate(dScore.begin(), dScore.end(), 0.0f);
    double avg = sum / (double)dScore.size(); //��ƽ����

    //ͨ��*it(ѡ�ֱ��)����map����Ӧѡ��,���Ե�ǰѡ�ֵ�m_score��ֵ,��Ϊm_score������ʼ�±�Ϊ0,m_Index��ʼ�±�Ϊ1,����Ҫ��m_index-1
    this->m_Speaker[*it].setScore(this->m_Index - 1, avg);

    // 6��һ��,����ʱ��������
    groupScore.insert(make_pair(avg, *it));
    // num�ۼӵ�6��12ʱ����if���
    if (num % 6 == 0) {
      cout << "��" << num / 6 << "С���������:" << endl;
      for (auto it = groupScore.begin(); it != groupScore.end(); it++)
        cout << "���:" << it->second
             << " ����:" << this->m_Speaker[it->second].getName() << " �ɼ�:"
             << this->m_Speaker[it->second].getScore(this->m_Index - 1) << endl;
      int count = 0;
      //ȡǰ����,����ǵ�һ�ַ���v2��,����Ǿ�������vVictory��
      for (auto it = groupScore.begin(); it != groupScore.end() && count < 3;
           count++, it++) {
        if (this->m_Index == 1)
          v2.push_back(it->second);
        else
          vVictory.push_back(it->second);
      }
      groupScore.clear(); //�ӵ�7�˿�ʼ����ͳ��
    }
  }
  cout << "----------��" << this->m_Index << "�ֱ������!----------" << endl;
  system("pause");
}

//���忪ʼ��������
void SpeechManager::startSpeech() {
  //��һ�ֱ���
  // 1.��ǩ
  this->speechDraw();
  //����
  this->speechContes();
  //��ʾ�������
  this->showScore();
  //�ڶ��ֱ���
  this->m_Index++;
  //��ǩ
  this->speechDraw();
  //����
  this->speechContes();
  //��ʾ�������
  this->showScore();
  //������������ѡ�ַ������ļ�
  this->saveRecord();
  cout << "����������!" << endl;

  //����������������������,����ȡ��¼
  this->initSpeech();
  this->createSpeaker();
  this->loadRecord();

  system("pause");
  system("cls");
}

//������ʾ��������
void SpeechManager::showScore() {
  cout << "----------��" << this->m_Index << "�ֽ���ѡ����Ϣ����:----------"
       << endl;
  vector<int> v; //��ʱ����
  if (this->m_Index == 1)
    v = v2;
  else
    v = vVictory;
  for (auto it = v.begin(); it != v.end(); it++)
    cout << "ѡ�ֱ��:" << *it << " ����:" << m_Speaker[*it].getName()
         << " �ɼ�:" << m_Speaker[*it].getScore(this->m_Index - 1) << endl;
  cout << endl;
  system("pause");
  system("cls");
  this->show_Menu();
}

//���屣���¼����
void SpeechManager::saveRecord() {
  ofstream ofs;
  //��׷��(app)�ķ�ʽд�ļ�
  ofs.open("speech.csv", ios::out | ios::app);

  //�����Ǽ���ѡ�ֵ�����д���ļ�
  for (auto it = vVictory.begin(); it != vVictory.end(); it++)
    ofs << *it << "," << m_Speaker[*it].getScore(1) << ",";
  ofs << endl;
  ofs.close();
  cout << "����ǰ������¼�ѱ���" << endl;
  //�����ļ���Ϊ�յ�״̬
  this->fileIsEmpty = false;
}

//��������¼����
void SpeechManager::loadRecord() {
  ifstream ifs("speech.csv", ios::in);
  if (!ifs.is_open()) {
    this->fileIsEmpty = true;
    cout << "�ļ�������!" << endl;
    ifs.close();
    return;
  }

  char ch;
  ifs >> ch;
  if (ifs.eof()) {
    cout << "�ļ�Ϊ��!" << endl;
    this->fileIsEmpty = true;
    ifs.close();
    return;
  }

  //�ļ������Ҳ�Ϊ��ʱ
  this->fileIsEmpty = false;
  ifs.putback(ch); //�ղŶ�ȡ�ĵ����ַ��Ż�
  string data;
  int index = 0;
  //��ifs�е����ݶ���data��
  while (ifs >> data) {
    vector<string> v;
    int pos = -1;
    int start = 0;
    while (true) {
      pos = data.find(",", start); //���ַ����д�0λ��ʼ����","
      if (pos == -1)               //û�ҵ�����-1
        break;
      //�ҵ���,posΪ��ǰ","��λ��.pos-start��start��ʼ��","֮���ַ����ĳ���,��substr������","֮����ַ����ָ����
      string tmp = data.substr(start, pos - start);
      v.push_back(tmp);
      //�ض�λfind��ʼѰ�ҵ�λ��Ϊ��ǰ","����һ��λ��,����������Ϊsubstr�ָ����ʼλ��
      start = pos + 1;
    }
    this->m_Record.insert(make_pair(index, v));
    index++;
  }
  ifs.close();
}

//��������÷���ʾ����
void SpeechManager::showRecord() {
  if (this->fileIsEmpty)
    cout << "�ļ�������,���¼Ϊ��" << endl;
  for (int i = 0; i < this->m_Record.size(); i++)
    cout << "��" << i + 1 << "��"
         << " �ھ����:" << this->m_Record[i][0]
         << " �÷�:" << this->m_Record[i][1] << " "
         << " �Ǿ����:" << this->m_Record[i][2]
         << " �÷�:" << this->m_Record[i][3] << " "
         << " �������:" << this->m_Record[i][4]
         << " �÷�:" << this->m_Record[i][5] << endl;
  system("pause");
  system("cls");
}

//������ռ�¼����
void SpeechManager::clearRecord() {
  cout << "ȷ�����?" << endl;
  cout << "1.ȷ��" << endl;
  cout << "2.����" << endl;
  int select = 0;
  cin >> select;
  if (select == 1) {
    // ios::trunc,����ļ�������ɾ�������´���
    ofstream ofs("speech.csv", ios::trunc);
    ofs.close();
    this->initSpeech();
    this->createSpeaker();
    this->loadRecord();
    cout << "��ճɹ�!" << endl;
  }
  system("pause");
  system("cls");
}
