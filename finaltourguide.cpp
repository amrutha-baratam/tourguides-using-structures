#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct tourguide{
    char *name;
    int energy;
};
struct location{
    int x;
    struct tourguide* present[10];
    
}pos[11];

void add(char *name,int loc,int e){
    int i=0;
    for(int i=0;i<10;i++)
        if(pos[loc].present[i]==NULL)
        break;
    pos[loc].present[i]=(struct tourguide *)malloc(sizeof(struct tourguide));
    pos[loc].present[i]->energy=e;
    pos[loc].present[i]->name=name;
    
}

void solve(int,int);
int main() {
    int n;
    printf("enter number of guides\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char* s=(char *)malloc(sizeof(char)*50);
        int loc,energy;
        printf("enter name location and energy\n");
        scanf("%s%d%d",s,&loc,&energy);
        add(s,loc,energy);
    }
        int q,u,v;
        printf("enter number of queries\n");
        scanf("%d",&q);
        for(int i=0;i<q;i++){
        	printf("enter source and destination\n");
            scanf("%d %d",&u,&v);
            solve(u,v);
        }
    

}
void solve(int u,int v){
    int x,y;x=-1;y=-1;
    for(int i=1;i<=10;i++){
        for(int j=0;j<10;j++){
            if(pos[i].present[j]==NULL)
            continue;
        if(pos[i].present[j]->energy<abs(i-u)+abs(u-v))
            continue;
        if(x==-1){
            x=i;y=j;
            }
            else{
                if(abs(x-u)>abs(i-u)){
                    x=i;y=j;
                }
                else if(abs(x-u)==abs(i-u)){
                    if(pos[i].present[j]->energy>pos[x].present[j]->energy){
                        x=i;
                        y=j;
                    }
                }
            }
        }
    }
    if(x==-1){
        printf("all guides are exhausted");
    }
    else{
        printf("%s\n",pos[x].present[y]->name);
        pos[x].present[y]->energy-=abs(x-u)+abs(u-v);
        int i=0;
        for(int i=0;i<10;i++)
            if(pos[v].present[i]==NULL)
                break;
        pos[v].present[i]=pos[x].present[y];
        pos[x].present[y]=NULL;
            
        
    }
}


