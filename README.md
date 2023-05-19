TRIOULEYRE Thomas

# Projet échecs

## Compilation :

le Makefile inclus et la commande "Make" permettent de compiler le programme


## Niveau de rendu :

Les fonctions "Base", "Prise", "Pions", "Obstacle", "Echec", "Roque", "Promotion", "Mat" et "Pat" ont étées implémentées.


## Conception du programme et difficultés rencontrées :

Le programme suit les consignes proposées dans le sujet avec le découpage en classe : une classe Piece abstraite, une classe par type de pièce (cavalier, fou, reine, pion, ...), une classe pour les cases de l'échiquier (Square), une classe pour l'échiquier (Plateau) et une classe gérant le bon déroulement de la partie

La fonction "Mat" a étée implémentée en testant, si on est en échec, pour toute les pièces, si il existe un mouvement qui nous sortirait de l'échec.

Pour la fonction "Pat" j'ai réutilisé la fonction qui testait si le joueur était en echec et mat mais en la modifiant pour voir si le joueur avait un coup possible mais sans etre en echec. Je n'ai pas eu le temps de tester toutes les issues possibles de cette fonction. 

Le projet étant très volumineux j'ai compris les avanteges de la programmation orientée objet pour ce type de programmation.

La principale difficultée que j'ai rencontré est la conception des bonnes abstraction pour avoir un code clair et efficace (ce qui est souvent difficile sans de bons commentaires). Aussi  l'application de certains principes de la POO n'a pas été évidente (je pense à l'héritage multiple, utilisée pour la classe Queen, classe sur laquelle j'ai passé un certain temps).
