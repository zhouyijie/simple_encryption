
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void){
    //char *args[20];
    
    int letterUP[20];
    int letterLOW[20];
    int shift;
    int number;
    int number2;
    while(1){
        shift = 0;
        for (int i =0;i<20;i++){
            letterLOW[i]=-1;
            letterUP[i]=-1;
        }
        printf( "Enter a word and a shift number without space :");
        for (int i = 0;i<20;i++){
            int token = getchar();
            //printf("%d",token);
            
            if (token<91 && token>64){
                letterUP[i] = token - 'A';
                letterLOW[i] = -1;
            }
            else if(token > 96 && token <123){
                letterLOW[i] = token - 'a';
                letterUP[i] = -1;
            }
            else if(token > 47 && token < 58 ){
                if(shift > 0){
                    shift = shift * 10;
                }
                shift = shift + token -'0';
                //printf("%d\n",shift);
                shift = shift % 26;
                
            }
            else if (token = 10){
                letterLOW[i] = -1;
                letterUP[i] = -1;
                
                break;
            }
            


        }
        printf("encripted: ");
        
        for(int i = 0;i<20;i++){
            //printf("begin: %d and %d\n",letterLOW[i],letterUP[i]);
            if(letterUP[i]>=0 && letterUP[i]<27){
                letterUP[i] = letterUP[i] - shift;
                number2 = letterUP[i];
                if(number2<0){
                    //printf("GOIN\n");
                    letterUP[i] = 26 + letterUP[i];
                }
                letterUP[i] = 'A'+letterUP[i];
                //printf("up is %d\n",letterUP[i]);
                
                putchar(letterUP[i]);
            }
            else if (letterLOW[i]>=0 && letterLOW[i]<27){
                letterLOW[i] = letterLOW[i] - shift;
                
                number = letterLOW[i];
                if(number<0){
                    
                    letterLOW[i] = 26 + letterLOW[i];
                }
                letterLOW[i] = 'a'+letterLOW[i];
                //printf("low is %d\n",letterLOW[i]);
                
                putchar(letterLOW[i]);
                
            }else{
                break;
            }
            
        }
        printf("\n");
        printf("decripted: ");
        int letterUP_d[20];
        int letterLOW_d[20];
        for(int i = 0;i<20;i++){
            //
            letterUP_d[i] = letterUP[i] - 'A';
            letterLOW_d[i] = letterLOW[i] - 'a';
            //printf("begin: %d and %d\n",letterLOW[i],letterUP[i]);
            if(letterUP_d[i]>=0 && letterUP_d[i]<27){
                letterUP_d[i] = letterUP_d[i] + shift;
                number2 = letterUP_d[i];
                if(number2>25){
                    //printf("GOIN\n");
                    letterUP_d[i] = letterUP_d[i] - 26;
                }
                letterUP_d[i] = 'A'+letterUP_d[i];
                //printf("up is %d\n",letterUP_d[i]);
                
                putchar(letterUP_d[i]);
            }
            else if (letterLOW_d[i]>=0 && letterLOW_d[i]<27){
                letterLOW_d[i] = letterLOW_d[i] + shift;
                
                number = letterLOW_d[i];
                if(number>25){
                    
                    letterLOW_d[i] = letterLOW_d[i]-26;
                }
                letterLOW_d[i] = 'a'+letterLOW_d[i];
                //printf("low is %d\n",letterLOW_d[i]);
                
                putchar(letterLOW_d[i]);
                
            }else{
                break;
            }
            
        }
        printf("\n");
        shift = 0;
        for (int i =0;i<20;i++){
            letterLOW[i]=-1;
            letterUP[i]=-1;
        }
        

        
        
        //number = shift - '0';
        //letter = letter - number;
        //printf("result: \n");
        //putchar(letter);
    }
    return 0;
    //char myString[] = args[0];
    //char mychar = myString[0];
    //letter = 'B' - 'A';
    //printf("%c",mychar);
}