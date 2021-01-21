
#include "stdio.h"
#include "stdlib.h"

typedef struct item
{
	int num;		//ҳ��
	int time;		//�ȴ�ʱ�䣬LRU�㷨���õ��������
}Pro;

int pageNum;		//ϵͳ�������ҵ�������е�ҳ����
int memoryNum;		//�����ڴ�ҳ����

void print(Pro* page1);		//��ӡ��ǰ�����е�ҳ��
int  Search(int num1, Pro* memory1);	//��ҳ�漯memory1�в���num1������ҵ�����������memory1�е��±꣬���򷵻�-1

int main(void)
{
	int i;
	int curmemory;		//�����ڴ��е�ҳ�����
	int missNum;		//ȱҳ����
	float missRate;		//ȱҳ��
	char c;				//�õ��û��������ַ�����ѡ����Ӧ���û��㷨

	Pro* page;			//��ҵҳ�漯
	Pro* memory;		//�ڴ�ҳ�漯

	printf("����ϵͳ�������ҵ�������е�ҳ����:");
	scanf_s("%d", &pageNum);
	printf("�����ڴ�ҳ����:");
	scanf_s("%d", &memoryNum);

	page = (Pro*)malloc(sizeof(Pro) * pageNum);
	memory = (Pro*)malloc(sizeof(Pro) * memoryNum);

	for (i = 0; i < pageNum; i++)
	{
		printf("�� %d ��ҳ���Ϊ:", i);
		scanf_s("%d", &page[i].num);
		page[i].time = 0;			//�ȴ�ʱ�俪ʼĬ��Ϊ0
	}

	do {
		for (i = 0; i < memoryNum; i++)		//��ʼ���ڴ���ҳ��
		{
			memory[i].num = -1;				//ҳ��Ϊ����-1��ʾ
			memory[i].time = -1;				//
		}

		printf("*****f:FIFOҳ���û�*****\n");
		printf("*****o:OPTҳ���û�*****\n");
		printf("*****l:LRUҳ���û�*****\n");
		printf("*****��ѡ���������(f,o,l),������������******\n");
		//fflush(stdin);
		getchar();
		scanf_s("%c", &c);

		i = 0;
		curmemory = 0;

		if (c == 'f')			//FIFOҳ���û�
		{
			missNum = 0;

			printf("FIFOҳ���û����:   \n");
			for (i = 0; i < pageNum; i++)
			{
				if (Search(page[i].num, memory) < 0)//�����ڴ���û���ҵ���ҳ��
				{
					missNum++;
					memory[curmemory].num = page[i].num;
					print(memory);
					curmemory = (curmemory + 1) % memoryNum;   //�ҳ����Ƚ����ڴ��ҳ��
				}
			}//end for
			missRate = (float)missNum / pageNum;
			printf("ȱҳ������%d   ȱҳ��:  %f\n", missNum, missRate);

		}//end if

		if (c == 'o')			//OPTҳ���û��㷨
		{
			missNum = 0;
			curmemory = 0;

			printf("Optimalҳ���û����:   \n");
			for (i = 0; i < pageNum; i++)
			{
				if (Search(page[i].num, memory) < 0)//�����ڴ���û���ҵ���ҳ��
				{

					//�ҳ�δ���ʱ���ڲ��ٱ����ʵ�ҳ��
					int tem;
					int opt = 0;
					for (int k = 0; k < memoryNum; k++)
					{
						if (memory[k].num == -1)
						{
							curmemory = k;
							break;
						}
						tem = 0;       //ҳ��k��δ��temʱ���ڲ������
						int j;
						for (j = i + 1; j < pageNum; j++)
						{
							if (page[j].num == memory[k].num)
							{
								if (tem > opt)
								{
									opt = tem;
									curmemory = k;
								}
								break;
							}
							else tem++;
						}
						if (j == pageNum)
						{
							opt = tem;
							curmemory = k;
						}
					}

					missNum++;
					memory[curmemory].num = page[i].num;
					print(memory);
				}
			}//end for
			missRate = (float)missNum / pageNum;
			printf("ȱҳ������%d   ȱҳ��:  %f\n", missNum, missRate);

		}//end if

		if (c == 'l')			//LRUҳ���û��㷨
		{
			missNum = 0;
			curmemory = 0;

			printf("LRUҳ���û����:   \n");
			for (i = 0; i < pageNum; i++)
			{
				int rec = Search(page[i].num, memory);
				if (rec < 0)    //�����ڴ���û���ҵ���ҳ��
				{
					missNum++;
					for (int j = 0; j < memoryNum; j++)     //�ҳ�������δʹ�õ�ҳ��
						if (memory[j].time == -1) {
							curmemory = j; break;
						}
						else if (memory[j].time > memory[curmemory].time)
							curmemory = j;

					memory[curmemory].num = page[i].num;
					memory[curmemory].time = 0;
					print(memory);

				}
				else memory[rec].time = 0;

				for (int j = 0; j < memoryNum; j++)     //�ڴ��е�����ҳ��ȴ�ʱ��+1	
					if (memory[j].num != -1)
						memory[j].time++;

			}//end for
			missRate = (float)missNum / pageNum;
			printf("ȱҳ������%d   ȱҳ��:  %f\n", missNum, missRate);
		}//end if

	} while (c == 'f' || c == 'l' || c == 'o');


	return 0;
}


void print(Pro* memory1)//��ӡ��ǰ��ҳ��
{
	int j;

	for (j = 0; j < memoryNum; j++)
		printf("%d ", memory1[j].num);
	printf("\n");
}

//��ҳ�漯memory1�в���num1������ҵ�����������memory1�е��±꣬���򷵻�-1
int  Search(int num1, Pro* memory1)
{
	int j;

	for (j = 0; j < memoryNum; j++)
	{
		if (num1 == memory1[j].num)
			return j;
	}
	return -1;
}