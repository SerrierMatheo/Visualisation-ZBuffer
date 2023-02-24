import os
import filecmp


def compare_files(file1, file2):
    # Spécifier le chemin complet des fichiers
    file1_path = os.path.join("..", "Ressources", file1)
    file2_path = os.path.join("..", "Ressources", file2)

    # Vérifier si les deux fichiers existent
    if not (os.path.exists(file1_path) and os.path.exists(file2_path)):
        print("L'un ou les deux fichiers n'existent pas.")
        return

    # Vérifier si les deux fichiers ont le même contenu
    if filecmp.cmp(file1_path, file2_path):
        print("Les fichiers sont identiques.")
        return

    # Calculer le pourcentage de différence
    with open(file1_path, "rb") as f1, open(file2_path, "rb") as f2:
        num_different_bytes = 0
        total_bytes = 0
        while True:
            byte1 = f1.read(1)
            byte2 = f2.read(1)
            if not byte1 or not byte2:
                break
            total_bytes += 1
            if byte1 != byte2:
                num_different_bytes += 1
        percentage_difference = (num_different_bytes / total_bytes) * 100
        print(f"Le pourcentage de différence est de {percentage_difference:.2f}%.")


# Exemple d'utilisation
compare_files("airplane.ply", "airplane1.ply")
