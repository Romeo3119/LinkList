#include "linklist.h"

int main()
{
	LinkList list;
	initLinkList(&list);
	cout << "β��" << endl;
	pushBackData(&list, 'B');
	pushBackData(&list, 'C');
	pushBackData(&list, 'D');
	pushBackData(&list, 'E');
	printData(&list);

	cout << "ͷ��" << endl;
	pushFrontData(&list, 'A');
	pushFrontData(&list, 'A');
	printData(&list);

	cout << "ɾ��ָ��ֵ" << endl;
	delData(&list, 'o');
	printData(&list);
	/*cout << "ͷɾ" << endl;
	popFrontData(&list);
	printData(&list);//B->C->D->E
	popFrontData(&list); 
	printData(&list);//C->D->E
	popFrontData(&list);
	printData(&list);//D->E
	popFrontData(&list);
	printData(&list);//E
	popFrontData(&list);
	printData(&list);//NULL*/

	/*cout << "βɾ" << endl;
	popBackData(&list);
	printData(&list);//ABCD
	popBackData(&list);
	printData(&list);//ABC
	popBackData(&list);
	printData(&list);//AB
	popBackData(&list);
	printData(&list);//A
	popBackData(&list);
	printData(&list);//NULL*/


	destroyLinkList(&list);
	system("pause");
	return 0;
}