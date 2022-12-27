#include "binary_stitch.h"

// Constant variables for the placement of lines
const int lineLength = 22, space = 19, margin = 26;

// Function converting decimal number to binary array
int * convertToBinary(int n) {
    static int a[4];
    int i;
    for(i=0; n>0; i++)    
    {    
        a[i]={n%2};    
        n= n/2;
    }
    if(i != 4){
        for(;i<5; i++){
            a[i]=0;
        }
    }
    return a;
}

// Function drawing hour part of the face
int BinaryStitch::drawHour(int digit, int positionCount){
    int *arr;
    arr = convertToBinary(digit);
    for(int i = 3; i>=0; i--){
        display.setCursor(35 + 20*positionCount, 23);
        display.print(arr[i]);
        for(int j=0; j<8; j++){
            if(arr[i] == 1){
                if(j%2 == 0){
                   display.writeFastVLine(45 + space*positionCount, margin+space*j, lineLength, GxEPD_WHITE);
                   display.writeFastVLine(46 + space*positionCount, margin+space*j, lineLength, GxEPD_WHITE);
                   display.writeFastVLine(47 + space*positionCount, margin+space*j, lineLength, GxEPD_WHITE);
                }
            }
            if(arr[i] == 0){
                if(j%2 != 0){
                   display.writeFastVLine(45 + space*positionCount, margin+space*j, lineLength, GxEPD_WHITE);
                   display.writeFastVLine(46 + space*positionCount, margin+space*j, lineLength, GxEPD_WHITE);
                   display.writeFastVLine(47 + space*positionCount, margin+space*j, lineLength, GxEPD_WHITE);
                }
            }
        }
        positionCount++;
    }
    return positionCount;
}

// Function drawing minute part of the face
int BinaryStitch::drawMinute(int digit, int positionCount){
    int *arr;
    arr = convertToBinary(digit);
    for(int i = 3; i>=0; i--){
        display.setCursor(9, 28+20*(positionCount+1));
        display.print(arr[i]);
        for(int j=0; j<8; j++){
            if(arr[i] == 1){
                if(j%2 == 0){
                   display.writeFastHLine(margin + space*j, 45+space*positionCount, lineLength, GxEPD_WHITE); 
                   display.writeFastHLine(margin + space*j, 46+space*positionCount, lineLength, GxEPD_WHITE); 
                   display.writeFastHLine(margin + space*j, 47+space*positionCount, lineLength, GxEPD_WHITE); 
                }
            }
            if(arr[i] == 0){
                if(j%2 != 0){
                   display.writeFastHLine(margin + space*j, 45+space*positionCount, lineLength, GxEPD_WHITE); 
                   display.writeFastHLine(margin + space*j, 46+space*positionCount, lineLength, GxEPD_WHITE); 
                   display.writeFastHLine(margin + space*j, 47+space*positionCount, lineLength, GxEPD_WHITE); 
                }
            }
        }
        positionCount++;
    }
    return positionCount;
}

// Main function
void BinaryStitch::drawWatchFace(){
    display.fillScreen(GxEPD_BLACK);
    display.setTextColor(GxEPD_WHITE);
    display.setFont(&Px437_IBM_BIOS8pt7b);
    int hourPositionCount = 0;
    hourPositionCount = drawHour(currentTime.Hour/10, hourPositionCount);
    drawHour(currentTime.Hour%10, hourPositionCount);
    int minutePositionCount = 0;
    minutePositionCount = drawMinute(currentTime.Minute/10,minutePositionCount);
    drawMinute(currentTime.Minute%10,minutePositionCount);
}

