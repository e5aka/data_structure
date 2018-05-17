typedef struct Node
{
	DataType data;
	struct Node *next;
}SLNode;

void ListInitiate(SLNode * *head)
{
	if((*head=(SLNode *)malloc(sizeof(SLNode)))==NULL)exit(1);
	(*head)->next=NULL;
}

int ListLength(SLNode * head)
{
	SLNode *p=head;
	int size =0;
	while(p->next!=NULL)
	{
		p=p->next;
		size++;
	}
	return size;
}

int ListInsert(SLNode * head, int i, DataType x)
{
	SLNode *p,*q;
	int j;
	p=head;
	j=-1;
	while(p->next!=NULL&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(j!=i-1)
	{
		printf("����δ֪��������");
		return 0;
	}
	if((q=(SLNode *)malloc(sizeof(SLNode)))==NULL)exit(1);
	q->data=x;

	q->next=p->next;
	p->next=q;
	return 1;
}

int ListDelete(SLNode *head,int i, DataType *x)
{
	SLNode *p,*s;
	int j;
	p=head;
	j=-1;
	while(p->next!=NULL&&p->next->next!=NULL&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(j!=i-1)
	{
		printf("ɾ��λ�ò�����");
		return 0;
	}
	s=p->next;
	*x=s->data;
	p->next=p->next->next;
	free(s);
	return 1;
}

int ListGet(SLNode *head,int i, DataType *x)
{
	SLNode *p;
	int j;
	p=head;
	j=-1;
	while(p->next!=NULL&&j<i)
	{
		p=p->next;
		j++;
	}
	if(j!=i)
	{
		printf("ȡ��Ԫ��λ�ò�����!");
		return 0;
	}
	*x=p->data;
	return 1;
}	

int ListFind(SLNode *head,DataType x)
{
       SLNode *p;
       p = head;
       
	   while(p->next!=NULL)
       { 
           p = p->next; 
		   if(p->data==x)	 return x;
	   } 
		if(p->next==NULL)
       {
             printf("û���ҵ�Ԫ�أ�");
              return -1;
       }	   
}



void Destroy(SLNode * *head)
{
	SLNode 	*p,*p1;
	p=*head;
	while(p!=NULL)
	{
		p1=p;
		p=p->next;
		free(p1);
	}
	*head=NULL;
}