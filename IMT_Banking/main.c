#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to randomly generates password
// of length N
char randomPasswordGeneration(int N)
{
    // Initialize counter
    int i = 0;
    int randomizer = 0;
    // Seed the random-number generator
    // with current time so that the
    // numbers will be different every time
    srand((unsigned int)(time(NULL)));
    // Array of numbers
    char numbers[] = "0123456789";
    // Array of small alphabets
    char letter[] = "abcdefghijklmnoqprstuvwyzx";
    // Array of capital alphabets
    char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
    // Array of all the special symbols
    char symbols[] = "!@#$^&*?";
    // Stores the random password
    char password[N];
    // To select the randomizer
    // inside the loop
    randomizer = rand() % 4;
    // Iterate over the range [0, N]
    for (i = 0; i < N; i++) {
        randomizer = rand() % 4;
    switch (randomizer) {
    case 1:
        password[i] = numbers[rand() % 10];
        break;
    case 2:
        password[i] = symbols[rand() % 8];
        break;
    case 3:
        password[i] = LETTER[rand() % 26];
        break;
    default:
        password[i] = letter[rand() % 26];
        break;
    }
    //return password;
    }
    printf("%s\n",password);
    //return (char*)password;
}


typedef struct bank_account{
    char full_name[40];
    char address[40];
    char national_id[15];  //national id must consist of 14 digit numbers
    int age;
    char bank_acc_id[11];
    char gardian[40];
    char gardian_nat_id[15];   // gardian national id must consist of 14 digits numbers
    char status[10];
    float balance;
    char password[6];  //Random Password will be generated for each account during creation of it

};

int main()
{
    // Seed the random-number generator
    // with current time so that the
    // numbers will be different every time
//-----------------------------------------------------------------------

//------------------------------------------------------------------------
    int option,choice;
    struct bank_account acc;
    char filename[15] , bank_account_id[11], national_id[15];
    float amount;
    FILE *fp, *fptr;
    // goto part
    menu:

    printf("Welcome to IMT Bank Admin page\n");
    printf("1.Create a new account\n\n");
    printf("2.Open Existing Account\n\n");
    printf("3.Exit the System\n\n");
    printf("Enter your choice\n");

    scanf("%d",&option);

    if (option == 1){
        system("cls");
        printf("\nEnter your full name ");
        scanf("%s",acc.full_name);
        printf("\nEnter your full Address ");
        scanf("%s",acc.address);

        fflush(stdin);   // clear standard input
        printf("\nEnter your age ");
        scanf("%d",&acc.age);

        printf("\nEnter your National ID\n");
        scanf("%s",acc.national_id);

        if (acc.age < 21){
            fflush(stdin);   //clear standard input
            printf("\nEnter your Guardian National ID ");
            scanf("%s",acc.gardian_nat_id);
        }
        printf("\nEnter your Balance ");
        scanf("%f",&acc.balance);
        printf("Bank account Id created randomly\n");
        printf("Password created randomly\n");

        stpcpy(acc.status,"Active");
        // create filename based on national id just for now
        stpcpy(filename, acc.national_id);  // todo change to bank account id
        fp=fopen(strcat(filename,".dat"),"w");
		fwrite(&acc,sizeof(acc),1,fp);
            if(fwrite != 0){
                printf("Registered Succesfully\n");
            }

    // Initialize counter
/*------------------------------------------------------------
        int randomizer = 0;

    // Seed the random-number generator
    // with current time so that the
    // numbers will be different every time
        srand((unsigned int)(time(NULL)));

    // Array of numbers
        char numbers[] = "0123456789";

    // Array of small alphabets
        char letter[] = "abcdefghijklmnoqprstuvwyzx";

    // Array of capital alphabets
        char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";

    // Array of all the special symbols
        char symbols[] = "!@#$^&*?";

    // Stores the random password
        char password[4];

    // To select the randomizer
    // inside the loop
        randomizer = rand() % 4;
        fflush(stdin);
        int i = 0;
    // Iterate over the range [0, N]
        for (i = 0; i < 4; i++) {
            randomizer = rand() % 4;
            switch (randomizer) {
                case 1:
                    password[i] = numbers[rand() % 10];
                    break;
                //case 2:
                  //  password[i] = symbols[rand() % 8];
                    //break;
                case 3:
                    password[i] = LETTER[rand() % 26];
                    break;
                default:
                    password[i] = letter[rand() % 26];
                    break;
        }
        //printf("%s\n",password);
        }
        printf("%s\n",password);
------------------------------------------------------------------------------------*/
    }
    else if (option == 2){
        system("cls");
        printf("\nEnter Bank Account ID\n");
        //scanf("%s",bank_account_id);
        scanf("%s",national_id);     //todo change to bank account id
        fp = fopen(strcat(national_id,".dat"),"r");
		if(fp == NULL){
            printf("Account not registered");
		}
		else{
		    fread(&acc,sizeof(acc),1,fp);
			fclose(fp);
            printf("Account registered\n");
//            //printf("%d",acc.age);
            printf("\n1.Make transaction");
            printf("\n2.Change Account Status");
            printf("\n3.Get Cash");
            printf("\n4.Deposite in Account");
            printf("\n5.Return to Main Menu\n");
            printf("\nEnter choice ");     //how
            scanf("%d",&choice);
            system("cls");
            if (choice == 1){
                printf("\nMake transaction");
                printf("\nEnter Bank Account ID to transfer to");
                scanf("%s",national_id);
                printf("\nEnter the transfer amount");
                scanf("%f",&amount);
                if (acc.balance < amount){
                    printf("\nNot enough money to transfer");
                }

//                else{
//                    fptr = fopen(strcat(national_id, ".dat","r"));     //ctr shift c
//                    if(fptr == Null){
//                        printf()
//                    }
//                }
            }
            else if (choice == 5){
                    goto menu;
    }
	}

    }
    else if (option == 3){
        exit(0);
    }

    return 0;
}
