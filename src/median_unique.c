//
//  median_unique.c
//  
//
//  Created by pallak tayal on 2015-07-12.
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
    int count[400], tweets=1, u=0, v;
    float median=0, sum=0;
    FILE *f1;
    FILE *f2;
    char ch;
    int q=0;
    
    
    f1= fopen("/Users/pallaktayal/Documents/project/tweet_input/tweets.txt","r");
    
   start: while((ch=getc(f1))!='\n')
    {
     
    fseek(f1, -1, SEEK_CUR);
        fscanf(f1,"%s", s);
     
        strcpy(arr1[i],s);
        i++;
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
   // for(l=1;l<num+1;l++)
    //{
      //  printf("%25s %2d", arr2[l],freq2[l]);
        //printf("\n");
    //}
    count[u]=0;
    for(l=1;l<num+1;l++)
    {
            count[u]=count[u]+1;
    }
    
    for(v=0;v<=u;v++)
        {
            sum=sum+count[v];
        }
    //printf("sum: %f\n", sum);
    //printf("u: %d\n", u);
    //printf("tweets: %d\n", tweets);
    

        median=sum/tweets;
    printf("median: %f\n", median);
    f2= fopen("/Users/pallaktayal/Documents/project/tweet_output/ft2.txt","a");
    fprintf(f2,"median: %f\n", median);
    fclose(f2);
    
    u=u+1;
        tweets=tweets+1;
        sum=0;
    
    i=0;
    if(ch!=EOF)
    {
        goto start;
    }
   
    fclose(f1);
    }


