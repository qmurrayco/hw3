#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
	if(head == NULL){
		//done, leave
		smaller = NULL;
		larger = NULL;
		return;
	}
	if(head->val <= pivot){
		smaller = head;
		head = head->next;
		smaller->next = NULL;
		llpivot(head, smaller->next, larger, pivot);
	}else{
		larger = head;
		head = head->next;
		larger->next = NULL;
		llpivot(head, smaller, larger->next, pivot);
	}
}

