/**
 * Zaprojektuj strukture IVector (jako pseudo klase).
 * IVector to struktura przechowujaca dynamiczna tablice integerow. Dziala podobnie do std::vector<int> z C++.
 *
 * Poczatkowo tablica wewnatrz IVectora ma rozmiar K (K dobierz sam), gdy tablica jest pelna, alokujemy wieksza tablice
 * (nowy rozmiar K' > K) i przepisujemy wszystkie K elementow do nowej tablicy. Uzytkownik nie moze widziec tej zmiany,
 * to znaczy on dziala na strukturze IVector i nie interesuje go jakie metadane przechowujesz w swojej strukturze.
 * Oznacza to, ze musisz zadbac o pelna hermetyzacje swojego kodu.
 *
 * 1. Napisz konstruktor swojej struktury IVector (funkcja new), destruktor (funkcja delete) oraz wstawianie do IVectora (funkcja insert).
 *      Dla ulatwienia, zakladamy ze nie mozna nic usunac z IVector. A wstawianie dziala jako dodawanie elementu na koniec.
 * 2. Dopisz odpowiednie gettery, jak pobieranie liczby elementow czy pobieranie elementu z danego indeksu
 * 3. Napisz kilka prostych testow. Mozesz do tego uzyc funkcji assert. Pokaz ze powiekszanie tablicy dziala.
 * 4. Jak szybko dziala IVector? Jaka jest zlozonosc obliczeniowa (asymptotycznie) dodawania kolejnego elementu?
 *      Mozesz uzyc do tego kosztu zamortyzowanego i policzyc ile zajmuje dodanie n elementow gdzie (n = (K'/ K) ^ P)
 * 5. Napisz konstruktor IVectora w taki sposob aby uzytkownik mogl podac liczby, ktore maja znajdowac sie w vectorze zaraz po jego stworzeniu
 *      np. IVector* iv = ivector_new_vals(5, 1, 2, 3, 4, 5) // tworzymy ivector i wstawiamy od razu 5 liczb {1, 2, 3, 4, 5}
 *      np. IVector* iv = ivector_new_vals(1, 2, 3, 4, 5) // trudniejsza wersja bo nie podajemy liczby elementow ale same elementy
 *      np. ... mozesz uzyc swojego wlasnego pomyslu na realizacje tego punktu, wazne aby uzytkownik nie musial tworzyc dodatkowych zmiennych np tablic
 
 * Pokaz swoj styl programowania, pochwal sie znajomoscia dobrych metodyk oraz ficzerow jezyka C.
 *      Zadbaj o to aby Twoj kod byl bezpieczny, czytelny i szybki (wez pod uwage aspekty algorytmiczne jak i ficzery nowych cpu)
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
 
typedef struct IVector
{
    int *data;
    size_t size;
    size_t capacity;
} IVector;

IVector* ivector_new(void);
void ivector_delete(IVector* iv);
void ivector_insert(IVector* iv, int val);
 
/* Dopisz pozostale funkcje */
 
IVector* ivector_new(void)
{
    IVector* iv = (IVector*)malloc(sizeof(IVector));
    if (!iv) {
        return NULL;
    }
    
    iv->data = (int*)malloc(sizeof(int)*8);
    if(!iv->data) {
        free(iv);
        return NULL;
    }
    
    iv->size = 0;
    iv->capacity = 8;
    
    return iv;
}
 
void ivector_delete(IVector* iv)
{
    free(iv->data);
    free(iv);
}
 
void ivector_insert(IVector* iv, int val)
{
    /* Zaimplementuj dodawanie elementu */
    if(iv->size==iv->capacity) {
        int* new_data = realloc(iv->data, sizeof(int) * iv->capacity * 2);
        if(!new_data) {
            return;
        }
        iv->data = new_data;
        iv->capacity *= 2;
    }
    else {
        iv->data[iv->size++] = val;
    }
    
}

int ivector_size(IVector* iv)
{
    return iv->size;
}

int ivector_at(IVector* iv, int at)
{
    return iv->data[at];
}
 
int main(void)
{
    IVector* iv = ivector_new();
    
 
    //Proste testy:
    
    
    
    /* Dopisz pozostale funkcje i testy */
 
    return 0;
}
