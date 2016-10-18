/*Assignment no.:
Title : Implement Apriori approach for datamining to organize the data items on a shelf using following table of items purchased in a Mall.
Batch:
*/

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int i,j,k,l,f1,f2,f3,g1,g2,g3,transaction=5,itemset=6,items=11;       // nt=No. of transaction ,ni=No. of itm set, nui= No. of unique itemset
	//Initial item-purchase
	char a[transaction][itemset][15],itmset[items][15];
	char l1itmset[items][15],l2itmset[items][30],l2[items][30];
	int support[items],sup[items][items];  //support value

	cout<<"\n No. of transaction ";
	cin>>transaction;
	cout<<"\n No. of items purchased in one transaction ";
	cin>>itemset;

	cin.clear();

	for(i=0;i<transaction;i++)
	{
		cout<<"\n Enter items purchased in "<<i+1<<" transaction:";
		for(j=0;j<itemset;j++)
		{
			cin>>a[i][j];
			cin.clear();
		}
		cin.clear();
	}

//Initialization of support 

	for(i=0;i<items;i++)
	{
		support[i]=0;
	}

	cout<<"\n Total no. of items purchased ";
	cin>>items;
	cout<<"\n Enter names of items purchased  :\n";

	for(j=0;j<items;j++)
	{
		cout<<"\nItemset "<<j+1<<": ";
		cin>>itmset[j];
		cin.clear();
	}

	cout<<"\n Transaction Table :\n";
	cout<<"Transaction   ";
	
	for(i=0;i<itemset;i++)
	{
		cout<<"\titem "<<i+1;
	}
	
	cout<<"\n------------------------------------------------------------\n";
	
	for(i=0;i<transaction;i++)
	{
		cout<<"Transaction"<<i+1<<"   ";
		
		for(j=0;j<itemset;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}

	cout<<"\n------------------------------------------------------------\n";

	//Defining minimum level for acceptence
	
	int min;
	cout<<"\n Enter minimum support : ";
	cin>>min;
	
	for(i=0;i<transaction;i++)
	{
		for(j=0;j<itemset;j++)
		{
			for(k=0;k<items;k++)
			{
				if(strcmp(a[i][j],itmset[k])==0)
				{
					support[k]++;
				}	
			}
		}
	}
	
	//disp
	cout<<"\nSupport Count of Itemset:\n";
	cout<<"\nITEMS\t\tSUPPORT\n------------------------------------------------------------\n";

	for(j=0;j<items;j++)
	{
		cout<<itmset[j]<<"\t\t"<<support[j]<<"\n";
	}
	
	cout<<"\n------------------------------------------------------------\n";
	int count=0,cnt=0,c=0,ct=0;
	cout<<"Generating level 1 Itemset:\n\n";
	cout<<"ITEMS\t\t  SUPPORT\n------------------------------------------------------------\n";

	for(i=0;i<items;i++)
	{
		if(support[i]>=min)
		{
			strcpy(l1itmset[count],itmset[i]);
			cout<<itmset[i]<<"\t\t"<<support[i]<<endl;
			count++;
			
		}
	}
	//cout<<count;
	cout<<"\n------------------------------------------------------------";
	cout<<"\n Generating Level 2";
	cout<<"\n------------------------------------------------------------";
	cout<<"\nITEMS\t\tSUPPORT\n------------------------------------------------------------\n";

	
	for(i=0;i<count;i++)
	{
		   for(j=i+1;j<count;j++)
		   {
			cnt=0;	    
			//cout<<l1itmset[i]<<"   "<<l1itmset[j]<<"\n";
			for(k=0;k<transaction;k++)
			{
				f1=0;f2=0;
				for(l=0;l<itemset;l++)
				{
					if(strcmp(l1itmset[i],a[k][l])==0)
					{
						f1=1;
					}
					if((strcmp(l1itmset[j],a[k][l]))==0)
					{
						f2=1;
					}
					if(f1==1 && f2==1)
					{
						cnt++;
						f1=0;f2=0;
					}
					sup[i][j]=cnt;
				}
			}  
		      cout<<l1itmset[i]<<"\t"<<l1itmset[j]<<"\t"<<cnt<<"\n";
		      c++;
		   
		  
   		   }
	}

	cout<<"--------------------------------------------------------\n";
		cout<<"Generating level 2 Itemset:\n\n";
		cout<<"\nITEMS\t\tSUPPORT\n------------------------------------------------------------\n";
	
		for(i=0;i<count;i++)
		{
			for(j=i+1;j<count;j++)
			{
				 if(sup[i][j]>=min)
				 {
				 
				//strcpy(l2itmset[ct],l1itmset[i]);
				//cout<<l2itmset[ct]<<"\t\t"<<sup[i][j]<<endl;
				cout<<l1itmset[i]<<l1itmset[j]<<"\t\t"<<sup[i][j]<<endl;
				 }
			}
		 
		  
   		 }
		
		
	return 0;
}


/*------------------Output---------------------------
swl-12@Comp-SWL-12:~$ cd be51
swl-12@Comp-SWL-12:~/be51$ g++ apriori.cpp
swl-12@Comp-SWL-12:~/be51$ ./a.out

 No. of transaction 5

 No. of itemset 6

 Enter items from purchase 1:Mango
onion
jar
key-chain
eggs
chocolates

 Enter items from purchase 2:nuts
onion
jar
key-chain
eggs
chocolates

 Enter items from purchase 3:mango
apple
key-chain
eggs
-
-

 Enter items from purchase 4:mango
toothbrush
corn
key-chain
chocolates
-

 Enter items from purchase 5:corn
onion
onion
key-chain               
knife
eggs

 No. of unique itemset 11

 Enter Unique item set :

Itemset 1: mango

Itemset 2: onion

Itemset 3: jar

Itemset 4: key-chain

Itemset 5: eggs

Itemset 6: chocolates

Itemset 7: nuts

Itemset 8: apple

Itemset 9: toothbrush

Itemset 10: corn

Itemset 11: knife

 Transaction Table :
Transaction   	item 1	item 2	item 3	item 4	item 5	item 6
------------------------------------------------------------
Transaction1   Mango	onion	jar	key-chain	eggs	chocolates	
Transaction2   nuts	onion	jar	key-chain	eggs	chocolates	
Transaction3   mango	apple	key-chain	eggs	-	-	
Transaction4   mango	toothbrush	corn	key-chain	chocolates	-
Transaction5   corn	chocolates	onion	key-chain	knife	eggs	

------------------------------------------------------------

 Enter minimum acceptance level : 3

Support Count of Itemset:

ITEMS		SUPPORT
------------------------------------------------------------
mango			2
onion			3
jar			2
key-chain		5
eggs			4
chocolates		4
nuts			1
apple			1
toothbrush		1
corn			2
knife			1

------------------------------------------------------------
Generating level 1 Itemset:

ITEMS		SUPPORT
------------------------------------------------------------
onion			3
key-chain		5
eggs			4
chocolates		4

------------------------------------------------------------
 Generating Level 2
------------------------------------------------------------
ITEMS			SUPPORT
------------------------------------------------------------
onion	key-chain		3
onion	eggs			3
onion	chocolates		3
key-chain	eggs		4
key-chain	chocolates	3
eggs	chocolates		3
------------------------------------------------------------
swl-12@Comp-SWL-12:~/be51$ 
*/
