#include <iostream>
#include <stack>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

// Code by Rizwan Gilani

// Queue with stacks (int in this case).

// Implementing Queue operations, namely enqueue and dequeue with 2 stacks. Enqueuing is simply pushing the content into the stack.
// For dequeuing, we use a temporary stack to store the values popped off the original stack. This way, the bottom most element in the original
// stack is now the top most element in the temp stack. A simple pop operation on the temp stack results in dequeue. 
// Contents of the temp stack are then placed back into the original stack.



// Stack passed by reference
int dequeue(stack <int> &s){
	
	// Corner case, i.e. if the stack is empty.
	if(s.empty()){
		cout<<"Stack is empty"<<endl;
		exit(1);
	}

	// Temporary stack to store content that is popped off the original stack.
	stack <int> temp;

	// Adding values to the temporary stack.
	while(!s.empty()){
		temp.push(s.top());
		s.pop();

	}

	// Getting top of the temp stack (to implement FIFO for original stack), and popping the value off.
	int top=temp.top();
	temp.pop();
	

	// Putting the content back in the original stack.
	while(!temp.empty()){
		s.push(temp.top());
		temp.pop();
	}


	// Returns top.
	return top;


}



int main(){
	
	stack <int> myStack;
	int queueLead;

	myStack.push(10);
	myStack.push(5);
	myStack.push(15);
	myStack.push(1);


	queueLead=dequeue (myStack);
	cout<<"Queue lead = "<<queueLead<<endl;

	queueLead=dequeue (myStack);
	cout<<"Queue lead = "<<queueLead<<endl;


	return 0;
}
