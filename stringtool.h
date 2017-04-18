/*************************************************************************
    > File Name: stringtool.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年12月05日 星期一 13时34分39秒
 ************************************************************************/
#ifndef STRINGTOOL_H_
#define STRINGTOOL_H_

#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>

namespace basetool{
	class StringTool{
		public:
			static std::vector<std::string> splitstring(const std::string& str,const char delimiter=' ');
			static std::string chartostring(char *src);
			static const char* stringtochar(std::string src);
			static int stringKMP(std::string src,std::string part);
			static bool isomorphic(std::string src,std::string src2);
			static bool ispalindromic(std::string src);
	};
}

#endif

