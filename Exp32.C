#include <stdio.h>

int main()
{
    int pages[50], frames[10], time[10];
    int n,f,i,j,faults=0, counter=0;

    printf("Enter number of pages: ");
    scanf("%d",&n);

    for(i=0;i<n;i++) scanf("%d",&pages[i]);

    printf("Enter frames: ");
    scanf("%d",&f);

    for(i=0;i<f;i++) frames[i]=-1;

    for(i=0;i<n;i++)
    {
        int found=0;

        for(j=0;j<f;j++)
        {
            if(frames[j]==pages[i])
            {
                found=1;
                time[j]=counter++;
                break;
            }
        }

        if(!found)
        {
            int lru=0;

            for(j=1;j<f;j++)
                if(time[j]<time[lru])
                    lru=j;

            frames[lru]=pages[i];
            time[lru]=counter++;
            faults++;
        }
    }

    printf("Page Faults = %d\n",faults);

    return 0;
}
