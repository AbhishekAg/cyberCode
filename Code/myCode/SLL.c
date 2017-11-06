#include <stdio.h>
#include <stdlib.h>

struct sList {
    int data;
    struct sList *next;
};

int insertNode(struct sList **head, int nodeV, int end)
{
    struct sList *node = NULL, *endNode = *head;

    node = (struct sList *)malloc(sizeof(struct sList));
    if (node == NULL) {
	printf("Insufficient memory\n");
	return -1;
    }
    node->next = NULL;
    node->data = nodeV;   /* standalone node created and value assigned */

    if(*head == NULL) {
	*head = node;
	return 0;
    }
    if(!end) { /* Insert at the beginning */
        node->next = *head;
        *head = node;
        return 0;
    } else { /* Insert at end */
        while(endNode->next) {
            endNode = endNode->next;
        }

        endNode->next = node;
        return 0;
    }
}
#if 0
int insertNodeEnd(struct sList **head, int nodeV)
{
    struct sList *node = NULL, *endNode = *head;

    node = (struct sList *)malloc(sizeof(struct sList));
    if (node == NULL) {
	printf("Insufficient memory\n");
	return -1;
    }
    node->next = NULL;
    node->data = nodeV;   /* standalone node created and value assigned */

    if(*head == NULL) {
	*head = node;
	return 0;
    }
    while(endNode->next) {
	endNode = endNode->next;
    }

    endNode->next = node;
    return 0;
}
#endif

struct sList *deleteNode(struct sList **head, int end)
{
    struct sList *delNode = NULL, *endNode = *head;
    
    if(*head == NULL) { /* NO Nodes */
	return NULL;
    }
    if((*head)->next == NULL) { /* Single Node in list */
	delNode = *head;
	*head = NULL;
        return delNode;
    }

    if(!end) { /* Delete from begin */
	delNode = *head;
	*head = (*head)->next;
    } else { /* Delete from end */
	while(endNode->next->next) {
	    endNode = endNode->next;
	}
	delNode = endNode->next;
	endNode->next = NULL;
    }

    return delNode;
}

void printList(struct sList *head)
{
    if(!head) {
	printf("NO Nodes\n");
	return;
    }
    while(head) {
	printf("%d -->", head->data);
	head = head->next;
    }
    printf("X\n");
    return;
}

void reverseList(struct sList **head)
{
    struct sList *mid = NULL, *prev = NULL, *tmp = NULL;
    if(*head == NULL)
	return;
    mid = *head;
    tmp = (*head)->next;

    while(tmp) {
	mid->next = prev;
	prev = mid;
	mid = tmp;
	tmp = tmp->next;
    }
    mid->next = prev;
    *head = mid;
    return;
}
#if 0
void reverseList(struct sList **head, struct sList **newHead)
{
    struct sList *mid = *head, *prev = NULL;
    if(*head == NULL)
	return;
    *head = (*head)->next;

    while(*head) {
	mid->next = prev;
	prev = mid;
	mid = *head;
	*head = (*head)->next;
    }
    mid->next = prev;
    *newHead = mid;
    return;
}
#endif

void deleteList(struct sList **head)
{
    struct sList *tmp = *head;

    if(*head)
	*head = (*head)->next;
    else
	return;

    while(*head) {
	free(tmp);
	tmp = *head;
	*head = (*head)->next;
    }
    free(tmp);
}

struct sList* recReverse(struct sList *head, struct sList **newHead)
{
    if(head->next !=NULL) {
	recReverse(head->next, newHead);
	head->next->next = head;
	return(head);
    } else {
	newHead = &head;
    }
}

int main()
{
    int opt = 0, nodeValue = 0;
    struct sList *head = NULL, *nodeDel = NULL;

    while(1) {
        printf("Select an option: \n");
        scanf("%d", &opt);

        switch(opt) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &nodeValue);
                insertNode(&head, nodeValue, 0);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &nodeValue);
                insertNode(&head, nodeValue, 1);
                break;
            case 3:
                nodeDel = deleteNode(&head, 0);
		if(nodeDel) {
		    printf("Deleted Node Value: %d\n", nodeDel->data);
		    free(nodeDel);
		} else {
		    printf("List is empty\n");
		}
                break;
            case 4:
                nodeDel = deleteNode(&head, 1);
		if(nodeDel) {
		    printf("Deleted Node Value: %d\n", nodeDel->data);
		    free(nodeDel);
		}
                break;
            case 5:
                printList(head);
                break;
            case 6:
                //reverseList(&head, &newHead);
                reverseList(&head);;
                break;
            case 7:
                deleteList(&head);
		break;
	    case 8:
		recReverse(head, &head);
		break;
	    case 0:
                exit(0);
            //default:
                /* Do Nothing */
        }
    }

    return 0;
}
