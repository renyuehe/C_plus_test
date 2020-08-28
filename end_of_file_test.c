/*************************************************************************
	> File Name: test.c
	> Author: ryh
	> Mail: 601612274@qq.com 
	> Created Time: 2020年08月27日 星期四 21时29分42秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

char buf[1024*1024];
int ret;

struct stat fdStat;

int main(){
	int fd;
	fd = open("111.txt",O_RDONLY);
//	fd = open("vcs",O_RDONLY);
//	fd = open("huge.jpg",O_RDONLY);
	ret = read(fd,buf,sizeof(buf));

	fstat(fd,&fdStat);

	printf("ret = %d\n",ret);	
	printf("111.txt fdStat.st_size = %ld\n",fdStat.st_size);

	int i;
	for(i = 0; i < fdStat.st_size+1; i++)
	{
			printf("111.txt at %d = %d\n",i,buf[i]);
	}

	close(fd);
	return 0;
}
