#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "cat.h"
#include "dog.h"
using namespace std;

int main()
{
	vector<string> svec;

	svec.push_back("hello");
	svec.push_back("c++");
	svec.push_back("STL");
	svec.push_back("and");
	svec.push_back("program");
	list<string> llist(svec.begin(),
		svec.end()); //使用迭代器將vector容器轉爲list容器
	list<string>::iterator iter;
	vector<string>::iterator mid = svec.begin() + svec.size() / 2; //定位到svec的中間位置
	deque<string> defront(
		svec.begin(),
		mid); //用迭代器將svec從begin到mid(不包括)的元素轉爲deque容器中.
	deque<string>::iterator deiter = defront.begin();
	for (deiter; deiter != defront.end(); deiter++)
		cout << *deiter << endl;
	cout << "-----------------" << endl;
	for (iter = llist.begin(); iter != llist.end(); iter++)
		cout << *iter << endl;
	vector<Dog> dogvec;
	list<Cat> catlist;
	vector<vector<string>> line; //容器的容器
	line.push_back(svec);
	vector<vector<string>>::iterator liiter = line.begin();
	cout << "-----------------" << endl;
	for (liiter; liiter != line.end();
		liiter++)
	{ //外層迭代器,指向每一個内層vector
		vector<string> temp = *liiter; //將當前指向的vector建立臨時vector
		vector<string>::iterator it; //建立迭代器
		for (it = temp.begin(); it != temp.end(); it++)
			cout << *it << endl; //迭代輸出
	}

	return 0;
}