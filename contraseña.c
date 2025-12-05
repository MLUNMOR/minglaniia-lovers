#include <iostream>
#include <string> 

int contraseña(){
    int total=99;
    int actual=50;
    guess=0;
    char direc;
    if (actual==0){
        return guess++;
    }
    int giro(int val){
        if(direc==R){
            if(val+actual>total){
                actual=val+actual-100;
        }else{
            actual=actual+val;
    }
        if(direc==L{){
            if(actual-val<0){
                actual=100+(actual-val);
            }else{
                actual=actual-val;
            }
    }
        return actual;
    }
}