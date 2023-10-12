#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <ctime>

using namespace cv;
using namespace std;

int WIN_WIDTH = 1920;
int WIN_HEIGHT = 1080;

int main()
{
    Mat frame;
    int deviceID = 1;  // Utilisez l'ID de la caméra appropriée
    int apiID = CAP_ANY;
    VideoCapture cap;
    cap.open(deviceID, apiID);

    if (!cap.isOpened())
    {
        cout << "Erreur lors de l'ouverture de la caméra" << endl;
        return -1;
    }

    // Démarre le chronomètre
    double start_time = static_cast<double>(getTickCount());

    while (1)
    {
        if (!cap.read(frame))
        {
            cout << "Impossible de lire la vidéo" << endl;
            break;
        }

        // Obtenir la date et l'heure actuelles
        time_t now = time(0);
        struct tm currentTime;
        localtime_s(&currentTime, &now);
        char dateTimeString[50];
        strftime(dateTimeString, sizeof(dateTimeString), "%d-%m-%Y %H:%M:%S", &currentTime); // Format de la date et de l'heure
        namedWindow("frame", WINDOW_NORMAL);
        resizeWindow("frame", WIN_WIDTH, WIN_HEIGHT);

        // Afficher la date et l'heure sur l'image
        putText(frame, dateTimeString, Point(450, 425), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 100), 1);

        // Calculer le temps écoulé depuis le début du programme
        double elapsed_time = ((double)getTickCount() - start_time) / getTickFrequency();

        // Afficher le chronomètre
        stringstream ss;
        ss << elapsed_time << " secondes";
        putText(frame, ss.str(), Point(490, 450), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 100), 1);

        imshow("frame", frame);

        if (waitKey(2) == 27) // Quitter avec la touche échap
            break;
    }

    cap.release();
    return 0;
}
