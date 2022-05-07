#include"workerManager.cpp"

int main(){
    
    WorkerManager wbk;
    int choice;

    while(true){
        wbk.Show_Menu();
        cout<<"Please enter your choice:"<<endl;
        cin>>choice;

        switch(choice){
            case 0:
                wbk.exitSystem();
                break;
            case 1:
                wbk.add_worker();
                break;
            case 2:
                wbk.show_worker();
                break;
            case 3:
                wbk.delete_worker();
                break;
            case 4:
                wbk.modify_worker();
                break;
            case 5:
                wbk.clean_file();
                break;
            default:
                system("cls");  // clear screen
                break;
        }
    }
    

    return 0;
}