/*
 Copyright (C) 2012 Kristian Lauszus, TKJ Electronics. All rights reserved.
 This software may be distributed and modified under the terms of the GNU
 General Public License version 2 (GPL2) as published by the Free Software
 Foundation and appearing in the file GPL2.TXT included in the packaging of
 this file. Please note that GPL2 Section 2[b] requires that all works based
 on this software must also be made publicly available under the terms of
 the GPL2 ("Copyleft").
 Contact information
 -------------------
 Kristian Lauszus, TKJ Electronics
 Web      :  http://www.tkjelectronics.com
 e-mail   :  kristianl@tkjelectronics.com
*/

#include <QFile>
#include "kalman.h"

    Kalman::Kalman()
    {
        /* We will set the variables like so, these can also be tuned by the user */
        Q_angle   = 0.001f;
        Q_bias    = 0.1f;//0.003f;
        R_measure = 0.03f;

        angle = 0.0f; // Reset the angle
        bias  = 0.0f; // Reset bias

        P[0][0] = 0.0f; // Since we assume that the bias is 0 and we know the starting angle (use setAngle), the error covariance matrix is set like so - see: http://en.wikipedia.org/wiki/Kalman_filter#Example_application.2C_technical
        P[0][1] = 0.0f;
        P[1][0] = 0.0f;
        P[1][1] = 0.0f;

        //added code
        orientation = QQuaternion(1.0f, 0.0f, 0.0f, 0.0f);
        ex = 0;
        ey = 0;
        ez = 0;
        angleX = 0.0f;
        angleY = 0.0f;
        angleZ = 0.0f;
    }

    /*
    * The angle should be in degrees and the rate should be in degrees per second and the delta time in seconds
    */
    float Kalman::getAngle(float newAngle, float newRate, float dt)
    {
        // KasBot V2  -  Kalman filter module - http://www.x-firm.com/?page_id=145
        // Modified by Kristian Lauszus
        // See my blog post for more information: http://blog.tkjelectronics.dk/2012/09/a-practical-approach-to-kalman-filter-and-how-to-implement-it

        // Discrete Kalman filter time update equations - Time Update ("Predict")
        // Update xhat - Project the state ahead
        /* Step 1 */
        rate = newRate - bias;
        angle += dt * rate;

        // Update estimation error covariance - Project the error covariance ahead
        /* Step 2 */
        P[0][0] += dt * (dt*P[1][1] - P[0][1] - P[1][0] + Q_angle);
        P[0][1] -= dt * P[1][1];
        P[1][0] -= dt * P[1][1];
        P[1][1] += Q_bias * dt;

        // Discrete Kalman filter measurement update equations - Measurement Update ("Correct")
        // Calculate Kalman gain - Compute the Kalman gain
        /* Step 4 */
        S = P[0][0] + R_measure;
        /* Step 5 */
        K[0] = P[0][0] / S;
        K[1] = P[1][0] / S;

        // Calculate angle and bias - Update estimate with measurement zk (newAngle)
        /* Step 3 */
        y = newAngle - angle;
        /* Step 6 */
        angle += K[0] * y;
        bias += K[1] * y;

        // Calculate estimation error covariance - Update the error covariance
        /* Step 7 */
        P[0][0] -= K[0] * P[0][0];
        P[0][1] -= K[0] * P[0][1];
        P[1][0] -= K[1] * P[0][0];
        P[1][1] -= K[1] * P[0][1];

        return (float)angle;
    }

    /*
    * set start angle
    * Used to set angle, this should be set as the starting angle
    */
    void Kalman::setAngle(float newAngle)
    {
      angle = newAngle;
    }

    /*
    * Return the unbiased rate
    */
    float Kalman::getRate()
    {
      return rate;
    }

    /*
    * These are used to tune the Kalman filter
    */
    void Kalman::setQangle(float newQ_angle)
    {
      Q_angle = newQ_angle;
    }

    /*
    * set q bias to kalman filter
    */
    void Kalman::setQbias(float newQ_bias)
    {
      Q_bias = newQ_bias;
    }

    /*
    * set r mesure to kalman filter
    */
    void Kalman::setRmeasure(float newR_measure)
    {
      R_measure = newR_measure;
    }

    /*
    * get q angle
    */
    float Kalman::getQangle()
    {
      return Q_angle;
    }

    /*
    * get q bias from kalman filter internal
    */
    float Kalman::getQbias()
    {
      return Q_bias;
    }

    /*
    * get r mesure from kalman filter
    */
    float Kalman::getRmeasure()
    {
      return R_measure;
    }

    //added funcitons
    void Kalman::updateOrientation(float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz){

        //Kalman kalman;
        QList<float> accAngle = getAngleFromVectorDegree(ax,ay,az, mx,my,mz);
        accAngle[0] = accAngle[0];//radToDegree(accAngle[0]);
        accAngle[1] = accAngle[1];//radToDegree(accAngle[1]);
        accAngle[2] = accAngle[2];//radToDegree(accAngle[2]);

        //accAngle.append(ax);//
        //accAngle.append(ay);
        //accAngle.append(az);
        QList<float> gyros;
        gyros.append(radToDegree(gx));
        gyros.append(radToDegree(gy));
        gyros.append(radToDegree(gz));
        QList<float> angles = getAngles(accAngle, gyros, 100.0f);
        //ex = kalman.getAngle(accAngle[0], radToDegree(gx), 1.0f);
        //ey = kalman.getAngle(accAngle[1], radToDegree(gy), 1.0f);
        //ez = kalman.getAngle(accAngle[2], radToDegree(gz), 1.0f);
        //orientation = QQuaternion::fromEulerAngles(ex, ey, ez);

        orientation = QQuaternion::fromEulerAngles(angles[0], angles[1], angles[2]);

        QFile file("kalmanangles.txt");
        if(!file.open(QIODevice::Append | QIODevice::Text)){
            return;
        }
        QTextStream out(&file);
        out << QString::number(angles[0]) + " " + QString::number(angles[1]) + " " + QString::number(angles[2]) +"\n";
        file.close();

        //orientation.normalize();
        //orientation = QQuaternion(1.0f ,angles[0], angles[1], angles[2]);

    }

    QQuaternion Kalman::getRotation(){

        return orientation;

    }

    float Kalman::radToDegree(float rad){

        if (isnan(rad)){

            rad = 0;

        }
        return rad * 180 / M_PI;

    }

    QList<float> Kalman::getAngleFromVectorDegree(float x, float y, float z, float xMag, float yMag, float zMag){

        /*
        //float magNorm = sqrt(xMag * xMag + yMag * yMag + zMag * zMag);
        //float magNormed[3] = {xMag / magNorm, yMag / magNorm, zMag / magNorm};
        //Roll   = -atan2(  yAccel ,  sqrt(sq(xAccel)+sq(zAccel)));
        //Pitch  = atan2(  xAccel ,  sqrt(sq(yAccel)+sq(zAccel)));
        //yaw=atan2( (-yMagnetMap*cos(Roll) + zMagnetMap*sin(Roll) ) , (xMagnetMap*cos(Pitch) + yMagnetMap*sin(Pitch)*sin(Roll)+ zMagnetMap*sin(Pitch)*cos(Roll)) ) *180/PI;
        */
        float magNorm = sqrt(xMag * xMag + yMag * yMag + zMag * zMag);
        float magNormed[3] = {xMag / magNorm, yMag / magNorm, zMag / magNorm};
        float thetaXDeg = atan2(x,sqrt(pow(y,2) + pow(z,2)));
        float thetaYDeg = -atan2(y,z);//float thetaYDeg = -atan2(y,z);//float thetaYDeg = radToDegree(-atan2(y,sqrt(pow(x,2) + pow(z,2))));//float thetaYDeg = atan2(y,z);//float thetaYDeg = radToDegree(atan2(y,z));//float thetaYDeg = radToDegree(-atan2(y,sqrt(pow(x,2) + pow(z,2))));//float thetaYDeg = atan2(y,z);
        //float thetaZDeg = radToDegree(atan2(sqrt(pow(x,2) + pow(y,2)), z));//float thetaZDeg = radToDegree(atan2((-magNormed[1] * cos(thetaYDeg) + magNormed[2] * sin(thetaYDeg)), (magNormed[0] * cos(thetaXDeg) + magNormed[1] * sin(thetaXDeg) * sin(thetaYDeg) + magNormed[2] * sin(thetaXDeg) * cos(thetaYDeg))));//float thetaZDeg = atan2(sqrt(pow(x,2) + pow(y,2)), z);
        float thetaZDeg = atan2((-magNormed[1] * cos(thetaYDeg) + magNormed[2] * sin(thetaYDeg) ) , (magNormed[0] * cos(thetaXDeg) + magNormed[1] * sin(thetaXDeg) * sin(thetaYDeg)+ magNormed[2] * sin(thetaXDeg) * cos(thetaYDeg)));



        QList<float> angleDeg;
        angleDeg.append(radToDegree(thetaXDeg));
        angleDeg.append(radToDegree(thetaYDeg));
        angleDeg.append(radToDegree(thetaZDeg));
        return angleDeg;

    }

    QList<float> Kalman::getAngles(QList<float> newAngles, QList<float> newRates, float dt)
    {
        // KasBot V2  -  Kalman filter module - http://www.x-firm.com/?page_id=145
        // Modified by Kristian Lauszus
        // See my blog post for more information: http://blog.tkjelectronics.dk/2012/09/a-practical-approach-to-kalman-filter-and-how-to-implement-it

        // Discrete Kalman filter time update equations - Time Update ("Predict")
        // Update xhat - Project the state ahead
        /* Step 1 */
        rateX = newRates[0] - bias;
        angleX += dt * rateX;

        rateY = newRates[1] - bias;
        angleY += dt * rateY;

        rateZ = newRates[2] - bias;
        angleZ += dt * rateZ;

        // Update estimation error covariance - Project the error covariance ahead
        /* Step 2 */
        P[0][0] += dt * (dt*P[1][1] - P[0][1] - P[1][0] + Q_angle);
        P[0][1] -= dt * P[1][1];
        P[1][0] -= dt * P[1][1];
        P[1][1] += Q_bias * dt;

        // Discrete Kalman filter measurement update equations - Measurement Update ("Correct")
        // Calculate Kalman gain - Compute the Kalman gain
        /* Step 4 */
        S = P[0][0] + R_measure;
        /* Step 5 */
        K[0] = P[0][0] / S;
        K[1] = P[1][0] / S;

        // Calculate angle and bias - Update estimate with measurement zk (newAngle)
        /* Step 3 */
        yX = newAngles[0] - angleX;
        /* Step 6 */
        angleX += K[0] * yX;
        bias += K[1] * yX;

        yY = newAngles[1] - angleY;
        angleY += K[0] * yY;

        yZ = newAngles[2] - angleZ;
        angleZ += K[0] * yZ;

        // Calculate estimation error covariance - Update the error covariance
        /* Step 7 */
        P[0][0] -= K[0] * P[0][0];
        P[0][1] -= K[0] * P[0][1];
        P[1][0] -= K[1] * P[0][0];
        P[1][1] -= K[1] * P[0][1];

        QList<float> angles;
        angles.append(angleX);
        angles.append(angleY);
        angles.append(angleZ);

        return angles;
    }

    void Kalman::setAngles(QList<float> newAngles)
    {
        this->angleX = newAngles[0];
        this->angleY = newAngles[1];
        this->angleZ = newAngles[2];
    }
