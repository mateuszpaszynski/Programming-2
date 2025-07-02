//Mateusz Paszynski
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void wyrzucsmieci(int ***arr, int *starting_point, int *wiersze) {
    int i;
    int **tab = *arr;
    int index = *starting_point;
    free(*(tab + index));
    for (i = index; i < (*wiersze) - 1; i++) {
        *(tab + i) = *(tab + i + 1);
    }
    (*wiersze)--;
    *arr = realloc(*arr, (*wiersze) * sizeof(int*));
    (*starting_point)--;

}
int main() {
    char *buf = (char* )malloc(4 * sizeof(char));
    scanf("%3s",buf);
    int ** arr = NULL;
    int wiersze = 0;
    int w,h,r,c,d,s;
    int i,j,k;
    while ( strcmp(buf,"END")!= 0) {
        if (strcmp(buf,"ALR")==0) {
            scanf("%d ",&w);
            if (w!=0){
                wiersze++;
                arr = realloc(arr,wiersze * sizeof(int*));
                *(arr + wiersze - 1) =(int*) malloc((w+1)*sizeof(int));
                *(*(arr+wiersze-1)+0)=w;
                for (i=1; i<=w; i++) {
                    scanf("%d",&(*(*(arr + wiersze - 1) + i )));
                }
            }
        }
        if ( strcmp(buf,"AFR")==0) {
            scanf("%d ",&w);
            if ( w!= 0 ){
                wiersze++;
                arr = realloc(arr,wiersze * sizeof(int*));
                for ( i = wiersze - 1;i>0;i--) {
                    *(arr+i) = *(arr+i-1);
                }
                *(arr) =(int*) malloc((w+1)*sizeof(int));
                *(*arr)=w;
                for (i=1; i<=w; i++) {
                    scanf("%d",&(*(*(arr + 0) + i )));
                }
            }
        }
        if ( strcmp(buf,"AFC")==0) {
            scanf("%d ",&h);
            c = 0;
            if ( h > wiersze) {
                arr = realloc(arr,h * sizeof(int*));
                for (i = wiersze;i<h;i++) {
                    *(arr+i) = NULL;
                }
                wiersze = h;
            }
            for ( i = 0; i < h; i++) {
                if ( *(arr+i) ==NULL) {
                    *(arr+i) = malloc((2) * sizeof(int));
                    *(*(arr+i)) = 1;
                    scanf("%d ",(*(arr + i) + 1));
                }
                else {
                    int * row = *(arr + i);
                    row = realloc(row,(*row+2) * sizeof(int));
                    (*row)++;
                    if ( c < *row) {
                        //printf("%d\n",*row);
                        for (j = *row;j>c;j--) {
                            *(row+j) = *(row+j-1);
                        }

                        scanf("%d ",(row+c+1));
                    }
                    else {
                        scanf("%d ",(row+*row));
                    }
                    *(arr+i)=row;
                }
            }
        }
        if ( strcmp(buf,"ALC")==0) {
            scanf("%d",&h);
            if ( h > wiersze) {
                arr = realloc(arr,h * sizeof(int*));
                for (i = wiersze;i<h;i++) {
                    *(arr+i) = NULL;
                }
                wiersze = h;
            }
            for ( i = 0; i < h; i++) {

                if ( *(arr+i) ==NULL) {
                    *(arr+i) = malloc((2) * sizeof(int));
                    *(*(arr+i)) = 1;
                    scanf("%d",(*(arr + i) + 1));
                }
                else {
                    int * row = *(arr + i);
                    c = *row;
                    row = realloc(row,(*row+2) * sizeof(int));
                    (*row)++;
                    if ( c < *row ) {
                        //printf("%d\n",*row);
                        for (j = *row;j>c;j--) {
                            *(row+j) = *(row+j-1);
                        }

                        scanf("%d",(row+c+1));
                    }
                    else {
                        scanf("%d",(row+*row));
                    }
                    *(arr+i)=row;
                }
            }
        }
        if ( strcmp(buf,"IBR")==0) {
            scanf("%d",&r);
           scanf("%d",&w);
            if (r<wiersze && w >0){
                wiersze++;
                arr = realloc(arr,wiersze * sizeof(int*));
                for ( i = wiersze - 1; i > r; i--) {
                    *(arr+i) = *(arr+i-1);
                }

                *(arr+r)=malloc((w+1) * sizeof(int));
                **(arr+r)=w;
                for ( i = 1; i <= w; i++) {
                    scanf("%d",&(*(*(arr + r) + i)));
                }
            }

    }
        if ( strcmp(buf,"IAR")==0) {
            scanf("%d",&r);
            if (r<wiersze){
                wiersze++;
                arr = realloc(arr,wiersze * sizeof(int*));
                for ( i = wiersze - 1; i > r + 1 ; i--) {
                    *(arr+i) = *(arr+i-1);
                }
                scanf("%d",&w);
                *(arr+r+1)=malloc((w+1) * sizeof(int));
                **(arr+r+1)=w;
                for ( i = 1; i <= w; i++) {
                    scanf("%d",&(*(*(arr + r + 1) + i)));
                }
            }
        }
        if ( strcmp(buf,"IBC")==0) {
            scanf("%d %d",&c,&h);
            if ( h > wiersze) {
                arr = realloc(arr,h * sizeof(int*));
                for (i = wiersze;i<h;i++) {
                    *(arr+i) = NULL;
                }
                wiersze = h;
            }
            for ( i = 0; i < h; i++) {
                if ( *(arr+i) ==NULL) {
                    *(arr+i) = malloc((2) * sizeof(int));
                    *(*(arr+i)) = 1;
                    scanf("%d",(*(arr + i) + 1));
                }
                else {
                int * row = *(arr + i);
                row = realloc(row,(*row+2) * sizeof(int));
                (*row)++;
                if ( c < *row) {
                    //printf("%d\n",*row);
                    for (j = *row;j>c;j--) {
                        *(row+j) = *(row+j-1);
                    }

                    scanf("%d",(row+c+1));
                }
                else {
                    scanf("%d",(row+*row));
                }
                *(arr+i)=row;
            }
            }
        }
        if ( strcmp(buf,"IAC")==0) {
            scanf("%d %d",&c,&h);
            if ( h > wiersze) {
                arr = realloc(arr,h * sizeof(int*));
                for (i = wiersze;i<h;i++) {
                    *(arr+i) = NULL;
                }
                wiersze = h;
            }
            for ( i = 0; i < h; i++) {
                if ( *(arr+i) ==NULL) {
                    *(arr+i) = malloc((2) * sizeof(int));
                    *(*(arr+i)) = 1;
                    scanf("%d",(*(arr + i) + 1));
                }
                else {
                int * row = *(arr + i);
                row = realloc(row,(*row+2) * sizeof(int));
                (*row)++;
                if ( c < *row -1 ) {
                    //printf("%d\n",*row);
                    for (j = *row;j>c+1;j--) {
                        *(row+j) = *(row+j-1);
                    }
                    scanf("%d",(row+c+2));
                }
                else {
                    scanf("%d",(row+*row));
                }
                *(arr+i)=row;
            }
        }
        }
        if ( strcmp(buf,"SWR")==0) {
            scanf("%d %d",&r,&s);
            if ( r >= 0 && s >= 0 && r < wiersze && s < wiersze )
            {
                int * temp = *(arr+r);
                *(arr+r) = *(arr+s);
                *(arr+s) = temp;
            }
        }
        if ( strcmp(buf,"SWC")==0) {
            scanf("%d %d",&c,&d);
            if (c>=0 && d>=0 && c != d ) {
                for ( i = 0;i < wiersze ;i++) {
                    int * row = *(arr + i);
                    if ( *row > c && *row > d ) {
                        int temp = *(row+c+1);
                        *(row+c+1) = *(row+d+1);
                        *(row+d+1) = temp;
                    }
                }
            }
        }
        if ( strcmp(buf,"DFR")==0) {
            if ( wiersze!=0) {
                free(*(arr+0));
                wiersze--;
                for ( i = 0; i < wiersze; i++) {
                    *(arr+i)=*(arr+i+1);
                }
                arr = realloc(arr,wiersze * sizeof(int*));
            }
        }
        if ( strcmp(buf,"DLR")==0) {
            if ( wiersze!=0) {
                wiersze--;
                free(*(arr+wiersze));
                arr = realloc(arr,wiersze * sizeof(int*));
            }
        }
        if ( strcmp(buf,"DFC")==0) {
            for ( i = 0;i < wiersze; i++) {
                int * row = *(arr + i);
                for ( j = 1;j< *row ;j++) {
                    *(row+j) = *(row+j+1);
                }
                (*row)--;
                if (*row<=0)*row=0;
                row=realloc(row,(*row+1) * sizeof(int));
                *(arr+i) = row;
                if ( (*row)==0) {
                    wyrzucsmieci(&arr,&i,&wiersze);

                }
            }
        }
        if ( strcmp(buf,"DLC")==0) {
            for ( i = 0;i<wiersze;i++) {
                int * row = (*(arr + i));
                (*row)-=1;

                if (*row<=0)*row=0;
                row=realloc(row,(*row + 1)*sizeof(int));
                *(arr+i) = row;
                if ( *row == 0) {
                    wyrzucsmieci(&arr,&i,&wiersze);
                }
            }
        }
        if ( strcmp(buf,"RMR")==0) {
            scanf("%d",&r);
            if ( r >= 0 && r < wiersze) {
                wyrzucsmieci(&arr,&r,&wiersze);
            }
        }
        if ( strcmp(buf,"RMC")==0) {
            scanf("%d",&c);
            for ( i = 0;i < wiersze; i++) {
                int * row = *(arr + i);
                if ( c>=0  && c < *row) {
                for ( j = c+1;j < *row;j++) {
                    *(row+j) = *(row+j+1);
                }
                (*row)--;
                if (*row<=0)*row=0;
                row=realloc(row,(*row+1) * sizeof(int));
                *(arr+i) = row;
                if ( (*row)==0) {
                    wyrzucsmieci(&arr,&i,&wiersze);
                }
            }
            }
        }
        if ( strcmp(buf,"RMB")==0) {
            scanf("%d %d %d %d",&r,&h,&c,&w);
            for (i = 0;i<h;i++) {
                if ( r + i >= wiersze) {
                    i = h;
                }
                else {
                int* row = *(arr+r+i);

                if (c<*row) {
                    for (j = c + 1;j<=(*row)-w;j++) {
                        *(row+j) = *(row+j+w);
                    }
                    if ((c+w)<=(*row)) {
                        *row-=w;
                    }
                    else {
                        *row=c;
                    }
                    if (*row<=0)*row=0;
                    row=realloc(row,(*row+1) * sizeof(int));
                    *(arr+r+i) = row;
                    if ( (*row)==0) {
                        int m = r+i;
                        wyrzucsmieci(&arr,&m,&wiersze);
                        i--;
                        h--;
                    }
                }
            }
            }
        }
        if ( strcmp(buf,"ISB")==0) {
            scanf("%d %d %d %d",&r,&c,&h,&w);
           // printf("%d %d\n",r+h,wiersze);
            if ( r > wiersze) {
               r = wiersze;
             }
            if ( h + r > wiersze ) {
                arr = realloc(arr,(h+r) * sizeof(int*));
                for ( i = wiersze;i < h + r;i++) {
                    *(arr+i) = NULL;
                }
                wiersze = h + r;
            }
            for (i = 0;i<h;i++) {
                int * row = *(arr + i + r);

                if (row!=NULL) {
                    int pos = (c < *row) ? c : *row;
                    row = realloc(row,(*row+w+1) * sizeof(int));
                    (*row)+=w;
                    for ( j = *row;j>=pos+2;j--) {
                        if ( j - w >=1)*(row+j) = *(row+j-w);
                    }
                    for ( k = pos+1;k<=pos+w;k++) {
                        scanf("%d",(row+k));
                    }
                }
                else {
                    row = malloc((w+1)*sizeof(int));
                    *row = w;
                    for ( k = 1;k<=*row;k++) {
                        scanf("%d",(row+k));
                    }
                }
                *(arr+i+r) = row;
        }
        }
        if ( strcmp(buf,"WRF")==0) {
            if (wiersze>0)
            {
            char *filename = malloc(17 * sizeof(char));
            scanf("%16s",filename);
            FILE* plik = fopen(filename,"w");
                if ( plik != NULL) {
                    fprintf(plik,"%d\n",wiersze);
                    unsigned char bit1,bit2,bit3,bit4;
                    for ( i = 0;i<wiersze;i++)
                    {
                        unsigned short size = **(arr+i);
                        bit1 = (size>>8) ;
                        bit2 = size;
                        fprintf(plik,"%c%c",bit1,bit2);
                        for ( j = 1; j <=**(arr+i);j++)
                        {
                            int num = *(*(arr+i)+j);
                            bit1 = (num >>24);
                            bit2 = num>>16;
                            bit3 = num >>8;
                            bit4 = num;
                            fprintf(plik,"%c%c%c%c",bit1,bit2,bit3,bit4);
                        }
                    }
                    fclose(plik);
                }
                free(filename);
        }
        }
        if ( strcmp(buf,"RDF")==0) {
            char* filename = malloc(17 * sizeof(char));
            scanf("%16s",filename);
            FILE *plik = fopen(filename, "r");
            if ( plik != NULL) {
                for ( i = 0;i<wiersze;i++)
                {
                    free(*(arr+i));
                }
                free(arr);
                wiersze = 0;
                fscanf(plik, "%d", &wiersze);
                arr = malloc(wiersze * sizeof(int*));
                unsigned char c;
                fscanf(plik,"%c",&c);
                unsigned char bit1,bit2,bit3,bit4;
                unsigned int b1,b2,b3,b4;
                unsigned short size;
                for ( i = 0; i < wiersze; i++) {
                    fscanf(plik,"%c%c",&bit1,&bit2);
                    size = (bit1 << 8) | bit2;
                    *(arr+i) = malloc((size+1)*sizeof(int));
                    **(arr+i) = size;
                    for (j = 1; j <= size; j++) {
                        fscanf(plik,"%c%c%c%c",&bit1,&bit2,&bit3,&bit4);
                        unsigned int num = ((bit1 << 24) | (bit2 << 16) | (bit3 << 8) | bit4);
                        *(*(arr+i)+j) = num;
                    }
                }
                fclose(plik);
            }
        free(filename);
        }
        if ( strcmp(buf,"PRT")==0) {
            printf("%d\n",wiersze);
            int i;
            for (i=0;i<wiersze;i++) {
                int n = *(*(arr + i)+0);
                int j;
                for ( j=0;j<=n;j++) {
                    printf("%d",*(*(arr+i)+j));
                    if ( j!=n)printf(" ");
                }
                printf("\n");
            }
        }
        scanf("%3s",buf);
    }
    for ( i=0;i<wiersze;i++) {
        free(*(arr+i));
    }
    free(arr);
    free(buf);
    return 0;
}