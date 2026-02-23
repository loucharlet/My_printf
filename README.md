# 🎀 My_Printf - Epitech 2026

Réimplémentation de la fonction `printf` de la bibliothèque C standard selon la norme C99.  
Ce projet a été développé en respectant les contraintes de la libC : toute la libC est interdite exceptés `write`, `malloc`, `free`, `va_start`, `va_end` et `va_arg`.

---

##  Fonctionnalités

Cette bibliothèque supporte les spécificateurs, les flags et les modificateurs de longueur demandés.

### Spécificateurs de type

- `%d`, `%i` : Entiers signés  
- `%s` : Chaînes de caractères  
- `%c` : Caractères  
- `%x`, `%X` : Hexadécimal (minuscule/majuscule)  
- `%o` : Octal  
- `%u` : Entier non signé  
- `%p` : Adresses de pointeurs  
- `%%` : Affichage du caractère '%'  
- `%b` : **Bonus** - Affichage en binaire  

---

### Flags et Formatage

- `-` : Alignement à gauche  
- `+` : Force l'affichage du signe (+ ou -)  
- `0` : Remplissage avec des zéros  
- `#` : Préfixe pour l'hexadécimal et l'octal  
- ` ` (espace) : Ajoute un espace devant les nombres positifs  
- `width` : Largeur minimale du champ  
- `precision` : Précision pour les nombres ou tronquage pour les chaînes  

---

### Modificateurs de longueur

- `%hd`, `%hi` : Short int  
- `%ld`, `%li` : Long int  

---

## 🛠️ Installation et Compilation

Le projet utilise un **Makefile** pour générer la bibliothèque `libmy.a`.

### 1️⃣ Générer la bibliothèque

```bash
make
```

### 2️⃣ Nettoyer les fichiers objets

```bash
make clean
```

### 3️⃣ Supprimer tous les fichiers générés (lib et objets)

```bash
make fclean
```

### 4️⃣ Recompiler proprement

```bash
make re
```

---

## 📌 Utilisation

Pour utiliser `my_printf` dans votre projet, incluez le header `my.h` et liez la bibliothèque `libmy.a` lors de la compilation :

```c
#include "my.h"

int main(void) {
    my_printf("Hello %s! Score: %+d\n", "World", 42);
    return 0;
}
```

### 🔧 Commande de compilation

```bash
gcc votre_fichier.c -L. -lmy -I./include
```

---

## 🧪 Tests

Un dossier `tests/` contient les fichiers de test pour vérifier la conformité des sorties.

```bash
gcc tests/main_tests.c -L. -lmy -I./include -o unit_test
./unit_test
```
