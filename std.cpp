#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define SIZE_OF_ARRAY(ary) sizeof(ary) / sizeof(*ary)

typedef struct stu {
	char num[100];
	char tel[100];
	char add[100];
	char name[100];
	char stt[100];
} STU;

typedef enum {
	num, tel, add, name
} STU_FD;

typedef char * STRING;

typedef struct menu {
	char field1[10];
	char field2[10];
	char field3[10];
	char field4[10];
} MENU;

typedef struct temp {
	char f1[100];
	char f2[100];
	char f3[100];
	char f4[100];
	char f5[100];
} TEMP;

typedef struct tempout {
	char ff1[100];
	char ff2[100];
	char ff3[100];
	char ff4[100];
	char ff5[100];
} TEMPOUT;

typedef struct joinall {
	char j1[100];
	char j2[100];
	char j3[100];
	char j4[100];
	char j5[100];
} JoinAll;

char openfile[15];
char whereS[100];
char selectS[100];

void main() {
	FILE *cfptr, *tempFile, *outFile, *t1, *t2, *t3, *t4, *t5, *cfptr0, *cfptr1;
	FILE *outFile2, *afptr;
	FILE *ord, *cus, *del, *emp, *goo, *all;
	JoinAll ordjoin, cusjoin, deljoin, empjoin, goojoin;

	STU stu;
	MENU menu;
	TEMP temp;
	TEMPOUT tempout;
	STRING jf[2] = {" ", " "};
	STRING str[5] = {" ", " ", " ", " ", " "};
	STRING whe[5] = {" ", " ", " ", " ", " "};
	STRING key[5] = {" ", " ", " ", " ", " "};
	STRING value[5] = {" ", " ", " ", " ", " "};
	//STRING keyb[5] = {" ", " ", " ", " ", " "};
	//STRING valueb[5] = {" ", " ", " ", " ", " "};
	STRING Cot = " ";


	printf("SELECT : ");
	scanf("%s", &selectS);
	char *s = strtok(selectS, ",");
	int j = 0;
	int count = 0;
	while(s != NULL) {
		str[j] = s;
		j++;
	    s = strtok(NULL, ",");
	}
	if(strstr(selectS, "COUNT") != NULL) {
		char *count = strtok(selectS, "(");
		while(count != NULL) {
			Cot = count;
			count = strtok(NULL, ")");
		}

		printf("FROM : ");
		scanf("%s", &openfile);

		if((afptr = fopen(strcat(openfile,".txt"),"rt")) == NULL) {
			printf("Table could not be exsited.\n");
		}
		else {
			int count = 0;
			switch(openfile[0]) {
			case 'g':
				fscanf(afptr, "%s%s%s", stu.num, stu.tel, stu.add);

				while(!feof(afptr)) {
					fscanf(afptr, "%s%s%s", stu.num, stu.tel, stu.add);
					count++;
				}
				printf("| Count(%s)|\n| %-8d|\n", Cot, count-1);
			break;
			
			case 'd':
				fscanf(afptr, "%s%s%s", stu.num, stu.tel, stu.add);

				while(!feof(afptr)) {
					fscanf(afptr, "%s%s%s", stu.num, stu.tel, stu.add);
					count++;
				}
				printf("| Count(%s)|\n| %-8d|\n", Cot, count-1);
			break;
			case 'o':
				fscanf(afptr, "%s%s%s%s%s", stu.num, stu.tel, stu.add, stu.name, stu.stt);

				while(!feof(afptr)) {
					fscanf(afptr, "%s%s%s%s%s", stu.num, stu.tel, stu.add, stu.name, stu.stt);
					count++;
				}
				printf("| Count(%s)|\n| %-8d|\n", Cot, count-1);
			break;
			default:
			fscanf(afptr, "%s%s%s%s", stu.num, stu.tel, stu.add, stu.name);

			while(!feof(afptr)) {
				fscanf(afptr, "%s%s%s%s", stu.num, stu.tel, stu.add, stu.name);
				count++;
			}
			printf("| Count(%s)|\n| %-8d|\n", Cot, count-1);
			break;
			}
		}

		_getch();
		return;
	}

	if(strstr(selectS, "SUM") != NULL) {
		char *count = strtok(selectS, "(");
		while(count != NULL) {
			Cot = count;
			count = strtok(NULL, ")");
		}

		printf("FROM : ");
		scanf("%s", &openfile);

		if((afptr = fopen(strcat(openfile,".txt"),"rt")) == NULL) {
			printf("Table could not be exsited.\n");
		}
		else {
			if(strcmp(Cot, "price") != 0) {
				printf("Only 'Price' field support ( goo table) .\n");	
			}
			else {
			int sum = 0;
			fscanf(afptr, "%s%s%s", stu.num, stu.tel, stu.add);

			while(!feof(afptr)) {
				sum = sum+atoi(stu.tel);
				fscanf(afptr, "%s%s%s", stu.num, stu.tel, stu.add);
				//printf("%d\n", atoi(stu.tel));
			}
			printf("| Count(%s)|\n| %-12d|\n", Cot, sum);
			}
		}

		_getch();
		return;
	}

	if(strstr(selectS, "MAX") != NULL) {
		char *count = strtok(selectS, "(");
		while(count != NULL) {
			Cot = count;
			count = strtok(NULL, ")");
		}

		printf("FROM : ");
		scanf("%s", &openfile);

		if((afptr = fopen(strcat(openfile,".txt"),"rt")) == NULL) {
			printf("Table could not be exsited.\n");
		}
		else {
			if(strcmp(Cot, "price") != 0) {
				printf("Only 'Price' field support ( goo table) .\n");	
			}
			else {
			int max = 0;
			fscanf(afptr, "%s%s%s", stu.num, stu.tel, stu.add);

			while(!feof(afptr)) {
				if(atoi(stu.tel) > max)	max = atoi(stu.tel);
				fscanf(afptr, "%s%s%s", stu.num, stu.tel, stu.add);
				//printf("%d\n", atoi(stu.tel));
			}
			printf("| Count(%s)|\n| %-12d|\n", Cot, max);
			}
		}

		_getch();
		return;
	}

	if(strstr(selectS, "MIN") != NULL) {
		char *count = strtok(selectS, "(");
		while(count != NULL) {
			Cot = count;
			count = strtok(NULL, ")");
		}

		printf("FROM : ");
		scanf("%s", &openfile);

		if((afptr = fopen(strcat(openfile,".txt"),"rt")) == NULL) {
			printf("Table could not be exsited.\n");
		}
		else {
			if(strcmp(Cot, "price") != 0) {
				printf("Only 'Price' field support ( goo table) .\n");	
			}
			else {
			int min = 10000;
			fscanf(afptr, "%s%s%s", stu.num, stu.tel, stu.add);

			while(!feof(afptr)) {
				fscanf(afptr, "%s%s%s", stu.num, stu.tel, stu.add);
				if(atoi(stu.tel) < min )	min = atoi(stu.tel);
			}
			printf("| Count(%s)|\n| %-12d|\n", Cot, min);
			}
		}

		_getch();
		return;
	}

	if(strstr(selectS, "AVG") != NULL) {
		char *count = strtok(selectS, "(");
		while(count != NULL) {
			Cot = count;
			count = strtok(NULL, ")");
		}

		printf("FROM : ");
		scanf("%s", &openfile);

		if((afptr = fopen(strcat(openfile,".txt"),"rt")) == NULL) {
			printf("Table could not be exsited.\n");
		}
		else {
			if(strcmp(Cot, "price") != 0) {
				printf("Only 'Price' field support ( goo table) .\n");	
			}
			else {
			int avg = 0;
			int c = 0;
			fscanf(afptr, "%s%s%s", stu.num, stu.tel, stu.add);

			while(!feof(afptr)) {
				avg = avg+atoi(stu.tel);
				fscanf(afptr, "%s%s%s", stu.num, stu.tel, stu.add);
				c++;
			}
			printf("| Count(%s)|\n| %-12d|\n", Cot, avg/(c-1));
			}
		}

		_getch();
		return;
	}
/*-------------------------Aggregate functions end--------------------------------------------*/
	printf("FROM : ");
	scanf("%s", &openfile);

		if(strlen(openfile) > 4) {
			char *j = strtok(openfile, ",");
			int p = 0;
			while(j != NULL) {
				jf[p] = j;
				printf("%s\n", jf[p]);
				p++;
				j = strtok(NULL, ",");
			}

				all = fopen("joinall.txt","wt");
				ord = fopen("ord.txt","rt");
				cus = fopen("cus.txt","rt");
				del = fopen("del.txt","rt");
				emp = fopen("emp.txt","rt");
				goo = fopen("goo.txt","rt");

					fscanf(ord, "%s%s%s%s%s", ordjoin.j1, ordjoin.j2, ordjoin.j3, ordjoin.j4, ordjoin.j5);
					fprintf(all,"%s	%s	%s	%s %s	", ordjoin.j1, ordjoin.j2, ordjoin.j3, ordjoin.j4, ordjoin.j5);
					printf("|%-10s|%-10s|%-10s|%-10s|%-10s|\n", ordjoin.j1, ordjoin.j2, ordjoin.j3, ordjoin.j4, ordjoin.j5);
				if(strcmp(jf[1], "cus") == 0 ) {
					fscanf(cus, "%s%s%s%s", cusjoin.j1, cusjoin.j2, cusjoin.j3, cusjoin.j4);
					fprintf(all,"%s	%s	%s\n", cusjoin.j1, cusjoin.j2, cusjoin.j3);
					printf("|%-10s|%-10s|%-10s|\n", cusjoin.j1, cusjoin.j2, cusjoin.j3);
				}
				if(strcmp(jf[1], "del") == 0 ) {
					fscanf(del, "%s%s%s", deljoin.j1, deljoin.j2, deljoin.j3);
					fprintf(all,"%s	%s\n", deljoin.j2, deljoin.j3);
					printf("|%-10s|%-10s|\n", deljoin.j2, deljoin.j3);
				}
				if(strcmp(jf[1], "goo") == 0 ) {
					fscanf(goo, "%s%s%s", goojoin.j1, goojoin.j2, goojoin.j3);
					fprintf(all,"%s	%s\n", goojoin.j2, goojoin.j3);
					printf("|%-10s|%-10s|\n", goojoin.j2, goojoin.j3);
				}
				if(strcmp(jf[1], "emp") == 0 ) {
					fscanf(emp, "%s%s%s%s", empjoin.j1, empjoin.j2, empjoin.j3, empjoin.j4);
					fprintf(all,"%s	%s	%s\n", empjoin.j2, empjoin.j3, empjoin.j4);
					printf("|%-10s|%-10s|%-10s|\n", empjoin.j2, empjoin.j3, empjoin.j4);
				}

				fscanf(ord, "%s%s%s%s%s", ordjoin.j1, ordjoin.j2, ordjoin.j3, ordjoin.j4, ordjoin.j5);

			while(!feof(ord)) {
				fprintf(all,"%s	%s	%s	%s %s	", ordjoin.j1, ordjoin.j2, ordjoin.j3, ordjoin.j4, ordjoin.j5);
				printf("|%-10s|%-10s|%-10s|%-10s|%-10s|\n", ordjoin.j1, ordjoin.j2, ordjoin.j3, ordjoin.j4, ordjoin.j5);
				
				if(strcmp(jf[1], "cus") == 0 ) {
				while(!feof(cus))
				{
					fscanf(cus, "%s%s%s%s", cusjoin.j1, cusjoin.j2, cusjoin.j3, cusjoin.j4);
					if(strcmp(ordjoin.j2, cusjoin.j4) == 0)
					{
						fprintf(all,"%s	%s	%s\n", cusjoin.j1, cusjoin.j2, cusjoin.j3);
						printf("|%-10s|%-10s|%-10s|\n", cusjoin.j1, cusjoin.j2, cusjoin.j3);
						break;
					}
				}
				}
				if(strcmp(jf[1], "del") == 0 ) {
				while(!feof(del))
				{
					fscanf(del, "%s%s%s", deljoin.j1, deljoin.j2, deljoin.j3);
					if(strcmp(ordjoin.j3, deljoin.j1) == 0)
					{
						fprintf(all,"%s	%s\n", deljoin.j2, deljoin.j3);
						printf("|%-10s|%-10s|\n", deljoin.j2, deljoin.j3);
						break;
					}
				}
				}
				if(strcmp(jf[1], "goo") == 0 ) {
				while(!feof(goo))
				{
					fscanf(goo, "%s%s%s", goojoin.j1, goojoin.j2, goojoin.j3);
					if(strcmp(ordjoin.j4, goojoin.j1) == 0)
					{
						fprintf(all,"%s	%s\n", goojoin.j2, goojoin.j3);
						printf("|%-10s|%-10s|\n", goojoin.j2, goojoin.j3);
						break;
					}
				}
				}
				if(strcmp(jf[1], "emp") == 0 ) {
				while(!feof(emp))
				{
					fscanf(emp, "%s%s%s%s", empjoin.j1, empjoin.j2, empjoin.j3, empjoin.j4);
					if(strcmp(ordjoin.j5, empjoin.j1) == 0)
					{
						fprintf(all,"%s	%s	%s\n", empjoin.j2, empjoin.j3, empjoin.j4);
						printf("|%-10s|%-10s|%-10s|\n", empjoin.j2, empjoin.j3, empjoin.j4);
						break;
					}
				}
				}
				fscanf(ord, "%s%s%s%s%s", ordjoin.j1, ordjoin.j2, ordjoin.j3, ordjoin.j4, ordjoin.j5);
				rewind(cus);
				rewind(del);
				rewind(emp);
				rewind(goo);
			}
			fclose(all);
			_getch();
			return;
		}

	printf("WHERE : ");
	scanf("%s", &whereS);
	if(strcmp(whereS, "-") != 0) {
	char *ss = strtok(whereS, "AND");
	int x = 0;
	while(ss != NULL) {
		whe[x] = ss;
		//printf("%s\n", ss);
		x++;
	    ss = strtok(NULL, "AND");
	}
	//	printf("%d", SIZE_OF_ARRAY(whe));
		for(int i=0;i<2;i++) {
			int y = 0;
			//printf("%s\n", whe[i]);
			char *sss = strtok(whe[i], "=");
			while(sss != NULL) {
				if(y%2 == 0) {
					key[i] = sss;
					//printf("key[%d]:%s\n", i, key[i]);
				}
				else {
					value[i] = sss;
					//printf("value[%d]:%s\n", i, value[i]);
				}
				//printf("%s\n", sss);
				y++;
				sss = strtok(NULL, "=");
			}
			int z = 0;
		/*	//printf("%s\n", whe[i]);
			char *ssss = strtok(whe[i], ">");
			while(ssss != NULL) {
				if(z%2 == 0) {
					keyb[i] = ssss;
					printf("keyb[%d]:%s\n", i, keyb[i]);
				}
				else {
					valueb[i] = ssss;
					printf("valueb[%d]:%s\n", i, valueb[i]);
				}
				//printf("%s\n", sss);
				z++;
				ssss = strtok(NULL, ">");
			}
			*/
		}
	}
	//str[0] = menu.field1;	str[1] = menu.field2;	str[2] = menu.field3;	str[3] = menu.field4;

/*------------------------------------Input end---------------------------------------------------------*/
	if((cfptr = fopen(strcat(openfile,".txt"),"rt")) == NULL) {
		printf("Table could not be exsited.\n");
	}
	else {
		if(strcmp(str[0], "*") == 0) {	//select * all
			switch(openfile[0]) {
			case 'e':
				fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
				while(!feof(cfptr)) {
					printf("| %-10s| %-10s| %-10s| %-10s|\n", temp.f1, temp.f2, temp.f3, temp.f4);
					fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
				}
				break;
			case 'o':
				fscanf(cfptr, "%s%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4, temp.f5);
				while(!feof(cfptr)) {
					printf("| %-10s| %-10s| %-10s| %-10s| %-10s|\n", temp.f1, temp.f2, temp.f3, temp.f4, temp.f5);
					fscanf(cfptr, "%s%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4, temp.f5);
				}
				break;
			case 'g':
				fscanf(cfptr, "%s%s%s", temp.f1, temp.f2, temp.f3);
				while(!feof(cfptr)) {
					printf("| %-10s| %-10s| %-10s|\n", temp.f1, temp.f2, temp.f3);
					fscanf(cfptr, "%s%s%s", temp.f1, temp.f2, temp.f3);
				}
				break;
			case 'd':
				fscanf(cfptr, "%s%s%s", temp.f1, temp.f2, temp.f3);
				while(!feof(cfptr)) {
					printf("| %-10s| %-10s| %-10s|\n", temp.f1, temp.f2, temp.f3);
					fscanf(cfptr, "%s%s%s", temp.f1, temp.f2, temp.f3);
				}
				break;
			case 'c':
				fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
				while(!feof(cfptr)) {
					printf("| %-10s| %-10s| %-10s| %-10s|\n", temp.f1, temp.f2, temp.f3, temp.f4);
					fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
				}
				break;
			default:
				printf("Error.");
			}
			fclose(cfptr);
		}
		else {
			int s1 = 0;
			int s2 = 0;
			int s3 = 0;
			int s4 = 0;

			switch(openfile[0]) {
			
			case 'e':
				for(int i=0;i<5;i++) {
				char ntos[10];
				sprintf(ntos, "temp%d.txt", i);

			//	printf(ntos);
			//	printf("\n");
				if(strcmp(str[i], "empnum") == 0) {
					tempFile = fopen(ntos,"w");
					rewind(cfptr);
					fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
					fprintf(tempFile, "%s\n", temp.f1);
					fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
					while(!feof(cfptr)) {
						if(strcmp(whereS, "-") != 0) {
							for(int i=0;i<2;i++) {
							if(strcmp(key[i], "empnum") == 0) {
								if(strcmp(value[i], temp.f1) == 0) fprintf(tempFile, "%s\n", temp.f1);
							}
							}
						}
						else fprintf(tempFile, "%s\n", temp.f1);
						
						fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
						fflush(tempFile);
					}
					fclose(tempFile);
					count++;
					continue;
				}
				if(strcmp(str[i], "tel") == 0) {
					tempFile = fopen(ntos,"w");
					rewind(cfptr);
					fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
					fprintf(tempFile, "%s\n", temp.f2);
					fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
					while(!feof(cfptr)) {
						if(strcmp(whereS, "-") != 0) {
							for(int i=0;i<2;i++) {
							if(strcmp(key[i], "tel") == 0) {
								if(strcmp(value[i], temp.f2) == 0) fprintf(tempFile, "%s\n", temp.f2);
							}
							}
						}
						else fprintf(tempFile, "%s\n", temp.f2);

						fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
						fflush(tempFile);
					}
					fclose(tempFile);
					count++;
					continue;
				}
				if(strcmp(str[i], "add") == 0) {
					tempFile = fopen(ntos,"w");
					rewind(cfptr);
					fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
					fprintf(tempFile, "%s\n", temp.f3);
					fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
					while(!feof(cfptr)) {
						if(strcmp(whereS, "-") != 0) {
							for(int i=0;i<2;i++) {
							if(strcmp(key[i], "add") == 0) {
								if(strcmp(value[i], temp.f3) == 0) fprintf(tempFile, "%s\n", temp.f3);
							}
							}
						}
						else fprintf(tempFile, "%s\n", temp.f3);

						fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
						fflush(tempFile);
					}
					fclose(tempFile);
					count++;
					continue;
				}
				if(strcmp(str[i], "name") == 0) {
					tempFile = fopen(ntos,"w");
					rewind(cfptr);
					fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
					fprintf(tempFile, "%s\n", temp.f4);
					fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
					while(!feof(cfptr)) {
						if(strcmp(whereS, "-") != 0) {
							for(int i=0;i<2;i++) {
							if(strcmp(key[i], "name") == 0) {
								if(strcmp(value[i], temp.f4) == 0) fprintf(tempFile, "%s\n", temp.f4);
							}
							}
						}
						else fprintf(tempFile, "%s\n", temp.f4);

						fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
						fflush(tempFile);
					}
					fclose(tempFile);
					count++;
					continue;
				}
				}
			break;//---------------------------end case e----------------------------------------
			case 'o':
				for(int i=0;i<5;i++) {
				char ntos[10];
				sprintf(ntos, "temp%d.txt", i);

			//	printf(ntos);
			//	printf("\n");
				if(strcmp(str[i], "ordnum") == 0) {
					tempFile = fopen(ntos,"w");
					rewind(cfptr);
					fscanf(cfptr, "%s%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4, temp.f5);
					fprintf(tempFile, "%s\n", temp.f1);
					fscanf(cfptr, "%s%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4, temp.f5);
					while(!feof(cfptr)) {
						if(strcmp(whereS, "-") != 0) {
							for(int i=0;i<2;i++) {
							if(strcmp(key[i], "ordnum") == 0) {
								if(strcmp(value[i], temp.f1) == 0) fprintf(tempFile, "%s\n", temp.f1);
							}
							}
						}
						else fprintf(tempFile, "%s\n", temp.f1);

						fscanf(cfptr, "%s%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4, temp.f5);
						fflush(tempFile);
					}
					fclose(tempFile);
					count++;
					continue;
				}
				if(strcmp(str[i], "name") == 0) {
					tempFile = fopen(ntos,"w");
					rewind(cfptr);
					fscanf(cfptr, "%s%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4, temp.f5);
					fprintf(tempFile, "%s\n", temp.f2);
					fscanf(cfptr, "%s%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4, temp.f5);
					while(!feof(cfptr)) {
						if(strcmp(whereS, "-") != 0) {
							for(int i=0;i<2;i++) {
							if(strcmp(key[i], "name") == 0) {
								if(strcmp(value[i], temp.f2) == 0) fprintf(tempFile, "%s\n", temp.f2);
							}
							}
						}
						else fprintf(tempFile, "%s\n", temp.f2);

						fscanf(cfptr, "%s%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4, temp.f5);
						fflush(tempFile);
					}
					fclose(tempFile);
					count++;
					continue;
				}
				if(strcmp(str[i], "comnum") == 0) {
					tempFile = fopen(ntos,"w");
					rewind(cfptr);
					fscanf(cfptr, "%s%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4, temp.f5);
					fprintf(tempFile, "%s\n", temp.f3);
					fscanf(cfptr, "%s%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4, temp.f5);
					while(!feof(cfptr)) {
						if(strcmp(whereS, "-") != 0) {
							for(int i=0;i<2;i++) {
							if(strcmp(key[i], "comnum") == 0) {
								if(strcmp(value[i], temp.f3) == 0) fprintf(tempFile, "%s\n", temp.f3);
							}
							}
						}
						else fprintf(tempFile, "%s\n", temp.f3);

						fscanf(cfptr, "%s%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4, temp.f5);
						fflush(tempFile);
					}
					fclose(tempFile);
					count++;
					continue;
				}
				if(strcmp(str[i], "goonum") == 0) {
					tempFile = fopen(ntos,"w");
					rewind(cfptr);
					fscanf(cfptr, "%s%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4, temp.f5);
					fprintf(tempFile, "%s\n", temp.f4);
					fscanf(cfptr, "%s%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4, temp.f5);
					while(!feof(cfptr)) {
						if(strcmp(whereS, "-") != 0) {
							for(int i=0;i<2;i++) {
							if(strcmp(key[i], "goonum") == 0) {
								if(strcmp(value[i], temp.f4) == 0) fprintf(tempFile, "%s\n", temp.f4);
							}
							}
						}
						else fprintf(tempFile, "%s\n", temp.f4);

						fscanf(cfptr, "%s%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4, temp.f5);
						fflush(tempFile);
					}
					fclose(tempFile);
					count++;
					continue;
				}
				if(strcmp(str[i], "empnum") == 0) {
					tempFile = fopen(ntos,"w");
					rewind(cfptr);
					fscanf(cfptr, "%s%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4, temp.f5);
					fprintf(tempFile, "%s\n", temp.f5);
					fscanf(cfptr, "%s%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4, temp.f5);
					while(!feof(cfptr)) {
						if(strcmp(whereS, "-") != 0) {
							for(int i=0;i<2;i++) {
							if(strcmp(key[i], "empnum") == 0) {
								if(strcmp(value[i], temp.f5) == 0) fprintf(tempFile, "%s\n", temp.f5);
							}
							}
						}
						else fprintf(tempFile, "%s\n", temp.f5);

						fscanf(cfptr, "%s%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4, temp.f5);
						fflush(tempFile);
					}
					fclose(tempFile);
					count++;
					continue;
				}
				}
			break;//---------------------------end case o----------------------------------------
			case 'g':
				for(int i=0;i<5;i++) {
				char ntos[10];
				sprintf(ntos, "temp%d.txt", i);

				//printf(ntos);
				//printf("\n");
				if(strcmp(str[i], "goonum") == 0) {
					tempFile = fopen(ntos,"w");
					rewind(cfptr);
					fscanf(cfptr, "%s%s%s", temp.f1, temp.f2, temp.f3);
					fprintf(tempFile, "%s\n", temp.f1);
					fscanf(cfptr, "%s%s%s", temp.f1, temp.f2, temp.f3);
					while(!feof(cfptr)) {
						if(strcmp(whereS, "-") != 0) {
							for(int i=0;i<2;i++) {
							if(strcmp(key[i], "goonum") == 0) {
								if(strcmp(value[i], temp.f1) == 0) fprintf(tempFile, "%s\n", temp.f1);
							}
							}
						}
						else fprintf(tempFile, "%s\n", temp.f1);

						fscanf(cfptr, "%s%s%s", temp.f1, temp.f2, temp.f3);
						fflush(tempFile);
					}
					fclose(tempFile);
					count++;
					continue;
				}
				if(strcmp(str[i], "price") == 0) {
					tempFile = fopen(ntos,"w");
					rewind(cfptr);
					fscanf(cfptr, "%s%s%s", temp.f1, temp.f2, temp.f3);
					fprintf(tempFile, "%s\n", temp.f2);
					fscanf(cfptr, "%s%s%s", temp.f1, temp.f2, temp.f3);
					while(!feof(cfptr)) {
						if(strcmp(whereS, "-") != 0) {
							for(int i=0;i<2;i++) {
							if(strcmp(key[i], "price") == 0) {
								if(strcmp(value[i], temp.f2) == 0) fprintf(tempFile, "%s\n", temp.f2);
							}
							}
						}
						else fprintf(tempFile, "%s\n", temp.f2);

						fscanf(cfptr, "%s%s%s", temp.f1, temp.f2, temp.f3);
						fflush(tempFile);
					}
					fclose(tempFile);
					count++;
					continue;
				}
				if(strcmp(str[i], "makedate") == 0) {
					tempFile = fopen(ntos,"w");
					rewind(cfptr);
					fscanf(cfptr, "%s%s%s", temp.f1, temp.f2, temp.f3);
					fprintf(tempFile, "%s\n", temp.f3);
					fscanf(cfptr, "%s%s%s", temp.f1, temp.f2, temp.f3);
					while(!feof(cfptr)) {
						if(strcmp(whereS, "-") != 0) {
							for(int i=0;i<2;i++) {
							if(strcmp(key[i], "makedate") == 0) {
								if(strcmp(value[i], temp.f3) == 0) fprintf(tempFile, "%s\n", temp.f3);
							}
							}
						}
						else fprintf(tempFile, "%s\n", temp.f3);

						fscanf(cfptr, "%s%s%s", temp.f1, temp.f2, temp.f3);
						fflush(tempFile);
					}
					fclose(tempFile);
					count++;
					continue;
				}
				}
				break;//---------------------------end case g----------------------------------------
			case 'd':
				for(int i=0;i<5;i++) {
				char ntos[10];
				sprintf(ntos, "temp%d.txt", i);

			//	printf(ntos);
			//	printf("\n");
				if(strcmp(str[i], "comnum") == 0) {
					tempFile = fopen(ntos,"w");
					rewind(cfptr);
					fscanf(cfptr, "%s%s%s", temp.f1, temp.f2, temp.f3);
					fprintf(tempFile, "%s\n", temp.f1);
					fscanf(cfptr, "%s%s%s", temp.f1, temp.f2, temp.f3);
					while(!feof(cfptr)) {
						if(strcmp(whereS, "-") != 0) {
							for(int i=0;i<2;i++) {
							if(strcmp(key[i], "comnum") == 0) {
								if(strcmp(value[i], temp.f1) == 0) fprintf(tempFile, "%s\n", temp.f1);
							}
							}
						}
						else fprintf(tempFile, "%s\n", temp.f1);
					
						fscanf(cfptr, "%s%s%s", temp.f1, temp.f2, temp.f3);
						fflush(tempFile);
					}
					fclose(tempFile);
					count++;
					continue;
				}
				if(strcmp(str[i], "tel") == 0) {
					tempFile = fopen(ntos,"w");
					rewind(cfptr);
					fscanf(cfptr, "%s%s%s", temp.f1, temp.f2, temp.f3);
					fprintf(tempFile, "%s\n", temp.f2);
					fscanf(cfptr, "%s%s%s", temp.f1, temp.f2, temp.f3);
					while(!feof(cfptr)) {
						if(strcmp(whereS, "-") != 0) {
							for(int i=0;i<2;i++) {
							if(strcmp(key[i], "tel") == 0) {
								if(strcmp(value[i], temp.f2) == 0) fprintf(tempFile, "%s\n", temp.f2);
							}
							}
						}
						else fprintf(tempFile, "%s\n", temp.f2);

						fscanf(cfptr, "%s%s%s", temp.f1, temp.f2, temp.f3);
						fflush(tempFile);
					}
					fclose(tempFile);
					count++;
					continue;
				}
				if(strcmp(str[i], "add") == 0) {
					tempFile = fopen(ntos,"w");
					rewind(cfptr);
					fscanf(cfptr, "%s%s%s", temp.f1, temp.f2, temp.f3);
					fprintf(tempFile, "%s\n", temp.f3);
					fscanf(cfptr, "%s%s%s", temp.f1, temp.f2, temp.f3);
					while(!feof(cfptr)) {
						if(strcmp(whereS, "-") != 0) {
							for(int i=0;i<2;i++) {
							if(strcmp(key[i], "add") == 0) {
								if(strcmp(value[i], temp.f3) == 0) fprintf(tempFile, "%s\n", temp.f3);
							}
							}
						}
						else fprintf(tempFile, "%s\n", temp.f3);

						fscanf(cfptr, "%s%s%s", temp.f1, temp.f2, temp.f3);
						fflush(tempFile);
					}
					fclose(tempFile);
					count++;
					continue;
				}
				}
			break;//---------------------------end case d----------------------------------------
			case 'c':
				for(int i=0;i<5;i++) {
				char ntos[10];
				sprintf(ntos, "temp%d.txt", i);

			//	printf(ntos);
			//	printf("\n");
				if(strcmp(str[i], "cusnum") == 0) {
					tempFile = fopen(ntos,"w");
					rewind(cfptr);
					fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
					fprintf(tempFile, "%s\n", temp.f1);
					fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
					while(!feof(cfptr)) {
						if(strcmp(whereS, "-") != 0) {
							for(int i=0;i<2;i++) {
							if(strcmp(key[i], "cusnum") == 0) {
								if(strcmp(value[i], temp.f1) == 0) fprintf(tempFile, "%s\n", temp.f1);
							}
							}
						}
						else fprintf(tempFile, "%s\n", temp.f1);
						
						fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
						fflush(tempFile);
					}
					fclose(tempFile);
					count++;
					continue;
				}
				if(strcmp(str[i], "tel") == 0) {
					tempFile = fopen(ntos,"w");
					rewind(cfptr);
					fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
					fprintf(tempFile, "%s\n", temp.f2);
					fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
					while(!feof(cfptr)) {
						if(strcmp(whereS, "-") != 0) {
							for(int i=0;i<2;i++) {
							if(strcmp(key[i], "tel") == 0) {
								if(strcmp(value[i], temp.f2) == 0) fprintf(tempFile, "%s\n", temp.f2);
							}
							}
						}
						else fprintf(tempFile, "%s\n", temp.f2);
						fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
						fflush(tempFile);
					}
					fclose(tempFile);
					count++;
					continue;
				}
				if(strcmp(str[i], "add") == 0) {
					tempFile = fopen(ntos,"w");
					rewind(cfptr);
					fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
					fprintf(tempFile, "%s\n", temp.f3);
					fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
					while(!feof(cfptr)) {
						if(strcmp(whereS, "-") != 0) {
							for(int i=0;i<2;i++) {
							if(strcmp(key[i], "add") == 0) {
								if(strcmp(value[i], temp.f3) == 0) fprintf(tempFile, "%s\n", temp.f3);
							}
							}
						}
						else fprintf(tempFile, "%s\n", temp.f3);

						fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
						fflush(tempFile);
					}
					fclose(tempFile);
					count++;
					continue;
				}
				if(strcmp(str[i], "name") == 0) {
					tempFile = fopen(ntos,"w");
					rewind(cfptr);
					fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
					fprintf(tempFile, "%s\n", temp.f4);
					fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
					while(!feof(cfptr)) {
						if(strcmp(whereS, "-") != 0) {
							for(int i=0;i<2;i++) {
							if(strcmp(key[i], "name") == 0) {
								if(strcmp(value[i], temp.f4) == 0) fprintf(tempFile, "%s\n", temp.f4);
							}
							}
						}
						else fprintf(tempFile, "%s\n", temp.f4);

						fscanf(cfptr, "%s%s%s%s", temp.f1, temp.f2, temp.f3, temp.f4);
						fflush(tempFile);
					}
					fclose(tempFile);
					count++;
					continue;
				}
				}
			break;//---------------------------end case c----------------------------------------
			default:
				printf("Error");
			}
			fclose(cfptr);


			outFile2 = fopen("output.txt","w");
			if((t1 = fopen("temp0.txt","rt"))== NULL) {
				printf("Error_open.");
			}
			else 
			{
			//Format => | %-4s| %-10s| %-10s| %-10s|\n
			if(count == 1)
			{
				t1 = fopen("temp0.txt","rt"); rewind(t1);
				fscanf(t1, "%s", tempout.ff1); 
				while(!feof(t1)) {
					fprintf(outFile2, "%s\n", tempout.ff1);
					printf("| %-10s|\n", tempout.ff1);
					fscanf(t1, "%s", tempout.ff1);
					fflush(outFile2);
				}
				fclose(outFile2);
			}
			if(count == 2)
			{
				t1 = fopen("temp0.txt","rt"); rewind(t1);
				fscanf(t1, "%s", tempout.ff1);
				t2 = fopen("temp1.txt","rt"); rewind(t2);
				fscanf(t2, "%s", tempout.ff2);
				while(!feof(t1)) {
					fprintf(outFile2, "%s	%s\n", tempout.ff1, tempout.ff2);
					printf("| %-10s| %-10s|\n", tempout.ff1, tempout.ff2);
					fscanf(t1, "%s", tempout.ff1);
					fscanf(t2, "%s", tempout.ff2);
					fflush(outFile2);
				}
				fclose(outFile2);
			}
			if(count == 3)
			{
				t1 = fopen("temp0.txt","rt"); rewind(t1);
				fscanf(t1, "%s", tempout.ff1);
				t2 = fopen("temp1.txt","rt"); rewind(t2);
				fscanf(t2, "%s", tempout.ff2);
				t3 = fopen("temp2.txt","rt"); rewind(t3);
				fscanf(t3, "%s", tempout.ff3);
				while(!feof(t1)) {
					fprintf(outFile2, "%s	%s	%s\n", tempout.ff1, tempout.ff2, tempout.ff3);
					printf("| %-10s| %-10s| %-10s|\n", tempout.ff1, tempout.ff2, tempout.ff3);
					fscanf(t1, "%s", tempout.ff1);
					fscanf(t2, "%s", tempout.ff2);
					fscanf(t3, "%s", tempout.ff3);
					fflush(outFile2);
				}
				fclose(outFile2);
			}
			if(count == 4)
			{
				t1 = fopen("temp0.txt","rt"); rewind(t1);fscanf(t1, "%s", tempout.ff1); 
				t2 = fopen("temp1.txt","rt"); rewind(t2);fscanf(t2, "%s", tempout.ff2);
				t3 = fopen("temp2.txt","rt"); rewind(t3);fscanf(t3, "%s", tempout.ff3);
				t4 = fopen("temp3.txt","rt"); rewind(t4);fscanf(t4, "%s", tempout.ff4);	
			
				while(!feof(t1)) {
					fprintf(outFile2, "%s	%s	%s	%s\n", tempout.ff1, tempout.ff2, tempout.ff3, tempout.ff4);
					printf("| %-10s| %-10s| %-10s| %-10s|\n", tempout.ff1, tempout.ff2, tempout.ff3, tempout.ff4);
					fscanf(t1, "%s", tempout.ff1);
					fscanf(t2, "%s", tempout.ff2);
					fscanf(t3, "%s", tempout.ff3);
					fscanf(t4, "%s", tempout.ff4);
					fflush(outFile2);
				}
				fclose(outFile2);
			}
			if(count == 5)
			{
				t1 = fopen("temp0.txt","rt"); rewind(t1);fscanf(t1, "%s", tempout.ff1); 
				t2 = fopen("temp1.txt","rt"); rewind(t2);fscanf(t2, "%s", tempout.ff2);
				t3 = fopen("temp2.txt","rt"); rewind(t3);fscanf(t3, "%s", tempout.ff3);
				t4 = fopen("temp3.txt","rt"); rewind(t4);fscanf(t4, "%s", tempout.ff4);
				t5 = fopen("temp3.txt","rt"); rewind(t5);fscanf(t5, "%s", tempout.ff5);	
			
				while(!feof(t1)) {
					fprintf(outFile2, "%s	%s	%s	%s	%s\n", tempout.ff1, tempout.ff2, tempout.ff3, tempout.ff4, tempout.ff5);
					printf("| %-10s| %-10s| %-10s| %-10s| %-10s|\n", tempout.ff1, tempout.ff2, tempout.ff3, tempout.ff4, tempout.ff5);
					fscanf(t1, "%s", tempout.ff1);
					fscanf(t2, "%s", tempout.ff2);
					fscanf(t3, "%s", tempout.ff3);
					fscanf(t4, "%s", tempout.ff4);
					fscanf(t5, "%s", tempout.ff5);
					fflush(outFile2);
				}
				fclose(outFile2);
			}
			}

		}
		
	}
	
	_getch();
}