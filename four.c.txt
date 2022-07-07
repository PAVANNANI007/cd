#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char tab[12][9][2]={"S5","N","N","S4","N","N","1","2","3",
"N","S6","N","N","N","Z","0","0","0",
"N","R2","S7","N","R2","R2","0","0","0",
"N","R4","R4","N","R4","R4","0","0","0",
"S5","N","N","S4","N","N","8","2","3",
"N","R6","R6","N","R6","R6","0","0","0",
"S5","N","N","S4","N","N","0","9","3",
"S5","N","N","N","S4","N","0","0","X",
"N","S6","N","N","SY","N","0","0","0",
"N","R1","S7","N","R1","R1","0","0","0",
"N","R3","R3","N","R3","R3","0","0","0",
"N","R5","R5","N","R5","R5","0","0","0"};


char prod[7][4]={"0","E+T","T","T*F","F","(E)","d"};

char ind[12]={'0','1','2','3','4','5','6','7','8','9','X','Y'};

char term[9]={'d','+','*','(',')','$','E','T','F'};

int row,col,st_pt=0,ip_pt=0;

char input[10], stack[20];

void shift(char ch)
{
	st_pt++;
	stack[st_pt++]=input[ip_pt++];
	stack[st_pt]=ch;
}

int isind(char ch)
{
	int k;
	
	for (k=0;k<=9;k++)
		if(ind[k]==ch)
			return(k);
	
	if(ch=='X')
		return(10);
	
	else
		if(ch=='Y')
			return(11);
}

int isterm(char ch)
{
	int k;

	for(k=0;k<9;k++)
		if(term[k]==ch)
			return(k);
}


void reduce(char ch)
{
	int k,prno,prlen,rowno,colno;
	
	for(k=1;k<7;k++)
		if(ind[k]==ch)
			prno=k;
	
	prlen=strlen(prod[prno]);
	
	for(k=1;k<=2*prlen;k++)
		st_pt--;
	
	st_pt++;
	
	if(prno==1||prno==2)
		stack[st_pt]='E';
	
	else
		if(prno==3||prno==4)
			stack[st_pt]='T';
		else
			if(prno==5||prno==6)
				stack[st_pt]='F';
	
	rowno= isind(stack[st_pt-1]);
	
	colno= isterm(stack[st_pt]);
	
	stack[++st_pt]=tab[rowno][colno][0];
}


void main()
{
	int j,k;
	
	printf("\n enter input string :");
	scanf("%s", input);
	
	strcat(input,"$");
	
	stack[0]='0';
	
	for(j=0;j<7;j++)
		strcat(prod[j],"\0");
	
	printf("\nSTACK \t\t\t INPUT \n \n");
	
	while(1)
	{
		for(k=0;k<=st_pt; k++)
			printf("%c", stack[k]);
		printf(" \t\t\t ");
		
		for(k=ip_pt;input[k-1]!='$';k++)
			printf("%c", input[k]);
		
		printf("\n");
		
		row= isind(stack[st_pt]);
		col= isterm(input[ip_pt]);
	
		if(tab[row][col][0]=='S')
			shift(tab[row][col][1]);
		
		else
			if(tab[row][col][0]=='R')
				reduce(tab[row][col][1]);
			
			else
				if(tab[row][col][0]=='Z')
				{
					printf (" \n success");
					exit(0);
				}
				else
					if(tab[row][col][0]=='N')
					{
						printf("\n error");
						exit(0);
					}
	}
}



