#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

char *ReadData(FILE *fp, char *buf)
{
	return fgets(buf,1024,fp);
      
}

typedef struct node
{
	char s[20] ;
	struct node  *next;
} LinkListNode;

LinkListNode *CreateNode(void)
{
	LinkListNode *head,*p,*q;
	int i;
    FILE *fp;
	char *p1;
	
//	printf("Input filename:\n");

//	gets(filename);
	
    
	
	if((fp=fopen(("poet.txt"),"r"))==NULL)
          printf("open file erroe!!\n");

	head=(LinkListNode *)malloc(sizeof(LinkListNode));

	q=head;
	for(i=0;i<1000;i++)
	{
		p=(LinkListNode *)malloc(sizeof(LinkListNode));
		
        p1=ReadData(fp,p->s);     
		   
	    q->next=p;
		q=p;
	}
   
	p->next=NULL;
	return head; 
}
LinkListNode *Get_LkList(LinkListNode *head,int i)
{
	int j;
	LinkListNode *p;
	p=head;j=0;
	if(i==0) return NULL;

	while(j<i&&p->next !=NULL)
	{
		p=p->next;
		j++;
	}
	if(i==j) return p;
	else return NULL;
}





int main(void)
{
     LinkListNode *ge,*head,*p,*range[10];
	 char  a[100];
	 int   len,i,j;
	 int   x;
     int   h,l,mult;
     int    m,y;
	 int   n[12];

	 printf("Input your Matrix:\n");
	 
	 scanf("%d*%d",&h,&l);
	//  LinkListNode  *range1;
//	 printf("%d%d\n",h,l);
	
	srand(time(0));
	
	head = CreateNode();

	x = rand()%120+1;
//	printf("%d\n",x);
     
	 
     ge = Get_LkList(head,x);
   // range = Get_LkList(head,rand()%50+50);
   //  range1 = Get_LkList(head,rand()%10+1);


   //  printf("%s",ge->s);
  //   printf("%s",range->s);
     
	 len = strlen(ge->s);
	 mult = h * l;
	 for(i=0;i<mult-len/2;i++)
	 {  
		 range[i] = Get_LkList(head,rand()%50+50);
		// printf("%s",range[i]->s);

	 }

	 

	 for(i=0;i<len-1;i++)
	 {
		 a[i] = ge->s[i];
	 }

	 for(i=len-1;i<mult*2-1;i=i+2)
	 {
         
	//	 printf("%c%c",range[(i-len+1)/2]->s[0],range[(i-len+1)/2]->s[1]);
		 a[i] = range[(i-len+1)/2]->s[0];
		 a[i+1]=range[(i-len+1)/2]->s[1];
	//	 printf("%c%c\n",a[i],a[i+1]);
	 }
	 a[mult*2] = '\0';

//	 printf("%s\n",a);
	 /*for(i=l;i<mult*2+1;i++)
	 {
		 printf("%c%c\n",a[2*i],a[2*i+1]);
	 }*/
    
	 for(i=0;i<mult;i++)
	{
	   n[i]=rand()%(mult);
	   while(1)  //判断是否重复 
	 {
	  for(j=0;j<i;j++)
	  {
	  	if(n[i]==n[j])
	  		{
	  		 n[i]=rand()%(mult);	
	  		 j=0; 
	  		 break; 
			}
	  }
	  if(j==i)//新随机数与前面几个随机数都不重复 
	 		 break;
	 }
	 }
	 
      //  printf("%c%c",a[10],a[11]);    
	 for(i=0;i<(mult);i++)
	 {
		 printf("%c%c ",a[n[i]*2],a[n[i]*2+1]);
		 if((i+1)%h==0)
			 printf("\n");
		 
	 }

     printf("num:") ;
	 printf("%d\n",len/2);


     p=head->next;
       m=0;
	 for(;strlen(p->s)!=1;p=p->next)
	 {
		 //printf("%d\n",p->s);
            m=0;
		 if(strlen(p->s)==len)
		 {
		    // printf("%s",p->s);
			 for(y=0;y<(len-1)/2;y++)
			 {

                   
				 for(i=0;i<mult;i++)
				 {
                     if((a[i*2]==p->s[y*2])&&(a[i*2+1]==p->s[y*2+1]))
					 {	 
						 
					   //   printf("%c%c",a[i*2],a[i*2+1]);
					     // printf("%c%c\n",p->s[y*2],p->s[y*2+1]);
						  m ++;
					 }
	           }
			 }
			
		 }
          
		 if(m==(len-1)/2)
		 {
			 
			 printf("%s",p->s);
		 }


	 }
	/* printf("%d\n",m);

         if(m==(len-1)/2)
			 {
				 printf("%s",p->s);
			 }*/





	 
    
   
}
