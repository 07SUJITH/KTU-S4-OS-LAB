#include<stdio.h>

struct frame {
    int content;
    int count;
}fr[10];

int main(){

    int np, nf, pg[25],found = 0,k=0,pfault=0;
    int count=1,min =0;
    printf("ENTER THE NUMBER OF PAGES : ");
    scanf("%d", &np);
    printf("ENTER THE REFERENCE STRING : ");
    for (int j = 0; j < np; j++)
        scanf("%d", &pg[j]);
    printf("ENTER THE NUMBER OF FRAMES : ");
    scanf("%d",&nf);
    for(int j =0;j< nf ;j++){
        fr[j].content= -1;
        fr[j].count = 0;
    }
    printf("\nREFERENCE PAGE  STATUS  FRAME CONTENT \n");
    for(int i = 0;i< np ;i++){
            found = 0;
            printf("\n\t%d\t ",pg[i]);
            for(int j = 0; j< nf ;j++)
                if(fr[j].content == pg[i]){
                    found = 1;
                    fr[j].count = count++;
                    printf("HIT\t");
                }
    
            if(!found){
                printf("MISS\t");
                if(k<nf){
                    fr[k].content = pg[i];
                    fr[k].count= count++;
                    k++;
                }
                else{
                    min = 0;
                    for(int j =0;j< nf;j++)
                        if(fr[j].count < fr[min].count)
                            min =j;
                    fr[min].content = pg[i];
                    fr[min].count= count++;
                }
                pfault++;
            }

            for(int j = 0;j<nf;j++)
                if(fr[j].content !=-1)
                    printf(" %d ",fr[j]);
    }
    printf("\n\nPAGE FAULT : %d",pfault);
}
