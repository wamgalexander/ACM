#include <cstdio>
#include <cstring>
#include <cstdlib>

int main(){
	char buf[10001];
	while(1){
		memset(buf,0,strlen(buf));
		gets(buf);
		if(!strcmp(buf,"ENDOFINPUT")) break;
		if(strcmp(buf,"START") && strcmp(buf,"END")){
			for(int i=0; i < strlen(buf) ; i++)
			{
				if(buf[i] >= 'A' && buf[i] <= 'Z'){
					int c = (buf[i]-5) >= 'A' ? buf[i]-5 : buf[i]+21;
					buf[i] = (char) c;			
				}
			}
			printf("%s\n", buf);
		}
	}
	return 0;
}