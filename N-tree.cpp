#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
typedef struct tree_element{
    int value;
    struct tree_element* left;
    struct tree_element* right;
} tree_element;

tree_element* create_tree_element(int i){
    tree_element* elem=new tree_element;
    elem->value=i;
    elem->left=NULL;
    elem->right=NULL;
    return elem;
}

void insert_into_tree(tree_element* root, tree_element* elem){
    if(elem->value < root->value){
        if(root->left==NULL){
            root->left=elem;
        }
        else{
            insert_into_tree(root->left,elem);
        } 
    }
    else{
        if(root->right==NULL){
            root->right=elem;
        }
        else{
            insert_into_tree(root->right,elem);
        } 
    }
}

void print_tree1(tree_element* cur_elem){
    if(cur_elem->left!=NULL){
        print_tree1(cur_elem->left);
    }
    std::cout<<"V= "<<cur_elem->value<<std::endl;
    if(cur_elem->right!=NULL){
        print_tree1(cur_elem->right);
    }
}
void print_tree2(tree_element* cur_elem,  int n){
    if(cur_elem->left!=NULL and cur_elem->value!=n){
        print_tree2(cur_elem->left, n);
    }
    if(cur_elem->value!=n){
        std::cout<<"V= "<<cur_elem->value<<std::endl;
    }
    if(cur_elem->right!=NULL and cur_elem->value!=n){
        print_tree2(cur_elem->right, n);
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
    std::cout<< logo <<std::endl;
    int a[7]={-1,2,10,44,5,-6,7};
    int num=0;
    int q=0,k=0;
    std::cout<<"Введите количество элдементов дерева: ";
    while(!(std::cin>>k) || (std::cin.peek()!='\n')){
        std::cin.clear();
        while(std::cin.get()!='\n');
        std::cout<<"Error! Введите число заново"<<std::endl;
    }
    tree_element* root=create_tree_element(0);
    for(int i=0;i<k;i++){
        std::cout<<"Число "<<i+1<<": ";
        while(!(std::cin>>num) || (std::cin.peek()!='\n')){
            std::cin.clear();
        while(std::cin.get()!='\n');
            std::cout<<"Error! Введите число заново"<<std::endl;
        }
        tree_element* el=create_tree_element(num);
        insert_into_tree(root,el);
    }
    std::cout<<"Дерево:"<<std::endl;
    print_tree1(root);
    std::cout<<"----------------------------------------------------"<<std::endl;
    std::cout<<"Введите число: ";
    while(!(std::cin>>q) || (std::cin.peek()!='\n')){
        std::cin.clear();
        while(std::cin.get()!='\n');
        std::cout<<"Error! Введите число заново"<<std::endl;
    }
    std::cout<<"----------------------------------------------------"<<std::endl;
    print_tree2(root,q);
    return 0;
}
