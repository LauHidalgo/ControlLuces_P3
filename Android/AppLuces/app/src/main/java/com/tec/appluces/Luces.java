package com.tec.appluces;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

public class Luces extends AppCompatActivity {
    //Se trabajara con una ip y socket estáticos, por tanto se definen a  continuacion
    private String AddServer = "172.21.255.192";
    private Socket socket;
    private int Port = 9500;

    private boolean addr = true;

    class Hilo extends Thread{
        //Se creo un hilo para trabajar con el socket y hacer envio de los datos
        // (en este caso letras) para encender los leds
        public void run(){
            addr = true;
            while (true){
                try {
                    BufferedReader data = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                } catch (IOException e) {
                    //Se ejecuta en caso de que existan fallos
                    //ademas se muestra el error ocurrido
                    e.printStackTrace();
                }
            }//close while true
        }//Close void run
    }//Close class Hilo

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_luces);


    }//Close onCreate
}//Close Class Luces
