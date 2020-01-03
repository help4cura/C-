#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <map>

using namespace std;

int main()
{
	//vector
	const char* str = "0123456789";
	vector<char> vc(&str[0], &str[10]);

	vector<char>::iterator vc_iterator;

	//vector 맨 끝에 특정 요소 삽입
	vc.push_back('A');
	//

	//vector 중간에 삽입
	vc.insert(vc.begin() + 3, 'B');
	//

	//vector 맨 끝에 요소를 삭제
	vc.pop_back();
	//

	for (vc_iterator = vc.begin(); vc_iterator < vc.end(); vc_iterator++)
	{
		cout << *vc_iterator << endl;
	}

	//vector의 크기(size)
	cout << vc.size();
	cout << endl;
	//

	//list

	list<string> lc;

	lc.push_back("A");
	lc.push_back("B");
	lc.push_back("C");
	lc.push_back("D");
	lc.push_back("E");
	lc.push_back("F");
	lc.push_back("G");
	lc.push_back("H");

	list<string>::iterator lc_iterator;
	for (lc_iterator = lc.begin(); lc_iterator != lc.end(); lc_iterator++) 
	{
		cout << *lc_iterator << endl;
	}

	//map
	map<string, int> m;

	//map 삽입
	m.insert(pair<string, int> (string("서울"), 1000));
	m.insert(pair<string, int> ("부산", 500));
	m["대전"] = 400;
	m["대구"] = 300;
	m["광주"] = 200;
	m["인천"] = 100;

	//map 삭제
	m.erase("인천");

	//map 출력
	map <string, int>::iterator m_iterator;
	for (m_iterator = m.begin(); m_iterator != m.end(); m_iterator++)

	{
		cout << m_iterator->first << " : " << m_iterator->second << "만 명"<< endl;
	}

	return 0;
}