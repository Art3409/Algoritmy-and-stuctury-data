#include<iostream>

void qsort(int *mas, int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    int mid = mas[size / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while(mas[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while(mas[j] > mid) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > 0) {
        //"Левый кусок"
        qsort(mas, j + 1);
    }
    if (i < size) {
        //"Првый кусок"
        qsort(&mas[i], size - i);
    }
}

int main(){
    char logo[] =
"**********************************************\n"
"* Nizhny Novgorog State Technical University *\n"
"* Study work number 3. Task number 1.        *\n"
"* Performed student 21-IVT-2 Kitov A. A.     *\n"
"**********************************************\n";
    setlocale(LC_ALL, "Russian");
    int k=0,num=0; 
    std::cout<<"Введите количество элементов: ";
    while(!(std::cin>>k) || (std::cin.peek()!='\n')){
        std::cin.clear();
        while(std::cin.get()!='\n');
        std::cout<<"Error! Введите число заново"<<std::endl;
    }
    int* massiv;
    massiv=new int[k];
    for(int i=0;i<k;i++){
        while(!(std::cin>>num) || (std::cin.peek()!='\n')){
            std::cin.clear();
            while(std::cin.get()!='\n');
            std::cout<<"Error! Введите число заново"<<std::endl;
        }
        massiv[i]=num;
    }
    for(int i=0;i<k;i++){
        std::cout<<massiv[i]<<" ";
    }
    std::cout<<std::endl;
    qsort(massiv,k);
    for(int i=0;i<k;i++){
        std::cout<<massiv[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
