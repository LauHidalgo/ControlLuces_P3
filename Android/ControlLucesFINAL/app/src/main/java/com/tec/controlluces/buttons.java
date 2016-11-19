package com.tec.controlluces;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;

public class buttons extends AppCompatActivity {

    //Creacion de variables
    Boolean[] isPressed = {false};
    Button bL3, bL4, bL5, bL6, bL7;
    String dato;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_buttons);

//A continuacion se encuentra el codigo de los 5 botones que se presentan en la segunda de la aplicacion,
//los mismos cambian su fondo para que sea más fácil saber si se encendió o apagó la luz correspondiente.
//Además, se envía un string al servidor para poder realizar la acción que corresponda

        //Boton Luz 3
        bL3 = (Button) findViewById(R.id.Luz3);
        bL3.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(isPressed[0]){ //led off
                    bL3.setBackgroundResource(R.drawable.led_red);
                    dato = "a";}
                else{ //led on
                    bL3.setBackgroundResource(R.drawable.led_green);
                    dato = "A";}
                isPressed[0] = !isPressed[0];}//close onClick
        });//Close L3.setOnClickListener

        //Boton Luz 4
        bL4 = (Button) findViewById(R.id.Luz4);
        bL4.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(isPressed[0]){ //led off
                    bL4.setBackgroundResource(R.drawable.led_red);
                    dato = "b";}
                else{//led on
                    bL4.setBackgroundResource(R.drawable.led_green);
                    dato = "B";}
                isPressed[0] = !isPressed[0];}//Close onClick
        });//Close L4.setOnClickListener

        //Boton Luz 5
        bL5 = (Button) findViewById(R.id.Luz5);
        bL5.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(isPressed[0]){ //led off
                    bL5.setBackgroundResource(R.drawable.led_red);
                    dato = "c";}
                else{//led on
                    bL5.setBackgroundResource(R.drawable.led_green);
                    dato = "C";}
                isPressed[0] = !isPressed[0];}//close onClick
        });//Close L5.setOnClickListener

        //Boton Luz 6
        bL6 = (Button) findViewById(R.id.Luz6);
        bL6.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(isPressed[0]){//led off
                    bL6.setBackgroundResource(R.drawable.led_red);
                    dato = "d";}
                else{//led on
                    bL6.setBackgroundResource(R.drawable.led_green);
                    dato = "D";}
                isPressed[0] = !isPressed[0];}//Close onClick
        });//Close L6.setOnClickListener

        //Boton Luz 7
        bL7 = (Button) findViewById(R.id.Luz7);
        bL7.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (isPressed[0]) {//led off
                    bL7.setBackgroundResource(R.drawable.led_red);
                    dato = "e";}
                else { //led on
                    bL7.setBackgroundResource(R.drawable.led_green);
                    dato = "E";}
                isPressed[0] = !isPressed[0];
            }//Close onClick
        });//Close L7.setOnClickListener

        //Llamado a funcion para envio de dato
        SendData(dato);
    }//Close onCreate

    public void SendData(String data){
        //La función se encarga de enviar el dato que enciende o apaga el led
        Socket socket;
        try {
            socket = new Socket("172.21.255.192",9500);//Son los mismos datos que se ingresaron en
            //la ventana anterior para poder hacer la conexion con el socket
            PrintWriter dataOut;
            dataOut = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())),true);
            dataOut.println(data);//Se hace el envío del dato
        } catch (IOException e) {//Se ejecuta en caso de que existan errores
            e.printStackTrace();}
    }//Close SendData
}//Close class