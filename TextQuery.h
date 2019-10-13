#pragma once
#include<sstream>
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>
#include<utility>
#include<string>
#include<iostream>
using std::ifstream;
using std::ofstream;
using std::vector;
using std::string;
using std::shared_ptr;
using std::map;
using std::istringstream;
using std::transform;
using std::ostream;
using std::endl;
class TextQuery
{
	friend ostream& operator<<(ostream& os, TextQuery& item);
public:
	TextQuery(const string&);
	TextQuery() = default;
	bool open(const string&);
	auto size() const { return allwords.size(); }
	auto line() const { return line_no; }
	auto charsize() const { return char_size; }
	void setprintsize(int _size)
	{
		printsize=_size;
	}
	void countwords(int n);
	void print(ostream& os);
private:
	vector<string> file;
	map<string, size_t> word_count;
	vector < std::pair< string, size_t> >words_sorted;
	int line_no = 0;
	int char_size = 0;
	int printsize = 10;
	map<string, size_t> vec;
	void datapcs();
	vector<string> allwords;
};
bool find_n(std::pair<string, string>& a);
bool find_m(std::pair<string, string>& a);
bool find_o(std::pair<string, string>& a);