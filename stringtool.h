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

namespace basetool{
	class StringTool{
		public:
			static std::vector<std::string> splitstring(const std::string& str,const char delimiter=' ');

	};
}

#endif

