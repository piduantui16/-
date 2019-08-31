#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#define OUT_size 1000
#define MAX 500000
typedef struct Word
{
	char arr[40];
	int count;
}Word;

typedef struct Num
{
	Word *brr;
	int length;
	int listsize;
}N;

int file_size(char* path)  
{  
    FILE *fp = fopen(path,"r");  
    if(!fp) return -1;  
    fseek(fp,0L,SEEK_END);  
    int size=ftell(fp);  
    fclose(fp);  
    return size;  
}
void Chul(char *str,N *temp,int size)
{
	int i;
	int j = 0;
	int k = 0;
	int flg = 0;
	char tem[40];
	for(i=0;i<size;i++)
	{
		if(isalpha(str[i]))
		{
			tem[k] = str[i];
			k++;
		}
		else
		{
			if(k>0)
			{
				flg = 1;
			}
			tem[k] ='\0';
			
			
		}
		if(flg)
		{
			for(int t=0;t<k+1;t++)
			{
				(*temp).brr[j].arr[t] = tem[t];
			}
			(*temp).length++;
			j++;
			flg = 0;
			k=0;
		}


	}
}



void Cshcount(N *temp,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		(*temp).brr[i].count = 1;
	}
}

void Mycompare(N *temp,int len)
{
	int i,j;
	for(i=0;i<len;i++)
	{
		for(j=i;j<len;j++)
		{
			if((*temp).brr[j].count != 0)
			{
				if(strcmp((*temp).brr[i].arr,(*temp).brr[j].arr)==0)
				{
					(*temp).brr[i].count++;
					(*temp).brr[j].count = 0;
				}
			}
		}
	}
}

void Myprint(N *temp,int len)
{
	int i;
	int j;
	int max=0;
	int flg2;
	for(i=0;i<OUT_size;i++)
	{
		for(j=0;j<len;j++)
		{
			if(max < (*temp).brr[j].count)
			{
				max = (*temp).brr[j].count;
				flg2 = j;
			}
		}
		printf("%s    ",(*temp).brr[flg2].arr);
		printf("%d\n",(*temp).brr[flg2].count);
		(*temp).brr[flg2].count = 0;
		max = 0;
		flg2 = 0;

	}
}

int main()
{
	int i;
	N temp;
	temp.brr = (Word*)malloc(MAX*sizeof(Word));
	temp.length = 0;
	temp.listsize = MAX;
	char *path = "1.txt";
	FILE *fr = fopen(path,"r");
	assert (fr != NULL);

	int size = file_size(path);
	char *str =(char *)malloc(size*sizeof(char));

	for(i=0;i<size;i++)
	{
		str[i] = fgetc(fr);
	}

	Chul(str,&temp,size);

	Cshcount(&temp,temp.length);

	Mycompare(&temp,temp.length);

	Myprint(&temp,temp.length);
	
	free(temp.brr);

	free(str);
	return 0;
}
