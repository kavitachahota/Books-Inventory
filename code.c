#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>


typedef struct book{
    int isbn;
    char title[80];
    char author[80];
    char publisher[80];
    char genre[80];
    int y_o_p;
    int amount_in_stock;
    int selling_price;
} book;

book books_data[500] = {
                        {1, "Rethinking Productivity in Software Engineering", "Caitlin Sadowski", "Apress", "Education", 2020, 10, 50},
                        {2, "Pro Git", "Scott Chacon", "Apress", "Education", 2010, 20, 40},
                        {3, "You Don't Know JS Yet", "Kyle Simpson", "Independently published", "Education", 2012, 10, 10}
                        };

int k=3; // tracking number of books;

void add_book();
void display_books();
void search_book();
void print_book(int);
void transaction_process(int);
void issue_book(int);
void return_book(int);
void del_book_input();
void delete_record();

int main(){
    int choice;
    do{
        printf("\nMain Menu");
        printf("\n1. Populate the inventory");
        printf("\n2. Search by keyword");
        printf("\n3. Process a transaction");
        printf("\n4. Delete a book record");
        printf("\n5. Display all the books");
        printf("\n6. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
    }while(choice<1 || choice>6);
    
    switch(choice){
        case 1:
            add_book();
            break;
        case 2:
            search_book();
            break;
       case 3:
            search_book();
            break;
        case 4:
            delete_record();
            break;
        case 5:
            display_books();
            break;
        case 6:
            printf("\nEXITING THE SYSTEM....");
            exit(0);    
            break;             
    }
    
    
    return 0;
    }

// add a new book
void add_book(){
    system("cls");
    printf("\nADD");

    int i=k;
    bool isSameIsbn;
    do{
        isSameIsbn = false;
        printf("\nPlease enter the isbn number of the books: ");
        fflush(stdin);
        scanf("%d", &books_data[i].isbn);

        int j=0;
        while (j<k)
        {
            /* code */
            if(books_data[i].isbn == books_data[j].isbn){
                printf("\nisbn is already existed.Please enter the another one.");
                isSameIsbn = true;
                break;
            }
            j++;
        }
    
    }while(isSameIsbn);
    

    printf("\nPlease enter the title of the books: ");
    fflush(stdin);
    fgets(books_data[i].title, 79, stdin);
    books_data[i].title[strlen(books_data[i].title)-1]='\0';

    printf("\nPlease enter the name of the author: ");
    fflush(stdin);
    fgets(books_data[i].author, 79, stdin);
    books_data[i].author[strlen(books_data[i].author)-1]='\0';

    printf("\nPlease enter the name of the publisher: ");
    fflush(stdin);
    fgets(books_data[i].publisher, 79, stdin);
    books_data[i].publisher[strlen(books_data[i].publisher)-1]='\0';

    printf("\nPlease enter the genre of the books: ");
    fflush(stdin);
    fgets(books_data[i].genre, 79, stdin);
    books_data[i].genre[strlen(books_data[i].genre)-1]='\0';

    printf("\nPlease enter the year of publication: ");
    fflush(stdin);
    scanf("%d", &books_data[i].y_o_p);

    printf("\nPlease enter the amount in stock: ");
    fflush(stdin);
    scanf("%d", &books_data[i].amount_in_stock);

    printf("\nPlease enter the selling price: ");
    fflush(stdin);
    scanf("%d", &books_data[i].selling_price);
    
    // increasing the number of books
    k++;

    main();
}

//display books

void display_books(){
    system("cls");
    printf("\nDISPLAY BOOKS");

    for(int i=0;i<k;i++){
        printf("\n\n.isbn* %d", books_data[i].isbn);
        printf("\n.title* %s", books_data[i].title);
        printf("\n.author* %s", books_data[i].author);
        printf("\n.publisher* %s", books_data[i].publisher);
        printf("\n.genre* %s", books_data[i].genre);
        printf("\n.year of publication* %d", books_data[i].y_o_p);
        printf("\n.amount in stock* %d", books_data[i].amount_in_stock);
        printf("\n.selling price* %d", books_data[i].selling_price);
    }
    printf("\n");
    main();
}

// book searching
void search_book(){
    system("cls");
    printf("\nSEARCH");

    bool isBookFound = false;

    int isbn_for_search, choice;
    char other_search_options[80];

    printf("\nWhat you want to search with??");
    printf("\n1. ISBN\n2. TITLE\n3. AUTHOR\n4. PUBLISHER\n5. GENRE");
    printf("\nYour Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:printf("\nEnter the ISBN number of the book :");
        fflush(stdin);
        scanf("%d", &isbn_for_search);
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        printf("\nEnter the value: ");
        fflush(stdin);
        fgets(other_search_options, 79, stdin);
        other_search_options[strlen(other_search_options)-1]='\0';  
        break;
    default: printf("\nWrong option selected!! Please enter the right option...");
        break;
    }


    for(int i=0;i<k;i++){
        if(books_data[i].isbn == isbn_for_search || strcmp(books_data[i].title, other_search_options) == 0 || strcmp(other_search_options, books_data[i].author) == 0 || strcmp(other_search_options, books_data[i].publisher) == 0 || strcmp(other_search_options, books_data[i].genre) == 0 ){
            isBookFound=true;

            printf("\n...BOOK-FOUND....");
            printf("\n\n.isbn* %d", books_data[i].isbn);
            printf("\n.title* %s", books_data[i].title);
            printf("\n.author* %s", books_data[i].author);
            printf("\n.publisher* %s", books_data[i].publisher);
            printf("\n.genre* %s", books_data[i].genre);
            printf("\n.year of publication* %d", books_data[i].y_o_p);
            printf("\n.amount in stock* %d", books_data[i].amount_in_stock);
            printf("\n.selling price* %d", books_data[i].selling_price);

            char choice;
            printf("\nDo you want to issue or return? (Y/N): ");
            fflush(stdin);
            scanf("%c", &choice);
            
            if(toupper(choice)== 'Y'){
                transaction_process(i);
            }
        }
    }

    if(!isBookFound){
        printf("\nBOOK NOT FOUND WITH ENTERED DETAILS... PLEASE ENTER THE DETAILS AGAIN...");
        search_book();
    }
}

// process a transaction
void transaction_process(int i){
    system("cls");

    printf("\nPROCESS-A-TRANSACTION");

    int t_option;
    printf("\nChoose the following options to move forward:\n1. Issue Book\n2. Return Book");
    printf("\nYour Choice: ");
    fflush(stdin);
    scanf("%d", &t_option);

    switch(t_option){
        case 1: printf("\nISSUE"); issue_book(i);
            break;
        case 2: printf("\nRETURN"); return_book(i);
            break;
    }
}

// issue book
void issue_book(int i){
    if(books_data[i].amount_in_stock == 0){
        printf("\nSorry the book you are searching is not available.. Please check another one.");
    }
    else{
        books_data[i].amount_in_stock--; // -1 in stock
        printf("\n*HURRAH* -Book Issued- ");
        printf("\nTITLE: %s\nAUTHOR: %s", books_data[i].title, books_data[i].author);

        printf("\n~~~~\n");
    }
    main();
}

// book returning
void return_book(int i){
    books_data[i].amount_in_stock++;
    printf("\n -Book Returned-");
    printf("\n~~~~\n");

    main();
}

// delete record
void delete_record(){
    system("cls");
    printf("\nDELETE RECORD");

    bool isDeleted= false;
    int isbn_of_deleted_book;

    printf("\nEnter the ISBN number of the book to delete:");
    fflush(stdin);
    scanf("%d", &isbn_of_deleted_book);

    printf("\n...DELETING...");

    //VALUE OF BOOK TO DELETE
    for(int i=0; i<k; i++){
        if(isbn_of_deleted_book == books_data[i].isbn){
            for(int j=i; j<k; j++){
                books_data[i].isbn = books_data[i+1].isbn;
                strcpy(books_data[i].title, books_data[i+1].title);
                strcpy(books_data[i].author, books_data[i+1].author);
                strcpy(books_data[i].publisher, books_data[i+1].publisher);
                strcpy(books_data[i].genre, books_data[i+1].genre);
                books_data[i].y_o_p = books_data[i+1].y_o_p;
                books_data[i].selling_price = books_data[i+1].selling_price;
                books_data[i].amount_in_stock = books_data[i+1].amount_in_stock;
            }
            printf("\nBOOK DELETED....");
            isDeleted=true;
            k--;
            main();
        } 
    }

    if(!isDeleted){
        printf("\nEntered ISBN number not available!!!\nPlease enter the right one to delete");
        delete_record();
    }
}