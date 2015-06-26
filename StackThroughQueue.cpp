#include <iostream>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

// Code by Rizwan

// Stack with queues (int in this case).

// Implementing stack operations, namely push and pop with 2 queues. push is simply pushing the content into the queue.
// For pop, we use a temporary queue to store the values dequeued from the original queue. We dequeue all the elements from the original
// queue except the last one, and enqueue them in the temp queue. The one element left in the original queue is our answer. Once we save it in
// a variable, we then equate our original queue with our temp queue.



// Queue passed by reference
int pop(queue <int> &q){
	
	// Corner case, i.e. if the queue is empty.
	if(q.empty()){
		cout<<"Queue is empty"<<endl;
		exit(1);
	}

	// Temporary queue to store content that is dequeued off the original queue.
	queue <int> temp;

	// Adding values to the temporary queue, except the last one. The last value will be our answer.
	while(q.size()!=1){
		temp.push(q.front());
		q.pop();

	}


	// Getting the last value off the original queue, as it was the last value inserted in the queue. This will satisfy LIFO property.
	int top=q.front();
	q.pop();

	// Equating our original queue with the temp queue, after dequeuing the last element as the stack top.
	q=temp;	


	// Returns top.
	return top;


}



int main(){
	
	queue <int> myQueue;
	int stackTop;

	myQueue.push(10);
	myQueue.push(5);
	myQueue.push(15);
	myQueue.push(1);


	stackTop=pop (myQueue);
	cout<<"Stack top = "<<stackTop<<endl;

	stackTop=pop (myQueue);
	cout<<"Stack top = "<<stackTop<<endl;


	return 0;
}
