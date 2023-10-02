
#include <stdio.h>

int main(){

    int np, nf, pg[25], fr[10],found =0,k=0,pfault=0;
    printf("ENTER THE NUMBER OF PAGES : ");
    scanf("%d", &np);
    printf("ENTER THE REFERENCE STRING : ");
    for (int j = 0; j < np; j++)
        scanf("%d", &pg[j]);
    printf("ENTER THE NUMBER OF FRAMES : ");
    scanf("%d",&nf);
    for(int j =0;j< nf ;j++)
        fr[j] = -1;

    printf("\nREFERENCE PAGE  STATUS  FRAME CONTENT \n");
    for(int i = 0;i< np ;i++){
            found = 0;
            printf("\n\t%d\t ",pg[i]);
            for(int j = 0; j< nf ;j++)
                if(fr[j] == pg[i])
                    found = 1;
            if(!found){
                fr[k] = pg[i];
                k = (k+1)%nf;
                pfault++;
            }
            if(found)
                printf("HIT\t");
            else    
                printf("MISS\t");

            for(int j = 0;j<nf;j++)
                if(fr[j]!=-1)
                    printf(" %d ",fr[j]);
    }
    printf("\nPAGE FAULT : %d ",pfault);
}
