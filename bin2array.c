#include <stdio.h>
#include <string.h>
FILE *fi,*fo;
unsigned int n;
int c;

void main(int argc,char* argv[])
{
	if((fi=fopen(argv[1],"rb")) == NULL)
	{
		return;
	}
	if((fo=fopen(argv[2],"w")) == NULL)
	{
		return;
	}
	fprintf(fo,"const unsigned char IopNormalCode []=\n{");
	n = 0;
	
	int cnt = 4096*16;
	while(cnt--)
	{
		c = fgetc(fi);
		if(EOF == c)
			c = 0xFF;
		n++;
		if(1==n){
			fprintf(fo,"\n	0x%02x,",c);
		}
		else{
			if(1 == n%16)
				fprintf(fo,"\n	0x%02x,",c);
			else
				fprintf(fo,"0x%02x,",c);
		}
	}
fprintf(fo,"\n};");
fclose(fi);
fclose(fo);
}