#define MAX_SIZE 30
char findTheDifference(char * s, char * t){
    char out='\0';
    for(;*s;++s) out^=*s;
    for(;*t;++t) out^=*t;
    return out;
}
void _start()
{
	char s[MAX_SIZE]="v-3md97q";
	char t[MAX_SIZE]="v-3mdu97q";
	char diff=findTheDifference(s,t);
	volatile char *tx = (volatile char *) 0x40002000;
	*tx = (char) ((diff) & 0x000000FF);
}
