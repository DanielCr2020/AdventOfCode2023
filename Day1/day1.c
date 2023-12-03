#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char* buildNum(int i, char* buf){
    
}

int main(){
    FILE* fp = fopen("inputday1.txt","r");
    char line[100];
    int sum=0;
    while(fscanf(fp,"%s",line)==1){
        int length=strnlen(line,100);
        char num[3] = {'0','0','\0'};
        // part 1
        // int i=0;
        // for(;i<length;i++){
        //     if(line[i]=='0' || line[i]=='1' || line[i]=='2' || line[i]=='3' || line[i]=='4' || line[i]=='5' || line[i]=='6' || line[i]=='7' || line[i]=='8' || line[i]=='9'){
        //         num[0]=line[i];
        //         break;
        //     }
        // }
        // for(int j=length;j>=i;j--){
        //     if(line[j]=='0' || line[j]=='1' || line[j]=='2' || line[j]=='3' || line[j]=='4' || line[j]=='5' || line[j]=='6' || line[j]=='7' || line[j]=='8' || line[j]=='9'){
        //         num[1]=line[j];
        //         break;
        //     }
        // }
        // int temp = atoi(num);
        // sum+=temp;


        // Part 2
        // Doesn't work
        char* s1=strstr(line,"one");
        char* s2=strstr(line,"two");
        char* s3=strstr(line,"three");
        char* s4=strstr(line,"four");
        char* s5=strstr(line,"five");
        char* s6=strstr(line,"six");
        char* s7=strstr(line,"seven");
        char* s8=strstr(line,"eight");
        char* s9=strstr(line,"nine");
        char* s10=strstr(line,"0");
        char* s11=strstr(line,"1");
        char* s12=strstr(line,"2");
        char* s13=strstr(line,"3");
        char* s14=strstr(line,"4");
        char* s15=strstr(line,"5");
        char* s16=strstr(line,"6");
        char* s17=strstr(line,"7");
        char* s18=strstr(line,"8");
        char* s19=strstr(line,"9");

        char linerev[strlen(line)];
        int j=0;
        for(int i=strlen(line)-1;i>0;i--){
            linerev[j]=line[i];
            j++;
        }
        char* bs1=strstr(linerev,"eno");
        char* bs2=strstr(linerev,"owt");
        char* bs3=strstr(linerev,"eerht");
        char* bs4=strstr(linerev,"ruof");
        char* bs5=strstr(linerev,"evif");
        char* bs6=strstr(linerev,"xis");
        char* bs7=strstr(linerev,"neves");
        char* bs8=strstr(linerev,"thgie");
        char* bs9=strstr(linerev,"enin");
        char* bs10=strstr(linerev,"0");
        char* bs11=strstr(linerev,"1");
        char* bs12=strstr(linerev,"2");
        char* bs13=strstr(linerev,"3");
        char* bs14=strstr(linerev,"4");
        char* bs15=strstr(linerev,"5");
        char* bs16=strstr(linerev,"6");
        char* bs17=strstr(linerev,"7");
        char* bs18=strstr(linerev,"8");
        char* bs19=strstr(linerev,"9");

        char* indexes[]={
            s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,
            s11,s12,s13,s14,s15,s16,s17,s18,s19,
            bs1,bs2,bs3,bs4,bs5,bs6,bs7,bs8,bs9,
            bs10,bs11,bs12,bs13,bs14,bs15,bs16,bs17,bs18,bs19
        };

        char* min = NULL;
        for(int i=0;i<19;i++){
            if(min==NULL){
                min=indexes[i];
            }
            if(indexes[i]<min && indexes[i]!=NULL){
                min=indexes[i];
            }
        }
        char* max = NULL;
        for(int i=19;i<38;i++){
            if(max==NULL){
                max=indexes[i];
            }
            if(indexes[i]>max && indexes[i]!=NULL){
                max=indexes[i];
            }
        }
        if(min!=NULL){
            if(min==s10)
                num[0]='0';
            else if(min==s1 || min==s11)
                num[0]='1';
            else if(min==s2 || min==s12)
                num[0]='2';
            else if(min==s3 || min==s13)
                num[0]='3';
            else if(min==s4 || min==s14)
                num[0]='4';
            else if(min==s5 || min==s15)
                num[0]='5';
            else if(min==s6 || min==s16)
                num[0]='6';
            else if(min==s7 || min==s17)
                num[0]='7';
            else if(min==s8 || min==s18)
                num[0]='8';
            else if(min==s9 || min==s19)
                num[0]='9';
        }
        if(max!=NULL){
            if(max==bs10)
                num[1]='0';
            else if(max==bs1 || max==bs11)
                num[1]='1';
            else if(max==bs2 || max==bs12)
                num[1]='2';
            else if(max==bs3 || max==bs13)
                num[1]='3';
            else if(max==bs4 || max==bs14)
                num[1]='4';
            else if(max==bs5 || max==bs15)
                num[1]='5';
            else if(max==bs6 || max==bs16)
                num[1]='6';
            else if(max==bs7 || max==bs17)
                num[1]='7';
            else if(max==bs8 || max==bs18)
                num[1]='8';
            else if(max==bs9 || max==bs19)
                num[1]='9';
        }
        int temp=atoi(num);
        num[0]='0';
        num[1]='0';
        sum+=temp;
        printf("%d %s %s\n",num[0],line,linerev);
    }
    printf("%d\n",sum);
    fclose(fp);
}