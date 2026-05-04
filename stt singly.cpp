#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
class NODE
{
public:
    string SID;
    string ANAME;
    string SD;
    NODE *NEXT;
    NODE(string x, string y, string z)
    {
        SID = x;
        ANAME = y;
        SD = z;
        NEXT = nullptr;
    }
};
class LinkList
{
public:
    string SID;
    int SCNT;
    string AName, SCAP;
    NODE *START,*END;
    int countNode;
    LinkList(){
        SCNT = 1001;
        countNode = 0;
        START = nullptr;
        END = nullptr;
    }
    void getData()
    {
        SID = "STUDENT"+ to_string(SCNT);
        cout<<"\GENERATE STUDENT ID -- "<<SID<<endl;
        cout<<"Enter STUDENT NAME  -- ";
        getline(cin,AName);
        cout<<"Enter STUDENT COURSE -- ";
        getline(cin,SCAP);
    }
    char continueCheck()
    {
        char c;
        cout<<"\n\nAre you.. \n";
        cout<<"1. Continue with Same\n";
        cout<<"2. Go to Main Previous Menu\n";
        cout<<"3. Go to Main Menu..\n";
        cout<<"4. Exit\n";
        c = getch();
        if ( c == '4'){
            thanksLine();
            exit(0);
        }else{
            return (c);
        }
    }
    int insertNode(int opr)
    {
        system("cls");
        if ( opr == 1){
            cout<<"\n\nInsert STUDENT Detail At Beginning . \n\n";
            getData();
            NODE *TEMP = new NODE(SID,AName, SCAP);
            if ( TEMP == nullptr){
                cout<<"Insufficient Memory.. \n";
                return 0;
            }
            if ( START == nullptr){
                END = START = TEMP;
            }
            else{
                TEMP->NEXT = START;
                START = TEMP;
            }
            countNode++;
            SCNT++;
        }
        else if ( opr == 2){
            cout<<"\n\nInsert STUDENT Detail At End . \n\n";
            getData();
            NODE *TEMP = new NODE(SID,AName, SCAP);

            if ( TEMP == nullptr){
                cout<<"Insufficient Memory.. \n";
                return 0;
            }
            if ( START == nullptr){
                END = START = TEMP;
            }
            else{
                END->NEXT = TEMP;
                END = TEMP;
            }
            countNode++;
            SCNT++;
        }
        else if ( opr == 3){
            cout<<"\n\nInsert STUDENT Detail At Given Position . \n\n";
            cout<<"Total Songs -- "<<countNode<<"\n\n";
            int pos;
            getData();
            cout<<"Enter Position Between 0 to "<<countNode<<" -- ";
            cin>>pos;

            NODE *TEMP = new NODE(SID,AName, SCAP);
            if ( TEMP == nullptr){
                cout<<"Insufficient Memory.. \n";
                return 0;
            }
            int i;
            NODE *TEMP1 = START;
            for ( i = 2 ; i < pos ; i++){
                TEMP1 = TEMP1->NEXT;
            }
            if ( START == nullptr){
                END = START = TEMP;
            }
            else{
                TEMP->NEXT = TEMP1->NEXT;
                TEMP1->NEXT = TEMP;
                if ( TEMP1 == END){
                    END = TEMP1->NEXT;
                }
            }
            countNode++;
            SCNT++;
        }
        char c = continueCheck();
        if (c == '1')
            insertNode(opr);
        else if ( c == '2')
            insertionOperation();
        else if ( c == '3')
            MainMenu();
    }
    void showNode()
    {
        cout<<"\n\nSTUDENT Detail -- \n\n";
        cout<<"* Head -> ";
        NODE *TEMP = START;
        if ( START == nullptr){
            cout<<"null \n\nSTUDENT Detail is empty\n";
        }
        else{
            while ( TEMP!= nullptr){
                cout<<"["<<TEMP->SID<<", ";
                cout<<TEMP->ANAME<<", ";
                cout<<TEMP->SD<<"] -> ";
                TEMP = TEMP->NEXT;
            }
            cout<<"Null";
        }
    }
    void countNodes()
    {
        system("cls");
        cout<<"Count STUDENT Detail Module --\n\n";
        cout<<"Total Number of STUDENT -- "<<countNode<<" STUDENT Detail Available\n\n"
;    }
    int insertionOperation()
    {
        system("cls");
        cout<<"\nInsertion Operation..\n\n";
        cout<<"1. Insert STUDENT Detail At Beginning\n";
        cout<<"2. Insert STUDENT Detail At End\n";
        cout<<"3. Insert STUDENT Detail After Data\n";
        cout<<"4. Go to Main Menu\n";
        cout<<"5. Exit.\n";
        char c = getch();
        if ( c == '1'){
            insertNode(1);
        }
        else if ( c == '2'){
            insertNode(2);
        }
        else if ( c == '3'){
            insertNode(3);
        }
        else if ( c == '4'){
            MainMenu();
        }
        else if ( c == '5'){
            thanksLine();
            exit(0);
        }
    }

    int deleteNode(int opr)
    {
        NODE *TEMP;
        if ( opr == 1){
            cout<<"\n\nDelete STUDENT Detail From Beginning . \n\n";
            if ( START == nullptr)
            {
                cout<<"STUDENT Detail List is Empty.. \n\n";
                return 0;
            }
            else if ( START->NEXT == nullptr){
                TEMP = START;
                END = START = nullptr;
            }
            else{
                TEMP = START;
                START = START->NEXT;
            }
            countNode--;
            delete(TEMP);
            cout<<"\nSTUDENT Detail Deleted Successfully\n\n";
        }
        else if ( opr == 2){
            cout<<"\n\nDelete STUDENT Detail From End . \n\n";
            if ( START == nullptr)
            {
                cout<<"STUDENT Detail List is Empty.. \n\n";
                return 0;
            }
            else if ( START->NEXT == nullptr){
                TEMP = START;
                END = START = nullptr;
            }
            else{
                TEMP = START;
                int c = 1;
                while ( TEMP->NEXT != END)
                {
                    cout<<c++<<endl;
                    TEMP = TEMP->NEXT;
                }
                NODE *T1 = END;
                TEMP->NEXT = nullptr;
                END = TEMP;
                cout<<END->ANAME<<endl;
                delete(T1);
            }
            countNode--;
            cout<<"\nSTUDENT Detail Deleted Successfully\n\n";
        }
        else if ( opr == 3){
            cout<<"\n\nDelete STUDENT Detail From Given Position . \n\n";

            if ( START == nullptr)
            {
                cout<<"STUDENT DetailList is Empty.. \n\n";
                return 0;
            }
            int pos;
            cout<<"Enter Position for Delete (1 - "<<countNode<<") - ";
            cin>>pos;
            if ( pos == 1 && START == END)
            {
                TEMP = START;
                START = END = nullptr;
            }
            else{
                TEMP = START;
                for (int i = 2 ; i < pos ; i++)
                {
                    TEMP = TEMP->NEXT;
                }
                if (TEMP->NEXT == END){
                    NODE *T1 = END;
                    TEMP->NEXT = nullptr;
                    END = TEMP;
                }
                else{
                    NODE *T1 = TEMP->NEXT;
                    TEMP->NEXT = T1->NEXT;
                    delete(T1);
                }
            }
            countNode--;
            cout<<"\nSTUDENT Detail Deleted Successfully\n\n";
        }
        char c = continueCheck();
        if (c == '1')
            deleteNode(opr);
        else if ( c == '2')
            deleteOperation();
        else if ( c == '3')
            MainMenu();
            return 0;
    }
    int deleteOperation()
    {
        system("cls");
        cout<<"\nDeletion Operation..\n\n";
        cout<<"1. Delete STUDENT Detail From Beginning\n";
        cout<<"2. Delete STUDENT Detail From End\n";
        cout<<"3. Delete STUDENT Detail From Given Position\n";
        cout<<"4. Go to Main Menu\n";
        cout<<"5. Exit.\n";
        char c = getch();
        if ( c == '1'){
            deleteNode(1);
        }
        else if ( c == '2'){
            deleteNode(2);
        }
        else if ( c == '3'){
            deleteNode(3);
        }
        else if ( c == '4'){
            MainMenu();
        }
        else if ( c == '5'){
            thanksLine();
            exit(0);
        }

    }
    /*search module start*/

    int searchTweetInNode()
    {
        cout<<"\n\nSearch STUDENT Detail in STUDENT Detail List -- \n\n";
        cout<<"* Head -> ";
        NODE *TEMP = START;
        if ( START == nullptr){
            cout<<"null \n\nSTUDENT Detail list is empty\n";
            return 0;
        }
        else{
            cout<<"\n\nEnter STUDENT Name To Find DETAIL -- ";
            string Aname;
            int counter = 0;
            getline(cin,Aname);
            while ( TEMP!= nullptr){
                if (TEMP->ANAME == Aname)
                {
                    cout<<"\n["<<TEMP->SID<<", ";
                    cout<<TEMP->ANAME<<", ";
                    cout<<TEMP->SD<<"]\n";
                    counter++;
                }
                TEMP = TEMP->NEXT;
            }
            if ( counter == 0){
                cout<<"\nNo SONG Found..\n\n";
            }
        }
        char c;
        cout<<"\n\nAre you .. \n";
        cout<<"1. Continue with Same\n";
        cout<<"2. Go to Main Menu..\n";
        cout<<"3. Exit\n";
        c = getch();
        if (c == '1')
            searchTweetInNode();
        else if ( c == '2')
            MainMenu();
        else if ( c == '3'){
            thanksLine();
            exit(0);

        }
        return 0;
    }

    /*Search Module End*/
    int MainMenu()
    {
        system("cls");
        cout<<"========== LinkList Operation ==========\n\n";
        cout<<"1. Insertion Of STUDENT Detail \n";
        cout<<"2. Traversal STUDENT\n";
        cout<<"3. Delete STUDENT Detail \n";
        cout<<"4. Search STUDENT\n";
        cout<<"5. Count STUDENT\n";
        cout<<"6. Exit\n";
        cout<<"Choose One of them -- ";
        char c = getch();
        if ( c == '1'){
            insertionOperation();
        }
        else if ( c == '2'){
            showNode();
        }
        else if ( c == '3'){
            deleteOperation();
        }
        else if ( c == '4'){
            searchTweetInNode();
        }
        else if ( c == '5'){
            countNodes();
        }
        else if ( c == '6'){
            thanksLine();
            exit(0);
        }
        cout<<"\n\nDo you want to continue .. press 1 else any key..";
        c = getch();
        if ( c == '1'){
            MainMenu();
        }
    }
    void thanksLine()
    {
        cout<<"\n\nThanks for Using My APP\n\n";
    }
};
int main()
{
    LinkList l;
    l.MainMenu();
    cout<<"\n\nThanks for Using My APP\n\n";
}






