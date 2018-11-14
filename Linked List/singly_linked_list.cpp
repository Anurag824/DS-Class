#include<iostream>
using namespace std;

class ll
{
	struct node
	{
		int value;
		struct node*  next;
	};
	struct node* start;
	struct node* new_node;
	struct node* ptr;
	struct node* save;
	struct node* temp;
	struct node* copy_;
	int count;
	public:
		ll()
		{
			start=NULL;
			count = 0;
		}
		void create_ll(int num)
		{
			while(num!=-1)
			{
				new_node = new node;
				new_node->value = num;
				new_node->next = start;
				start = new_node;
				count ++;
				cin >> num;
			}
		}
    	void create_ll_back(int num)
    	{
        	while(num!=-1)
        	{
            	if(start==NULL)
            	{
            	
                	new_node = new node;
					new_node->value = num;
            		new_node->next = start;
            		start = new_node;
            		save = new_node;
            		count++;
            }
            	else
            	{
            		new_node = new node;
					new_node->value = num;
            		new_node->next = NULL;
            		save->next = new_node;
            		save = new_node;
            		count++;
            	}
            	cin >> num;
        	}
    	}
		void insert_beg(int num)
	    {
    	   new_node=new node;
	       new_node->value=num;
	       new_node->next=start;
	       start=new_node;
	    }
		void insert_end(int num)
    	{
	       new_node=new node;
	       new_node->value=num;
	       new_node->next=NULL;
	       save->next=new_node;
	       save=new_node;
    	}
		void insert_after(int given,int num)
    	{   copy_==NULL;
      		ptr=start;
      		while(ptr!=NULL)
       		{
         		if(ptr->value==given)
          		{	
					break;
          		}
         	ptr=ptr->next;
       		}
       		new_node=new node;
       		new_node->value=num;
       		new_node->next=ptr->next;
       		ptr->next=new_node;
    	}
		void insert_before(int given,int num)
    	{
	       ptr=start;
	       while(ptr!=NULL)
			{
          		if(ptr->value==given)
           		{
             		break;
           		}
           		copy_=ptr;
       			ptr=ptr->next;
        	}
       		if(copy_==NULL)
        	{
           		insert_beg(num);
        	}
       		else
        	{
          		new_node=new node;
          		new_node->value=num;
          		new_node->next=copy_->next;
          		copy_->next=new_node;
        	}
    	}
    	void insert_sort(int num)
    	{
       		ptr=start;
       		while(ptr!=NULL)
        	{
          		if(ptr->value>num)
           		{
            		break;
           		}
           		copy_=ptr;
           		ptr=ptr->next;
        	}
       		if(ptr==NULL)
        	{
           		insert_end(num);
        	}
       		else if(copy_==NULL)
        	{
           		insert_beg(num);
        	}
       		else
        	{
           		new_node=new node;
           		new_node->value=num;
           		new_node->next=copy_->next;
           		copy_->next=new_node;
        	}
    	}  
		void del_beg()
		{
			temp = start;
			start = temp -> next;
			temp -> next = NULL;
			delete temp;
		}
		void del_end()
		{
			ptr = start;
			save = NULL;
			while(ptr -> next != NULL)
			{
				save = ptr;
				ptr = ptr -> next;
			}
			save -> next = NULL;
			delete ptr;
		}
		void del_given_no(int no)
		{
			ptr = start;
			save = NULL;
			while(ptr != NULL)
			{
				if(ptr -> value == no)
					break;
				save = ptr;
				ptr = ptr -> next;
			}
			if(save == NULL)
			{
				del_beg();
			}
			else if(ptr  == NULL)
			{
				cout << "Number doesn't exist" << endl;
			}
			else
			{
				save -> next = ptr -> next;
				ptr -> next = NULL;
				delete ptr;
			}
		}
		void del_given_pos(int pos)
		{
			ptr = start;
			save = NULL;
			int count = 0;
			while(ptr != NULL)
			{
				count++;
				if(count == pos)
					break;
				save = ptr;
				ptr = ptr -> next;
			}
			if(save == NULL)
			{
				del_beg();
			}
			else if(ptr  == NULL)
			{
				cout << "Number doesn't exist" << endl;
			}
			else
			{
				save -> next = ptr -> next;
				ptr -> next = NULL;
				delete ptr;
			}
		}
		/*void del_same()
		{
			ptr = start;

		}*/
		void sort(){
			for(int p = 1; p < count; p++){
				save = start;
				for(int c = 0; c < (count-p); c++){
					ptr = save;
					save = ptr -> next;
					if(ptr -> value > save -> value){
						int copy = ptr -> value;
						ptr -> value = save -> value;
						save -> value = copy;
					}
				}
			}
		}
		void show()
		{
			cout << endl << endl;
			ptr = start;
			while(ptr!=NULL)
			{
				cout << ptr -> value << endl;
				ptr = ptr ->next;
			}
		}
};

/*int main()
{
	ll obj1,obj2;
	int no;
	/*obj1.create_ll();
	obj1.show();
	obj1.del_beg();
	obj1.show();
	obj2.create_ll_back();
	obj2.del_beg();
	obj2.del_end();
	cout << "enter the number you want to delete from the list" << endl;
	cin >> no;
	obj2.del_given_no(no);
	cout << "enter the position of the number you want to delete from the list" << endl;
	cin >> no;
	obj2.del_given_pos(no);
	obj2.show();
	cout << "Hello user to this program for opertions with linked list" << endl << "Select any of the following operations using index number of the option"
	cout << "1. Create a linked list" << endl <<"2. Display the linked list" << endl <<"3.  
	return 0;
}*/
int main()
{
	int n , num , given;
	char a ;
	ll obj1;
	int created = false;
	cout << "Hello user to this program for operations with linked list" << endl << "Select any of the following operations using index number of the option" << endl;
	cout << "1. Create a linked list" << endl <<"2. Display the linked list" << endl <<"3. insert an element to the list" << endl;
	cout << "4. Deleting an Element" << endl << "5. Sorting the list" << endl;
	cout << "Enter -1 for termination/ completion of any function / program" << endl;
	cin >> n;
	while (n != -1)
	{
		switch (n)
		{
			case 1:{
				cout << "Enter how you want to create the list" << endl;
				cout << "b for insertion at beginning" << endl;
				cout << "e for insertion at the end" << endl;
				cin >> a;
				if(a == 'b' || a == 'B') {
					cin >> num;
					obj1.create_ll(num);
					created = true;
				}
				else if(a == 'e' || a == 'E')
				{
					cin >> num;
					obj1.create_ll_back(num);
					created = true;
				}
				else
				{
					cout << "invalid option. Try again" << endl;
				}
				break;
			}
			case 2:{
				if(created)
					obj1.show();
				else
					cout << "list not created";
				break;
			}
			case 3:{
				cout << "enter the following option for insertion" << endl;
				cout << "b for insertion at beginning" << endl;
				cout << "e for insertion at the end" << endl;
				cout << "a for after given element" << endl;
				cout << "g for before given element" << endl;
				cout << "p for insertion of element at desired position" << endl;
				cin >> a;
				if (a == 'b') {
					cin >> num;
					obj1.insert_beg(num);
				} else if (a == 'e') {
					cin >> num;
					obj1.insert_end(num);
				} else if (a == 'a') {
					cin >> given;
					cin >> num;
					obj1.insert_after(given, num);
				} else if (a == 'g') {
					cin >> given;
					cin >> num;
					obj1.insert_before(given, num);
				} else if (a == 'p') {
					cin >> given;
					cin >> num;
					obj1.insert_after(given, num);
				} else {
					cout << "no matching option";
				}
				break;
			}
			case 4:{
				cout << "enter the following option for selected deletion";
				cout << "b for deletion of first element";
				cout << "";
				break;
			}
			case 5:{
				cout << "The list has been sorted" << endl;;
				obj1.sort();
				break;
			}
			default:{
				cout << "invalid input "<< endl;
			}
		}
		cout << "1. Create a linked list" << endl <<"2. Display the linked list" << endl <<"3. insert an element to the list" << endl;
		cout << "4. Deleting an Element" << endl << "5. Sorting the list" << endl;
		cout << "Enter -1 for termination/ completion of any function / program" << endl;
		cin >> n;
	}
	return 0;
}
