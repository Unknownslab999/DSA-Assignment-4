#include<iostream>
//#include<cstring>
using namespace std;

class Stack_Char_Array
{
	private:
    	char* A;
    	int top;
    	int capacity;

	public:
	    Stack_Char_Array(int size)
		{
	        A = new char[size];
    	    top = -1;
	        capacity = size;
    	}

    	void push(char ch)
		{
	        if (Is_Full())
			{
        	    cout << "Stack Over Flow..." << endl;
            	return;
        	}
        	top++;
        	A[top] = ch;
    	}

    	char pop()
		{
        	if (Is_Empty())
			{
            	cout << "Stack Under Flow..." << endl;
            	return '\0';
        	}
        	char ch = A[top];
        	top--;
        	return ch;
    	}

	    char peek()
		{
        	if (Is_Empty())
			{
	            return '\0';
    	    }
        	char ch = A[top];
        	return ch;
    	}

	    void size()
		{
        	cout << "Size of Elements in Array :- " << top + 1;
    	}

    	bool Is_Full()
		{
	        return top == capacity - 1;
    	}

	    bool Is_Empty()
		{
	        return top == -1;
    	}
};

int strlen_custom(const char* str)
{
    int length = 0;
    while (str[length] != '\0')
	{
        length++;
    }
    return length;
}

bool Parenthesis_Matching(char* exp)
{
    Stack_Char_Array stack(strlen_custom(exp) + 1);
    int i = 0;
    while (exp[i] != '\0')
	{
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
		{
            stack.push(exp[i]);
        }
        else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
		{
            if (stack.Is_Empty())
			{
                return false;
            }
            else
			{
                char temp = stack.pop();
                if ((exp[i] == '}' && temp != '{') || (exp[i] == ']' && temp != '[') || (exp[i] == ')' && temp != '('))
                {
                    return false;
                }
            }
        }
        i++;
    }
    return stack.Is_Empty();
}

int Precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

bool Is_Operand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return false;
    else
        return true;
}

char* Infix_To_PostFix(char* infix)
{
    int i = 0, j = 0;
    Stack_Char_Array Stack(strlen_custom(infix));
    int len = strlen_custom(infix);
    char* postfix = new char[len + 1];
    while (infix[i] != '\0')
	{
        if (Is_Operand(infix[i]))
            postfix[j++] = infix[i++];
        else
		{
            if (Precedence(infix[i]) > Precedence(Stack.peek()))
                Stack.push(infix[i++]);
            else
                postfix[j++] = Stack.pop();
        }
    }
    while (!Stack.Is_Empty())
	{
        postfix[j++] = Stack.pop();
    }
    postfix[j] = '\0';
    return postfix;
}

class Node
{
	public:
		char value;
		Node* next;
		Node(char value)
		{
			this->value = value;
			next = NULL;
		}
};

class Stack_Char_Linked_List
{
	private:
		Node* top;
		int size;
	public:
		Stack_Char_Linked_List()
		{
			top = NULL;
			size = 0;
		}
	
		void push(char ch)
		{
			Node* new_Node = new Node(ch);
			new_Node->next = top;
			top = new_Node;
			size++;
		}
		char pop()
		{
			if(Is_Empty())
			{
				return '\0';
			}
			else
			{
				char pop = top->value;
				Node* temp = top;
				top = top->next;
				delete temp;
				size--;
				return pop;
			}
		}
		char peek()
		{
			if(Is_Empty())
			{
				return '\0';
			}
			else
			{
				return top->value;	
			}
		}
		void Size()
		{
			if(Is_Empty())
			{
				cout<<"Linked List is Empty..."<<endl;
			}
			else
			{
				cout<<"Size of Linked List:- "<<size<<endl;
			}
		}
		bool Is_Full()
		{
			return false;
		}
		bool Is_Empty()
		{
			return top == NULL;
		}
};

bool L_Parenthesis_Balanced(char* exp)
{
    Stack_Char_Linked_List stack;
    int i = 0;

    while (exp[i] != '\0')
	{
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
		{
            stack.push(exp[i]);
        }
		else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
		{
            if (stack.Is_Empty())
			{
                return false;
            }
			else
			{
                char temp = stack.pop();
                if ((exp[i] == '}' && temp != '{') || (exp[i] == ']' && temp != '[') || (exp[i] == ')' && temp != '('))
				{
                    return false;
                }
            }
        }
        i++;
    }
    return stack.Is_Empty();
}

int L_Precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

bool L_Is_Operand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return false;
    else
        return true;
}

char* L_Infix_To_PostFix(char* infix)
{
    int i = 0, j = 0;
    Stack_Char_Linked_List stack;
    int length = strlen_custom(infix);
    char* postfix = new char[length + 1];

    while (infix[i] != '\0')
	{
        if (L_Is_Operand(infix[i]))
            postfix[j++] = infix[i++];
        else
		{
            if (L_Precedence(infix[i]) > L_Precedence(stack.peek()))
                stack.push(infix[i++]);
            else
                postfix[j++] = stack.pop();
        }
    }

    while (!stack.Is_Empty())
	{
        postfix[j++] = stack.pop();
    }

    postfix[j] = '\0';
    return postfix;
}



class Stack_Number_Array
{
	private:
		int *A;
		int capacity;
		int top;
	public:
		Stack_Number_Array(int size)
		{
			A = new int [size];
			top = -1;
			capacity = size;
		}
		~Stack_Number_Array()
		{
			delete [] A;
		}
		void push(int value)
		{
				top++;
				A[top] = value;
		}
		void pop()
		{
			top--;
		}
		int value()
		{
			return A[top]; 
		}
};

class Queue_Array
{
	private:
		int *A;
		int capacity;
		int front;
		int rare;
	public:
		Queue_Array(int size)
		{
			A = new int [size];
			capacity = size;
			front = rare = -1;
		}
		
		void Put_in_Queue(int value)
		{
			if(rare == capacity-1)
			{
				cout<<"Yes Queue is Full..."<<endl;
				return;
			}
			else
			{
				if((rare + 1)%capacity == front)
				{
					front = (front + 1)%capacity;
					rare = (rare + 1)%capacity;
					A[rare] = value;
				}
				else if(front == -1)
				{	
					front = rare = 0;
					A[rare] = value;
				}
				else
				{
					rare = (rare + 1)%capacity;
					A[rare] = value;
				}
			}
		}
		void Remove_from_Queue()
		{
    		if(front == -1)
			{
		        cout << "Queue is Empty..." << endl;
    		    return;
    		}

	    	cout << "Dequeueing: " << A[front] << endl;

		    if (front == rare)
			{
    	    	front = rare = -1;
    		}
			else
			{
	        	front = (front + 1) % capacity;
    		}
			}
			void Front()
			{
				if(rare == -1)
				{
					cout<<"There is No more Queue in Array..."<<endl;
				}
				else
				{
					cout<<"Front of Queue :- "<<A[front]<<endl;
				}
			}
			void Rear()
			{
				if(rare == -1)
				{
					cout<<"There is No more Queue in Array..."<<endl;
				}
				else
				{
					cout<<"Rare :- "<<A[rare]<<endl;
				}
			}
			void Is_Full()
			{
				if(rare == capacity-1)
				{
					cout<<"Yes Queue is Full..."<<endl;
				}
				else
				{
					cout<<"Queue is Not Full..."<<endl;
				}
			}
			void Size()
			{
				if(rare == -1)
				{
					cout<<"There is No more Queue in Array..."<<endl;
				}
				else
				{
				cout<<"Size of Queue :- "<<rare+1<<endl;
				}
			}
			void IS_Empty()
			{
				if(rare == -1)
				{
					cout<<"Queue Array Is Empty"<<endl;
				}
				else
				{
					cout<<"Queue Array Is Not Empty"<<endl;
				}
			}
			void Reverse_Queue()
			{
				Stack_Number_Array stack(rare+1);
			
				for(int i=0; i<=rare; i++)
				{
					stack.push(A[i]);
				}
				for(int i=0; i<=rare; i++)
				{
					A[i] = stack.value();
					stack.pop();
				}
			}
};

class Q_Node
{
	public:
		int value;
		Q_Node* next;
		Q_Node(int value)
		{
			this->value = value;
			next = NULL;
		}
};

class Queue_Linked_List
{
	private:
		Q_Node *front, *rare;
		int size;
	public:
		Queue_Linked_List()
		{
			front = NULL;
			rare = NULL;
			size = 0;
		}
		void Put_in_Queue(int value)
		{
			Q_Node* new_node = new Q_Node(value);
			if(rare == NULL)
			{
				front = new_node;
				rare = new_node;
				rare->next = front;
				size++;
				return;
			}
			else
			{
				rare->next = new_node;
				rare = new_node;
				rare->next = front;
				size++;
			}
		}
		void Remove_from_Queue()
		{
			if(front == NULL)
			{
				cout<<"There Is NO Queue..."<<endl;
			}
			else
			{
				Q_Node* temp = front;
				if(front == rare)
				{
					front = NULL;
					rare = NULL;
				}
				else
				{
					front = front->next;
					rare->next = front;
				}
				delete temp;
				size--;
			}
		}
		void Front()
		{
			if(front != NULL)
				cout<<"Front Value :- "<<front->value<<endl;
			else
				cout<<"No Queue Found..."<<endl;
		}
		void Rear()
		{
			if(rare != NULL)
				cout<<"Rare Value :- "<<rare->value<<endl;
			else
				cout<<"No Queue Found..."<<endl;
		}
		void Is_Full()
		{
			cout<<"Queue Not Full..."<<endl;
		}
		void Size()
		{
			cout<<"Size of Queue Linked List:- "<<size<<endl;
		}
		void Is_Empty()
		{
			if(front == NULL)
				cout<<"Queue Is Empty..."<<endl;
			else
				cout<<"Queue Is Not Empty..."<<endl;
		}
		void Reverse()
		{
			if(front != NULL)
			{
				Stack_Number_Array stack(100);
				Q_Node* temp = front;
				do
				{
					stack.push(temp->value);
					temp = temp->next;
				}
				while(temp != front);
				temp = front;
				do
				{
		            temp->value = stack.value();
		            stack.pop();
		            temp = temp->next;
		        }
				while(temp != front);
			}
			else
			{
				cout<<"Queue Linked List Is Empty..."<<endl;
			}
		}
};

void MenuSA()
{
	system("CLS");
	int size;
	cout<<"ENTER THE SIZE OF ARRAY :- ";
    cin>>size;
    Stack_Char_Array SCA(size);
	int choice;
	do
	{
		system("CLS");
		cout<<"\t\t\t\t\t\t Singly Linked List"<<endl<<endl;
		cout<<"\t\t\t\t\t\t1. PUSH"<<endl;
		cout<<"\t\t\t\t\t\t2. POP"<<endl;
		cout<<"\t\t\t\t\t\t3. PEEK"<<endl;
		cout<<"\t\t\t\t\t\t4. IS EMPTY"<<endl;
		cout<<"\t\t\t\t\t\t5. IS FULL"<<endl;
		cout<<"\t\t\t\t\t\t6. CHECK BALANCED PARENTHESIS"<<endl;
		cout<<"\t\t\t\t\t\t7. INFIX TO POST-FIX"<<endl;
		cout<<"\t\t\t\t\t\t0. RETURN"<<endl;
		cout<<"\n\nEnter Your choice :- ";
		cin>>choice;
		if (choice == 1)
		{
    		char ch, chk;
    		do
			{
	        	system("CLS");
    	    	cout << "Enter Value :- ";
        		cin >> ch;
        		SCA.push(ch);
        		cout << "Enter Value Again (Y / N) :- ";
	        	cin >> chk;
    		}
			while (chk == 'Y' || chk == 'y');
		}
		else if (choice == 2)
		{
    		system("CLS");
    		cout << "POPING THE LAST VALUE..." << endl;
    		SCA.pop();
    		system("PAUSE");
		}
		else if (choice == 3)
		{
    		system("CLS");
    		char ch = SCA.peek();
    		if (ch != '\0')
			{
        		cout << "PEEK VALUE :-  " << ch << endl;
    		}
			else
			{
        		cout << "STACK EMPTY..." << endl;
    		}
    		system("PAUSE");
		}
		else if (choice == 4)
		{
    		system("CLS");
    		if (SCA.Is_Empty() == 1)
			{
        		cout << "STACK IS EMPTY..." << endl;
    		}
			else
			{
        		cout << "STACK IS NOT EMPTY......" << endl;
    		}
    		system("PAUSE");
		}
		else if (choice == 5)
		{
    		system("CLS");
    		if (SCA.Is_Full() == 1)
			{
        		cout << "STACK IS FULL..." << endl;
    		}
			else
			{
        		cout << "STACK IS NOT FULL......" << endl;
    		}
    		system("PAUSE");
		}
		else if (choice == 6)
		{
    		system("CLS");
    		char exp[100];
    		cout << "ENTER EXPRESSION HERE:- ";
    		cin.ignore();
    		cin.getline(exp, 100);
    		cout << "Is " << exp << " Balanced :- " << (Parenthesis_Matching(exp) ? "Yes" : "No") << endl;
    		system("PAUSE");
		}
		else if (choice == 7)
		{
    		system("CLS");
    		char infix[100] = {};
    		cout << "ENTER EXPRESSION:- ";
    		cin.ignore();
    		cin.getline(infix, 100);
    		Infix_To_PostFix(infix);
    		cout << "Infix: " << infix << endl;
    		cout << "Postfix: " << Infix_To_PostFix(infix) << endl;
    		system("PAUSE");
		}
		else if (choice == 0)
		{
    		int main();
		}
		else
		{
    		cout << "Invalid choice..." << endl << endl;
    		system("PAUSE");
    		system("CLS");
		}

	}
	while(choice !=0);
}

void MenuSL()
{
	system("CLS");
    Stack_Char_Linked_List SCL;
	int choice;
	do
	{
		system("CLS");
		cout<<"\t\t\t\t STACK LINKED LIST"<<endl<<endl;
		cout<<"\t\t\t\t\t\t1. PUSH"<<endl;
		cout<<"\t\t\t\t\t\t2. POP"<<endl;
		cout<<"\t\t\t\t\t\t3. PEEK"<<endl;
		cout<<"\t\t\t\t\t\t4. IS EMPTY"<<endl;
		cout<<"\t\t\t\t\t\t5. IS FULL"<<endl;
		cout<<"\t\t\t\t\t\t6. CHECK BALANCED PARENTHESIS"<<endl;
		cout<<"\t\t\t\t\t\t7. INFIX TO POST-FIX"<<endl;
		cout<<"\t\t\t\t\t\t0. RETURN"<<endl;
		cout<<"\n\nEnter Your choice :- ";
		cin>>choice;
		switch (choice)
		{
            case 1:
            	{
	            	char ch, chk;
	                do
					{
	                	system("CLS");
	                	cout<<"Enter Value :- ";
	                	cin>>ch;
	                	SCL.push(ch);
	                	cout<<"Enter Value Again (Y / N) :- ";
	                	cin>>chk;
					}
					while(chk == 'Y' || chk == 'y');
				}
                break;
            case 2:
	            {
	            	system("CLS");
	            	cout<<"POPING THE LAST VALUE..."<<endl;
					SCL.pop();
					system("PAUSE");
				}
                break;
            case 3:
	            {
	            	system("CLS");
	                char ch = SCL.peek();
	                if(ch != '\0')
					{
	                	cout<<"PEEK VALUE :- "<<ch<<endl;
					}
					else
					{
	                	cout<<"THERE IS NO CHARACTER IN STACK LINKED LIST..."<<endl;
					}
					system("PAUSE");
				}
				break;
            case 4:
	            {
	            	system("CLS");
	                if(SCL.Is_Empty() == 1)
					{
	                	cout<<"STACK LINKED LIST IS EMPTY..."<<endl;
					}
					else
					{
	                	cout<<"STACK LINKED LIST IS NOT EMPTY......"<<endl;
					}
					system("PAUSE");
				}
                break;
            case 5:
            	{
            		system("CLS");
	            	if(SCL.Is_Full() == 1)
					{
	                	cout<<"STACK LINKED LIST IS FULL..."<<endl;
					}
					else
					{
	                	cout<<"STACK LINKED LIST IS NOT FULL......"<<endl;
					}
					system("PAUSE");
				}
            	break;
            case 6:
            	{
            		system("CLS");
            		char exp[100]; 
            		cout<<"ENTER EXPRESSION :- ";
					cin.ignore();
					cin.getline(exp,100);
					cout<<"Is "<<exp<<" Balanced :- "<< (L_Parenthesis_Balanced(exp)? "Yes" : "No")<<endl;
					system("PAUSE");
				}
            	break;
            case 7:
	            {
	            	system("CLS");
	            	char infix[100] = {};
    				cout<<"ENTER EXPRESSION :- ";
	            	cin.ignore();
	            	cin.getline(infix,100);
					Infix_To_PostFix(infix);
	    			cout<<"Infix: " <<infix<<endl;
	    			cout<<"Postfix: "<<L_Infix_To_PostFix(infix)<<endl;
					system("PAUSE");
				}
            	break;
            case 0:
            	int main();
            	break;
            default:
                cout<<"Invalid choice..."<<endl<<endl;
                system("PAUSE");
                system("CLS");
        }
	}
	while(choice !=0);
}

void MenuQA()
{
	system("CLS");
	int size;
	cout<<"ENTER THE SIZE OF ARRAY :- ";
    cin>>size;
    Queue_Array QA(size);
	int choice;
	do
	{
		system("CLS");
		cout<<"\t\t\t\t\t\t QUEUE USING ARRAY"<<endl<<endl;
		cout<<"\t\t\t\t\t\t1. ENQUEUE"<<endl;
		cout<<"\t\t\t\t\t\t2. DEQUEUE"<<endl;
		cout<<"\t\t\t\t\t\t3. GET FRONT"<<endl;
		cout<<"\t\t\t\t\t\t4. GET RARE"<<endl;
		cout<<"\t\t\t\t\t\t5. IS FULL"<<endl;
		cout<<"\t\t\t\t\t\t6. IS EMPTY"<<endl;
		cout<<"\t\t\t\t\t\t7. SIZE"<<endl;
		cout<<"\t\t\t\t\t\t8. REVRESE"<<endl;
		cout<<"\t\t\t\t\t\t0. RETURN"<<endl;
		cout<<"\n\nEnter Your choice :- ";
		cin>>choice;
		if (choice == 1)
        {
            int value;
	       	char ch;
            do
			{
	           	system("CLS");
               	cout<<"Enter Value :- ";
	            cin>>value;
	            QA.Put_in_Queue(value);
	            cout<<"Enter Value Again (Y / N) :- ";
	            cin>>ch;
			}
			while(ch == 'Y' || ch == 'y');
		}
                
        else if (choice == 2)
	    {
	    	system("CLS");
	        cout<<"DEQUEUEING THE FIRST VALUE..."<<endl;
			QA.Remove_from_Queue();
			system("PAUSE");
		}
                
        else if (choice == 3)
	    {
	        system("CLS");
	        QA.Front();
			system("PAUSE");
		}
				
    	else if (choice == 4)
	    {
	        system("CLS");
	        QA.Rear();
			system("PAUSE");
		}
                
    	else if (choice == 5)
        {
            system("CLS");
	        QA.Is_Full();
			system("PAUSE");
		}
            	
    	else if (choice == 6)
        {
            system("CLS");
            QA.IS_Empty();
			system("PAUSE");
		}
            
    	else if (choice == 7)
	    {
	        system("CLS");
	        QA.Size();
			system("PAUSE");
		}
            
        else if (choice == 8)
	    {
	    	system("CLS");
	        QA.Reverse_Queue();
			system("PAUSE");
		}
            	
        else if (choice == 0)
		{	
            int main();
		}
     	
        else
		{
			cout<<"Invalid choice..."<<endl<<endl;
        	system("PAUSE");
            system("CLS");
        }
	}
	while(choice !=0);
}

void MenuQL()
{
	system("CLS");
	Queue_Linked_List QL;
	int choice;
	do
	{
		system("CLS");
		cout<<"\t\t\t\t\t\t QUEUE LINKED LIST"<<endl<<endl;
		cout<<"\t\t\t\t\t\t1. ENQUEUE"<<endl;
		cout<<"\t\t\t\t\t\t2. DEQUEUE"<<endl;
		cout<<"\t\t\t\t\t\t3. GET FRONT"<<endl;
		cout<<"\t\t\t\t\t\t4. GET RARE"<<endl;
		cout<<"\t\t\t\t\t\t5. IS FULL"<<endl;
		cout<<"\t\t\t\t\t\t6. IS EMPTY"<<endl;
		cout<<"\t\t\t\t\t\t7. SIZE"<<endl;
		cout<<"\t\t\t\t\t\t8. REVRESE"<<endl;
		cout<<"\t\t\t\t\t\t0. RETURN"<<endl;
		cout<<"\n\nEnter Your choice:- ";
		cin>>choice;
	
        if (choice == 1)
        {
           	int value;
	        char ch;
	        do
			{
	            system("CLS");
	            cout<<"Enter Value :- ";
	            cin>>value;
	            QL.Put_in_Queue(value);
	            cout<<"Enter Value Again (Y / N) :- ";
	            cin>>ch;
			}
			while(ch == 'Y' || ch == 'y');
		}
               
        else if (choice == 2)
	    {
	        system("CLS");
			QL.Remove_from_Queue();
			system("PAUSE");
		}
        else if (choice == 3)
	    {
	        system("CLS");
	        QL.Front();
			system("PAUSE");
		}
		else if (choice == 4)
	    {
	        system("CLS");
	        QL.Rear();
			system("PAUSE");
		}
                
        else if (choice == 5)
        {
            system("CLS");
	        QL.Is_Full();
			system("PAUSE");
		}
            	
        else if (choice == 6)
        {
            system("CLS");
            QL.Is_Empty();
			system("PAUSE");
		}
            
        else if (choice == 7)
        {
	        system("CLS");
	        QL.Size();
			system("PAUSE");
		}
        else if (choice == 8)
        {
	        system("CLS");
	        QL.Reverse();
			system("PAUSE");
		}
            	
        else if (choice == 0)
		{			
            int main();
    	}
        else
		{	
            cout<<"Invalid choice..."<<endl<<endl;
            system("PAUSE");
            system("CLS");
        }
	}
	while(choice !=0);
}


int main()
{
	int choice;
	
	
    do
	{
		system("CLS");
		cout << "                                       _________________________________ " << endl;
    	cout << "                                      |                                 |" << endl;
    	cout << "                                      |        STACKS AND QUEUES        |" << endl;
    	cout << "                                      |_________________________________|" << endl << endl << endl;
    	cout << "                                                  MainMenue" << endl << endl << endl;
    	cout<<"\t\t\t1. STACK with ARRAY      ";
    	cout<<"\t\t\t2. STACK with LINKED LIST"<<endl;
    	cout<<"\t\t\t3. QUEUE with ARRAY      ";
    	cout<<"\t\t\t4. QUEUE with LINKED LIST"<<endl;
    	cout<<"\t\t\t\t\t\t  0. EXIT"<<endl<<endl;
    	cout<<"\n\nEnter Choice :-";
    	cin>>choice;

        if (choice == 1)
		{
            MenuSA();
            break;
		}
        else if (choice == 2)
		{
            MenuSL();
       	}
        else if (choice == 3)
		{
            MenuQA();
       	}
        else if (choice == 4) 
		{
           	MenuQL();
        }
        else if (choice == 0)
		{
                cout<<"Quitting..."<<endl;        
		}
        else
		{	
	        cout<<"Invalid choice..."<<endl<<endl;
            system("PAUSE");
            system("CLS");
        }

    }
	while (choice != 0);
}
