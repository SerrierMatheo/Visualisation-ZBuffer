import csv

import comparateurFichier


def diff_to_csv(file1, file2, output_file):
    # Calculer la différence en pourcentage entre les deux fichiers
    diff_percent = comparateurFichier.compare_files(file1, file2)

    # Écrire les données dans le fichier CSV
    with open(output_file, 'a', newline='') as f:
        writer = csv.writer(f)

        # Si le fichier est vide, écrire les noms de colonnes
        if f.tell() == 0:
            writer.writerow(['Fichier 1', 'Fichier 2', 'Différence en pourcentage'])

        # Écrire les données dans le fichier CSV
        writer.writerow([file1, file2, diff_percent])


# diff_to_csv("airplane.ply", "airplane1.ply", "resultats.csv")
