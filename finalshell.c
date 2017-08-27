

		/*    Created By G.Sharath
			alientrunkcall


			 A sample shell with few commands
				reveal - cat
				spawn - touch
				mkefold - mkdir
				clone - cp
					 			*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#define BLOCK_SIZE 4096

char str[100];
char words[4][10];
int main();
void clone()
{


	int fdsrc=-1,fddes=-1;
	ssize_t readbytes=-1,writebytes=-1;
	int i=0;
	char openf1[20],openf2[20];
	strcpy(openf1,words[1]);
	strcpy(openf2,words[2]);
	i=strlen(openf2);
	openf2[i-1]='\0';
	fdsrc=open(openf1,O_RDONLY);
	off_t size=lseek(fdsrc,0,SEEK_END);
	lseek(fdsrc,0,SEEK_SET);
	char *buff=malloc(size+1);
	int total_size=0;

	if(fdsrc<0)
	perror("Failed To Open Source File");

	fddes=creat(openf2,S_IRWXU);
	if(fddes<0)
		perror("Failed To Create Destination File");
	do{
		readbytes=read(fdsrc,buff,BLOCK_SIZE);
	if(readbytes<0)
		perror("Failed To Read The File");

	writebytes=write(fddes,buff,readbytes);
	if(writebytes<0){
		perror("Failed To Write To Destination File");main();}
	}while(readbytes>0);
		printf("%s Copied To %s File\n",openf1,openf2);
		close(fdsrc);
		close(fddes);
		main();
	}





	void spawn(int in)
	{
	int j;
	int fp;
	for(j=1;j<in;j++)
	{
	fp=open(words[j],O_CREAT|O_RDWR|O_EXCL,0755);
	printf("%s Created \n",words[j]);
	}
	main();
	}




	void mkefold(int in)
	{
	int j;
	for(j=1;j<in;j++)
	//if(mkdir(words[j],0755)==-1)
	perror("Error Creating Folder");
	main();
	}

	void disp()
	{
	int fd=-1;
	ssize_t bytes=-1;
	int i=0;
	char openf[20];
	strcpy(openf,words[1]);
	i=strlen(openf);
	openf[i-1]='\0';
	fd=open(openf,O_RDONLY);
	off_t size=lseek(fd,0,SEEK_END);
	lseek(fd,0,SEEK_SET);
	char *buff=malloc(size+1);

	printf("Entering Display Function\n");

	if(fd==-1)
	{
		perror("Open Failed\n");
	}

	while((bytes=read(fd,buff,BLOCK_SIZE))>0)
	{
		printf("%s",buff);
	}
	close(fd);
	main();
	}
	int main()
	{

	int a=0,i=0,index=0;
	printf("gsharath's Shell $$$$ : $$$ ::");
	fgets(str,100,stdin);

	while(str[a]!='\0') {
	if(str[a]==' ')
		{
			words[index][i]='\0'; i=0;a++;index++;
		}

			words[index][i++]=str[a++];
		}
			words[index++][i]='\0';

		if(!strcmp(words[0],"reveal"))
			disp();
		if(!strcmp(words[0],"clone"))
			clone();
		if(!strcmp(words[0],"spawn"))
			spawn(index);
		if(!strcmp(words[0],"mkefold"))
			mkefold(index);
		if(!strcmp(words[0],"exit\n"))
			exit(0);
		else
			main();


	return 0;
}










