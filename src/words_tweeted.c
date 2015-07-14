//
//  words_tweeted.c
//  
//
//  Created by pallak tayal on 2015-07-13.
//
//

#include <stdio.h>
#include <string.h>

int main()
{
    char arr1[400][100], arr2[400][100];
    int freq1[400], freq2[400],tf;
    int i, j, k ,l ,m, n, num;
    char t[100];
    char s[100];
    FILE *f1;
    FILE *f2;
    f1= fopen("/Users/pallaktayal/Documents/project/tweet_input/tweets.txt","r");
    
    for(i=0; i<400 && !feof(f1);i++)
    {
        fscanf(f1,"%s", s);
        strcpy(arr1[i],s);
    }
    n=i;
    for(i=0;i<n+1;i++)
    {
        freq1[i]=1;
    }
    for(i=1;i<n+1;i++)
    {
        for(j=0;j<i;j++)
        {
            if(strcmp(arr1[i],arr1[j])==0)
            {
                //strcpy(arr1[i],"***");
                freq1[j]=freq1[j]+1;
                freq1[i]=0;
                break;
            }
        }
    }
    j=0;
    for(i=0;i<n;i++)
    {
        if(freq1[i]!=0)
        {
            strcpy(arr2[j],arr1[i]);
            freq2[j]=freq1[i];
            j++;
        }
    }
    num=j;
    for(k=1;k<num+1;k++)
    {
        for(l=1;l<num+1;l++)
        {
            if(strcmp(arr2[l-1],arr2[l])>0)
            {
                strcpy(t, arr2[l-1]);
                strcpy(arr2[l-1],arr2[l]);
                strcpy(arr2[l],t);
                tf=freq2[l-1];
                freq2[l-1]=freq2[l];
                freq2[l]=tf;
                
            }
        }  }
    for(l=1;l<num+1;l++)
    {
        printf("%25s %2d", arr2[l],freq2[l]);
        printf("\n");
    }
    fclose(f1);
    f2= fopen("/Users/pallaktayal/Documents/project/tweet_output/ft1.txt ","w");
    
    for(l=1;l<num+1;l++)
    {
        // fputs(arr2[l],f2);
        fprintf ( f2, "%25s %2d \n", arr2[l],freq2[l] ) ;
    }
    fclose(f2);
    
}



