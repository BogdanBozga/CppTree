#include <iostream>

struct NodArbore {
    int valoare;            // Valoarea stocată în nod
    NodArbore* stanga; // Pointer către fiul stâng
    NodArbore* dreapta; // Pointer către fiul drept

    NodArbore(int val) {
        valoare = val;
        stanga = nullptr;
        dreapta = nullptr;
    }
};

// Funcție pentru inserarea unei valori în arborele binar
void inserare(NodArbore* radacina, int val) {
    std::cout << &radacina<<std::endl;
    NodArbore* nouNod = new NodArbore(val);
    std::cout << &nouNod<<std::endl;
    if (radacina == nullptr) {
        radacina = nouNod;
        if (radacina != nullptr) {
            std::cout << radacina->valoare << std::endl;
        }
    }else {

        NodArbore *nodCurent = radacina;
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

// Funcție pentru afișarea arborelui în traversare în ordine (inorder)
void afisareInordine(NodArbore* radacina) {
    if (radacina != nullptr) {
        std::cout << radacina->valoare << " ";
        afisareInordine(radacina->stanga);

        afisareInordine(radacina->dreapta);
    }
}

void checkNullptr(NodArbore *nod){
    if (nod == nullptr) {
        std::cout << "I'm null \n ";
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    NodArbore* radacina;
    inserare(radacina, 3);
    inserare(radacina, 1);
    inserare(radacina, 5);
    inserare(radacina, 2);
    inserare(radacina, 4);
    std::cout << "Arborele binar in traversare in ordine: ";
    std::cout << radacina->valoare<<std::endl;
    std::cout << radacina<<std::endl;

    // Afișarea arborelui în traversare în ordine (inorder)

    afisareInordine(radacina);
    std::cout << std::endl;

    return 0;
}
