#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void kwadrat_dwa(int n){
    double x[2] = {0,0};
	double y[2] = {0,2};
	double z[2] = {2,2};
	double w[2] = {2,0};
	double punkt[2] = {0,0.1};
	FILE *fp = fopen("wynik4.plt","w");
	int seed;
	time_t tt;
	seed = time(&tt);
	srand(seed);
	int i;
	int rzut = 0;
	int rzut_prev = 0;
	for(i=1;i<=n;i++){
		fprintf(fp,"%f %f\n",punkt[0],punkt[1]);
		rzut = rand()%4+1;
		if(rzut == (rzut_prev+4)%4 +1)
			i--;
		else{
			switch(rzut){
				case 1:
					punkt[0]=(punkt[0]+x[0])/2;
					punkt[1]=(punkt[1]+x[1])/2;
					break;
				case 2:
					punkt[0]=(punkt[0]+y[0])/2;
                    punkt[1]=(punkt[1]+y[1])/2;
                    break;
				case 3:
					punkt[0]=(punkt[0]+z[0])/2;
                    punkt[1]=(punkt[1]+z[1])/2;
                    break;
				case 4:
					punkt[0]=(punkt[0]+w[0])/2;
                    punkt[1]=(punkt[1]+w[1])/2;
                    break;
				default:
					break;
			}
			rzut_prev=rzut;
		}
	}
	fclose(fp);
}

void kwadrat_jeden(int n){
	double x[2] = {0,0};
	double y[2] = {0,2};
	double z[2] = {2,2};
	double w[2] = {2,0};
	double punkt[2] = {0,0.1};
	FILE *fp = fopen("wynik3.plt","w");
	int seed;
	time_t tt;
	seed = time(&tt);
	srand(seed);
	int i;
	int rzut = 0;
	int rzut_prev = 0;
	for(i=1;i<=n;i++){
		fprintf(fp,"%f %f\n",punkt[0],punkt[1]);
		rzut = rand()%4+1;
		if(rzut == (rzut_prev-1)%4 +1)
			i--;
		else{
			switch(rzut){
				case 1:
					punkt[0]=(punkt[0]+x[0])/2;
					punkt[1]=(punkt[1]+x[1])/2;
					break;
				case 2:
					punkt[0]=(punkt[0]+y[0])/2;
                    punkt[1]=(punkt[1]+y[1])/2;
                    break;
				case 3:
					punkt[0]=(punkt[0]+z[0])/2;
                    punkt[1]=(punkt[1]+z[1])/2;
                    break;
				case 4:
					punkt[0]=(punkt[0]+w[0])/2;
                    punkt[1]=(punkt[1]+w[1])/2;
                    break;
				default:
					break;
			}
		}
		rzut_prev=rzut;
	}
	fclose(fp);
}
void trojkat(int n){
    double x[2] = {0,0};
    double y[2] = {10,0};
    double z[2] = {5,5*sqrt(3)};
    double punkt[2] = {0,0};
    FILE *fp = fopen("wynik.plt", "w");
    int i;
    int seed;
    int rzut = 0;
    time_t tt;
    seed = time(&tt);
    srand(seed);
    for(i=1;i<=n;i++){
        fprintf(fp,"%f %f\n",punkt[0],punkt[1]);
        rzut = rand()%3+1;
        switch(rzut){
            case 1:
                punkt[0] = (punkt[0]+x[0])/2;
                punkt[1] = (punkt[1]+x[1])/2;
                break;
            case 2:
                punkt[0] = (punkt[0]+y[0])/2;
                punkt[1] = (punkt[1]+y[1])/2;
                break;
            case 3:
                punkt[0] = (punkt[0]+z[0])/2;
                punkt[1] = (punkt[1]+z[1])/2;
                break;
            default :
                break;
        }
    }
    fclose(fp);
}

void paproc(int n){
    FILE *fp = fopen("wynik2.plt", "w");
    double punkt[2] = {0,0};
    double tmp;
    int i;
    int seed;
    int rzut = 0;
    time_t tt;
    seed = time(&tt);
    srand(seed);
    for(i=1;i<=n;i++){
        rzut=rand()%100+1;
        if(rzut<=85){
            tmp = punkt[0];
            punkt[0] = 0.85*punkt[0]+0.04*punkt[1];
            punkt[1] = (-0.04)*tmp+0.85*punkt[1]+1.6;
            fprintf(fp,"%f %f\n",punkt[0],punkt[1]);
        }else if(rzut>85 && rzut<=92){
            tmp = punkt[0];
            punkt[0] = (-0.15)*punkt[0]+0.28*punkt[1];
            punkt[1] = 0.26*tmp+0.24*punkt[1]+0.44;
            fprintf(fp,"%f %f\n",punkt[0],punkt[1]);
        }else if(rzut>92 && rzut <=99){
            tmp = punkt[0];
            punkt[0] = 0.2*punkt[0]+(-1)*0.26*punkt[1];
            punkt[1] = 0.23*tmp+0.22*punkt[1]+1.6;
            fprintf(fp,"%f %f\n",punkt[0],punkt[1]);
        }else{
            punkt[0] = 0;
            punkt[1] = 0.16*punkt[1];
            fprintf(fp,"%f %f\n",punkt[0],punkt[1]);
        }
    }
    fclose(fp);
}

int main()
{
	int n = 0;
	printf("Podaj ilosc rzutow: ");
	scanf("%d",&n);
	printf("\n");
    trojkat(n);
    paproc(n);
	kwadrat_jeden(n);
	kwadrat_dwa(n);
    return 0;
}
