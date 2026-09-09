#include <stdio.h>

struct food
{
    int id;
    char name[31];
    float price;
    int quantity;
};

void takeorder(struct food*n)
{
    int id,quantity;

    printf("\nenter food id:");
    scanf("%d",&id);

    printf("enter quantity:");
    scanf("%d",&quantity);

    switch(id)
    {
        case 1:
            n[0].quantity=n[0].quantity+quantity;
            break;

        case 2:
            n[1].quantity=n[1].quantity+quantity;
            break;

        case 3:
            n[2].quantity=n[2].quantity+quantity;
            break;

        case 4:
            n[3].quantity=n[3].quantity+quantity;
            break;

        case 5:
            n[4].quantity=n[4].quantity+quantity;
            break;
        default:

    }
}

float calculatebill(struct food*n)
{
    float subtotal=0;
    int j;

    for(j=0;j<5;j++)
    {
        subtotal=subtotal+n[j].price*n[j].quantity;
    }

    return subtotal;
}

void displayreceipt(struct food*n)
{
    float subtotal;
    float service;
    float discount;
    float total;
    int j;

    subtotal=calculatebill(n);
    service=subtotal*5/100;
    discount=subtotal*10/100;
    total=subtotal+service-discount;

    printf("\nReceipt\n");

    for(j=0;j<5;j++)
    {
        if(n[j].quantity>0)
        {
            printf("%s %.2f %d\n",n[j].name,n[j].price,n[j].quantity);
        }
    }

    printf("Subtotal=%.2f\n",subtotal);
    printf("Service charge=%.2f\n",service);
    printf("Discount=%.2f\n",discount);
    printf("Total bill amount=%.2f\n",total);
}

int main()
{
    struct food n[5]=
    {
        {1,"idly",10,0},
        {2,"dosa",50,0},
        {3,"briyani",120,0},
        {4,"friedrice",80,0},
        {5,"noodles",60,0}
    };

    int choice;

    printf("Food Menu\n");
    printf("1.idly 10\n");
    printf("2.dosa 50\n");
    printf("3.briyani 120\n");
    printf("4.friedrice 80\n");
    printf("5.noodles 60\n");

    do
    {
        takeorder(n);

        printf("\nEnter one to order more:");
        scanf("%d",&choice);

    } while(choice==1);

    displayreceipt(n);

    return 0;
}
