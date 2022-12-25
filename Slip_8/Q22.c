#include <stdio.h>

int main()
{
    int i, j, k, np, nf, ref_string[]={12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 8, 12, 15, 19, 8}, frame[10], temp[10], pos,
        page_found_1, page_found_2, page_found_3, fcount = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &np);

    // printf("Enter the reference string: ");
    // for (i = 0; i < np; ++i)
    //     scanf("%d", &ref_string[i]);

    printf("Enter the number of memory frames: ");
    scanf("%d", &nf);

    for (i = 0; i < nf; ++i)
    {
        frame[i] = -1;
    }

    j=0;

    // printf("\nRef_string \t Page Frames \t hit/fault \n");

    for (i = 0; i < np; ++i)
    {
        //printf("%d\t\t", ref_string[i]);
        page_found_1 = page_found_2 = 0;

        for (k = 0; k < nf; ++k)
        {
            if (frame[k] == ref_string[i]) // input of page requested is compared with existing content of frame
            {
                page_found_1 = page_found_2 = 1; // as page found available turns 1
                // for(k=0; k<nf; ++k)
                // {
                //     printf("%d\t",frame[k]);
                // }
                // printf("H");
                break;
            }
        }

        if (page_found_1 == 0)
        {
            for (k = 0; k < nf; ++k)
            {
                if (frame[k] == -1)
                {
                    fcount++;
                    frame[k] = ref_string[i];
                    page_found_2 = 1;
                    break;
                }
            }
        }

        if (page_found_2 == 0)
        {
            page_found_3 = 0;

            for (k = 0; k < nf; ++k)
            {
                temp[k] = -1;

                for (j = i + 1; j < np; ++j)
                {
                    if (frame[k] == ref_string[j])
                    {
                        temp[k] = j;
                        break;
                    }
                }
            }

            for (k = 0; k < nf; ++k)
            {
                if (temp[k] = -1)
                {
                    pos = k;
                    page_found_3 = 1;
                    break;
                }
            }

            if (page_found_3 == 0)
            {
                int max = temp[0];
                pos = 0;

                for (k = 1; k < nf; ++k)
                {
                    if (temp[k] > max)
                    {
                        max = temp[k];
                        pos = k;
                    }
                }
            }
            frame[pos] = ref_string[i];
            fcount++;
        }
        printf("\n");
        for (k = 0; k < nf; ++k)
        {
            printf("%d\t", frame[k]);
        }
    }
    printf("\n\nTotal Page Faults = %d\n\n", fcount);
    return 0;
}