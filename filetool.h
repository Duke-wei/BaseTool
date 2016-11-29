/*************************************************************************
    > File Name: filetool.h
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年11月29日 星期二 20时17分35秒
 ************************************************************************/
#ifndef FILETOOL_H_
#define FILETOOL_H_

#include<iostream>
#include<string>
#include<vector>
#include <list>
#include<cstdio>
#include<cstdlib>
#include <cstring>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

namespace basetool{
	class FileTool{
		public:
			static std::string getFileName(const std::string& path, const bool postfix=false);

			static std::vector<std::string> getFiles(const std::string& folder, const bool all=true);

			static bool mkdir(const std::string folder);

			static bool mkfile(const std::string filename);

			static bool rmfile(const std::string filename);

			static bool rmdir(const std::string folder,const bool andsubfolder=true);

		private:
			static std::size_t get_last_slash(const std::string& path);

	};
}
