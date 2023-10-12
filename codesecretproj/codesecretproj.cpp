#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <iomanip>

using namespace cv;
using namespace std;

int main()
{
    int WIN_WIDTH = 300;
    int WIN_HEIGHT = 300;

    // Demander le message � l'utilisateur
    cout << "Entrez le message � encoder en pixels : ";
    string message;
    getline(cin, message);

    // Cr�er une image vide avec la taille sp�cifi�e
    Mat image(WIN_HEIGHT, WIN_WIDTH, CV_8UC3, Scalar(0, 0, 0));

    int colOffset = 10;
    int rowOffset = 10;

    // Parcourir les caract�res du message
    for (size_t i = 0; i < message.length(); ++i) {
        char hexChar = message[i];

        int decimalValue;

        // Convertir le caract�re hexad�cimal en d�cimal
        if (hexChar >= 'a' && hexChar <= 'f') {
            decimalValue = 10 + (hexChar - 'a');
        }
        else if (hexChar >= 'A' && hexChar <= 'F') {
            decimalValue = 10 + (hexChar - 'A');
        }
        else {
            decimalValue = hexChar - '0';
        }

        // Parcourir les bits du caract�re hexad�cimal
        for (int bit = 3; bit >= 0; --bit) {
            int row = rowOffset + i * 10 + bit; // Calculer la ligne en fonction de l'indice du caract�re et du bit
            int col = colOffset + (3 - bit) * 10; // Chaque bit est repr�sent� sur 10 colonnes

            // V�rifier le bit � la position donn�e
            int bitValue = (decimalValue >> bit) & 1;

            // Mettre � jour les pixels en fonction de la valeur du bit
            if (bitValue == 1) {
                image.at<Vec3b>(row, col) = Vec3b(255, 255, 255); // Mettre le pixel en blanc
            }
        }
    }

    // Afficher l'image modifi�e
    namedWindow("Image Modifi�e", WINDOW_NORMAL);
    imshow("Image Modifi�e", image);
    waitKey(0);

    return 0;
}
