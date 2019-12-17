#pragma once
#include <iostream>

using namespace std;

typedef struct LinkList{
	char data; //数据
	struct LinkList* _next;
} LinkList;

//初始化
void initLinkList(LinkList* pHead)
{
	pHead->_next = nullptr;
	cout << "初始化完成!" << endl;
}

//销毁链表
void destroyLinkList(LinkList* pHead)
{
	LinkList* pCur = pHead->_next;
	while (pCur)
	{
		LinkList* node = pCur;
		pCur = node->_next;
		delete node;
	}
	pHead = nullptr;
	cout << "销毁完成!" << endl;
}

//申请新的节点
LinkList* buyNewNode()
{
	LinkList* newNode = new LinkList();
	return newNode;
}

//尾插元素
void pushBackData(LinkList* pHead, char ch)
{

	LinkList* newNode = buyNewNode();
	newNode->data = ch;
	LinkList* pCur = pHead;
	for (; pCur->_next != nullptr; pCur = pCur->_next)
	{
	}
	pCur->_next = newNode;
	newNode->_next = nullptr;
}

//头插元素
void pushFrontData(LinkList* pHead, char ch)
{
	LinkList* newNode = buyNewNode();
	newNode->data = ch;
	newNode->_next = pHead->_next;
	pHead->_next = newNode;
}

//头删元素
void popFrontData(LinkList* pHead)
{
	if (pHead->_next == nullptr)
	{
		cout << "链表仅有头节点，删除失败!" << endl;
		return;
	}
	LinkList* pCur = pHead->_next;
	//若只有一个元素，则直接删除
	if (pCur->_next == nullptr)
	{
		//pCur = nullptr;
		delete pCur;
		pCur = nullptr;
		pHead->_next = nullptr;
		return;
	}
	//若有多个元素
	pHead->_next = pCur->_next;
	delete pCur;
}

//尾删元素
void popBackData(LinkList* pHead)
{
	//若链表没有元素（仅有头）
	if (pHead->_next == nullptr)
	{
		cout << "链表没有任何元素，删除失败!" << endl;
	}
	//若仅有一个元素（头-->元素1-->Null)
	//尾删即头删
	LinkList* pCur = pHead->_next;
	if (pCur->_next == nullptr)
	{
		delete pCur;
		pCur = nullptr;
		pHead->_next = nullptr;
		return;
	}

	//若有很多元素,则遍历
	LinkList* pPrev = pHead;
	while (pCur->_next != nullptr)
	{
		pPrev = pCur;
		pCur = pCur->_next;
	}
	pPrev->_next = pCur->_next;
	delete pCur;
	pCur = nullptr;
}

//删除指定值
void delData(LinkList* pHead, char ch)
{
	if (pHead->_next == nullptr)
	{
		cout << "链表为空，删除失败!" << endl;
	}
	LinkList* pCur = pHead->_next;
	LinkList* pPrev = pHead;

	while (pCur)
	{
		if (pCur->data != ch)
		{
			pCur = pCur->_next;
		}
	}
	if (pCur == nullptr)
	{
		cout << "链表里无此元素，删除失败!" << endl;
		return;
	}
	while (pCur)
	{
		if (pCur->data != ch)
		{
			pPrev = pCur;
			pCur = pCur->_next;
		}
		else
		{
			pPrev->_next = pCur->_next;
			delete pCur;
			pCur = pPrev->_next;
		}
	}
}


//打印元素
void printData(LinkList* pHead)
{
	if (pHead->_next == nullptr)
	{
		cout << "链表为空!" << endl;
		return;
	}
	LinkList* pCur = pHead->_next;
	for (; pCur != nullptr; pCur = pCur->_next)
	{
		cout << pCur->data << "-->";
	}
	cout << endl;
}