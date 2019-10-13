#include<iostream>
#include"TextQuery.h"


int main(int argc, char** argv)
{
	if (argc == 1)
	{
		std::cerr << "Parameterless input" << endl;
		return 1;
	}
	TextQuery txt;
	if (strcmp(argv[1], "-i") == 0)
	{
		txt.open(argv[2]);
	}
	else
	{
		std::cerr << "fail to find txt ! ";
		return 1;
	}
	vector<std::pair<string,string>> _argv;
	for (int i = 1; i != argc; ++i)
	{
		if (strcmp(argv[i] , "-i")==0 || strcmp(argv[i] ,"-m")==0 || strcmp(argv[i] , "-n")==0 || strcmp(argv[i] ,"-o")==0)
		{
			_argv.push_back(std::make_pair(argv[i], argv[i + 1]));
		}
	}

	auto beg = _argv.begin();
	auto end = _argv.end();
	if (std::find_if(beg, end, find_n) != end)
	{
		auto ix = std::find_if(beg, end, find_n);
		txt.setprintsize(std::stoi(ix->second));
	}
	if (std::find_if(beg, end, find_m) != end)
	{
		auto ix = std::find_if(beg, end, find_m);
		txt.countwords(std::stoi(ix->second));
	}
	txt.print(std::cout);
	if (std::find_if(beg, end, find_o) != end)
	{
		auto ix = std::find_if(beg, end, find_o);
		ofstream output(ix->second, ofstream::app);
		txt.print(output);
	}
	
	return 0;
}
