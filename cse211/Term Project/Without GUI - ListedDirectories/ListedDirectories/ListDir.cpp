#include "ListDir.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <windows.h>

#define PAGINATION 40

char* substr(char const* input, size_t start, size_t len)
{
	char* ret = static_cast<char*>(malloc(len + 1));
	memcpy(ret, input + start, len);
	ret[len] = '\0';
	return ret;
}

void ListDir::PrintInfo(const Info info) const {
	std::cout << "\t|";
	std::cout.width(14);
	std::string size = info.size ? std::to_string(info.size) : " "; 
	std::cout << std::right << size << " |";
	std::cout.width(6);
	std::cout << std::right << info.type << "\t | ";;
	std::cout.width(30);
	std::cout << std::left << info.name;
	std::cout << "|" << std::endl;
}


Node::Node(const Info el)
{
	info = el;
	sizeNext = sizePrev = nameNext = namePrev = typeNext = typePrev = nullptr;
}

ListDir::ListDir()
{
	sizeHead = sizeTail = nameHead = nameTail = typeHead = typeTail = nullptr;
}

void ListDir::AddNode(const Info el)
{
	Node* node = new Node(el);
	AddSize(*node);
	AddName(*node);
	AddType(*node);
}

void ListDir::Directory(std::string el)
{
	HANDLE dir;
	WIN32_FIND_DATA file_data;
	el = el + "*";
	if ((dir = FindFirstFile(el.c_str(), &file_data)) == INVALID_HANDLE_VALUE)
		return; /* No files found */
	do
	{
		const std::string file = file_data.cFileName;
		const bool is_directory = (file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
		Info info;

		//Find filetype filename and filesize
		if (is_directory)
		{
			info.type = "<DIR>";
			info.name = file;
		}

		else//not a directory
		{
			int i;
			for (i = file.size() - 1; file[i] != '.' && i > 0; i--);

			if (i > 0)
			{
				info.type.append(substr(file.c_str(), i + 1, file.size() - i));
			}
			info.name = file;
		}
		info.size = file_data.nFileSizeLow;
		AddNode(info);
	} while (FindNextFile(dir, &file_data));

	FindClose(dir);
}

void ListDir::PrintBySize() const
{
	Node* temp = sizeHead;
	int counter = 0;
	getchar();//for buffer cleaning

	std::cout << "\n\t|------SIZE-----|--TYPE--|-------------NAME--------------|\n";
	while (temp != nullptr)
	{
		counter++;
		PrintInfo(temp->info);
		temp = temp->sizeNext;
		if (!(counter % PAGINATION))
		{
			std::cout << "Press enter to continue..." << std::endl;
			getchar();
			system("CLS");
		}
	}
	std::cout << "\t|--------------------------------------------------------|\n";
}

void ListDir::PrintByName() const
{
	Node* temp = nameHead;
	int counter = 0;
	getchar();//for buffer cleaning

	std::cout << "\n\t|------SIZE-----|--TYPE--|-------------NAME--------------|\n";
	while (temp != nullptr)
	{
		counter++;
		PrintInfo(temp->info);
		temp = temp->nameNext;
		if (!(counter % PAGINATION))
		{
			std::cout << "Press enter to continue..." << std::endl;
			getchar();
			system("CLS");
		}
	}
	std::cout << "\t|--------------------------------------------------------|\n";
}

void ListDir::PrintByType() const
{
	Node* temp = typeHead;
	int counter = 0;

	getchar();//for buffer cleaning

	std::cout << "\n\t|------SIZE-----|--TYPE--|-------------NAME--------------|\n";
	while (temp != nullptr)
	{
		counter++;
		PrintInfo(temp->info);
		temp = temp->typeNext;
		if (!(counter % PAGINATION))
		{
			std::cout << "Press enter to continue..." << std::endl;
			getchar();
			system("CLS");
		}
	}
	std::cout << "\t|--------------------------------------------------------|\n";
}

void ListDir::RemoveAll()
{
	Node* temp = sizeHead;
	while (temp->sizeNext != nullptr)
	{
		temp = temp->sizeNext;
		delete temp->sizePrev;
	}
	delete sizeTail;
	sizeHead = sizeTail = nameHead = nameTail = typeHead = typeTail = nullptr;
}
void ListDir::RemoveNode(Node * temp) {

	if (temp == nullptr)return;
	if (temp == sizeHead)
	{
		sizeHead = sizeHead->sizeNext;
		sizeHead->sizePrev = nullptr;
	}
	else if (temp == sizeTail)
	{
		sizeTail = sizeTail->sizePrev;
		sizeTail->sizeNext = nullptr;
	}
	else
	{
		temp->sizeNext->sizePrev = temp->sizePrev;
		temp->sizePrev->sizeNext = temp->sizeNext;
	}

	if (temp == nameHead)
	{
		nameHead = nameHead->nameNext;
		nameHead->namePrev = nullptr;
	}
	else if (temp == nameTail)
	{
		nameTail = nameTail->namePrev;
		nameTail->nameNext = nullptr;
	}
	else
	{
		temp->nameNext->namePrev = temp->namePrev;
		temp->namePrev->nameNext = temp->nameNext;
	}
	if (temp == typeHead)
	{
		typeHead = typeHead->typeNext;
		typeHead->typePrev = nullptr;
	}
	else if (temp == typeTail)
	{
		typeTail = typeTail->typePrev;
		typeTail->typeNext = nullptr;
	}
	else
	{
		temp->typeNext->typePrev = temp->typePrev;
		temp->typePrev->typeNext = temp->typeNext;
	}

	delete temp;
}
void ListDir::RemoveBySize(int size)
{
	Node* temp = sizeHead;
	while (temp != nullptr)
	{
		if (temp->info.size != size) temp = temp->sizeNext;
		else break;
	}
	if (temp == nullptr)return;
	RemoveNode(temp);
}

void ListDir::RemoveByName(std::string name)
{
	Node* temp = nameHead;

	while (temp != nullptr)
	{
		if (strcmp(temp->info.name.c_str(), name.c_str()) != 0) temp = temp->nameNext;
		else break;
	}
	if (temp == nullptr)return;
	RemoveNode(temp);

}

void ListDir::RemoveByType(std::string type)
{
	Node* temp = typeHead;
	while (temp != nullptr)
	{
		if (strcmp(temp->info.type.c_str(), type.c_str()) != 0) temp = temp->typeNext;
		else break;
	}
	if (temp == nullptr)return;
	RemoveNode(temp);
}

void ListDir::SearchByName(std::string name)
{
	Node* temp = nameHead;
	std::cout << "\n\t|------SIZE-----|--TYPE--|-------------NAME--------------|\n";

	while (temp != nullptr)
	{

		if (strcmp(temp->info.name.c_str(), name.c_str())) temp = temp->nameNext;
		else {
			PrintInfo(temp->info);
			std::cout << "\t|--------------------------------------------------------|\n";
			return;
		}

	}
	std::cout << "Not Found!\n";
}

void ListDir::SearchBySize(int size)
{
	Node* temp = sizeHead;
	int count = 0;
	std::cout << "\n\t|------SIZE-----|--TYPE--|-------------NAME--------------|\n";

	while (temp != nullptr)
	{

		if (temp->info.size > size) {
			PrintInfo(temp->info);
			count++;
		}

		temp = temp->sizeNext;

	}
	if (!count)std::cout << "Not Found!\n";
	std::cout << "\t|--------------------------------------------------------|\n";


}

void ListDir::SearchByType(std::string type)
{
	Node* temp = typeHead;
	int count = 0;
	std::cout << "\n\t|------SIZE-----|--TYPE--|-------------NAME--------------|\n";

	while (temp != nullptr)
	{

		if (!strcmp(temp->info.type.c_str(), type.c_str())) {
			PrintInfo(temp->info);
			count++;
		}
		temp = temp->typeNext;
	}
	if (!count)std::cout << "Not Found!\n";
	std::cout << "\t|--------------------------------------------------------|\n";

}


void ListDir::AddSize(Node& el)
{
	if (sizeHead != nullptr)
	{
		Node* temp = sizeHead;

		while (temp != nullptr)
		{
			if (el.info.size < temp->info.size)
			{
				if (temp == sizeHead)
				{
					sizeHead->sizePrev = &el;
					el.sizeNext = temp;
					sizeHead = &el;
					return;
				}
				else
				{
					el.sizeNext = temp;
					temp->sizePrev->sizeNext = &el;
					el.sizePrev = temp->sizePrev;
					temp->sizePrev = &el;
					return;
				}
			}
			else if (temp->sizeNext == nullptr)
			{
				temp->sizeNext = &el;
				el.sizePrev = temp;
				sizeTail = &el;
				return;
			}
			temp = temp->sizeNext;
		}
	}
	else
	{
		sizeHead = sizeTail = &el;
	}
}

void ListDir::AddName(Node& el)
{
	if (nameHead != nullptr)
	{
		Node* temp = nameHead;

		while (temp != nullptr)
		{
			std::string n1 = el.info.name;
			for (int i = 0; i < n1.size(); i++) n1[i] = tolower(n1[i]);
			std::string n2 = temp->info.name;
			for (int i = 0; i < n2.size(); i++) n2[i] = tolower(n2[i]);

			if (strcmp(n1.c_str(), n2.c_str()) == -1)
			{
				if (temp == nameHead)
				{
					nameHead->namePrev = &el;
					el.nameNext = temp;
					nameHead = &el;
					return;
				}
				else
				{
					el.nameNext = temp;
					temp->namePrev->nameNext = &el;
					el.namePrev = temp->namePrev;
					temp->namePrev = &el;
					return;
				}
			}
			else if (temp->nameNext == nullptr)
			{
				temp->nameNext = &el;
				el.namePrev = temp;
				nameTail = &el;
				return;
			}
			temp = temp->nameNext;
		}
	}
	else
	{
		nameHead = nameTail = &el;
	}
}

void ListDir::AddType(Node& el)
{
	if (typeHead != nullptr)
	{
		Node* temp = typeHead;

		while (temp != nullptr)
		{
			std::string n1 = el.info.type;
			for (int i = 0; i < n1.size(); i++) n1[i] = tolower(n1[i]);
			std::string n2 = temp->info.type;
			for (int i = 0; i < n2.size(); i++) n2[i] = tolower(n2[i]);
			if (strcmp(n1.c_str(), n2.c_str()) == -1)
			{
				if (temp == typeHead)
				{
					typeHead->typePrev = &el;
					el.typeNext = temp;
					typeHead = &el;
					return;
				}
				else
				{
					el.typeNext = temp;
					temp->typePrev->typeNext = &el;
					el.typePrev = temp->typePrev;
					temp->typePrev = &el;
					return;
				}
			}
			else if (temp->typeNext == nullptr)
			{
				temp->typeNext = &el;
				el.typePrev = temp;
				typeTail = &el;
				return;
			}
			temp = temp->typeNext;
		}
	}
	else
	{
		typeHead = typeTail = &el;
	}
}

