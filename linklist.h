#pragma once
#include <iostream>

using namespace std;

typedef struct LinkList{
	char data; //����
	struct LinkList* _next;
} LinkList;

//��ʼ��
void initLinkList(LinkList* pHead)
{
	pHead->_next = nullptr;
	cout << "��ʼ�����!" << endl;
}

//��������
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
	cout << "�������!" << endl;
}

//�����µĽڵ�
LinkList* buyNewNode()
{
	LinkList* newNode = new LinkList();
	return newNode;
}

//β��Ԫ��
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

//ͷ��Ԫ��
void pushFrontData(LinkList* pHead, char ch)
{
	LinkList* newNode = buyNewNode();
	newNode->data = ch;
	newNode->_next = pHead->_next;
	pHead->_next = newNode;
}

//ͷɾԪ��
void popFrontData(LinkList* pHead)
{
	if (pHead->_next == nullptr)
	{
		cout << "�������ͷ�ڵ㣬ɾ��ʧ��!" << endl;
		return;
	}
	LinkList* pCur = pHead->_next;
	//��ֻ��һ��Ԫ�أ���ֱ��ɾ��
	if (pCur->_next == nullptr)
	{
		//pCur = nullptr;
		delete pCur;
		pCur = nullptr;
		pHead->_next = nullptr;
		return;
	}
	//���ж��Ԫ��
	pHead->_next = pCur->_next;
	delete pCur;
}

//βɾԪ��
void popBackData(LinkList* pHead)
{
	//������û��Ԫ�أ�����ͷ��
	if (pHead->_next == nullptr)
	{
		cout << "����û���κ�Ԫ�أ�ɾ��ʧ��!" << endl;
	}
	//������һ��Ԫ�أ�ͷ-->Ԫ��1-->Null)
	//βɾ��ͷɾ
	LinkList* pCur = pHead->_next;
	if (pCur->_next == nullptr)
	{
		delete pCur;
		pCur = nullptr;
		pHead->_next = nullptr;
		return;
	}

	//���кܶ�Ԫ��,�����
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

//ɾ��ָ��ֵ
void delData(LinkList* pHead, char ch)
{
	if (pHead->_next == nullptr)
	{
		cout << "����Ϊ�գ�ɾ��ʧ��!" << endl;
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
		cout << "�������޴�Ԫ�أ�ɾ��ʧ��!" << endl;
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


//��ӡԪ��
void printData(LinkList* pHead)
{
	if (pHead->_next == nullptr)
	{
		cout << "����Ϊ��!" << endl;
		return;
	}
	LinkList* pCur = pHead->_next;
	for (; pCur != nullptr; pCur = pCur->_next)
	{
		cout << pCur->data << "-->";
	}
	cout << endl;
}