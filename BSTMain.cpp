#include<bits/stdc++.h>
using namespace std;
set<int> id;
typedef struct BinaryTree
{
	int id;
	struct BinaryTree* leftChild;
	struct BinaryTree* rightChild;
}node;
node* root = NULL;
node* MakeNode(int v)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->id = v;
	temp->leftChild = NULL; temp->rightChild = NULL;
	return temp;
}
node* Find(int v, node* r)
{
	if(r==NULL || r->id==v) return r;
	node* tmp;
	tmp = Find(v, r->leftChild); if(tmp!=NULL) return tmp;
	tmp = Find(v, r->rightChild); if(tmp!=NULL) return tmp;
	return NULL;
}
node* AddLeft(int x, int y, node* r)
{
	if(r==NULL) return NULL;
	if(r->id == y)
	{
		if(r->leftChild!=NULL)
		{
			return r;
		}
		r->leftChild = MakeNode(x);
		return r;
	}
	r->leftChild = AddLeft(x, y, r->leftChild);
	r->rightChild = AddLeft(x, y, r->rightChild);
	return r;
}
node* AddRight(int x, int y, node* r)
{
	if(r==NULL) return NULL;
	if(r->id == y)
	{
		if(r->rightChild!=NULL)
		{
			return r;
		}
		r->rightChild = MakeNode(x);
		return r;
	}
	r->leftChild = AddRight(x, y, r->leftChild);
	r->rightChild = AddRight(x, y, r->rightChild);
	return r;
}
void PreOrder(node* r)
{
	if(r==NULL) return;
	cout << r->id << ' ';
	PreOrder(r->leftChild);
	PreOrder(r->rightChild);
	return;
}
void InOrder(node* r)
{
	if(r==NULL) return;
	InOrder(r->leftChild);
	cout << r->id << ' ';
	InOrder(r->rightChild);
	return;
}
void PostOrder(node* r)
{
	if(r==NULL) return;
	PostOrder(r->leftChild);
	PostOrder(r->rightChild);
	cout << r->id << ' ';
	return;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	string cmd;
	int x,y;
	while(1)
	{
		cin >> cmd;
		if(cmd == "*") break;
		if(cmd == "MakeRoot")
		{
			cin >> x;
			root = MakeNode(x);
			id.insert(x);
			continue;
		}
		if(cmd == "AddLeft")
		{
			cin >> x >> y;
			if(id.find(x)!=id.end() || id.find(y)==id.end())
				continue;
			root = AddLeft(x, y, root);
			id.insert(x);
			continue;
		}
		if(cmd == "AddRight")
		{
			cin >> x >> y;
			if(id.find(x)!=id.end() || id.find(y)==id.end())
				continue;
			root = AddRight(x, y, root);
			id.insert(x);
			continue;
		}
		if(cmd == "PreOrder")
		{
			PreOrder(root);
			cout << endl;
			continue;
		}
		if(cmd == "InOrder")
		{
			InOrder(root);
			cout << endl;
			continue;
		}
		if(cmd == "PostOrder")
		{
			PostOrder(root);
			cout << endl;
			continue;
		}
	}
	return 0;
}
