/*************************************************************************
    > File Name: filetool.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2016年11月29日 星期二 20时22分26秒
 ************************************************************************/

#include "filetool.h"
#define PATH_DELIMITER '/'
namespace basetool{
	std::string FileTool::getFileName(const std::string& path,const bool postfix/*=false*/){
		if(!path.empty()){
			std::size_t last_slash = FileTool::get_last_slash(path);
			std::size_t last_dot = path.find_last_of('.');
			if(last_dot<last_slash || last_dot==std::string::npos){
				//not found the right dot of the postfix,
				//return the file name diretcly
				return path.substr(last_slash+1);
			}else{
				//the path has a postfix
				if(postfix){
					//return the file name including postfix
					return path.substr(last_slash+1);
				}
				//without postfix
				return path.substr(last_slash+1,last_dot - last_slash -1);
			}
		}
		return "";
	}

	std::vector<std::string> FileTool::getFiles(const std::string& folder,const bool all/*=true*/){
		std::vector<std::string> files;
		std::list<std::string> subfolders;
		subfolders.push_back(folder);
		while(!subfolders.empty()){
			std::string current_folder(subfolders.back());
			if(*(current_folder.end()-1)!='/'){
				current_folder.push_back('/');
			}
			DIR* pdir = opendir(current_folder.c_str());
			subfolders.pop_back();
			if(!pdir){
				continue;
			}
			dirent* dir = NULL;
			while((dir=readdir(pdir))!=NULL){
				struct stat st;
				if(all && (!strcmp(dir->d_name,".")||!strcmp(dir->d_name,".."))){
					//must ignore .& ..
					continue;
				}
				std::string file_path;
				file_path.append(current_folder.c_str());
				file_path.append(dir->d_name);
				if(lstat(file_path.c_str(),&st)<0){
					//perror("lastat")
					continue;
				}
				if(S_ISDIR(st.st_mode)){
					//it's a subfolder
					if(all){
						//will search sub folder , so push back to subfolders
						std::string subfolder(current_folder);
						subfolder.append(dir->d_name);
						subfolders.push_back(subfolder.c_str());
					}
				}else{
					//it's a file
					files.push_back(file_path);
				}
			}//end while
			closedir(pdir);
		}
		return files;
	}

	bool FileTool::mkdir(const std::string folder){
		std::string folder_builder;
		std::string sub;
		sub.reserve(folder.size());
		for(auto it=folder.begin();it!=folder.end();++it){
			const char c = *it;
			sub.push_back(c);
			if(c==PATH_DELIMITER || it==folder.end()-1){
				folder_builder.append(sub);
				if(0!=::access(folder_builder.c_str(),0)){
					if(0!=::mkdir(folder_builder.c_str(),S_IRWXU)){
						return false;
					}
				}
				sub.clear();
			}
		}
		return true;
	}

	bool FileTool::mkfile(const std::string filename){
		FILE *fp;
		fp = ::fopen(filename.c_str(),"w");
		if(fp==NULL) return false;
		::fclose(fp);
		return true;
	}

	bool FileTool::rmfile(const std::string filename){
		if(::remove(filename.c_str())==0) return true;
		return false;
	}

	//***LMTW learn more to write this function!!!
	bool FileTool::rmdir(const std::string folder,const bool andsubfolder=true){
		std::vector<std::string> subfile = FileTool::getFiles(folder.c_str());
		for(auto file=subfile.begin();file!=subfile.end();++file){
			struct stat st;
			if(!((*file)==".")||!((*file)=="..")){
				//must ignore .& ..
				continue;
			}
			lstat((*file).c_str(),&st);
			if(S_ISDIR(st.st_mode)){
				//it's a subfolder
				FileTool::rmdir(file);
			}else{
				//it's a file
				FileTool::rmfile(file);
			}
		}
		if(::rmdir(folder.c_str())==0) return true;
		return false;
	}

	std::size_t FileTool::get_last_slash(const std::string& path){
		size_t last_slash=path.find_last_of('/');
		return last_slash;
	}
}
