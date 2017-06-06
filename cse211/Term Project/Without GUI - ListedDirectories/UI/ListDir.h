#pragma once
#include <string>

typedef struct
{
	std::string name;
	std::string type;
	unsigned long size;
} Info;

class Node
{
public:
	Node(const Info el);
	Info info;
	Node *sizeNext, *sizePrev;
	Node *nameNext, *namePrev;
	Node *typeNext, *typePrev;
};

class ListDir
{
public:
	ListDir();
	Node *sizeHead, *sizeTail;
	Node *nameHead, *nameTail;
	Node *typeHead, *typeTail;

public:
	void AddNode(const Info el);
	void Directory(std::string el);
	void PrintBySize() const;
	void PrintByName() const;
	void PrintByType() const;
	void RemoveAll();
	void RemoveNode(Node * node);
	void RemoveBySize(int size);
	void RemoveByName(std::string name);
	void RemoveByType(std::string type);
	void SearchBySize(int size);
	void SearchByName(std::string name);
	void SearchByType(std::string type);

private:
	void PrintInfo(const Info info)const;
	void AddSize(Node& el);
	void AddName(Node& el);
	void AddType(Node& el);
	
};
