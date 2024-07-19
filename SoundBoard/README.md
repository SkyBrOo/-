# SoundBoard V6.1 - Ultimate Admin Audio Tool for DayZ

## Auteur
- **Nom**: 🆅🅴🅶🅰🆂
- **Discord**: franckamara
- **SteamID**: 76561199088185222

## Description
SoundBoard V6.1 est l'outil audio ultime pour les administrateurs de serveurs DayZ. Cette mise à jour apporte des corrections critiques et des améliorations de performance, offrant une expérience sonore immersive et stable pour votre serveur.

## Nouvelles fonctionnalités et corrections (V6.1)
- Correction du bug de chargement des fichiers audio
- Optimisation de la gestion de la mémoire
- Amélioration de la compatibilité avec le DayZ Community Framework
- Correction des erreurs de compilation dans SoundBoardManager.c
- Interface utilisateur plus réactive
- Meilleure gestion des erreurs et logging amélioré

## Caractéristiques principales
- Interface utilisateur intuitive pour la sélection de chansons et de joueurs
- Bibliothèque de sons personnalisable
- Contrôle précis du volume et de la distance de diffusion
- Playlist dynamique avec navigation (suivant/précédent)
- Raccourcis clavier configurables
- Gestion avancée des permissions administratives
- Compatibilité totale avec la dernière version de DayZ

## Prérequis
- DayZ version 1.21 ou supérieure
- DayZ Community Framework (CF) version 1.0 ou supérieure

## Installation
1. Assurez-vous d'avoir installé le DayZ Community Framework.
2. Téléchargez le mod SoundBoard V6.1 et placez-le dans le dossier des mods de votre serveur DayZ.
3. Ajoutez le mod à la ligne de commande de lancement du serveur.
4. Assurez-vous que les clients ont également le mod et le CF installés.

## Structure des fichiers
@SoundBoard/
├── Addons/
│ └── SoundBoard.pbo
├── Keys/
│ └── SoundBoard.bikey
├── Music/
│ └── [vos fichiers .ogg ici]
├── gui/
│ ├── images/
│ │ ├── logo.paa
│ │ └── logo_small.paa
│ └── layouts/
│ └── SoundBoardMenu.layout
└── Scripts/
├── 3_Game/
│ └── SoundBoardVersion.c
├── 4_World/
│ ├── SoundBoardManager.c
│ └── SoundBoardSettings.c
└── 5_Mission/
├── SoundBoardMenu.c
└── SoundBoardInputHandler.c
├── config.cpp
├── mod.cpp
└── LICENSE

## Configuration
### Ajout de chansons
1. Placez vos fichiers audio au format .ogg dans le dossier `@SoundBoard/Music/`.
2. Assurez-vous que les noms de fichiers sont uniques et ne contiennent pas de caractères spéciaux.

### Configuration des touches (par défaut)
- Ouvrir/fermer la SoundBoard : `K`
- Chanson suivante : `Flèche droite`
- Chanson précédente : `Flèche gauche`

## Utilisation
1. En tant qu'administrateur, appuyez sur la touche de raccourci (par défaut `K`) pour ouvrir la SoundBoard.
2. Sélectionnez une chanson dans la liste.
3. Choisissez les joueurs pour lesquels vous voulez jouer la chanson.
4. Cliquez sur le bouton "Jouer" pour diffuser la chanson.
5. Utilisez les boutons ou les raccourcis pour naviguer dans la playlist.

## Dépannage
- Si vous rencontrez des problèmes de chargement des fichiers audio, vérifiez que vos fichiers .ogg sont correctement placés dans le dossier Music/.
- En cas d'erreur de compatibilité, assurez-vous d'utiliser la dernière version du DayZ Community Framework.
- Consultez les logs du serveur pour des messages d'erreur spécifiques liés à la SoundBoard.

## Support
Pour toute question ou problème, contactez-moi sur Discord: franckamara

## Licence et Droits
Ce mod est distribué sous la licence Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International (CC BY-NC-SA 4.0).

Vous êtes libre de :
- Partager — copier et redistribuer le matériel sous n'importe quel format
- Adapter — remixer, transformer et créer à partir du matériel

Sous les conditions suivantes :
- Attribution — Vous devez créditer l'œuvre, intégrer un lien vers la licence et indiquer si des modifications ont été effectuées.
- Pas d'Utilisation Commerciale — Vous n'êtes pas autorisé à faire un usage commercial de cette œuvre.
- Partage dans les Mêmes Conditions — Si vous remixez, transformez ou créez à partir du matériel, vous devez diffuser vos contributions sous la même licence que l'original.

Pour plus de détails : https://creativecommons.org/licenses/by-nc-sa/4.0/

## Changelog
### V6.1
- Correction du bug de chargement des fichiers audio
- Optimisation des performances
- Amélioration de la compatibilité avec le CF
- Correction des erreurs de compilation dans SoundBoardManager.c
- Interface utilisateur plus réactive

### V6.0
- Intégration complète avec le DayZ Community Framework
- Refonte majeure du code pour une meilleure stabilité
- Ajout de la navigation dans la playlist

### V5.0
- Ajout de touches par défaut pour les contrôles principaux
- Amélioration de la gestion des fichiers audio

### V4.0
- Ajout du dossier `Music/` pour une meilleure organisation
- Amélioration de la gestion des erreurs

### V3.0
- Ajout des permissions administratives
- Configuration des touches de raccourci

### V2.0
- Première version publique du mod SoundBoard

### V1.0
- Version initiale (interne) du mod SoundBoard

Merci d'utiliser SoundBoard V6.1 pour améliorer l'expérience audio sur votre serveur DayZ !