/* 
Assignment No.1
Title:- Classes and object
Problem Statement:- Consider a student database of SEIT class (at least 15 records). Database contains different fields of every student like Roll No, Name and SGPA.(array of structure)

a) Design a roll call list, arrange list of students according to roll numbers in ascending order (Use Bubble Sort)

b) Arrange list of students alphabetically. (Use Insertion sort)

c) Arrange list of students to find out first ten toppers from a class. (Use Quick sort)

d) Search students according to SGPA. If more than one student having same SGPA, then print list of all students having same SGPA.

e) Search a particular student according to name using binary search without recursion
student records having the presence of search key should be displayed)
(Note: Implement either Bubble sort or Inserti Sort.)

*/

//CODE:


#include <iostream>
#include <string.h>

using namespace std;

int const size= 15;

struct student
	{
	int roll_no;
	char name[30];
	float SGPA;
	};

void accept(struct student list[size]);
void display(struct student list[80]);
void bubble_sort(struct student list[size]);
void insert_sort(struct student list[size]);
void quick_sort(struct student list[size],int first,int last);
void search(struct student list[size]);
void binary_search(struct student list[size]);

// ACCEPT FUNCTION
void accept(struct student list[size])
	{
	int i;
	for(i=0; i<size; i++)
		{
		cout<<"\nEnter Roll-Number, Name, SGPA:";
		cin>>list[i].roll_no>>list[i].name>>list[i].SGPA;
		}
	}



// DISPLAY FUNCTION
void display(struct student list[80])
	{
	int i;
	cout<<"\n Roll-Number \t Name \t SGPA \n";
	for(int i=0; i<size; i++)
		{
		cout<<"\n      "<<list[i].roll_no<<"   \t  "<<list[i].name<<"\t  "<<list[i].SGPA;
		}
	cout<<"\n";
	}



// BUBBLE SORT FUNCTION
void bubble_sort(struct student list[size])
	{
	int i,j,c=0;
	struct student key;
	for(i=0; i<size; i++)
		{
		for(j=0; j<(size-1-i); j++)
			{
			if(list[j].roll_no>list[j+1].roll_no)
				{
				key=list[j];
				list[j]=list[j+1];
				list[j+1]=key;
				}
			c++;
			}
		}
	cout<<"\n";
	cout<<"\nNumber of passes is: "<<c;
	}




// INSERTION SORT FUNCTION
void insert_sort(struct student list[size])
	{
	int k,j,c=0;
	struct student key;
	for(k=1; k<size; k++)
		{
		key=list[k];
		j=k-1;

		while(strcmp(list[j].name,key.name)>0 && j>=0)
			{
			list[j+1]=list[j];
			j--;

			c++;

			}
		list[j+1]=key;

		}

	cout<<"\nNumber of passes is: "<<c;
	}



// QUICK SORT FUNCTION
void quick_sort(struct student list[size],int first,int last)
	{
	int pivot,i,j;

	if(first < last)
		{
		pivot = first;
		i = first;
		j = last;

		while(i < j)
			{
			while(list[i].roll_no <= list[pivot].roll_no && i < last)
				{
				i++;
				}

			while(list[j].roll_no > list[pivot].roll_no)
				{
				j--;
				}

			}

		swap(list[pivot].roll_no, list[j].roll_no);

		quick_sort(list,first,j-1);
		quick_sort(list,j+1,last);
		}
	}

// SEARCH FUNCTION
void search(struct student list[size])
{
	float SGPA;
	int i;
	cout<<"\n Enter SGPA:";
	cin>>SGPA;
	
	cout<<"\n Roll- Number \t Name \t SGPA \n";
	for(int i=0; i<size; i++)
	{
		if(SGPA==list[i].SGPA)
		cout<<"\n"<<list[i].roll_no<<"\t"<<list[i].name<<"\t"<<list[i].SGPA;
	}
}



// BINARY SEARCH FUNCTION
void binary_search(struct student list[size])
{
	int k, lower,upper,mid;
	char search[80];
	cout<<"\n Enter Name Of Student You Want To Search: ";
	cin>>search;
	
	lower=0;
	upper=size-1;
	mid=(lower+upper)/2;
	
	while(lower<=upper)
	{
		if(strcmp(list[mid].name, search)<0)
		lower=mid+1;
		
		else if(strcmp(list[mid].name, search)==0)
		{
			cout<<"\n"<<list[mid].roll_no<<"\t"<<list[mid].name<<"\t"<<list[mid].SGPA;
			break;
		}
		else
		upper=mid-1;
		mid=(lower+upper)/2;
	}
	
	if(lower>upper)
	cout<<search<<"Not Found In The List";
	}
	

// MAIN FUNCTION
int main()
	{
	int ch,i;
	struct student data[20];
	accept(data);
	do
		{
		cout<<"\n";
		cout<<"\n 1) Bubble Sort";
		cout<<"\n 2) Insertion Sort";
		cout<<"\n 3) Quick Sort ";
		cout<<"\n 4) Search ";
		cout<<"\n 5) Binary Search ";
		cout<<"\n 6) Exit \n";
		cout<<"\n Select Your Choice: ";
		cin>>ch;
		switch(ch)
			{
			case 1:
				bubble_sort(data);
				display(data);
				break;

			case 2:
				insert_sort(data);
				display(data);
				break;

			case 3:
				quick_sort(data,0,size-1);
				display(data);
				break;
			
			case 4:
				search(data);
				display(data);
				break;
				
            case 5:
				binary_search(data);
				display(data);
				break;
				
			case 6:
				cout<<"\nYou Have Successfully Exitted!!!.";
				break;	
	

			default:
				cout<<"\nPlease Enter Valid Choice.\n";

			}
		}
	while(ch!=6);
	return 0;
	}

// Output:

/*

Enter Roll-Number, Name, SGPA: 27001 qwe 10.0

Enter Roll-Number, Name, SGPA: 27015 rty 1.0

Enter Roll-Number, Name, SGPA: 27002 uio 9.5

Enter Roll-Number, Name, SGPA: 27014 pas 1.5

Enter Roll-Number, Name, SGPA: 27003 dfg 9.0

Enter Roll-Number, Name, SGPA: 27013 hjk 2.0

Enter Roll-Number, Name, SGPA: 27004 lzx 8.5

Enter Roll-Number, Name, SGPA: 27012 cvb 2.5

Enter Roll-Number, Name, SGPA: 27005 nmq 8.0

Enter Roll-Number, Name, SGPA: 27011 wer 3.0

Enter Roll-Number, Name, SGPA: 27006 tyu 7.5

Enter Roll-Number, Name, SGPA: 27010 qwe 3.5

Enter Roll-Number, Name, SGPA: 27007 iop 8.0

Enter Roll-Number, Name, SGPA: 27009 asd 4.0

Enter Roll-Number, Name, SGPA: 27008 fgh 5.0


 1) Bubble Sort
 2) Insertion Sort
 3) Quick Sort
 4) Search
 5) Binary Search
 6) Exit

 Select Your Choice: 1


Number of passes is: 105
 Roll-Number     Name    SGPA

      27001       qwe     10
      27002       uio     9.5
      27003       dfg     9
      27004       lzx     8.5
      27005       nmq     8
      27006       tyu     7.5
      27007       iop     8
      27008       fgh     5
      27009       asd     4
      27010       qwe     3.5
      27011       wer     3
      27012       cvb     2.5
      27013       hjk     2
      27014       pas     1.5
      27015       rty     1


 1) Bubble Sort
 2) Insertion Sort
 3) Quick Sort
 4) Search
 5) Binary Search
 6) Exit

 Select Your Choice: 2

Number of passes is: 54
 Roll-Number     Name    SGPA

      27009       asd     4
      27012       cvb     2.5
      27003       dfg     9
      27008       fgh     5
      27013       hjk     2
      27007       iop     8
      27004       lzx     8.5
      27005       nmq     8
      27014       pas     1.5
      27001       qwe     10
      27010       qwe     3.5
      27015       rty     1
      27006       tyu     7.5
      27002       uio     9.5
      27011       wer     3


 1) Bubble Sort
 2) Insertion Sort
 3) Quick Sort
 4) Search
 5) Binary Search
 6) Exit

 Select Your Choice: 3

 Roll-Number     Name    SGPA

      27001       asd     4
      27002       cvb     2.5
      27003       dfg     9
      27004       fgh     5
      27005       hjk     2
      27006       iop     8
      27007       lzx     8.5
      27008       nmq     8
      27009       pas     1.5
      27010       qwe     10
      27011       qwe     3.5
      27012       rty     1
      27013       tyu     7.5
      27014       uio     9.5
      27015       wer     3


 1) Bubble Sort
 2) Insertion Sort
 3) Quick Sort
 4) Search
 5) Binary Search
 6) Exit

 Select Your Choice: 4

 Enter SGPA:8.0

 Roll- Number    Name    SGPA

27006   iop     8
27008   nmq     8
 Roll-Number     Name    SGPA

      27001       asd     4
      27002       cvb     2.5
      27003       dfg     9
      27004       fgh     5
      27005       hjk     2
      27006       iop     8
      27007       lzx     8.5
      27008       nmq     8
      27009       pas     1.5
      27010       qwe     10
      27011       qwe     3.5
      27012       rty     1
      27013       tyu     7.5
      27014       uio     9.5
      27015       wer     3



 1) Bubble Sort
 2) Insertion Sort
 3) Quick Sort
 4) Search
 5) Binary Search
 6) Exit

 Select Your Choice: 5

 Enter Name Of Student You Want To Search: asd

27001   asd     4
 Roll-Number     Name    SGPA

      27001       asd     4
      27002       cvb     2.5
      27003       dfg     9
      27004       fgh     5
      27005       hjk     2
      27006       iop     8
      27007       lzx     8.5
      27008       nmq     8
      27009       pas     1.5
      27010       qwe     10
      27011       qwe     3.5
      27012       rty     1
      27013       tyu     7.5
      27014       uio     9.5
      27015       wer     3


 1) Bubble Sort
 2) Insertion Sort
 3) Quick Sort
 4) Search
 5) Binary Search
 6) Exit

 Select Your Choice: 6

You Have Successfully Exitted!!!.

*/

