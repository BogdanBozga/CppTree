#include <iostream>
#include <queue>

struct NodArbore {
    int valoare{};            // Valoarea stocată în nod
    NodArbore* stanga; // Pointer către fiul stâng
    NodArbore* dreapta; // Pointer către fiul drept
    int empty;
    explicit NodArbore(int val) {
        empty = 0;
        valoare = val;
        stanga = nullptr;
        dreapta = nullptr;
    }
    NodArbore() {
        empty = 1;
        stanga = nullptr;
        dreapta = nullptr;
    }
};

void inserare(NodArbore*& nod, int val) {
    auto* nouNod = new NodArbore(val);
    if (nod == nullptr || nod->empty==1) {
        nod = nouNod;
    }else {
        NodArbore *nodCurent = nod;
        while (true) {
            if (val < nodCurent->valoare) {
                if (nodCurent->stanga == nullptr) {
                    nodCurent->stanga = nouNod;
                    break;
                } else {
                    nodCurent = nodCurent->stanga;
                }
            } else {
                if (nodCurent->dreapta == nullptr) {
                    nodCurent->dreapta = nouNod;
                    break;
                } else {
                    nodCurent = nodCurent->dreapta;
                }
            }
        }
    }
}

void afisareInordine(NodArbore* nod) {
    if (nod != nullptr && nod->empty==0) {
        afisareInordine(nod->stanga);
        std::cout << nod->valoare << " ";
        afisareInordine(nod->dreapta);
    }
}
void afisarePostordine(NodArbore* nod) {
    if (nod != nullptr && nod->empty==0) {
        afisareInordine(nod->stanga);
        afisareInordine(nod->dreapta);
        std::cout << nod->valoare << " ";
    }
}
void afisarePreordine(NodArbore* nod) {
    if (nod != nullptr && nod->empty==0) {
        std::cout << nod->valoare << " ";
        afisareInordine(nod->stanga);
        afisareInordine(nod->dreapta);
    }
}

void afisarePeNivel(NodArbore* nod) {
    if (nod == nullptr || nod->empty==1 ) {
        return;
    }
    std::queue<NodArbore*> noduri;
    noduri.push(nod);
    while (!noduri.empty()) {
        int nivelSize = noduri.size();
        for (int i = 0; i < nivelSize; i++) {
            NodArbore* nodCurent = noduri.front();
            noduri.pop();
            std::cout << nodCurent->valoare << " ";
            if (nodCurent->stanga) {
                noduri.push(nodCurent->stanga);
            }
            if (nodCurent->dreapta) {
                noduri.push(nodCurent->dreapta);
            }
        }
        std::cout << std::endl;
    }
}

void afisareIn3(int nr){
    if(nr >=0) {
        if (nr < 10) {
            std::cout << " " << nr << " ";
        } else if (nr < 100) {
            std::cout << " " << nr;
        } else {
            std::cout << nr;
        }
    }else{
        if(nr > -10){
            std::cout << " " << nr;
        }else{
            std::cout << nr;
        }
    }
}

void afisareSpati(int nr){
    for(int i=0;i<nr;i++){
        std::cout << " ";
    }
}

void deseneazaCopac(NodArbore* nod, int maxLevel) {
    if (nod == nullptr) {
        return;
    }
    std::queue<NodArbore*> noduri;
    noduri.push(nod);
    while (!noduri.empty()) {
        int nivelSize = noduri.size();
        for (int i = 0; i < nivelSize; i++) {
            NodArbore* nodCurent = noduri.front();
            noduri.pop();
            afisareSpati(3*maxLevel / nivelSize);

            if(nodCurent->empty==1) {
                std::cout<<"   ";
            }else{
                afisareIn3(nodCurent->valoare);

            }
            if (nodCurent->stanga) {
                noduri.push(nodCurent->stanga);
            }
            if (nodCurent->dreapta) {
                noduri.push(nodCurent->dreapta);
            }

        }
        std::cout << std::endl;
    }
}

int calculareAdancime(NodArbore* nod) {
    if (nod == nullptr || nod->empty==1) {
        return 0;
    }
    int leftDepth = calculareAdancime(nod->stanga);
    int rightDepth = calculareAdancime(nod->dreapta);
    return 1 + std::max(leftDepth, rightDepth);
}


void completeazaArbore(NodArbore*& nod, int level, int maxLevel){
    if(level < maxLevel){
        if(nod->dreapta == nullptr){
            NodArbore *nodNou = new NodArbore();
            nod->dreapta = nodNou;
        }
        if(nod->stanga== nullptr){
            NodArbore *nodNou = new NodArbore();
            nod->stanga = nodNou;
        }
        completeazaArbore(nod->dreapta,level+1,maxLevel);
        completeazaArbore(nod->stanga,level+1,maxLevel);
    }
}

int main() {
    NodArbore* radacina = nullptr;
    int choice;
    do {
        // Display the menu
        for(int i=0;i<=100;i++) {
            std::cout << "" << std::endl;
        }
        std::cout << "Menu:" << std::endl;
        std::cout << "1 -> Insert new element" << std::endl;
        std::cout << "2 -> Display in inorder" << std::endl;
        std::cout << "3 -> Display in preorder" << std::endl;
        std::cout << "4 -> Display in postorder" << std::endl;
        std::cout << "5 -> Display by level" << std::endl;
        std::cout << "6 -> Draw tree" << std::endl;
        std::cout << "7 -> Calculate tree height" << std::endl;
        std::cout << "0 -> Exit" << std::endl;

        // Prompt for user input
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                // Call the function to insert a new element
                int val;
                std::cout << "Enter the value to insert: ";
                std::cin >> val;
                inserare(radacina, val);
                break;
            case 2:
                // Call the function to display in inorder
                afisareInordine(radacina);
                std::cout << std::endl;
                break;
            case 3:
                // Call the function to display in preorder
                afisarePreordine(radacina);
                std::cout << std::endl;
                break;
            case 4:
                // Call the function to display in postorder
                afisarePostordine(radacina);
                std::cout << std::endl;
                break;
            case 5:
                // Call the function to display by level
                afisarePeNivel(radacina);
                break;
            case 6:
                // Call the function to draw the tree
                deseneazaCopac(radacina,calculareAdancime(radacina));
                break;
            case 7:
                // Call the function to calculate tree height
                std::cout << "Tree height: " << calculareAdancime(radacina) << std::endl;
                break;
            case 0:
                // Exit the program
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }

    } while (choice != 0);

    return 0;
}
