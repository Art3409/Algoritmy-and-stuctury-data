#include<iostream>

struct HeshNum
{
    unsigned int data;
    int flag;
};
void HeshFunction(HeshNum* array, unsigned int num, int size){
    int sum=0;
    std::cout<<"Номер "<<num<<std::endl;
    sum=(num%100+(num/100)%100+(num/10000)%100+(num/1000000)%10)%size;
    std::cout<<"Номер в массиве "<<sum<<std::endl;
    if(array[sum].flag==0){
        array[sum].flag=1;
        array[sum].data=num;
    }
    else{
        int i=0;
        while(array[sum].flag!=0){
            i=i+1;
            sum=sum+3*i+4*i*i;
            if (sum>1000){
                sum=sum-1000;
            }
        }
        array[sum].flag=1;
        array[sum].data=num;
    }
}
void DeleteNum(HeshNum* array, unsigned int num, int size){
    int sum=0;
    sum=(num%100+(num/100)%100+(num/10000)%100+(num/1000000)%10)%size;
    array[sum].flag=2;
    array[sum].data=0;
}
void Search(HeshNum* array, unsigned int num, int size){
    int sum=0;
    sum=(num%100+(num/100)%100+(num/10000)%100+(num/1000000)%10)%size;
    std::cout<<"Номер: "<<num<<" Номер в массиве: "<<sum<<std::endl;
}

HeshNum* Rearray(HeshNum* array, int size){
    HeshNum* mas;
    mas=new HeshNum[size*2];
    for(int i=0;i<size*2;i++){
        mas[i].flag=0;
    }
    for(int i=0;i<size;i++){
        if(array[i].flag==1){
            HeshFunction(mas,array[i].data,size*2);
        }
    }
    delete[] array;
    return mas;
}
void Print(HeshNum* array, int size){
    for(int i=0;i<size;i++){
        if(array[i].flag==1){
            std::cout<<"Номер: "<<array[i].data<<" Номер в массиве: "<<i<<std::endl;
        }
    }
}

int main(){
    char logo[] =
"**********************************************\n"
"* Nizhny Novgorog State Technical University *\n"
"* Study work number 5. Task number 1.        *\n"
"* Performed student 21-IVT-2 Kitov A. A.     *\n"
"**********************************************\n";
    setlocale(LC_ALL, "Russian");
    std::cout<< logo <<std::endl;
    std::string line;
    int size=1000;
    HeshNum* massiv;
    massiv=new HeshNum[size];
    for(int i=0;i<size;i++){
        massiv[i].flag=0;
    }
    int k=0;
    unsigned int esize=0, nuber=0;
    while(1){
        if(k>750){
            massiv=Rearray(massiv,size);
            size=size*2;
        }
        std::cout<<"Введите команду: ";
        std::cin>>line;
        if(line=="HELP"){
            std::cout<<"Have command list: HELP, EXIT, NEW, SEARCH,DELETE, HISTORY"<<std::endl<<"Для ввода новых номеров введите NEW"<<std::endl<<"Для поиска номера введите SEARCH"<<std::endl<<"Для удаления номера из списка DELETE"<<std::endl<<"Для вывода всех значений введите HISTORY"<<std::endl<<"Для выхода введите EXIT"<<std::endl;
        }
        else if(line=="EXIT"){
            std::cout<<"END"<<std::endl;
            break;
        }
        else if(line=="NEW"){
            std::cout<<"Введите семизначный номер: ";
            while(!(std::cin>>esize) || (std::cin.peek()!='\n')){
                std::cin.clear();
                while(std::cin.get()!='\n');
                std::cout<<"Error! Введите число заново ";
            }
            HeshFunction(massiv,esize,size);
            esize=0;
        }
        else if(line=="SEARCH"){
            std::cout<<"Введите номер: ";
            while(!(std::cin>>esize) || (std::cin.peek()!='\n')){
                std::cin.clear();
                while(std::cin.get()!='\n');
                std::cout<<"Error! Введите число заново ";
            }
            Search(massiv,esize,size);
        }
        else if(line=="DELETE"){
            std::cout<<"Введите удаляемый номер: ";
            while(!(std::cin>>esize) || (std::cin.peek()!='\n')){
                std::cin.clear();
                while(std::cin.get()!='\n');
                std::cout<<"Error! Введите число заново ";
            }
            DeleteNum(massiv,esize,size);
        }
        else if(line=="HISTORY"){
            Print(massiv,size);
        }
        else{
            std::cout<<"ERROR! You write don't correct command. Write help for read information/"<<std::endl;
        }
        std::cin.clear();
    }
    return 0;
}
