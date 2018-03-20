# README
## Projet SHELL
### Membres
- Nicolas Cuadros
- Alexandre Nonnon
- Antoine Marjault
- Romain Andrieux

### Composition du projet

#### Partie interpréteur

##### Binôme

- Nicolas Cuadros
- Antoine Marjault

##### Organisation
Comment fonctionne les fichiers entre eux :

- Le main lance le commandEntry

    - Le commandEntry va s'occuper de lire les commandes utilisateurs. 

-   Une fois lue, la commande est envoyé à la fonction analyse dans le commandManager

    - Celle-ci va s'occuper d'envoyer la command à un parser

    - Une fois parser la commande est exécutée  en allant chercher sa fonction associé dans une liste chainée

Les résultats des commandes doivent être écrit dans les fichiers exit/standard et exit/error,
ceux-çi seront gérés par le commandManager.
Cela permet de gérer les flux correctement, sans redirection le commandManager ira directement lire les fichiers.
Sinon il copiera leurs contenus dans d'autres ou s'en servira pour les pipes en placant leurs contenu dans un fichier temporaire
exit/temp

#### Partie commande

##### Binôme

- Alexandre Nonnon
- Romain Andrieux

##### Organisation

Selon le mode les commandes auront différents prototypes :

- Intégré et librairie : ```int cmd(int argc,char *argv[]) ```
- Exécutable indépendant : ```int cmd(int argc,char ...) ```

Chaque commande seront contenus dans le fichier à part.
A l'initialisation du commandManager, les commandes seront stockées dans une liste chainé.
Dans le cas de des exécutable, le dossier contenant les processus sera lu et chaque exécutable associé à une commande.
