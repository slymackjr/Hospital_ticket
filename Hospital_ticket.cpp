#include <iostream>
#include <cstdio>
/*the problem met is that its difficult to impliment fcfs
on the linked list queue*/
// Define the node structure
struct node {
int key;
node *next;
};

// Define the queue class
class Queue {
public:
node *front;
node *rear;

public:
Queue();
void enqueue(int);
void dequeue();
void display();
bool isEmpty();
int count();
int fronti();
};

// Define the constructor to initialize the front and rear pointers
Queue::Queue() {
front = nullptr;
rear = nullptr;
}

// Define the enqueue function to add a new node to the queue
void Queue::enqueue(int key) {
// Check if the key is within the range 1000-2000
if (key >= 1000 && key <= 2000) {
// Create a new node
node *newNode = new node;
newNode->key = key;
newNode->next = nullptr;

    // Check if the queue is empty
    if (isEmpty()) {
        // If the queue is empty, set the front and rear pointers to the new node
        front = newNode;
        rear = newNode;
    }
    else {
        //If the queue is not empty, insert the new node at the front of the queue
        newNode->next = front;
        front = newNode;
        
        /*if the queue is not empty, insert the new node at the back of the front queue test 1 my code hahah!!!!
        frontrear=front->next;
        newNode->next=frontrear;
        front->next=newNode; */
        
    }
}
// If the key is not within the range 1000-2000, add it to the rear of the queue
else {
    // Create a new node
    node *newNode = new node;
    newNode->key = key;
    newNode->next = nullptr;

    // Check if the queue is empty
    if (isEmpty()) {
        // If the queue is empty, set the front and rear pointers to the new node
        front = newNode;
        rear = newNode;
    }
    else {
        // If the queue is not empty, insert the new node at the rear of the queue
        rear->next = newNode;
        rear = newNode;
    }
}
}

// Define the dequeue function to remove the front node from the queue
void Queue::dequeue() {
// Check if the queue is empty
node *temp=nullptr;
if (isEmpty()) {
std::cout << "The queue is empty" << std::endl;
return;
}

// Save the current front node
temp = front;

 if (front == rear) {
      front=nullptr;
	  rear = nullptr;  
    }
    else{
// Move the front pointer to the next node
front = front->next;
	}

// Delete the current front node
delete temp;
}

// Define the display function to print the keys of all the nodes in the queue
void Queue::display() {
// Check if the queue is empty
if (isEmpty()) {
std::cout << "The queue is empty" << std::endl;
return;
}

// Save a copy of the front pointer
node *temp = front;

// Print the keys of all the nodes in the queue
while (temp != nullptr) {
    std::cout << temp->key << " -> ";
    temp = temp->next;
}
//std::cout << std::endl;
}

// Define the isEmpty function to check if the queue is empty
bool Queue::isEmpty() {
return (front == nullptr);
}

int Queue::count() 
    {
      int count=0;
      node *temp=front;
      while(temp!=NULL)
      {
        count++;
        temp=temp->next;
    	}
     return count;
    }
int Queue::fronti() {
    if (front == nullptr) {
      return -1;
    }

    return front->key;
  }

//insertion sorting algorithm in ascending order
void sortQueue(Queue& q) {
  // Create a temporary linked list queue
  Queue sortedQueue;

  // Sort the queue using insertion sort
  while (!q.isEmpty()) {
    // Remove the front element from the original queue
    int value = q.fronti();
    q.dequeue();

    // Find the correct position for the element in the sorted queue
    node* current = sortedQueue.front;
    node* prev = nullptr;
    while (current != nullptr && current->key < value) {
      prev = current;
      current = current->next;
    }

    // Create a new node for the element
    node* temp = new node;
    temp->key = value;
    temp->next = current;

    // Insert the element into the sorted queue
    if (prev == nullptr) {
      sortedQueue.front = temp;
    }
    else {
      prev->next = temp;
    }
  }

  // Transfer all elements from the sorted queue back to the original queue
  while (!sortedQueue.isEmpty()) {
    q.enqueue(sortedQueue.fronti());
    sortedQueue.dequeue();
  }
}
  
  
    
// Function to sort a linked list queue in ascending order
void sortiQueue(Queue& q) {
  // Create a temporary linked list queue
  Queue tempQueue;

  // Transfer all elements from the original queue to the temporary queue
  while (!q.isEmpty()) {
    tempQueue.enqueue(q.fronti());
    q.dequeue();
  }

  // Sort the temporary queue
  while (!tempQueue.isEmpty()) {
    int min = tempQueue.fronti();
    node* temp = tempQueue.front;
    while (temp != nullptr) {
      if (temp->key < min) {
        min = temp->key;
      }
      temp = temp->next;
    }
    q.enqueue(min);
    temp = tempQueue.front;
    node* prev = nullptr;
    while (temp != nullptr && temp->key != min) {
      prev = temp;
      temp = temp->next;
    }
    if (prev == nullptr) {
      tempQueue.front = tempQueue.front->next;
    }
    else {
      prev->next = temp->next;
    }
    delete temp;
  }
}

int main() {
	
// Create a new queue object
Queue q;


int option,ticket;
std::cout<<"\t\t\t\t\tWELCOME TO KENYA PUBLIC HOSPITAL"<<std::endl<<std::endl;
std::cout<<"\t\tPATIENTS TICKETS RANGE 1000 TO 4000"<<std::endl<<std::endl;
std::cout<<"\tELDERLY AND CHILDERN COME FIRST!"<<std::endl<<std::endl;
 
  do {
std::cout << "patients tickets 1000 to 4000"<<std::endl;
std::cout<<"N.B: Elderly and children tickets range from 1000-2000" <<std::endl;
std::cout << "1. Patient ticket" <<std::endl;
std::cout << "2. Attended patient" <<std::endl;
std::cout << "3. Check for no patients" <<std::endl;
std::cout << "4. Count number of patients"<<std::endl;
std::cout << "5. display()" <<std::endl;
std::cout << "6. Clear Screen" <<std::endl<<std::endl;
std::cin >>option;
 	 
	  //Node n1 = new Node();
	 //Node * new_node = new Node();
	 
    
    switch (option) {
    case 0:
      break;
    case 1:
      std::cout << "Patient ticket -" <<std::endl;
      std::cout << "Enter Patient ticket number "
		<<"in the list"
		<<std::endl;
      std::cin>>ticket;
      q.enqueue(ticket);
      sortQueue(q);
      
      break;
    case 2:
      std::cout << "Attended patient - " <<std::endl;
      std::cout<<"Attended patient removed"<<std::endl;
      q.dequeue();
      break;
    case 3:
    	std::cout << "Check for availability of patients - " <<std::endl;
      if (q.isEmpty())
        std::cout << "There is no patients" <<std::endl;
      else
        std::cout << "Queue is NOT Empty" <<std::endl;
      break;
    case 4:
    	std::cout<<"Number of patients - " <<std::endl;
        std::cout<<"No of patients in the list: "<<q.count()<<std::endl;
      break;
    case 5:
      std::cout << "Available Patients are- " <<std::endl;
      //sortiQueue(q);
      q.display();
      std::cout<<std::endl;
      break;
    
    case 6:
      system("cls");
      break;
    default:
      std::cout << "Select proper option please! " <<std::endl;
    }
 
  } while (option != 0);

return 0;
}