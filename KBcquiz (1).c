 #include<stdio.h>


int answer;
int questionNumber;
char L ;

int LifeLine1Left=1;
int LifeLine2Left=1;
int LifeLineLeft=2;

/*
Develop the KBC game using C. The program should have the following features:
1. First of all, primary information, such as the total number of questions, prize money with
respect to each question, available life lines and intermediate question levels (described
in point no. 4 below) should be displayed on the screen, asking the user to press any key
to start the game.
2. When notified by the user, the game should start by displaying one question at a time
along with its four options on the screen, prompting the user to select the correct option.
3. When the user selects his/her option, the program should show a message whether the
selected option is correct or wrong.
4. If the selected option is correct, the corresponding prize money should be displayed.
Otherwise, the prize money counter should be reduced to zero or to the intermediate
level (e.g., after question number 3, 8 and 12, as set by you), and displayed on the screen.
5. The user can opt for two life lines, such as “50-50”, upon selection of which, two wrong
options should be removed from the screen, or “flip the question” that should replace
the entire question with a new one on the screen. These life lines can be availed by the
user only once (even at the same time as well). Therefore, the program should take care
of this provision.
6. The maximum number of questions a user can play should not exceed 15.
*/

//Here we have defined a counter function which would return the score after every question is answered.
/* Key :
Q 1  is of 5   thousand
Q 2  is of 10  thousand
Q 3  is of 20  thousand
Q 4  is of 50  thousand
Q 5  is of 1   lakh
Q 6  is of 2   lakh
Q 7  is of 5   lakh
Q 8  is of 10  lakh
Q 9  is of 20  lakh
Q 10 is of 30  lakh
Q 11 is of 50  lakh
Q 12 is of 70  lakh
Q 13 is of 1   crore
Q 14 is of 2   crore
Q 15 is of 5   crore


*/
//Score function returns your score according to the question number
int score (int questionNumber){
      int money[16]={0,5000,10000,20000,50000,100000,200000,500000,1000000,2000000,3000000,5000000,7000000,10000000,20000000,50000000};
      return money[questionNumber];
}

// A checkpoint function that is called to return the secured amount uptill now
// If a user enters a wrong answer then score will automatically reset to the last checkpoint
int checkpoint(int questionNumber){
    int money[16]={0,0,0,0,50000,50000,50000,50000,50000,50000,50000,50000,7000000,7000000,7000000,7000000};
    /* if(money[questionNumber]==0)
    {
        printf("\n Your secured amount now is 0 \n ");

    }
    */
    return money[questionNumber];

}

//This is the function that displays the information regarding lifelines
//It is also responsible for calling the lifeline functions
int lifeline(questionNumber){

    int LifeLineChoice;
    printf("\n You have %d lifelines available \n",LifeLineLeft);
    printf("\n \t i) 50-50 lifeline: \n \t upon selection of which, two wrong options should be removed from the screen \n \t ii) Flip-a-coin lifeline : \n \t upon selection of which your questions will be replaced by a new question,but no guarantee of level of the question \n");
    for(1;1;1){

        if (LifeLineLeft!=0)
            {
            printf("Choose a lifeline \n ");
            scanf("%d",&LifeLineChoice);
            if(LifeLineChoice==1){

                fiftyfifty(questionNumber);
                break;
                                 }
            else if(LifeLineChoice==2){
                flipTheQuestion(questionNumber);
                break;
                                    }
            else printf(" \n Enter a valid key \n");
            }

        else printf("Sorry You don't have any lifelines left. \n");
        return 0 ;

                }




                               }
// This is lifeline 2
// This lifeline gives a new question as replacement to the original question
// Can be only used once
void flipTheQuestion (int questionNumber){



   // int questionNumber2=questionNumber;
    if(LifeLineLeft!=0)
        {
        if(LifeLine2Left!=0)
        {
            char newChoice1;
            LifeLineLeft = LifeLineLeft - 1 ;
            LifeLine2Left = 0;

            printf("The amount that you have won by reaching the checkpoint levels is %d \n ",checkpoint(questionNumber));
            printf("Your new question is \n ");
            printf("Who was the 4th Prime Minister Of India? \n 1) Maroji Desai \t \t 2) Indira Gandhi \n 3) Charan Singh \t \t 4) Lal Bahadur Shastri \n");
            printf("\n Do you want to use another lifeline? \n");
            scanf(" %c",&newChoice1);
            if(newChoice1=='Y'){

                    fiftyfifty(questionNumber,'T');

                    }
                else{

                printf("\n You have not chosen the lifeline so please write your final answer, this CANNOT BE CHANGED \n");


        scanf("%d",&answer);
        if(answer==1)
            {
            printf("Correct! Congratulations your new score is %d \n " ,score(questionNumber));
            question(questionNumber+1);
            }

            else if(answer!=1)
                {
                 printf(" \n Wrong! Your score has now reduced to %d \n" , checkpoint(questionNumber));
                 printf("\nYou have been eliminated from the game \n");
                }
                }






                        }
                        }
}


// This lifeline erases 2 incorrect options from the provided question Lifeline1 is Fifty-fifty
// Can be use only once
void fiftyfifty (int questionNumber, char exception){
if(LifeLineLeft!=0)
    {
        if(LifeLine1Left!=0)
        {
        LifeLineLeft = LifeLineLeft - 1 ;
        LifeLine1Left=0;

        char newChoice;
        int newAnswer;
        if( questionNumber==1 && exception!='T'){
            printf("\n Your question number 1 is \n ");
            printf("Entomology is the science that studies? \n");
            printf("3) insects \t \t 4) formation of rocks \n ");
            printf("Do you want to use another lifeline? \n Enter Y for Yes  \n");
            scanf("%s",&newChoice);
                if(newChoice=='Y'){

                flipTheQuestion(questionNumber);

                }
            else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;



    scanf("%d",&newAnswer);
    if(newAnswer==3)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(1));
        question(questionNumber+1);
    }
     else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(questionNumber));
     printf("You have been eliminated from the game \n ");
         }
        }
        }

 if( questionNumber==2 && exception!='T'){
            printf("\n Your question number 2 is \n ");
    printf("UNO day is on \n");
    printf("1) 24th October \t \t 2) 12 May \n");
    printf("Do you want to use another lifeline? \n Enter Y for Yes  \n");
    scanf("%s",&newChoice);
           if(newChoice=='Y'){
           flipTheQuestion(questionNumber);
           }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
            LifeLineLeft = LifeLineLeft - 1 ;
                LifeLine1Left = 0;

    scanf("%d",&newAnswer);
    if(newAnswer==1)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(1));
        question(questionNumber+1);
    }
     else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(questionNumber));
    printf("You have been eliminated from the game \n ");
         }
        }
        }
        if( questionNumber==3 && exception!='T'){
            printf("\n Your question number  is \n ");
    printf("War of the Roses was \n");
    printf("3) War between Syrian and Roman forces \t \t 4) Civil War of England \n ");
    printf("Do you want to use another lifeline? \n Enter Y for Yes  \n");
    scanf("%s",&newChoice);
           if(newChoice=='Y'){
          flipTheQuestion(questionNumber);
           }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
            LifeLineLeft = LifeLineLeft - 1 ;
            LifeLine1Left = 0;

    scanf("%d",&newAnswer);
    if(newAnswer==4)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(1));
        question(questionNumber+1);
    }
     else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(questionNumber));
    printf("You have been eliminated from the game \n ");
         }
        }
        }
          if( questionNumber==4 && exception!='T'){
            printf("\n Your question number  is \n ");
      printf("Which is the house where the Chairperson is not the member of that house\n");
    printf("1) Lok Sabha \t \t 2) Rajya Sabha \n");
    printf("Do you want to use another lifeline? \n Enter Y for Yes  \n");
    scanf("%s",&newChoice);
           if(newChoice=='Y'){
          flipTheQuestion(questionNumber);
           }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
            LifeLineLeft = LifeLineLeft - 1 ;
                LifeLine1Left = 0;

    scanf("%d",&newAnswer);
    if(newAnswer==2)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(1));
        question(questionNumber+1);
    }
     else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(questionNumber));
    printf("You have been eliminated from the game \n ");
         }
        }
        }
         if( questionNumber==5 && exception!='T'){
            printf("\n Your question number  is \n ");
   printf("Finance bill of Indian Government is presented in\n");
    printf("1)Lower House \t \t 2) Upper House \n");
    printf("Do you want to use another lifeline? \n Enter Y for Yes  \n");
    scanf("%s",&newChoice);
           if(newChoice=='Y'){
          flipTheQuestion(questionNumber);
           }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
            LifeLineLeft = LifeLineLeft - 1 ;
                LifeLine1Left = 0;

    scanf("%d",&newAnswer);
    if(newAnswer==2)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(1));
        question(questionNumber+1);
    }
     else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(questionNumber));
    printf("You have been eliminated from the game \n ");
         }
        }
        }
         if( questionNumber==6 && exception!='T'){
            printf("\n Your question number  is \n ");
    printf("Who has recently become the new Secretary of Economic Affairs?\n");
     printf("3) Tarun Bajaj \t \t 4) Shashank Singh \n ");
    printf("Do you want to use another lifeline? \n Enter Y for Yes  \n");
    scanf("%s",&newChoice);
           if(newChoice=='Y'){
          flipTheQuestion(questionNumber);
           }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
            LifeLineLeft = LifeLineLeft - 1 ;
                LifeLine1Left = 0;

    scanf("%d",&newAnswer);
    if(newAnswer==3)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(1));
        question(questionNumber+1);
    }
     else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(questionNumber));
    printf("You have been eliminated from the game \n ");
         }
        }
        }
         if( questionNumber==7 && exception!='T'){
            printf("\n Your question number  is \n ");
     printf("Recently, a rice named Chak-Hao has got GI tag, it belongs to which state?\n");
    printf("1)manipur \t \t 2) kerala \n");
    printf("Do you want to use another lifeline? \n Enter Y for Yes  \n");
    scanf("%s",&newChoice);
           if(newChoice=='Y'){
          flipTheQuestion(questionNumber);
           }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
            LifeLineLeft = LifeLineLeft - 1 ;
                LifeLine1Left = 0;

    scanf("%d",&newAnswer);
    if(newAnswer==1)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(1));
        question(questionNumber+1);
    }
     else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(questionNumber));
    printf("You have been eliminated from the game \n ");
         }
        }
        }
         if( questionNumber==8 && exception!='T'){
            printf("\n Your question number  is \n ");
    printf("Recently, the central government has added 5 more states to the One Nation One Ration Card scheme, the total number of states included in this scheme has increased?\n");
     printf("3) 24\t \t 4) 17 \n ");
    printf("Do you want to use another lifeline? \n Enter Y for Yes  \n");
    scanf("%s",&newChoice);
           if(newChoice=='Y'){
          flipTheQuestion(questionNumber);
           }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
            LifeLineLeft = LifeLineLeft - 1 ;
                LifeLine1Left = 0;

    scanf("%d",&newAnswer);
    if(newAnswer==4)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(1));
        question(questionNumber+1);
    }
     else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(questionNumber));
    printf("You have been eliminated from the game \n ");
         }
        }
        }
         if( questionNumber==9 && exception!='T'){
            printf("\n Your question number  is \n ");
    printf("Famous personality 'Gulzar Dehalvi' has passed away, was he?\n");
     printf("3) Cricketer \t \t 4)Poet \n ");
    printf("Do you want to use another lifeline? \n Enter Y for Yes  \n");
    scanf("%s",&newChoice);
           if(newChoice=='Y'){
          flipTheQuestion(questionNumber);
           }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
            LifeLineLeft = LifeLineLeft - 1 ;
                LifeLine1Left = 0;

    scanf("%d",&newAnswer);
    if(newAnswer==3)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(1));
        question(questionNumber+1);
    }
     else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(questionNumber));
    printf("You have been eliminated from the game \n ");
         }
        }
        }
         if( questionNumber==10 && exception!='T'){
            printf("\n Your question number  is \n ");
    printf("Western Coalfields Limited, a subsidiary of Coal India Limited, has recently started 3 new coal mines in Maharashtra and which state?\n");
    printf("1)Madhya Pradesh \t \t 2) Jharkhand \n");
    printf("Do you want to use another lifeline? \n Enter Y for Yes  \n");
    scanf("%s",&newChoice);
           if(newChoice=='Y'){
          flipTheQuestion(questionNumber);
           }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
            LifeLineLeft = LifeLineLeft - 1 ;
                LifeLine1Left = 0;

    scanf("%d",&newAnswer);
    if(newAnswer==2)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(1));
        question(questionNumber+1);
    }
     else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(questionNumber));
    printf("You have been eliminated from the game \n ");
         }
        }
        }
         if( questionNumber==11 && exception!='T'){
            printf("\n Your question number  is \n ");
    printf("How long has the central government decided to increase the validity of driving license, fitness certificate and permit due to corona crisis?\n");
    printf("1)2nd February \t \t 2) 30th September \n");
    printf("Do you want to use another lifeline? \n Enter Y for Yes  \n");
    scanf("%s",&newChoice);
           if(newChoice=='Y'){
          flipTheQuestion(questionNumber);
           }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
            LifeLineLeft = LifeLineLeft - 1 ;
                LifeLine1Left = 0;

    scanf("%d",&newAnswer);
    if(newAnswer==2)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(1));
        question(questionNumber+1);
    }
     else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(questionNumber));
    printf("You have been eliminated from the game \n ");
         }
        }
        }
         if( questionNumber==12 && exception!='T'){
            printf("\n Your question number  is \n ");
    printf("Recently which first Arab country has announced to launch its 'Mars mission'?\n");
    printf("1)UAE \t \t 2)Iraq \n");
    printf("Do you want to use another lifeline? \n Enter Y for Yes  \n");
    scanf("%s",&newChoice);
           if(newChoice=='Y'){
          flipTheQuestion(questionNumber);
           }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
            LifeLineLeft = LifeLineLeft - 1 ;
                LifeLine1Left = 0;

    scanf("%d",&newAnswer);
    if(newAnswer==1)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(1));
        question(questionNumber+1);
    }
     else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(questionNumber));
    printf("You have been eliminated from the game \n ");
         }
        }
        }
         if( questionNumber==13 && exception!='T'){
            printf("\n Your question number  is \n ");
    printf(" In what name has the Chhattisgarh government started a campaign to reduce the mental stress and depression of police personnel in the state?\n");
    printf("3) Greeting \t \t 4) Joy \n ");
    printf("Do you want to use another lifeline? \n Enter Y for Yes  \n");
    scanf("%s",&newChoice);
           if(newChoice=='Y'){
          flipTheQuestion(questionNumber);
           }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
            LifeLineLeft = LifeLineLeft - 1 ;
                LifeLine1Left = 0;

    scanf("%d",&newAnswer);
    if(newAnswer==2)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(1));
        question(questionNumber+1);
    }
     else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(questionNumber));
    printf("You have been eliminated from the game \n ");
         }
        }
        }
         if( questionNumber==14 && exception!='T'){
            printf("\n Your question number  is \n ");
     printf(" Recently which state government has launched Raj Kaushal Portal and online labor employment exchange?\n");
    printf("1)Haryana \t \t 2) Maharashtra \n");
    printf("Do you want to use another lifeline? \n Enter Y for Yes  \n");
    scanf("%s",&newChoice);
           if(newChoice=='Y'){
          flipTheQuestion(questionNumber);
           }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
            LifeLineLeft = LifeLineLeft - 1 ;
                LifeLine1Left = 0;

    scanf("%d",&newAnswer);
    if(newAnswer==2)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(1));
        question(questionNumber+1);
    }
     else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(questionNumber));
    printf("You have been eliminated from the game \n ");
         }
        }
        }
         if( questionNumber==15 && exception!='T'){
            printf("\n Your question is \n ");
            printf(" Who has directed formation of a committee to examine the feasibility of using hotels as COVID-19 hospitals?\n");
            printf("1) Delhi HC\t \t 2) Supreme Court \n");
            printf("Do you want to use another lifeline? \n Enter Y for Yes  \n");
            scanf("%s",&newChoice);
                if(newChoice=='Y'){
                flipTheQuestion(questionNumber);
                                    }
                else {
                printf(" You have not chosen any lifeline so please Enter your final answer \n") ;

                scanf("%d",&newAnswer);
                if(newAnswer==1)
                {
                printf("Correct! Congratulations your new score is %d \n " ,score(1));
                question(questionNumber+1);
                }
                else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(questionNumber));
                printf("You have been eliminated from the game \n ");
                     }
                     }
                                                    }
        if(exception=='T'){
            printf("\n Your question is \n ");
            printf(" Who was the 4th Prime Minister Of India? \n ");
            printf("1) Maroji Desai \t \t 2) Indira Gandhi \n");
            printf("You do not have any lifeline left so please Enter your final answer \n") ;

        scanf("%d",&newAnswer);
            if(newAnswer==1)
            {
                printf("Correct! Congratulations your new score is %d \n " ,score(questionNumber));
                question(questionNumber+1);

            }
            else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(questionNumber));
                   printf("You have been eliminated from the game \n ");
                 }

                            }
    }
       else{printf("You have already used this FIfty-Fifty lifeline");
           }

}
}








// This is the function for running the questions
/* It is a recursive function which calls itself and increments the argument by one that is increases
the questionNumber one and calls itself again to proceed to the next question number.
There is also a provision to see the lifelines after every question is announced.
This function is also responsible for calling the score function to display the score after you answer
any question, irrespective of right or wrong. This is achieved by the two functions described above
score and checkpoint .

choice and answer are the two variables defined here

*/
void question(questionNumber)
{
    //choice variable to know if the user wants to see the lifelines
    char choice;
    //answer variable to store the user's answer to the question
    int answer;
    if(questionNumber==1)
    {
    printf("\n Your question number 1 is \n ");
    printf("Entomology is the science that studies? \n");
    printf("1) behaviour  of humans \t \t 2) plants \n");
    printf("3) insects \t \t 4) formation of rocks \n ");

    printf("Do you want to see the lifelines? \n Enter Y for Yes  \n");
    scanf("%s",&choice);
    if(choice=='Y')
    {
        lifeline(questionNumber);
    }
    else {
            printf(" You have not chosen any lifeline \n") ;
    }
    printf("\n Enter your final answer \n ");

    scanf("%d",&answer);
    if(answer==3)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(1));
        question(questionNumber+1);
    }
    else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(questionNumber));
    printf("You have been eliminated from the game \n ");
         }

        }



     if(questionNumber==2)
    {
    printf("\nYour question number %d is \n ",questionNumber);
    printf("\n UNO day is on \n");
    printf("1) 24th October \t \t 2) 12 May \n");
    printf("3) 15 August \t \t 4) 04 January \n ");

    printf("Do you want to see the lifelines? \n Enter Y for Yes  \n");
    scanf("%s",&choice);
    if(choice=='Y')
    {
        lifeline(questionNumber);
    }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
         }
    printf("\n Enter your final answer \n ");
    scanf("%d",&answer);
    if(answer==1)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(2));
        question(questionNumber+1);
    }
    else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(0));
    printf("\n\n You have been eliminated from the game \n ");


  }
    }

    if(questionNumber==3)
    {
    printf("\n Your question number %d is \n ",questionNumber);
    printf("War of the Roses was \n");
    printf("1) Religious-cum-political war between the Lutherans Catholics in Germany \t \t 2) Civil War in Rome \n");
    printf("3) War between Syrian and Roman forces \t \t 4) Civil War of England \n ");

    printf("Do you want to see the lifelines? \n Enter Y for Yes  \n");
    scanf("%s",&choice);
    if(choice=='Y')
    {
        lifeline(questionNumber);
    }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
    }
    printf("\n Enter your final answer \n ");
    scanf("%d",&answer);
    if(answer==4)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(3));
        question(questionNumber+1);
    }
    else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(0));
    printf("You have been eliminated from the game \n ");


}
    }

  if(questionNumber==4)
    {
    printf(" \n Your question number %d is \n ",questionNumber);
    printf("Which is the house where the Chairperson is not the member of that house\n");
    printf("1) Lok Sabha \t \t 2) Rajya Sabha \n");
     printf("3) Vidhan Sabha \t \t 4) Vidhan Sabha \n ");

    printf("Do you want to see the lifelines? \n Enter Y for Yes  \n");
    scanf("%s",&choice);
    if(choice=='Y')
    {
        lifeline(questionNumber);
    }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
    }
    printf("\n Enter your final answer \n ");
    scanf("%d",&answer);
    if(answer==2)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(4));
        question(questionNumber+1);
    }
    else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(questionNumber));
    printf("You have been eliminated from the game \n ");

}
    }

    if(questionNumber==5)
    {
    printf(" \n Your question number %d is \n ",questionNumber);
    printf("Finance bill of Indian Government is presented in\n");
    printf("1)Lower House \t \t 2) Upper House \n");
     printf("3) Middle House \t \t 4) Vidhan Sabha \n ");

    printf("Do you want to see the lifelines? \n Enter Y for Yes  \n");
    scanf("%s",&choice);
    if(choice=='Y')
    {
        lifeline(questionNumber);
    }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
    }
    printf("\n Enter your final answer \n ");
    scanf("%d",&answer);
    if(answer==2)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(5));
        question(questionNumber+1);
    }
    else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(4));
    printf("You have been eliminated from the game \n ");

}
    }

if(questionNumber==6)
    {
    printf(" \n Your question number %d is \n ",questionNumber);
    printf("Who has recently become the new Secretary of Economic Affairs?\n");
    printf("1)Poonam Guar \t \t 2) Omprakash Verma \n");
     printf("3) Tarun Bajaj \t \t 4) Shashank Singh \n ");

    printf("Do you want to see the lifelines? \n Enter Y for Yes  \n");
    scanf("%s",&choice);
    if(choice=='Y')
    {
        lifeline(questionNumber);
    }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
    }
    printf("\n Enter your final answer \n ");
    scanf("%d",&answer);
    if(answer==3)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(6));
        question(questionNumber+1);
    }
    else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(4));
    printf("You have been eliminated from the game \n ");

}
    }

if(questionNumber==7)
    {
    printf(" \n Your question number %d is \n ",questionNumber);
    printf("Recently, a rice named Chak-Hao has got GI tag, it belongs to which state?\n");
    printf("1)manipur \t \t 2) kerala \n");
     printf("3) Tamil Nadu \t \t 4) Karnataka \n ");

    printf("Do you want to see the lifelines? \n Enter Y for Yes  \n");
    scanf("%s",&choice);
    if(choice=='Y')
    {
        lifeline(questionNumber);
    }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
    }
    printf("\n Enter your final answer \n ");
    scanf("%d",&answer);
    if(answer==1)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(7));
        question(questionNumber+1);
    }
    else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(4));
    printf("You have been eliminated from the game \n ");

}
    }

    if(questionNumber==8)
    {
    printf(" \n Your question number %d is \n ",questionNumber);
    printf("Recently, the central government has added 5 more states to the One Nation One Ration Card scheme, the total number of states included in this scheme has increased?\n");
    printf("1)21 \t \t 2) 15 \n");
     printf("3) 24\t \t 4) 17 \n ");

    printf("Do you want to see the lifelines? \n Enter Y for Yes  \n");
    scanf("%s",&choice);
    if(choice=='Y')
    {
        lifeline(questionNumber);
    }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
    }
    printf("\n Enter your final answer \n ");
    scanf("%d",&answer);
    if(answer==4)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(8));
        question(questionNumber+1);
    }
    else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(4));
    printf("You have been eliminated from the game \n ");

}

    }
    if(questionNumber==9)
    {
    printf(" \n Your question number %d is \n ",questionNumber);
    printf("Famous personality 'Gulzar Dehalvi' has passed away, was he?\n");
    printf("1)Author \t \t 2) Actor \n");
     printf("3) Cricketer \t \t 4)Poet \n ");

    printf("Do you want to see the lifelines? \n Enter Y for Yes  \n");
    scanf("%s",&choice);
    if(choice=='Y')
    {
        lifeline(questionNumber);
    }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
    }
    printf("\n Enter your final answer \n ");
    scanf("%d",&answer);
    if(answer==3)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(9));
        question(questionNumber+1);
    }
    else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(4));
    printf("You have been eliminated from the game \n ");

}

    }
    if(questionNumber==10)
    {
    printf(" \n Your question number %d is \n ",questionNumber);
    printf("Western Coalfields Limited, a subsidiary of Coal India Limited, has recently started 3 new coal mines in Maharashtra and which state?\n");
    printf("1)Madhya Pradesh \t \t 2) Jharkhand \n");
     printf("3) Karnataka \t \t 4) Kerala \n ");

    printf("Do you want to see the lifelines? \n Enter Y for Yes  \n");
    scanf("%s",&choice);
    if(choice=='Y')
    {
        lifeline(questionNumber);
    }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
    }
    printf("\n Enter your final answer \n ");
    scanf("%d",&answer);
    if(answer==1)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(10));
        question(questionNumber+1);
    }
    else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(4));
    printf("You have been eliminated from the game \n ");

}
    }

    if(questionNumber==11)
    {
    printf(" \n Your question number %d is \n ",questionNumber);
    printf("How long has the central government decided to increase the validity of driving license, fitness certificate and permit due to corona crisis?\n");
    printf("1)2nd February \t \t 2) 30th September \n");
     printf("3)5th May \t \t 4) 20Th August \n ");

    printf("Do you want to see the lifelines? \n Enter Y for Yes  \n");
    scanf("%s",&choice);
    if(choice=='Y')
    {
        lifeline(questionNumber);
    }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
    }
    printf("\n Enter your final answer \n ");
    scanf("%d",&answer);
    if(answer==2)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(11));
        question(questionNumber+1);
    }
    else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(4));
    printf("You have been eliminated from the game \n ");

}
    }

if(questionNumber==12)
    {
    printf(" \n Your question number %d is \n ",questionNumber);
    printf("Recently which first Arab country has announced to launch its 'Mars mission'?\n");
    printf("1)UAE \t \t 2)Iraq \n");
     printf("3) Afganistan \t \t 4)Iran\n ");

    printf("Do you want to see the lifelines? \n Enter Y for Yes  \n");
    scanf("%s",&choice);
    if(choice=='Y')
    {
        lifeline(questionNumber);
    }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
    }
    printf("\n Enter your final answer \n ");
    scanf("%d",&answer);
    if(answer==1)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(12));
        question(questionNumber+1);
    }
    else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(4));
    printf("You have been eliminated from the game \n ");

}
    }

if(questionNumber==13)
    {
    printf(" \n Your question number %d is \n ",questionNumber);
    printf(" In what name has the Chhattisgarh government started a campaign to reduce the mental stress and depression of police personnel in the state?\n");
    printf("1)Flutter \t \t 2) Talent \n");
     printf("3) Greeting \t \t 4) Joy \n ");

    printf("Do you want to see the lifelines? \n Enter Y for Yes  \n");
    scanf("%s",&choice);
    if(choice=='Y')
    {
        lifeline(questionNumber);
    }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
    }
    printf("\n Enter your final answer \n ");
    scanf("%d",&answer);
    if(answer==3)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(13));
        question(questionNumber+1);
    }
    else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(12));
    printf("You have been eliminated from the game \n ");

}

    }

if(questionNumber==14)
    {
    printf(" \n Your question number %d is \n ",questionNumber);


     printf("3) Punjab \t \t 4) Gujarat \n ");

    printf("Do you want to see the lifelines? \n Enter Y for Yes  \n");
    scanf("%s",&choice);
    if(choice=='Y')
    {
        lifeline(questionNumber);
    }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
    }
    printf("\nEnter your final answer \n ");
    scanf("%d",&answer);
    if(answer==2)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(14));
        question(questionNumber+1);
    }
    else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(12));
    printf("You have been eliminated from the game \n ");

}
    }

if(questionNumber==15)
    {
    printf(" \n Your question number %d is \n ",questionNumber);
    printf(" Who has directed formation of a committee to examine the feasibility of using hotels as COVID-19 hospitals?\n");
    printf("1)Delhi HC \t \t 2) ICMR \n");
    printf("3) Supreme Court \t \t 4) Center \n ");
    printf("\n Do you want to see the lifelines? \n Enter Y for Yes  \n");
    scanf("%s",&choice);
    if(choice=='Y')
    {
        lifeline(questionNumber);
    }
    else {
            printf(" You have not chosen any lifeline so please Enter your final answer \n") ;
    }
    printf("\n Enter your final answer \n ");
    scanf("%d",&answer);
    if(answer==1)
    {
        printf("Correct! Congratulations your new score is %d \n " ,score(questionNumber));
        printf(" \n \n You have won the game! Congratulations you're now a crorepati! \n \n");
        question(questionNumber+1);
    }
    else { printf("Wrong! Your score has now reduced to %d \n " , checkpoint(12));
    printf("You have been eliminated from the game \n ");

}
    }
    }








int main(void){

    char a ;
    // We display the name of the game here as well as some essential rules in order to play the game

    printf("_____________ \n\n \t Kaun banega Crorepati? \n______________\n\n We want you to be familiar with the rules before we start \n 1) There are a total of 15 questions in the game \n 2)You have two helplines with you. Which you can avail one at a time and only one redemption per life line is allowed \n 3) \n \t i) 50-50 lifeline: \n \t upon selection of which, two wrong options should be removed from the screen \n \t ii) Flip-a-coin lifeline : \n \t upon selection of which your questions will be replaced by a new question,but no guarantee of level of the question \n 4) There are 2 checkpoints in this game upon reaching which you can safely exit the game with amount as mentioned \n but however you will not get the secured amount if you answer the any subsequent question wrong, \n But you can choose to quit the game in between to take home the secured amount. \n 5) Checkpoints are question 5 ( 1 lakh ) and question 12 (70 lakhs) \n");
    printf("\n \n Do you want to play the game? \n \n");
    // For a non terminating game an endless for loop
    for(1;1;1){
            printf("Press Y to play and N to exit\n");
            scanf("%c",&a);
            if(a == 'Y'){
                    printf("\n Welcome to the game\n");
                    question(1);
                    //Break is applied here so that if the user ends his game he doesn't have to forcefully play again
                    break;
                            }
                else if(a == 'N'){
                    printf("BYE\n");
                    printf( " \n You didn't win anything as you didn't participate \n " )  ;


                                 }

              }

              }


