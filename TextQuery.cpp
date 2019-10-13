#include"TextQuery.h"
bool cmp_first(std::pair<string, size_t>& a, std::pair<string, size_t>& b)
{
	return a.second > b.second;
}
bool cmp_sec(std::pair<string, size_t>& a, std::pair<string, size_t>& b)
{
	return a.first > b.first;
}

TextQuery::TextQuery(const string& str)
{
	ifstream is(str);
	if (!is)
	{
		std::cerr << "fail to open file ! ";
	}
	string text;
	while (getline(is, text))
	{
		char_size += text.size();
		file.push_back(text);
		istringstream line(text);
		string word;
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		while (line >> word)
		{
			++word_count[word];
			allwords.push_back(word);
		}
	}
	line_no = file.size();
}
bool TextQuery::open(const string& str)
{
	ifstream is(str);
	if (!is)
	{
		std::cerr << "fail to open file ! ";
		return false;
	}
	string text;
	while (getline(is, text))
	{
		char_size += text.size();
		file.push_back(text);
		istringstream line(text);
		string word;
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		while (line >> word)
		{
			++word_count[word];
			allwords.push_back(word);
		}
	}
	line_no = file.size();
	return true;
}
ostream& operator<<(ostream& os, TextQuery& item)
{
	item.datapcs();
	os << "charactors : " << item.charsize() << endl << "words : "
		<< item.size() << endl << "lines : " << item.line() << endl;
	for (auto iz : item.words_sorted)
	{
		os << "<" << iz.first << "> : " << iz.second << endl;
	}
	return os;
}
void TextQuery::print(ostream& os)
{
	datapcs();
	os << "charactors : " << charsize() << endl << "words : "
		<< size() << endl << "lines : " << line() << endl;
	os << endl;
	for (auto iz : words_sorted)
	{
		os << "<" << iz.first << "> : " << iz.second << endl;
	}
	if (!vec.empty())
	{
		os << endl;
		for (auto ix : vec)
		{
			os << "<" << ix.first << "> : " << ix.second << endl;
		}
	}
}
void TextQuery::datapcs()
{
	map<string, size_t>::iterator ix = word_count.begin();
	while (ix != word_count.end())
	{
		words_sorted.push_back(*ix);
		++ix;
	}
	//std::copy(item.word_count.begin(), item.word_count.end(), words_sorted.begin());
	std::sort(words_sorted.begin(), words_sorted.end(), cmp_sec);
	std::sort(words_sorted.begin(), words_sorted.end(), cmp_first);
	words_sorted.resize(printsize);
}
void TextQuery::countwords(int n)
{
	
	
	for (int i = 0; i+n < allwords.size(); ++i)
	{
		string str;
		for (int x = i; x < i + n; ++x)
		{
			str +=" "+ allwords.at(x);
		}
		++vec[str];
	}
}
bool find_n(std::pair<string, string>& a)
{
	if (a.first == "-n")
		return true;
	else
		return false;
}
bool find_m(std::pair<string, string>& a)
{
	if (a.first == "-m")
		return true;
	else
		return false;
}
bool find_o(std::pair<string, string>& a)
{
	if (a.first == "-o")
		return true;
	else
		return false;
}