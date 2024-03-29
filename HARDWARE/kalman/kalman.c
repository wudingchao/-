#include "kalman.h"

/*       
        Q:过程噪声，Q增大，动态响应变快，收敛稳定性变坏
        R:测量噪声，R增大，动态响应变慢，收敛稳定性变好  
*/

#define KALMAN_Q 0.02

#define KALMAN_R 7.0000

/* 卡尔曼滤波处理 */

double KalmanFilter(double ResrcData,double ProcessNiose_Q,double MeasureNoise_R)
{

    double R = MeasureNoise_R;
    double Q = ProcessNiose_Q;

    static double x_last;
    double x_mid = x_last;
    double x_now;

    static double p_last;
    double p_mid ;
    double p_now;

    double kg;

    x_mid=x_last;                       //x_last=x(k-1|k-1),x_mid=x(k|k-1)
    p_mid=p_last+Q;                     //p_mid=p(k|k-1),p_last=p(k-1|k-1),Q=噪声

    /*
     *  卡尔曼滤波五个重要公式
     */
    kg=p_mid/(p_mid+R);                 //kg为kalman filter,R为噪声
    x_now=x_mid+kg*(ResrcData-x_mid);   //估计出的最优解
    p_now=(1-kg)*p_mid;                 //最优解对应的covariance
    p_last = p_now;                     //更新covariance值
    x_last = x_now;                     //更新系统状态值

    return x_now;

}



