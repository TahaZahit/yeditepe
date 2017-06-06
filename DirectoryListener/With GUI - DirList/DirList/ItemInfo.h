#pragma once 
namespace DirList {
	using namespace System;
	public ref class ItemInfo
	{
	private:
		String^ Name;
		String^ Type;
		long long Size;

	public:
		ItemInfo(String^ fName, String^ typeName, long byteSize)
		{
			this->Name = fName;
			this->Type = typeName;
			this->Size = byteSize;
		}
		property String^ FileName
		{
			String^ get() { return Name; }
		}
		property String^ TypeName
		{
			String^ get() { return Type; }
		}
		property long ByteSize
		{
			long get() { return Size; }
		}

	};

	public ref class Node
	{
	public:
		ItemInfo^ Item;
		Node^ NameNext;
		Node^ NamePrev;
		Node^ TypeNext;
		Node^ TypePrev;
		Node^ SizeNext;
		Node^ SizePrev;
		Node(ItemInfo^ item) {
			this->Item = item;
		}
	};

	public ref class NodeList
	{
	public:
		Node^ NameHead;
		Node^ NameTail;

		Node^ TypeHead;
		Node^ TypeTail;

		Node^ SizeHead;
		Node^ SizeTail;
	
		NodeList()
		{

		}
		void Remove(String^ fileName) {
			Node^ temp=NameHead;
			while (temp != nullptr) {
				if (temp->Item->FileName == fileName) {
					RemoveNode(temp);
					break;
				}
				temp = temp->NameNext;
			}

	}
	void RemoveNode(Node^ temp){

			if (temp == nullptr)return;

			if (SizeHead == SizeTail)SizeHead = SizeTail = nullptr;
			
			else if (temp == SizeHead)
			{
				
				SizeHead = SizeHead->SizeNext;
				if(SizeHead!=nullptr)SizeHead->SizePrev = nullptr;
			}
			else if (temp == SizeTail)
			{
				SizeTail = SizeTail->SizePrev;
				SizeTail->SizeNext = nullptr;
			}
			else
			{
				temp->SizeNext->SizePrev = temp->SizePrev;
				temp->SizePrev->SizeNext = temp->SizeNext;
			}

			if (NameHead == NameTail) {
				NameHead = NameTail = nullptr;
			}
			else if (temp == NameHead)
			{

				NameHead = NameHead->NameNext;
				if (NameHead != nullptr)NameHead->NamePrev = nullptr;
			}
			else if (temp == NameTail)
			{
				NameTail = NameTail->NamePrev;
				NameTail->NameNext = nullptr;
			}
			else
			{
				temp->NameNext->NamePrev = temp->NamePrev;
				temp->NamePrev->NameNext = temp->NameNext;
			}

			if (TypeHead == TypeTail)TypeHead = TypeTail = nullptr;

			else if (temp == TypeHead)
			{
				TypeHead = TypeHead->TypeNext;
				if(TypeHead!=nullptr)TypeHead->TypePrev = nullptr;
			}
			else if (temp == TypeTail)
			{
				TypeTail = TypeTail->TypePrev;
				TypeTail->TypeNext = nullptr;
			}
			else
			{
				temp->TypeNext->TypePrev = temp->TypePrev;
				temp->TypePrev->TypeNext = temp->TypeNext;
			}

			delete temp;
		}

		void Clear()
		{
			Node^ temp = SizeHead;

			if (temp == nullptr)return;
			while (temp->SizeNext != nullptr)
			{
				temp = temp->SizeNext;
				delete temp->SizePrev;
			}
			if(SizeTail!=nullptr)delete SizeTail;
			SizeHead = SizeTail = NameHead = NameTail = TypeHead = TypeTail = nullptr;
			
		}
		void Add(ItemInfo^ item)
		{
			Node^ node = gcnew Node(item);
			AddName(node);
			AddType(node);
			AddSize(node);
		}
		void AddName(Node^ node)
		{
			if (NameHead == nullptr)
			{
				NameHead = NameTail = node;
			}
			else
			{
				Node^ temp = NameHead;
				while (temp!=nullptr)
				{
					if (String::Compare(node->Item->FileName,temp->Item->FileName)<0)
					{
						if (temp == NameHead)
						{
							NameHead->NamePrev = node;
							node->NameNext = temp;
							NameHead = node;
							break;
						}
						else
						{
							node->NameNext = temp;
							temp->NamePrev->NameNext = node;
							node->NamePrev = temp->NamePrev;
							temp->NamePrev = node;
							break;
						}
					}
					else
					{
						if (temp->NameNext == nullptr)
						{
							temp->NameNext = node;
							node->NamePrev = temp;
							NameTail = node;
							break;
						}
					}
					temp = temp->NameNext;
				}
			}
		}
		void AddType(Node^ node)
		{
			if (TypeHead == nullptr)
			{
				TypeHead = TypeTail = node;
			}
			else
			{
				Node^ temp = TypeHead;
				while (temp != nullptr)
				{
					if (String::Compare(node->Item->TypeName, temp->Item->TypeName)<0)
					{
						if (temp == TypeHead)
						{
							TypeHead->TypePrev = node;
							node->TypeNext = temp;
							TypeHead = node;
							break;
						}
						else
						{
							node->TypeNext = temp;
							temp->TypePrev->TypeNext = node;
							node->TypePrev = temp->TypePrev;
							temp->TypePrev = node;
							break;
						}
					}
					else
					{
						if (temp->TypeNext == nullptr)
						{
							temp->TypeNext = node;
							node->TypePrev = temp;
							TypeTail = node;
							break;
						}
					}
					temp = temp->TypeNext;
				}
			}
		}
		void AddSize(Node^ node)
		{
			if (SizeHead == nullptr)
			{
				SizeHead = SizeTail = node;
			}
			else
			{
				Node^ temp = SizeHead;
				while (temp != nullptr)
				{
					if (node->Item->ByteSize < temp->Item->ByteSize)
					{
						if (temp == SizeHead)
						{
							SizeHead->SizePrev = node;
							node->SizeNext = temp;
							SizeHead = node;
							break;
						}
						else
						{
							node->SizeNext = temp;
							temp->SizePrev->SizeNext = node;
							node->SizePrev = temp->SizePrev;
							temp->SizePrev = node;
							break;
						}
					}
					else
					{
						if (temp->SizeNext == nullptr)
						{
							temp->SizeNext = node;
							node->SizePrev = temp;
							SizeTail = node;
							break;
						}
					}
					temp = temp->SizeNext;
				}
			}
		}

	};

}