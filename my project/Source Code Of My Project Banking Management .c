//TEAM STAR PLAYERS
//BANK MANAGEMENT SYSTEM

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>


struct user{
    char name[50];
    char phone[50];
    char ac[50];
    char password[50];
};

int dip_amt, amt=10000, count=0;
int trans_amt;
int with_amt;


void deposit_money();
void withdraw_money();
void transfer_money();
void checkdetail();
void transaction_details();
void checkBalance();
void user_menu();
void divider();

void user_menu()
{
    printf("\n\tMENU\n");
    divider();
    printf("\n1.Deposit Money\n");
    printf("\n2.Withdraw Money\n");
    printf("\n3.Transfer Money\n");
    printf("\n4.Account Details\n");
    printf("\n5.Transaction Details\n");
    printf("\n6.Check Balance\n");
    printf("\n7.Exit\n");
    divider();
}

void divider()
{
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }
    printf("\n");
}

int main()
{
    struct user user;
    char filename[50], phone[50], password[50];
    FILE *fp;
    int opt, choice;
    char cont = 'y';
    jump:
    system("cls");
    printf("\n\t\t\t\t\tWELCOME TO CUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM\t\t\t\t\t");
    printf("\n\t\t\t\t\t1.Register your account\t\t\t\t");
    printf("\n\t\t\t\t\t2.Login to your account\t\t\t\t");

    printf("\n\n\t\t\t\tPlease enter your choice:\t");
    scanf("%d",&opt);
    if(opt == 1) {
        system("cls");
        printf("\nEnter your name:\t");
        scanf("%s",user.name);
        printf("\nEnter your account number:\t");
        scanf("%s",user.ac);
        printf("\nEnter your phone number:\t");
        scanf("%s",user.phone);
        printf("\nEnter your new password:\t");
        scanf("%s",user.password);

        strcpy(filename, user.phone);
        fp =fopen(strcat(filename, ".data"), "w");
        fwrite(&user, sizeof(user), 1, fp);
        if(fwrite != 0)
        {
            printf("Successfully registered\n");
        }
        fclose(fp);
        printf("\nPress any key to continue...");
        getch();
        }
    else if(opt == 2) {
        system("cls");
        printf("\nPhone No.:\t");
        scanf("%s", phone);
        printf("\nPassword:\t");
        scanf("%s", password);

        strcpy(filename, phone);
        fp =fopen(strcat(filename, ".data"), "r");
        if(fp == NULL) {
                printf("Account number not registered\n");
                printf("\nPress any key to continue...");
                getch();
            }
        else {
            fread(&user, sizeof(struct user), 1, fp);
            fclose(fp);
            if(!strcmp(password, user.password)) {
                while (cont == 'y') {
                    system("cls");
                    user_menu();
                    scanf("%d", &choice);

    switch (choice) {
    case 1:
        system("cls");
        deposit_money();
        break;
    case 2:
        system("cls");
        withdraw_money();
        break;
    case 3:
        system("cls");
        transfer_money();
        break;
    case 4:
        system("cls");
        checkdetail(&user);
        break;
    case 5:
        system("cls");
        transaction_details();
        break;
    case 6:
        system("cls");
        checkBalance();
        break;
    case 7:
        printf("\n\n***Thank you for banking ***\n\n");
        exit(0);
    default:
        printf("*****Invalid choice****\n");
    }
        printf("\n\nDo you want to continue? [y/n]:\t");
        scanf(" %c", &cont);
        }
    }
    else{
        printf("Invalid password\n");
        printf("\nPress any key to continue...");
        getch();
        }
            }
        } else {
            printf("Invalid choice, please try again.\n");
            printf("\nPress any key to continue...");
            getch();
        }

return 0;
}

void deposit_money()
{
    time_t tm;
    time(&tm);
    FILE *ptr =fopen("userAccount.txt", "a");
    printf("*****DEPOSITING MONEY*****\n");
    divider();
    printf("Enter the amount you want to deposit: ");
    scanf("%d", &dip_amt);
    amt +=dip_amt;
    printf("*****Money Deposited*****\n");
    printf("Now Balance: %d\n",amt);
    fprintf(ptr, "\nBDT %d has been deposited to your account\n",dip_amt);
    fprintf(ptr, "Date/Time of transaction: %s\n", ctime(&tm));
    count++;
    fclose(ptr);
    printf("Press any key....\n");
    getch();
}

void withdraw_money() {
    time_t tm;
    time(&tm);
    FILE *ptr =fopen("userAccount.txt", "a");
    printf("*****WITHDRAWING MONEY*****\n");
    divider();
    printf("\nEnter the amount you want to withdraw: ");
    scanf("%d",&with_amt);

    if(amt < with_amt)
    {
        printf("*****Insufficient Balance*****\n");
    }
    else {
        amt -=with_amt;
        printf("Current Balance: %d\n", amt);
        fprintf(ptr, "\nBDT %d has been withdrawn from your account\n", with_amt);
        fprintf(ptr, "Date/Time of transaction: %s\n", ctime(&tm));
        count++;
    }
    fclose(ptr);
    printf("Press any key....\n");
    getch();
}

void transfer_money() {
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("userAccount.txt", "a");
    printf("*****TRANSFERRING MONEY*****\n");
    divider();
    printf("\nEnter the account no in which you want to transfer the money: ");
    char ac[50];
    scanf("%s", ac);
    printf("\nEnter the amount you want to transfer: ");
    scanf("%d", &trans_amt);

    if(amt < trans_amt) {
        printf("*****Insufficient Balance*****\n");
    } else {
        amt -= trans_amt;
        printf("*****Money Transferred*****\n");
        printf("Current Balance: %d\n", amt);
        fprintf(ptr, "\nBDT %d has been transferred from your account to %s\n", trans_amt, ac);
        fprintf(ptr, "Date/Time of transaction: %s\n", ctime(&tm));
        count++;
    }
    fclose(ptr);
    printf("Press any key....\n");
    getch();
}

void transaction_details() {
    system("cls");
    FILE *ptr = fopen("userAccount.txt", "r");
    char c=fgetc(ptr);
    if(c== EOF) {
        printf("TRANSACTION DETAILS\n");
        divider();
        printf("\n**NO RECENT TRANSACTION**\n");
    } else {
        printf("TRANSACTION DETAILS\n");
        divider();
        printf("\n%d transactions have been made from your account\n", count);
        while(c!= EOF) {
            printf("%c", c);
            c =fgetc(ptr);
        }
    }
    fclose(ptr);
    printf("\nPress any key to go back to the menu...");
    getch();
}

void checkdetail(struct user *usr) {
    printf("ACCOUNT DETAILS\n");
    divider();
    printf("\nName: %s\n", usr->name);
    printf("Account No: %s\n", usr->ac);
    printf("Phone No: %s\n", usr->phone);
    printf("Total Balance: %d\n", amt);
    printf("\n\nPress any key to go back to the menu...");
    getch();
}

void checkBalance() {
    printf("You chose to see your balance\n");
    printf("****Your Available Balance is:  %d\n\n", amt);
    printf("Press any key to go back to the menu...");
    getch();
}









