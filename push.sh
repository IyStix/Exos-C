#!/bin/bash

# Vérifier si au moins un argument est fourni
if [ $# -lt 1 ]; then
    echo "Usage: $0 <chemin/vers/fichier1> [chemin/vers/fichier2] ..."
    exit 1
fi

# Extraire le nom du dossier du premier fichier
first_file="$1"
folder_name=$(dirname "$first_file")

# Vérifier si le dossier existe
if [ ! -d "$folder_name" ]; then
    echo "Le dossier $folder_name n'existe pas."
    exit 1
fi

# Vérifier et ajouter chaque fichier
files_added=0
for file in "$@"; do
    if [ ! -f "$file" ]; then
        echo "Le fichier $file n'existe pas. Il sera ignoré."
    else
        git add "$file"
        echo "Ajout de $file"
        ((files_added++))
    fi
done

# Vérifier si des fichiers ont été ajoutés
if [ $files_added -eq 0 ]; then
    echo "Aucun fichier n'a été ajouté. Arrêt du script."
    exit 1
fi

# Commit
git commit -m "submission"

# Créer le tag
tag_name="exercises-$(basename "$folder_name")-V1"
git tag -ma "$tag_name"

# Push avec les tags
git push --follow-tags

echo "Opération terminée avec succès."
