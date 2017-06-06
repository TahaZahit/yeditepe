#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "ListDir.h"
//#include "ListDir.h"
using namespace std;




int main(int argc, char* argv[])
{
	
	HANDLE dir;
	WIN32_FIND_DATA file_data;
	
	if ((dir = FindFirstFile("c:\\*", &file_data)) == INVALID_HANDLE_VALUE)
		return 0; /* No files found */

	do {
		const std::string file = file_data.cFileName;
		const bool is_directory = (file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
		Info info;

		if (file[0] == '.')
			continue;
		//findtype filename and filesize
		if (is_directory)
		{
			info.type = "directory";
			info.name = file;

		}

		else {
			int i;
			for (i = file.size() - 1 ; file[i] != '.'&& i>0; i--);
			if(i>0)
			{
				info.type.append(substr(file.c_str(), i + 1, file.size() - i));
				info.name.append(substr(file.c_str(), 0, i));
			}
			else
			{
				info.name=file;
			}
			
		}
		info.size = file_data.nFileSizeLow;
		


	} while (FindNextFile(dir, &file_data));

	FindClose(dir);
	getchar();
}


//int main(void)
//{
//	HANDLE hFind;
//	WIN32_FIND_DATA data;
//
//	hFind = FindFirstFile("c:\\*", &data);
//
//	if (hFind != INVALID_HANDLE_VALUE)
//	{
//		do
//		{
//			printf("%s\t%d\t%d\n", data.cFileName, data.nFileSizeLow, GetFileType(hFind));
//		}
//		while (FindNextFile(hFind, &data));
//		FindClose(hFind);
//	}
//	experimental::filesystem::path p("c:\\*.exe");
//	cout << "filename and extension : " << p.filename() << std::endl; // file.ext
//	cout << "filename only          : " << p.extension() << std::endl; // .ext
//	getchar();
//}

//int main(int argc, char* argv[])
//{
//
//	HANDLE hFind;
//	WIN32_FIND_DATA data;
//	
//	hFind = FindFirstFile("c:\\*", &data);
//	
//	if (hFind != INVALID_HANDLE_VALUE) {
//		do {
//			printf("%s\t%d\t%d\n", data.cFileName,data.nFileSizeLow,GetFileType(hFind));
//		} while (FindNextFile(hFind, &data));
//		FindClose(hFind);
//	}
//	/*
//	ListDir list;
//
//	Info x;
//	x.size = 1;
//	x.name = "a";
//	list.addNode(x);
//	x.size = 2;
//	x.name = "b";
//	list.addNode(x);
//	x.size = 3;
//	x.name = "c";
//	list.addNode(x);
//	x.size = 4;
//	x.name = "d";
//	list.addNode(x);
//	x.size = 3;
//	x.name = "c";
//	list.addNode(x);
//	x.size = 5;
//	x.name = "e";
//	list.addNode(x);
//
//	Node *temp = list.sizeHead;
//	while (temp!=nullptr)
//	{
//		cout << temp->info.name << endl;
//		temp = temp->nameNext;
//	}*/
//
//	getchar();
//
//}
