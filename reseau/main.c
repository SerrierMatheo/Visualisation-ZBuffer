#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

FILE * flog;

void affiche(int a){
    int s;
    char c;
    long d;
    flog=fopen("log.txt","r");

    while(fscanf(flog,"%d",&s)!=EOF){
        fscanf(flog,"%c",&c);
        fscanf(flog,"%ld",&d);
        printf("%d,%ld\n",s,d);
    }
    fclose(flog);
}

void traitment(int a){
    flog = fopen("log.txt","a");
    time_t t = time(NULL);
    fprintf(flog,"%d,%ld\n",a,t);
    fclose(flog);
}

void main(){
    Signal(SIGUSR1, traitment);
    Signal(SIGUSR2, traitment);
    Signal(SIGINT, affiche);
    while(1)
        pause();
}
---------------------------------------------------------------

int write(char *f, chaine c){
    File * fch = fopen(f,"wb");
    if(fch == NULL){
        return 0;
    }
    while(c!=NULL){
        fwrite(&c->val, sizeof(int),1,fch);
        c = c->next;
    }
    fclose(fch)
    return 1;
}

chiane read(char * f){
    FILE * fch=fopen(f,"nb");
    chaine c = init();
    int v;
    while(fread(&v,sizeof(int), 1, fch) != 0){
        c = intail(c,v);
    }
    fclose(fch);
    return c;
}