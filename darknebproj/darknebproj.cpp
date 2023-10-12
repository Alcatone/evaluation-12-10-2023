#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    int largeur, hauteur;

    cout << "Entrez la largeur de l'image : ";
    cin >> largeur;

    cout << "Entrez la hauteur de l'image : ";
    cin >> hauteur;

    Mat image(hauteur, largeur, CV_8UC3, Scalar(0, 0, 0)); // Cr�e une image noire de la taille sp�cifi�e

    // V�rifie si l'image a �t� correctement cr��e
    if (image.empty()) {
        cout << "Erreur lors de la cr�ation de l'image." << endl;
        return -1;
    }

    imshow("Image Noire", image); // Affiche l'image noire
    imwrite("image_noire.png", image); // Enregistre l'image noire dans un fichier

    waitKey(0); // Attends que l'utilisateur appuie sur une touche

    return 0;
}
