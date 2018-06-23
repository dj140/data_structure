#include<stdio.h>
#include<conio.h>
#include<stdlib.h> 
main()
{ 
      int i;
      FILE *fp;
      char ch;
      fp=fopen("ScoresAnalysis.txt","rt");
      if(fp==NULL)
      {
                   printf("Cannot open file strike any key exit!");
                   getch();
                   exit(1);                                      
      }
      ch=fgetc(fp);
      putchar(ch);
      /*
      for(i=0;i<10;i++)
      {                
      putchar(ch);
      ch=fgetc(fp);
      }
      */   
	                 
      while (ch!=EOF)
      {
      putchar(ch);
      ch=fgetc(fp);
      }
      fclose(fp);
      system("pause");
}
