#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour représenter un champ
typedef struct {
    char nom[50];
    int type; // 0: entier, 1: chaîne de caractères
} Champ;

// Structure pour représenter une table
typedef struct {
    char nom[50];
    int nbChamps;
    Champ champs[50];
} Table;

// Fonction pour créer une nouvelle table
Table creerTable(char nom[50], int nbChamps, Champ champs[]) {
    Table nouvelleTable;
    strcpy(nouvelleTable.nom, nom);
    nouvelleTable.nbChamps = nbChamps;
    
    for (int i = 0; i < nbChamps; i++) {
        strcpy(nouvelleTable.champs[i].nom, champs[i].nom);
        nouvelleTable.champs[i].type = champs[i].type;
    }
    
    return nouvelleTable;
}

// Fonction pour afficher les détails d'une table
void afficherTable(Table table) {
    printf("Nom de la table: %s\n", table.nom);
    printf("Nombre de champs: %d\n", table.nbChamps);
    
    for (int i = 0; i < table.nbChamps; i++) {
        printf("Champ %d - Nom: %s\n", i + 1, table.champs[i].nom);
        printf("Champ %d - Type: %s\n", i + 1, table.champs[i].type == 0 ? "Entier" : "Chaîne de caractères");
    }
}

int main() {
    Champ champs[] = {{"Champ1", 0}, {"Champ2", 1}, {"Champ3", 0}};
    Table maTable = creerTable("MaTable", 3, champs);
    afficherTable(maTable);
    
    return 0;
}
