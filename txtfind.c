#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30
int getLine(char s[]){
    int indexS=0;
    int counter=0;
    int isLong=0; 
    while(scanf("%c",&s[indexS])==1){
        indexS++;
        if(indexS==LINE-1){
            isLong=1;
            break;
        }
        if(s[indexS-1]=='\n') break;
    }
    if(isLong==1){
        s[indexS]='\0';
    }
    else
    {
    s[indexS-1]='\0';
    }
    return indexS;//the length include the \n
}
int getword(char w[]){
    int indexW=0;
    while(scanf("%c",&w[indexW])==1){
        indexW++;
        if(indexW==WORD){
            break;
        }
        if(w[indexW-1]=='\n' ||w[indexW-1]==' '||w[indexW-1]=='\t'||w[indexW-1]=='\r'){
            break;
        }
    }
    char w1[indexW];
    strncpy(w1,w,indexW);
    if(w1[indexW-1]==' ' ||w1[indexW-1]== '\t'|| w1[indexW-1]=='\r'|| w1[indexW-1]=='\n')
    {
    w1[indexW-1]='\0';//-------------
    }
    strcpy(w,w1);
    return indexW;
}


int substring(char str1[],char str2[]){
  char *p1, *p2, *p3;
  int i=0,j=0,flag=0;

  p1 = str1;
  p2 = str2;

  for(i = 0; i<strlen(str1); i++)
  {
    if(*p1 == *p2)
      {
          p3 = p1;
          for(j = 0;j<strlen(str2);j++)
          {
            if(*p3 == *p2)
            {
              p3++;p2++;
            } 
            else
              break;
          }
          p2 = str2;
          if(j == strlen(str2))
          {
             flag = 1;
          }
      }
    p1++; 
  }
  return flag;
}

int similar(char s[],char t[]){
    char subs[strlen(s)-1];
    if(strcmp(s,t)==0){
        return 1;
    }
    if(strlen(s)-1>strlen(t)|| strlen(s)<strlen(t)){
        return 0;
    }
    int indexLetter=0;
    for(int i=0;i<strlen(s);i++){
        indexLetter=i;
        int subIndex=0;
        char temp[strlen(s)-1];
        strcpy(subs,temp);
        for(int j=0;j<strlen(s);j++){
            if(j!=indexLetter){
                subs[subIndex]=s[j];
                 subIndex++;
            }
        }
        if(strncmp(subs,t,strlen(t))==0) return 1;
    }
    return 0;
}
void print_lines(char * str){
    char l[LINE];
    while (getLine(l)>0)
    {
        if(substring(l,str)==1){
            printf("%s\n",l);
        }
    }
}
void print_similar_words(char * str){
    char w[WORD];
    while (getword(w)>0)
    {
        if(similar(w,str)==1){
            printf("%s\n",w);
        }
    }
}
void mainFunction(){
    char w[WORD];
    char option[WORD];
    int sizeW=getword(w);
    int sizeO=getword(option);
    if(strncmp(option,"a",sizeO)==0){
    print_lines(w);
    }
    if(strncmp(option,"b",sizeO)==0){
    print_similar_words(w);
    }
}
void main()
{
   mainFunction();
}
