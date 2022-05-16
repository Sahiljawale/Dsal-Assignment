/*
Problem statement :
A Dictionary stores keywords & its meanings. Provide facility for adding new keywords, deleting keywords,
 updating values of any entry.
Provide facility to display whole data sorted in ascending/ Descending order.
 Also find how many maximum comparisons may require for finding any keyword. 
 Use Binary Search Tree for implementation.*/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
int op;
int cnt=0;
class node
{
	public:
	node *left;
	char word[50],mean[50];
	node *right;
};
class BT
{
	public:
	node *root,*temp;
	BT()
	{
		root=NULL;
    }
	void create();
	node* insert(node *,node *);
	void inorder(node *);
	void reverse_inorder(node *);
	void search(node *, char []);
	void modify(node *, char []);
	node *delete_word(node * ,char []);
    node *FindMin(node * );


};

void BT::create()
{
	int op;
	node *temp;
    do
    {
    	temp=new node;
    	cout<<"Enter A word ";
    	cin>>temp->word;
    	cout<<"Enter A Meaning : ";
    	cin>>temp->mean;
     temp->left=temp->right=NULL;
     if(root==NULL)
     {
    	 root=temp;
     }
     else
     {
    	 root=insert(root,temp);
     }
     cout<<"Want to insert again : ";
     cin>>op;
    }while(op==1);
}

node* BT::insert(node *root,node *temp){     

if(strcmp (temp->word, root->word) < 0 )
 {
  if(root->left == NULL)
   root->left = temp;
  else
   insert(root->left,temp);
 }
 else
 { if(root->right == NULL)
   root->right = temp;
  else
   insert(root->right,temp);
 }


return root;
}

void BT::inorder(node *temp)
{
    if(temp!=NULL)
    {
    	inorder(temp->left);
    	cout<<temp->word<<" -> "<<temp->mean<<" , ";
    	inorder(temp->right);
    }
}

void BT::reverse_inorder(node *temp){
	if(temp!=NULL){
		reverse_inorder(temp->right);
		cout<<temp->word<<" -> "<<temp->mean<<" , ";
		reverse_inorder(temp->left);
	}
}



void BT::search(node *temp , char src[])
{

if(temp != NULL)
{
 if((strcmp(temp->word , src)) == 0)
 {
    cout<<"\n Word Found ";
    cout<<"\n Word    : "<<temp->word;
    cout<<"\n meaning : "<<temp->mean;
cnt++;
 }
 else 
 {
	 if((strcmp( src, temp->word )) > 0)
	 {
		 search(temp->right , src);
		cnt++;
	 }
	 else 
	 {
		 search(temp->left , src);
		cnt++;
	 }
  }
 }
else
	cout<<"\n Word Not Found ";

cout<<"\n Total no of Comparisions to search an element is: "<<cnt;
}

void BT::modify(node *temp , char src[]){
	cout<<"hi";
}


node* BT::delete_word(node *root , char src[]){
	if(root==NULL){
		cout<<"Tree Empty";
		return root;
	}
	if(strcmp(src,root->word)<0){
		root->left=delete_word(root->left,src);
		return root;
	}
	if(strcmp(src,root->word)>0){
		root->right=delete_word(root->right,src);
		return root;
	}
	if(root->left==NULL && root->right==NULL){
		temp=root;
		delete temp;
		return NULL;
	}
	if(root->left==NULL){
		temp=root;
		root=root->right;
		delete temp;
		return root;
	}
	if(root->right==NULL){
		temp=root;
		root=root->left;
		delete temp;
		return root;
	}

	temp=FindMin(root->right);
		strcpy(root->word , temp->word);
		strcpy(root->mean , temp->mean);
		root->right=delete_word(root->right,temp->word);
		return root;
	
}

node* BT:: FindMin(node* root)
{
  while(root->left != NULL) root = root->left;
  return root;
}


int main()
{
		BT b;
		int choice;
		char src[10];
		while(1){
				cout<<"\n***************";
				cout<<"\n 1. Insert Binary Search Tree ";
				cout<<"\n 2. Display Ascending Order ";
				cout<<"\n 3. Display Decending Order ";
				cout<<"\n 4. Search The Word ";
				cout<<"\n 5. Modify The Meaning Of Word ";
				cout<<"\n 6. Delete Word From Dictionary ";
				cout<<"\n 7. Exit";
				cout<<"\n Enter your choice: ";
				cin>>choice;
				switch(choice){
						case 1:
									b.create();
									break;

						case 2:
									if(b.root==NULL){
										cout<<"--TREE EMPTY--";
									}
									else{
										cout<<"\n Ascending Order : ";
											b.inorder(b.root);
										}
									
									break;
						case 3:
									if(b.root==NULL){
										cout<<"--TREE EMPTY--";
									}
									else{
										cout<<"\n Decending Order: ";
											b.reverse_inorder(b.root);
									}
									
									break;


						case 4:
									cnt=0;
									cout<<"\n Enter The Word Want To Search : ";
									cin>>src;
									b.search(b.root , src);
									break;

						case 5:
									cout<<"\n Enter The Word Want To Modify ";
									cin>>src;
									b.modify(b.root , src);
									break;

						case 6:
									cout<<"\n Enter The Word Want To Delete ";
									cin>>src;
									b.delete_word(b.root,src);
									// b.Delete(src);
									break;

						case 7:
									exit(0);
									break;

						default:
									cout<<"\n Invalid Option ";
									break;
		 }
		}
	}
