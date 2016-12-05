/*************************************************************************
    > File Name: stringtool.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月05日 星期一 13时39分55秒
 ************************************************************************/

#include<stringtool.h>

std::vector<std::string> StringTool::splitstring(const std::string& str,const char delimiter=' '){
	std::vector<std::string> splited;
	std::string s(str);
	size_t pos;
	while((pos = s.find(delimiter)) != std::string::npos){
		std::string sec = s.substr(0,pos);
		if(!sec.empty()){
			splited.push_back(s.substr(0,pos));
		}
		s = s.substr(pos+1);
	}
	splited.push_back(s);
	return splited;
}


