#include "binary_stitch.h"

// Constant variables for the placement of lines
const int lineLength = 27, space = 24;

// Function converting decimal number to binary array
int * convertToBinary(int n) {
    static int a[6];
    int i;
    for(i=0; n>0; i++)    
    {    
        a[i]={n%2};    
        n= n/2;
    }
    if(i != 5){
        for(;i<6; i++){
            a[i]=0;
        }
    }
    return a;
}

// Function drawing hour part of the face
void BinaryStitch::drawHour(int number){
    int *arr;
    arr = convertToBinary(number);
    int positionCount = 0;
    for(int i=5; i>=0; i--){
        display.setCursor(45 + 25*positionCount, 30);
        display.print(arr[i]);
        for(int j=0; j<6; j++){
            if(arr[i] == 1){
                if(j%2 == 0){
                   display.writeFastVLine(55 + space*positionCount, 34+space*j, lineLength, GxEPD_WHITE);
                   display.writeFastVLine(56 + space*positionCount, 34+space*j, lineLength, GxEPD_WHITE);
                   display.writeFastVLine(57 + space*positionCount, 34+space*j, lineLength, GxEPD_WHITE);
                }
            }
            if(arr[i] == 0){
                if(j%2 != 0){
                   display.writeFastVLine(55 + space*positionCount, 34+space*j, lineLength, GxEPD_WHITE);
                   display.writeFastVLine(56 + space*positionCount, 34+space*j, lineLength, GxEPD_WHITE);
                   display.writeFastVLine(57 + space*positionCount, 34+space*j, lineLength, GxEPD_WHITE);
                }
            }
        }
        positionCount++;
    }
}

// Function drawing minute part of the face
void BinaryStitch::drawMinute(int number){
    int *arr;
    arr = convertToBinary(number);
    int positionCount = 0;
    for(int i=5; i>=0; i--){
        display.setCursor(10, (40+25*(positionCount+1)));
        display.println(arr[i]);
        for(int j=0; j<6; j++){
            if(arr[i] == 1){
                if(j%2 == 0){
                   display.writeFastHLine(31 + space*j, 58+space*positionCount, lineLength, GxEPD_WHITE); 
                   display.writeFastHLine(31 + space*j, 59+space*positionCount, lineLength, GxEPD_WHITE); 
                   display.writeFastHLine(31 + space*j, 60+space*positionCount, lineLength, GxEPD_WHITE); 
                }
            }
            if(arr[i] == 0){
                if(j%2 != 0){
                   display.writeFastHLine(31 + space*j, 58+space*positionCount, lineLength, GxEPD_WHITE); 
                   display.writeFastHLine(31 + space*j, 59+space*positionCount, lineLength, GxEPD_WHITE); 
                   display.writeFastHLine(31 + space*j, 60+space*positionCount, lineLength, GxEPD_WHITE); 
                }
            }
        }
        positionCount++;
    }
}

// Main function
void BinaryStitch::drawWatchFace(){
    display.fillScreen(GxEPD_BLACK);
    display.setTextColor(GxEPD_WHITE);
    display.setFont(&Px437_IBM_BIOS10pt7b);
    drawHour(currentTime.Hour);
    drawMinute(currentTime.Minute);
}

