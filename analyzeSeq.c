// 0.979763 similarity with:
//    N = 2940
//    n = 100

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int similar(char *s1, char *s2, int N)
{
  int psi = 0;
  for (int i=0; i<N; i++)
    {
      if (s1[i] == s2[i])
	{
	  psi++;
	}
    }
  return psi;
}

int main()
{
  srand(time(NULL));
  int N; // length of genome
  int n; // number of generated strands
  char *strand;
  
  FILE *fp;
  fp = fopen("../GenSeq/sequences.txt","r");
  fscanf(fp,"%d",&N);
  fscanf(fp,"%d",&n);
  char *strands[n];
  for (int i=0; i<n; i++)
    {
      strand = malloc(N*sizeof(char));
      fscanf(fp,"%s",strand);
      strands[i] = strand;
    }
  fclose(fp);

  double mu = (double) N/4;
  double sigma = sqrt(N*3/16); // sqrt(N*p*q)
  double s_hat, z_hat;
  FILE *f1, *f2;
  f1 = fopen("data1.txt","w");
  f2 = fopen("data2.txt","w");
  for (int i=0; i<n; i++)
    {
      for (int j=i+1; j<n; j++)
	{
	  s_hat = similar(strands[i],strands[j],N);
	  z_hat = (s_hat-mu)/sigma;
	  fprintf(f1,"%f\n",s_hat);
	  fprintf(f2,"%f\n",z_hat);
	}
    }
  fclose(f1);
  fclose(f2);

  return 0;
}
