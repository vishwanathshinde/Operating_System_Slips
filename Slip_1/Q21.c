#include <stdio.h>

int main()
{
    int i, j, k, np, nf, ref_string[50], frame[10], page_found, fcount = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &np);

    printf("Enter the page reference string: ");
    for (i = 0; i < np; i++)
    {
        scanf("%d", &ref_string[i]);
    }

    printf("Enter the number of memory frames: ");
    scanf("%d",&nf);

    for(i=0; i<nf; i++)
    {
        frame[i] = -1;  //initializing all frames -1
    }
    j = 0;      // initializing page frame pointer

    printf("\n Ref_string \t Page Frames \t Hit/Fault \n");

    for(i=0; i<np; i++)
    {
        printf("%d\t\t",ref_string[i]);
        page_found = 0;

        for(k=0; k<nf; k++)
        {
            if(frame[k] == ref_string[i])   // input of  page  requested is compared with existing content of FRAME
            {
                page_found = 1;     //as page found available turns 1
                for(k=0; k<nf; k++)
                {
                    printf("%d\t",frame[k]);    //print current state of k
                }
                printf("H"); //indicating page hit
            }
        }

        if(page_found == 0) //input page requested is not available in frame
        {
            frame[j] = ref_string[i]; //place page requested at jth place
            j=(j+1) % nf; //update j for the next cycle
            fcount++;   //increment count for page fault

            for(k=0; k<nf; k++)
            {
                printf("%d\t",frame[k]); //print current state of k
            }
            printf("F");
        }
        printf("\n");
    }
    printf("\n Total page fault are: %d",fcount);
    return 0;
}