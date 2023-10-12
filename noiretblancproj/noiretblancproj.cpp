#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int WIN_WIDTH = 1920;
int WIN_HEIGHT = 1080;

int main()
{
    string nomFichier;
    cout << "Entrez le nom du fichier image : ";
    cin >> nomFichier;

    // Charger l'image à partir du fichier en couleur
    Mat image = imread(nomFichier);

    // Vérifier si l'image est chargée correctement
    if (image.empty()) {
        cout << "Impossible de charger l'image. Assurez-vous que le fichier existe." << endl;
        return -1;
    }

    // Obtenir les dimensions de l'image
    int largeur = image.cols;
    int hauteur = image.rows;

    // Inverser les couleurs de chaque pixel de l'image
    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            Vec3b& pixel = image.at<Vec3b>(y, x);
            // Inverser chaque canal de couleur (bleu, vert, rouge)
            pixel[0] = 255 - pixel[0]; // Canal bleu
            pixel[1] = 255 - pixel[1]; // Canal vert
            pixel[2] = 255 - pixel[2]; // Canal rouge
        }
    }

    // Afficher l'image originale et le négatif couleur
    namedWindow("Négatif Couleur", WINDOW_NORMAL);
    resizeWindow("Négatif Couleur", WIN_WIDTH, WIN_HEIGHT);
    imshow("Négatif Couleur", image);
    waitKey(0);

    // Enregistrer l'image avec le suffixe "_inv"
    size_t lastDotIndex = nomFichier.find_last_of(".");
    string nomFichierInv = nomFichier.substr(0, lastDotIndex) + "_inv" + nomFichier.substr(lastDotIndex);
    imwrite(nomFichierInv, image);
    cout << "Image enregistrée sous : " << nomFichierInv << endl;

    return 0;
}
