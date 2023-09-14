#include "mbed.h"
#include "MPU6050.h"

DigitalOut myled(LED1);
Serial pc(USBTX, USBRX);
I2C    i2c(I2C_SDA, I2C_SCL);
MPU6050 mpu(i2c);
 
int16_t ax, ay, az;
int16_t gx, gy, gz;
 
int main()
{
    pc.printf("MPU6050 test\n\n");
    pc.printf("MPU6050 initialize \n");
 
    mpu.initialize();
    
    pc.printf("MPU6050 testConnection \n");
 
    bool mpu6050TestResult = mpu.testConnection();
    if(mpu6050TestResult) {
        pc.printf("MPU6050 test passed \n");
    } else {
        pc.printf("MPU6050 test failed \n");
    }
   
    while(1) {
        wait(1);
        mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
        //writing current accelerometer and gyro position 
        pc.printf("Ax : %10d, Ay : %10d, Az : %10d / Gx : %10d, Gy : %10d Gz : %10d\n",ax,ay,az,gx,gy,gz);
    }
}