#include"struct.h"
#include"CheckMatch1.h"

CELL2* findPos(CELL2** board, int x, int y, int& BOARDHEIGHT, int& BOARDWIDTH)
{
	if (x<0 || x>BOARDWIDTH - 1 || y<0 || y>BOARDHEIGHT)
		return NULL;

	CELL2* tmp = board[y];
	while (tmp != NULL)
	{
		if (tmp->j == x) {
			return tmp;
		}

		tmp = tmp->pNext;
	}
	return NULL;
}

Node* createPath(char path)
{
	Node* newNode = new Node;
	newNode->path = path;
	newNode->next = NULL;
	return newNode;
}

void addHead(Node*& head)
{
	Node* newNode = new Node;
	if (head == NULL)
	{
		head = createPath('-');
	}
	else
	{
		newNode = createPath('-');
		newNode->next = head;
		head = newNode;
	}
}

void removeAll(Node*& head)
{
	if (head == NULL)
		return;
	Node* current = head;
	Node* tmp = NULL;
	while (current != NULL)
	{
		tmp = current->next;
		delete current;
		current = tmp;
	}
	head = NULL;
}

void printPath(Node* head)
{
	if (head == NULL)
	{
		return;
	}

	Node* current = head; 

	while (current != NULL) 
	{
		cout << current->path;
		current = current->next;
	}
}

void draw_I_Matching(CELL1**board, Node*& phead, int x1, int y1, int x2, int y2)
{
	//The pair is on the same row
	int x, y;
	if (x1 == x2)
	{
		if (y1 > y2)
		{
			x = y2;
			y = y1;
		}
		else
		{
			x = y1;
			y = y2;
		}

		for (int i = x + 1; i < y; i++)
		{
			if (!board[x1][i].isNotEmpty)
			{
				addHead(phead);
			}
			else if (board[x1][i].isNotEmpty)
			{
				removeAll(phead);
			}
		}
	}
}