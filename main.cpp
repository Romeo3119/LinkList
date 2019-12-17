#include "linklist.h"

int main()
{
	LinkList list;
	initLinkList(&list);
	cout << "Î²²å" << endl;
	pushBackData(&list, 'B');
	pushBackData(&list, 'C');
	pushBackData(&list, 'D');
	pushBackData(&list, 'E');
	printData(&list);

	cout << "Í·²å" << endl;
	pushFrontData(&list, 'A');
	pushFrontData(&list, 'A');
	printData(&list);

	cout << "É¾³ýÖ¸¶¨Öµ" << endl;
	delData(&list, 'o');
	printData(&list);
	/*cout << "Í·É¾" << endl;
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

	/*cout << "Î²É¾" << endl;
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