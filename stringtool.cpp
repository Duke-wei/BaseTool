/*************************************************************************
    > File Name: stringtool.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月05日 星期一 13时39分55秒
 ************************************************************************/

#include<stringtool.h>

namespace basttool{

std::vector<std::string> StringTool::splitstring(const std::string& str,const char delimiter=' '){
	std::vector<std::string> splited;
	std::string s(str);
	std::size_t pos;
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

std::string StringTool::chartostring(char *src) const {
	return std::string(src);
}

const char* StringTool::stringtochar(std::string src) const {
	return src.c_str();
}

int StringTool::stringKMP(std::string src,std::string part){
	if(part.empty()) return 0;
	std::vector<int> next(part.size());
	int j = -1,i=0;
	next[0] = -1;
	while(i < len){
		if(j==-1 || part[i]==part[j]){
			++i;
			++j;
			next[i] = j;
		}else{
			j = next[j];
		}
	}
	int lensrc = src.size();
	int curFind = 0;
	for(int k=0;k<lensrc;){
		if(part[curFind] == src[k]){
			++k;
			++curFind;
		}else{
			if(curFind == 0)
				++i;
			else{
				int movestep = curFind - next[curFind-1];
				k+=movestep;
				curFind = 0;
			}
		}
		if(curFind == part.size()){
			return k-part.size();
		}
	}
	return -1;
}

}
