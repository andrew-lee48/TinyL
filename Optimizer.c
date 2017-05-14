/*
 *********************************************
 *  314 Principles of Programming Languages  *
 *  Fall 2015                                *
 *  Author: Ulrich Kremer                    *
 *  Student Version                          *
 *********************************************
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "InstrUtils.h"
#include "Utils.h"

int main()
{
	Instruction *head;

	head = ReadInstructionList(stdin);
	if (!head) {
		WARNING("No instructions\n");
		exit(EXIT_FAILURE);
	}

	/* YOUR CODE GOES HERE */
	// start at the end of the linked list and work up to the head
	Instruction *newHead = NULL;
	Instruction *ptr = LastInstruction(head);
	
	// search for the first outputAI command
	while (ptr != null)
	{
		if (ptr->OPCODE == OUTPUTAI) {	// located outputAI command
			// marked ILOC commands are added to the front of the linked list
			if (newHead == NULL) {	// new list is empty
				newHead = ptr;
			}
			else {	// new list has existing commands
				Instruction *insert = ptr;
				insert->next = newHead;
				newHead = insert;
			}
			// search for matching outputAI command
			ptr = ptr->prev;
			while (ptr != null)
			{
				if (ptr->OPCODE == STOREAI && ptr->field1 == newHead->field3) {
					Instruction *insert = ptr;
					insert->next = newHead;
					newHead = insert;
				}
				ptr = ptr->prev;
			}
		}
		ptr = ptr->prev;
	}
	head = newHead;
	

	if (head) 
		PrintInstructionList(stdout, head);
	
	return EXIT_SUCCESS;
}

