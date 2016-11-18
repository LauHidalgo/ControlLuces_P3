package com.tec.appluces;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;

import java.net.Socket;

public class Luces extends AppCompatActivity {
    //Se trabajara con una ip y socket estáticos, por tanto se definen a  continuacion
    private String AddServer = "172.21.255.192";
    private Socket socket;
    private int Port = 9500;

    private boolean addr = true;

    
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_luces);


    }//Close onCreate
}//Close Class Luces
